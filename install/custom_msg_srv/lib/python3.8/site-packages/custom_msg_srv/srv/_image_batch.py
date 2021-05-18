# generated from rosidl_generator_py/resource/_idl.py.em
# with input from custom_msg_srv:srv/ImageBatch.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ImageBatch_Request(type):
    """Metaclass of message 'ImageBatch_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msg_srv')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msg_srv.srv.ImageBatch_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__image_batch__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__image_batch__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__image_batch__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__image_batch__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__image_batch__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ImageBatch_Request(metaclass=Metaclass_ImageBatch_Request):
    """Message class 'ImageBatch_Request'."""

    __slots__ = [
        '_overhead_cameras_num',
    ]

    _fields_and_field_types = {
        'overhead_cameras_num': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.overhead_cameras_num = kwargs.get('overhead_cameras_num', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.overhead_cameras_num != other.overhead_cameras_num:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def overhead_cameras_num(self):
        """Message field 'overhead_cameras_num'."""
        return self._overhead_cameras_num

    @overhead_cameras_num.setter
    def overhead_cameras_num(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'overhead_cameras_num' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'overhead_cameras_num' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._overhead_cameras_num = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_ImageBatch_Response(type):
    """Metaclass of message 'ImageBatch_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msg_srv')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msg_srv.srv.ImageBatch_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__image_batch__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__image_batch__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__image_batch__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__image_batch__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__image_batch__response

            from sensor_msgs.msg import Image
            if Image.__class__._TYPE_SUPPORT is None:
                Image.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ImageBatch_Response(metaclass=Metaclass_ImageBatch_Response):
    """Message class 'ImageBatch_Response'."""

    __slots__ = [
        '_image',
    ]

    _fields_and_field_types = {
        'image': 'sensor_msgs/Image[3]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'Image'), 3),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from sensor_msgs.msg import Image
        self.image = kwargs.get(
            'image',
            [Image() for x in range(3)]
        )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.image != other.image:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def image(self):
        """Message field 'image'."""
        return self._image

    @image.setter
    def image(self, value):
        if __debug__:
            from sensor_msgs.msg import Image
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 3 and
                 all(isinstance(v, Image) for v in value) and
                 True), \
                "The 'image' field must be a set or sequence with length 3 and each value of type 'Image'"
        self._image = value


class Metaclass_ImageBatch(type):
    """Metaclass of service 'ImageBatch'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('custom_msg_srv')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'custom_msg_srv.srv.ImageBatch')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__image_batch

            from custom_msg_srv.srv import _image_batch
            if _image_batch.Metaclass_ImageBatch_Request._TYPE_SUPPORT is None:
                _image_batch.Metaclass_ImageBatch_Request.__import_type_support__()
            if _image_batch.Metaclass_ImageBatch_Response._TYPE_SUPPORT is None:
                _image_batch.Metaclass_ImageBatch_Response.__import_type_support__()


class ImageBatch(metaclass=Metaclass_ImageBatch):
    from custom_msg_srv.srv._image_batch import ImageBatch_Request as Request
    from custom_msg_srv.srv._image_batch import ImageBatch_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
