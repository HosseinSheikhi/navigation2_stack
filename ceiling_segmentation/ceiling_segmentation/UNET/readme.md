#UNET
The u-net is convolutional network architecture for fast and precise segmentation of images.
![](docs/u-net-architecture.png)

Current implementation utilizes VGG16 for encoder and decoder part. The following parts explains different modules thoroughly.

##VGGBlock.py and VGGBlockWithBN.py
VGG Blocks are basic modules for a VGG implementations that are used for both Encoder and Decoder.
The main blocks of VGG16 are shown in the following figure. 

![](docs/vgg16.jpg)

**Note:** Fully connected layers (13-15) of VGG16 must be truncated for Unet.

**Note:** Pooling layers are part of encoder and de-conv layers are part of decoder.

The VGG Blocks are used for implementing layers (1, 3, 5, 7, 10) and are called within encoder and decoder.