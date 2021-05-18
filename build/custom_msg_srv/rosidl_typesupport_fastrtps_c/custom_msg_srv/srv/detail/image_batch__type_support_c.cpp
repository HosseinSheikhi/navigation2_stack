// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_msg_srv:srv/ImageBatch.idl
// generated code does not contain a copyright notice
#include "custom_msg_srv/srv/detail/image_batch__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_msg_srv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msg_srv/srv/detail/image_batch__struct.h"
#include "custom_msg_srv/srv/detail/image_batch__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _ImageBatch_Request__ros_msg_type = custom_msg_srv__srv__ImageBatch_Request;

static bool _ImageBatch_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ImageBatch_Request__ros_msg_type * ros_message = static_cast<const _ImageBatch_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: overhead_cameras_num
  {
    cdr << ros_message->overhead_cameras_num;
  }

  return true;
}

static bool _ImageBatch_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ImageBatch_Request__ros_msg_type * ros_message = static_cast<_ImageBatch_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: overhead_cameras_num
  {
    cdr >> ros_message->overhead_cameras_num;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msg_srv
size_t get_serialized_size_custom_msg_srv__srv__ImageBatch_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ImageBatch_Request__ros_msg_type * ros_message = static_cast<const _ImageBatch_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name overhead_cameras_num
  {
    size_t item_size = sizeof(ros_message->overhead_cameras_num);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ImageBatch_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msg_srv__srv__ImageBatch_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msg_srv
size_t max_serialized_size_custom_msg_srv__srv__ImageBatch_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: overhead_cameras_num
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ImageBatch_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_msg_srv__srv__ImageBatch_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ImageBatch_Request = {
  "custom_msg_srv::srv",
  "ImageBatch_Request",
  _ImageBatch_Request__cdr_serialize,
  _ImageBatch_Request__cdr_deserialize,
  _ImageBatch_Request__get_serialized_size,
  _ImageBatch_Request__max_serialized_size
};

static rosidl_message_type_support_t _ImageBatch_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ImageBatch_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msg_srv, srv, ImageBatch_Request)() {
  return &_ImageBatch_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "custom_msg_srv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "custom_msg_srv/srv/detail/image_batch__struct.h"
// already included above
// #include "custom_msg_srv/srv/detail/image_batch__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "sensor_msgs/msg/detail/image__functions.h"  // image

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_msg_srv
size_t get_serialized_size_sensor_msgs__msg__Image(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_msg_srv
size_t max_serialized_size_sensor_msgs__msg__Image(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_custom_msg_srv
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image)();


using _ImageBatch_Response__ros_msg_type = custom_msg_srv__srv__ImageBatch_Response;

static bool _ImageBatch_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ImageBatch_Response__ros_msg_type * ros_message = static_cast<const _ImageBatch_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: image
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    size_t size = 3;
    auto array_ptr = ros_message->image;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _ImageBatch_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ImageBatch_Response__ros_msg_type * ros_message = static_cast<_ImageBatch_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: image
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, sensor_msgs, msg, Image
      )()->data);
    size_t size = 3;
    auto array_ptr = ros_message->image;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msg_srv
size_t get_serialized_size_custom_msg_srv__srv__ImageBatch_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ImageBatch_Response__ros_msg_type * ros_message = static_cast<const _ImageBatch_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name image
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->image;

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_sensor_msgs__msg__Image(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ImageBatch_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_msg_srv__srv__ImageBatch_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_msg_srv
size_t max_serialized_size_custom_msg_srv__srv__ImageBatch_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: image
  {
    size_t array_size = 3;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_sensor_msgs__msg__Image(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _ImageBatch_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_msg_srv__srv__ImageBatch_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ImageBatch_Response = {
  "custom_msg_srv::srv",
  "ImageBatch_Response",
  _ImageBatch_Response__cdr_serialize,
  _ImageBatch_Response__cdr_deserialize,
  _ImageBatch_Response__get_serialized_size,
  _ImageBatch_Response__max_serialized_size
};

static rosidl_message_type_support_t _ImageBatch_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ImageBatch_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msg_srv, srv, ImageBatch_Response)() {
  return &_ImageBatch_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "custom_msg_srv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_msg_srv/srv/image_batch.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ImageBatch__callbacks = {
  "custom_msg_srv::srv",
  "ImageBatch",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msg_srv, srv, ImageBatch_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msg_srv, srv, ImageBatch_Response)(),
};

static rosidl_service_type_support_t ImageBatch__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ImageBatch__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_msg_srv, srv, ImageBatch)() {
  return &ImageBatch__handle;
}

#if defined(__cplusplus)
}
#endif
