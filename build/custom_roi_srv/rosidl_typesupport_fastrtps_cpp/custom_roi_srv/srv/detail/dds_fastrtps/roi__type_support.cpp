// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice
#include "custom_roi_srv/srv/detail/roi__rosidl_typesupport_fastrtps_cpp.hpp"
#include "custom_roi_srv/srv/detail/roi__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace custom_roi_srv
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_roi_srv
cdr_serialize(
  const custom_roi_srv::srv::ROI_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: structure_needs_at_least_one_member
  cdr << ros_message.structure_needs_at_least_one_member;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_roi_srv
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  custom_roi_srv::srv::ROI_Request & ros_message)
{
  // Member: structure_needs_at_least_one_member
  cdr >> ros_message.structure_needs_at_least_one_member;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_roi_srv
get_serialized_size(
  const custom_roi_srv::srv::ROI_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: structure_needs_at_least_one_member
  {
    size_t item_size = sizeof(ros_message.structure_needs_at_least_one_member);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_roi_srv
max_serialized_size_ROI_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: structure_needs_at_least_one_member
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _ROI_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const custom_roi_srv::srv::ROI_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ROI_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<custom_roi_srv::srv::ROI_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ROI_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const custom_roi_srv::srv::ROI_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ROI_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ROI_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _ROI_Request__callbacks = {
  "custom_roi_srv::srv",
  "ROI_Request",
  _ROI_Request__cdr_serialize,
  _ROI_Request__cdr_deserialize,
  _ROI_Request__get_serialized_size,
  _ROI_Request__max_serialized_size
};

static rosidl_message_type_support_t _ROI_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ROI_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace custom_roi_srv

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custom_roi_srv
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_roi_srv::srv::ROI_Request>()
{
  return &custom_roi_srv::srv::typesupport_fastrtps_cpp::_ROI_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_roi_srv, srv, ROI_Request)() {
  return &custom_roi_srv::srv::typesupport_fastrtps_cpp::_ROI_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace custom_roi_srv
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_roi_srv
cdr_serialize(
  const custom_roi_srv::srv::ROI_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: x_min
  cdr << ros_message.x_min;
  // Member: y_min
  cdr << ros_message.y_min;
  // Member: x_max
  cdr << ros_message.x_max;
  // Member: y_max
  cdr << ros_message.y_max;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_roi_srv
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  custom_roi_srv::srv::ROI_Response & ros_message)
{
  // Member: x_min
  cdr >> ros_message.x_min;

  // Member: y_min
  cdr >> ros_message.y_min;

  // Member: x_max
  cdr >> ros_message.x_max;

  // Member: y_max
  cdr >> ros_message.y_max;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_roi_srv
get_serialized_size(
  const custom_roi_srv::srv::ROI_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: x_min
  {
    size_t item_size = sizeof(ros_message.x_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y_min
  {
    size_t item_size = sizeof(ros_message.y_min);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: x_max
  {
    size_t item_size = sizeof(ros_message.x_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: y_max
  {
    size_t item_size = sizeof(ros_message.y_max);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_custom_roi_srv
max_serialized_size_ROI_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: x_min
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: y_min
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: x_max
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: y_max
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _ROI_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const custom_roi_srv::srv::ROI_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ROI_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<custom_roi_srv::srv::ROI_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ROI_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const custom_roi_srv::srv::ROI_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ROI_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ROI_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _ROI_Response__callbacks = {
  "custom_roi_srv::srv",
  "ROI_Response",
  _ROI_Response__cdr_serialize,
  _ROI_Response__cdr_deserialize,
  _ROI_Response__get_serialized_size,
  _ROI_Response__max_serialized_size
};

static rosidl_message_type_support_t _ROI_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ROI_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace custom_roi_srv

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custom_roi_srv
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_roi_srv::srv::ROI_Response>()
{
  return &custom_roi_srv::srv::typesupport_fastrtps_cpp::_ROI_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_roi_srv, srv, ROI_Response)() {
  return &custom_roi_srv::srv::typesupport_fastrtps_cpp::_ROI_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace custom_roi_srv
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _ROI__callbacks = {
  "custom_roi_srv::srv",
  "ROI",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_roi_srv, srv, ROI_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_roi_srv, srv, ROI_Response)(),
};

static rosidl_service_type_support_t _ROI__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ROI__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace custom_roi_srv

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_custom_roi_srv
const rosidl_service_type_support_t *
get_service_type_support_handle<custom_roi_srv::srv::ROI>()
{
  return &custom_roi_srv::srv::typesupport_fastrtps_cpp::_ROI__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_roi_srv, srv, ROI)() {
  return &custom_roi_srv::srv::typesupport_fastrtps_cpp::_ROI__handle;
}

#ifdef __cplusplus
}
#endif
