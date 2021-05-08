from rclpy._rclpy import rclpy_convert_from_py_qos_policy
import rclpy
from rclpy.node import Node
from rcl_interfaces.msg import ParameterDescriptor, ParameterType
from ceiling_segmentation.UNET.VGG16 import vgg16_train, vgg16_inference
from ceiling_segmentation.DenseNet.models import densenet_train, densenet_inference


class CeilingSegmentation(Node):
    def __init__(self):
        super(CeilingSegmentation, self).__init__('ceiling_segmentation')
        self.mode = None
        self.method = None
        self.frequency = None
        self.overhead_topics = None
        self.parameters()

    def parameters(self):
        """
        Define ROS2 parameters and read from config file
        :return: None
        """
        param_mode_descriptor = ParameterDescriptor(type=ParameterType.PARAMETER_STRING,
                                                    description='This parameter is used to determine this node must be in train or inference mode.')
        self.declare_parameter('mode', 'inference', param_mode_descriptor)

        param_method_descriptor = ParameterDescriptor(type=ParameterType.PARAMETER_STRING,
                                                      description='This parameter is used to determine the method that must be run in this node. Could be VGG16 or DenseNet')
        self.declare_parameter('method', 'VGG16', param_method_descriptor)

        param_frequency_descriptor = ParameterDescriptor(type=ParameterType.PARAMETER_DOUBLE,
                                                         description='This parameter is used to determine the frequency of publishing segmented images')
        self.declare_parameter('frequency', 10.0, param_frequency_descriptor)

        param_overhead_topics_descriptor = ParameterDescriptor(type=ParameterType.PARAMETER_STRING_ARRAY,
                                                               description='This parameter is used to find topics that overhead cameras are publishing on. (must be subscribed by this package)')
        self.declare_parameter('overhead_topics', '[]', param_overhead_topics_descriptor)

        self.mode = self.get_parameter('mode').get_parameter_value().string_value
        if self.mode != "VGG16" or self.mode != "DenseNet":
            self.get_logger().error("Mode in config file must be either VGG16 or DenseNet")
        self.method = self.get_parameter('method').get_parameter_value().string_value
        if self.method != "train" or self.method != "test":
            self.get_logger().error("Method in config file must be either train or inference")
        self.frequency = self.get_parameter('frequency').get_parameter_value().double_value
        self.overhead_topics = self.get_parameter('overhead_topics').get_parameter_value().string_array_value


def main(args=None):
    rclpy.init(args=args)
    ceiling_segmentation = CeilingSegmentation()
    if ceiling_segmentation.method == "VGG16":
        if ceiling_segmentation.method == "train":
            pass
        elif ceiling_segmentation.method == "inference":
            pass
    elif ceiling_segmentation.method == "DenseNet":
        if ceiling_segmentation.method == "train":
            pass
        elif ceiling_segmentation.method == "inference":
            pass