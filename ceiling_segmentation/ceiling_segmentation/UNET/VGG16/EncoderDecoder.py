import tensorflow as tf
from ceiling_segmentation.UNET.VGG16.Encoder import Encoder
from ceiling_segmentation.UNET.VGG16.Decoder import Decoder


class EncoderDecoder(tf.keras.Model):
    def __init__(self, num_classes, decoder_with_BN):
        super(EncoderDecoder, self).__init__()
        self.encoder = Encoder()
        self.decoder = Decoder(decoder_with_BN)
        self.middle_conv = tf.keras.layers.Conv2D(1024, 3, strides=1, padding="same", activation="relu")
        self.last_conv = tf.keras.layers.Conv2D(num_classes, 1, strides=1, padding="same", activation="softmax")

    def call(self, inputs, training=False):
        blk_1_out, blk_2_out, blk_3_out, blk_4_out, blk_5_out, x = self.encoder(inputs)

        x = self.middle_conv(x)

        x = self.decoder(x, blk_1_out, blk_2_out, blk_3_out, blk_4_out, blk_5_out, training)

        output = self.last_conv(x)
        return output
