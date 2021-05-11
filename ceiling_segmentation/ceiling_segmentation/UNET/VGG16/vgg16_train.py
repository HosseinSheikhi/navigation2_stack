import tensorflow as tf
from ceiling_segmentation.UNET.VGG16.EncoderDecoder import EncoderDecoder
from ceiling_segmentation.utils.LoadData import LoadData
import matplotlib.pyplot as plt
import datetime
import numpy as np
import pathlib

tf.config.experimental.set_memory_growth(tf.config.experimental.list_physical_devices('GPU')[0], True)


class VGG16Train:
    def __init__(self):
        self.batch_size = 16
        self.image_size = 224
        self.buffer_size = 32
        self.epoch = 6
        self.autotune = tf.data.experimental.AUTOTUNE
        self.seed = 15
        self.num_channels = 3
        self.num_classes = 2
        self.parameters()
        self.data_set = self.load_data()

    def load_data(self):
        data_address = pathlib.Path(__file__).parent.absolute()
        data_address.replace("UNET/VGG16", "data")
        dataset = LoadData(data_address + "/training/images/*.png",
                           data_address + "validation/images/*.png",
                           self.image_size, self.batch_size, shuffle_buffer_size=self.buffer_size,
                           seed=123).get_dataset()

        # following lines are used for debug
        print(dataset['train'])
        print(dataset['val'])

        sample_image = None
        sample_mask = None
        for image, segmented_mask in dataset['train'].take(1):
            sample_image, sample_mask = image, segmented_mask

        self.display_sample([sample_image[0], sample_mask[0]])

        return dataset

    def parameters(self):
        pass

    def display_sample(self, display_list):
        """
        Show side-by-side an input image, the ground truth and the prediction.
        :param display_list: a list including [image, ground truth] or [image, ground truth, prediction]
        :return:
        """
        plt.figure(figsize=(18, 18))

        title = ['Input Image', 'True Mask', 'Predicted Mask']

        for i in range(len(display_list)):
            plt.subplot(1, len(display_list), i + 1)
            plt.title(title[i])
            img = tf.keras.preprocessing.image.array_to_img(display_list[i])
            plt.imshow(img)
            plt.axis('off')
        plt.show()

    def create_mask(self, pred_mask: tf.Tensor) -> tf.Tensor:
        """Return a filter mask with the top 1 predictions
        only.

        Parameters
        ----------
        pred_mask : tf.Tensor
            A [IMG_SIZE, IMG_SIZE, N_CLASS] tensor. For each pixel we have
            N_CLASS values (vector) which represents the probability of the pixel
            being these classes. Example: A pixel with the vector [0.0, 0.0, 1.0]
            has been predicted class 2 with a probability of 100%.

        Returns
        -------
        tf.Tensor
            A [IMG_SIZE, IMG_SIZE, 1] mask with top 1 predictions
            for each pixels.
        """
        # pred_mask -> [IMG_SIZE, SIZE, N_CLASS]
        # 1 prediction for each class but we want the highest score only
        # so we use argmax
        pred_mask = tf.argmax(pred_mask, axis=-1)
        # pred_mask becomes [IMG_SIZE, IMG_SIZE]
        # but matplotlib needs [IMG_SIZE, IMG_SIZE, 1]
        pred_mask = tf.expand_dims(pred_mask, axis=-1)
        return pred_mask

    def show_predictions(self, dataset, num=1):
        """Show a sample prediction.

        Parameters
        ----------
        dataset : [type], optional
            [Input dataset, by default None
        num : int, optional
            Number of sample to show, by default 1
        """

        for image, segmented_mask in dataset.take(num):
            sample_image, sample_mask = image, segmented_mask

            # The UNET is expecting a tensor of the size
            # [BATCH_SIZE, IMG_SIZE, IMG_SIZE, 3]
            # but sample_image[0] is [IMG_SIZE, IMG_SIZE, 3]
            # and we want only 1 inference to be faster
            # so we add an additional dimension [1, IMG_SIZE, IMG_SIZE, 3]
            one_img_batch = sample_image[0][tf.newaxis, ...]
            pred_mask = encoderDecoder(one_img_batch, training=False)
            mask = self.create_mask(pred_mask)
            self.display_sample([sample_image[0], sample_mask[0], mask[0]])

    def weighted_loss_function(self, y_true, y_pred):
        cross_entropy = tf.keras.backend.sparse_categorical_crossentropy(y_true, y_pred)
        # calculate weight
        y_true = tf.cast(y_true, dtype='float32')
        y_true = tf.where(y_true == 0, np.dtype('float32').type(0.25), y_true)
        weight = tf.where(y_true == 1, np.dtype('float32').type(0.75), y_true)
        # multiply weight by cross entropy
        weight = tf.squeeze(weight)
        weighted_cross_entropy = tf.multiply(weight, cross_entropy)
        return tf.reduce_mean(weighted_cross_entropy)

    def build_model(self):
        self.encoderDecoder = EncoderDecoder(self.num_classes, batch_norm=False)

        # freeze the encoder and initialize it weights by vgg trained on imagenet
        self.encoderDecoder.encoder.trainable = False
        self.encoderDecoder.build((None, self.image_size, self.image_size, 3))
        self.encoderDecoder.encoder.set_weights(tf.keras.applications.VGG16(include_top=False, weights='imagenet',
                                                                       input_shape=(
                                                                       self.image_size, self.image_size, 3)).get_weights())

        self.loss_function = tf.keras.losses.SparseCategoricalCrossentropy()
        self.optimizer = tf.keras.optimizers.Adam(learning_rate=0.0002, epsilon=1e-6)




