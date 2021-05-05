import tensorflow as tf
from ceiling_segmentation.UNET.VGG16.VggBlock import VggBlock

"""
So if you're wondering, "should I use the Layer class or the Model class?", ask yourself: will I need to call fit() on it?
Will I need to call save() on it? If so, go with Model. If not (either because your class is just a block in a bigger 
system, or because you are writing training & saving code yourself), use Layer.

In general like this example: https://www.tensorflow.org/guide/keras/custom_layers_and_models#the_model_class
the Decoder and Encoder must be defined as subclass Layer, but cause I gonna load the pre-trained weights for UNET
I have to define as subclass UNET
"""


class Encoder(tf.keras.Model):
    def __init__(self):
        super(Encoder, self).__init__()
        self.conv_blk_5 = None
        self.conv_blk_4 = None
        self.conv_blk_3 = None
        self.conv_blk_2 = None
        self.conv_blk_1 = None

    def build(self, input_shape):
        self.conv_blk_1 = VggBlock(layers=2, filters=64, kernel_size=3, name="enc_conv_blk_1")
        self.conv_blk_2 = VggBlock(layers=2, filters=128, kernel_size=3, name="enc_conv_blk_2")
        self.conv_blk_3 = VggBlock(layers=3, filters=256, kernel_size=3, name="enc_conv_blk_3")
        self.conv_blk_4 = VggBlock(layers=3, filters=512, kernel_size=3, name="enc_conv_blk_4")
        self.conv_blk_5 = VggBlock(layers=3, filters=512, kernel_size=3, name="enc_conv_blk_5")

    def call(self, inputs):
        x = self.conv_blk_1(inputs)
        blk_1_out = x
        x = tf.keras.layers.MaxPooling2D((2, 2), strides=2, name="max_pool_1")(x)

        x = self.conv_blk_2(x)
        blk_2_out = x
        x = tf.keras.layers.MaxPooling2D((2, 2), strides=2, name="max_pool_2")(x)

        x = self.conv_blk_3(x)
        blk_3_out = x
        x = tf.keras.layers.MaxPooling2D((2, 2), strides=2, name="max_pool_3")(x)

        x = self.conv_blk_4(x)
        blk_4_out = x
        x = tf.keras.layers.MaxPooling2D((2, 2), strides=2, name="max_pool_4")(x)

        x = self.conv_blk_5(x)
        blk_5_out = x
        x = tf.keras.layers.MaxPooling2D((2, 2), strides=2, name="max_pool_5")(x)

        return blk_1_out, blk_2_out, blk_3_out, blk_4_out, blk_5_out, x
