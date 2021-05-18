// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice
#include "custom_roi_srv/srv/detail/roi__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "custom_roi_srv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_roi_srv/srv/detail/roi__struct.h"
#include "custom_roi_srv/srv/detail/roi__functions.h"
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


using _ROI_Request__ros_msg_type = custom_roi_srv__srv__ROI_Request;

static bool _ROI_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ROI_Request__ros_msg_type * ros_message = static_cast<const _ROI_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr << ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

static bool _ROI_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ROI_Request__ros_msg_type * ros_message = static_cast<_ROI_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: structure_needs_at_least_one_member
  {
    cdr >> ros_message->structure_needs_at_least_one_member;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_roi_srv
size_t get_serialized_size_custom_roi_srv__srv__ROI_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ROI_Request__ros_msg_type * ros_message = static_cast<const _ROI_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message->structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ROI_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_roi_srv__srv__ROI_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_roi_srv
size_t max_serialized_size_custom_roi_srv__srv__ROI_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _ROI_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_roi_srv__srv__ROI_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ROI_Request = {
  "custom_roi_srv::srv",
  "ROI_Request",
  _ROI_Request__cdr_serialize,
  _ROI_Request__cdr_deserialize,
  _ROI_Request__get_serialized_size,
  _ROI_Request__max_serialized_size
};

static rosidl_message_type_support_t _ROI_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ROI_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_roi_srv, srv, ROI_Request)() {
  return &_ROI_Request__type_support;
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
// #include "custom_roi_srv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__struct.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__functions.h"
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


// forward declare type support functions


using _ROI_Response__ros_msg_type = custom_roi_srv__srv__ROI_Response;

static bool _ROI_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ROI_Response__ros_msg_type * ros_message = static_cast<const _ROI_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: x_min
  {
    cdr << ros_message->x_min;
  }

  // Field name: y_min
  {
    cdr << ros_message->y_min;
  }

  // Field name: x_max
  {
    cdr << ros_message->x_max;
  }

  // Field name: y_max
  {
    cdr << ros_message->y_max;
  }

  return true;
}

static bool _ROI_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ROI_Response__ros_msg_type * ros_message = static_cast<_ROI_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: x_min
  {
    cdr >> ros_message->x_min;
  }

  // Field name: y_min
  {
    cdr >> ros_message->y_min;
  }

  // Field name: x_max
  {
    cdr >> ros_message->x_max;
  }

  // Field name: y_max
  {
    cdr >> ros_message->y_max;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_roi_srv
size_t get_serialized_size_custom_roi_srv__srv__ROI_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ROI_Response__ros_msg_type * ros_message = static_cast<const _ROI_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name x_min
  {
    size_t item_size = sizeof(ros_message->x_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_min
  {
    size_t item_size = sizeof(ros_message->y_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name x_max
  {
    size_t item_size = sizeof(ros_message->x_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name y_max
  {
    size_t item_size = sizeof(ros_message->y_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ROI_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_custom_roi_srv__srv__ROI_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_custom_roi_srv
size_t max_serialized_size_custom_roi_srv__srv__ROI_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: x_min
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y_min
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: x_max
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: y_max
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ROI_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_custom_roi_srv__srv__ROI_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ROI_Response = {
  "custom_roi_srv::srv",
  "ROI_Response",
  _ROI_Response__cdr_serialize,
  _ROI_Response__cdr_deserialize,
  _ROI_Response__get_serialized_size,
  _ROI_Response__max_serialized_size
};

static rosidl_message_type_support_t _ROI_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ROI_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_roi_srv, srv, ROI_Response)() {
  return &_ROI_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "custom_roi_srv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "custom_roi_srv/srv/roi.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t ROI__callbacks = {
  "custom_roi_srv::srv",
  "ROI",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_roi_srv, srv, ROI_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_roi_srv, srv, ROI_Response)(),
};

static rosidl_service_type_support_t ROI__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &ROI__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_roi_srv, srv, ROI)() {
  return &ROI__handle;
}

#if defined(__cplusplus)
}
#endif