# set up the metric and logs
train_loss = tf.keras.metrics.Mean(name="train_loss")
train_acc = tf.keras.metrics.SparseCategoricalAccuracy(name='train_accuracy')
test_loss = tf.keras.metrics.Mean(name='train_accuracy')
test_acc = tf.keras.metrics.SparseCategoricalAccuracy(name='test_accuracy')
current_time = datetime.datetime.now().strftime("%Y%m%d-%H%M%S")
train_log_dir = 'logs/gradient_tape/' + current_time + '/train'
test_log_dir = 'logs/gradient_tape/' + current_time + '/test'
train_summary_writer = tf.summary.create_file_writer(train_log_dir)
test_summary_writer = tf.summary.create_file_writer(test_log_dir)

show_predictions(dataset['val'], 1)


@tf.function
def train_model(images, masks):
    with tf.GradientTape() as g:
        prediction = encoderDecoder(images)
        loss = loss_function(masks, prediction)

    trainable_variables = encoderDecoder.trainable_variables
    gradients = g.gradient(loss, trainable_variables)
    optimizer.apply_gradients(zip(gradients, trainable_variables))

    train_loss.update_state(loss)
    train_acc.update_state(masks, prediction)


@tf.function
def test_model(images, masks):
    predictions = encoderDecoder(images)
    loss = loss_function(masks, predictions)

    test_loss.update_state(loss)
    test_acc.update_state(masks, predictions)


batch_train_ctr = 0
batch_test_ctr = 0
for repeat in range(EPOCHS):

    # reset the matrices at the beginning of every epoch
    train_loss.reset_states()
    train_acc.reset_states()
    test_loss.reset_states()
    test_acc.reset_states()

    for (x_batch, y_batch) in dataset['train']:
        train_model(x_batch, y_batch)
        batch_train_ctr += 1

        template = 'Epoch {}, Batch {}, Loss: {}, Accuracy: {}'
        print(template.format(repeat, batch_train_ctr,
                              train_loss.result(),
                              train_acc.result() * 100))

        with train_summary_writer.as_default():
            tf.summary.scalar('train_loss', train_loss.result(), step=batch_train_ctr)
            tf.summary.scalar('train_accuracy', train_acc.result(), step=batch_train_ctr)

    for (x_batch, y_batch) in dataset['val']:
        test_model(x_batch, y_batch)
        batch_test_ctr += 1

        template = 'Epoch {}, Batch{}, Test Loss: {}, Test Accuracy: {}'
        print(template.format(repeat, batch_test_ctr,
                              test_loss.result(),
                              test_acc.result() * 100))

        with test_summary_writer.as_default():
            tf.summary.scalar('test_loss', test_loss.result(), step=batch_test_ctr)
            tf.summary.scalar('test_accuracy', test_acc.result(), step=batch_test_ctr)

    show_predictions(dataset['val'], num=5)
    # encoderDecoder.save_weights(os.getcwd()+"/weights/WithoutBN/NaiveLoss"+str(repeat+1)+"/")
