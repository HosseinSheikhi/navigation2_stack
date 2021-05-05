import tensorflow as tf


class VggBlockWithBN(tf.keras.layers.Layer):
    def __init__(self, layers, filters, kernel_size, name, stride=1):
        super(VggBlockWithBN, self).__init__()
        self.kernel_size = kernel_size
        self.filters = filters
        self.stride = stride
        self.layers = layers
        self.layer_name = name

        self.conv_layers = [tf.keras.layers.Conv2D(self.filters, self.kernel_size, strides=self.stride, padding="SAME",
                                                   kernel_initializer='he_normal', name=self.layer_name + "_" + str(i))
                            for i in range(self.layers)]
        self.bn_layers = [tf.keras.layers.BatchNormalization(name=self.layer_name + "_" + str(i)) for i in range(self.layers)]

    def call(self, inputs, training):
        x = inputs
        for i in range(self.layers):
            x = self.conv_layers[i](x)
            x = self.bn_layers[i](x, training=training)
            x = tf.nn.relu(x)

        return x
