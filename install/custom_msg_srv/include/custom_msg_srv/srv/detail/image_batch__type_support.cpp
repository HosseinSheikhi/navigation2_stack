// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from custom_msg_srv:srv/ImageBatch.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "custom_msg_srv/srv/detail/image_batch__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_msg_srv
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ImageBatch_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_msg_srv::srv::ImageBatch_Request(_init);
}

void ImageBatch_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_msg_srv::srv::ImageBatch_Request *>(message_memory);
  typed_message->~ImageBatch_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ImageBatch_Request_message_member_array[1] = {
  {
    "overhead_cameras_num",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_srv::srv::ImageBatch_Request, overhead_cameras_num),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ImageBatch_Request_message_members = {
  "custom_msg_srv::srv",  // message namespace
  "ImageBatch_Request",  // message name
  1,  // number of fields
  sizeof(custom_msg_srv::srv::ImageBatch_Request),
  ImageBatch_Request_message_member_array,  // message members
  ImageBatch_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ImageBatch_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ImageBatch_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ImageBatch_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace custom_msg_srv


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg_srv::srv::ImageBatch_Request>()
{
  return &::custom_msg_srv::srv::rosidl_typesupport_introspection_cpp::ImageBatch_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_srv, srv, ImageBatch_Request)() {
  return &::custom_msg_srv::srv::rosidl_typesupport_introspection_cpp::ImageBatch_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "custom_msg_srv/srv/detail/image_batch__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace custom_msg_srv
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void ImageBatch_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) custom_msg_srv::srv::ImageBatch_Response(_init);
}

void ImageBatch_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<custom_msg_srv::srv::ImageBatch_Response *>(message_memory);
  typed_message->~ImageBatch_Response();
}

size_t size_function__ImageBatch_Response__image(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__ImageBatch_Response__image(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<sensor_msgs::msg::Image, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__ImageBatch_Response__image(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<sensor_msgs::msg::Image, 3> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ImageBatch_Response_message_member_array[1] = {
  {
    "image",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::Image>(),  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(custom_msg_srv::srv::ImageBatch_Response, image),  // bytes offset in struct
    nullptr,  // default value
    size_function__ImageBatch_Response__image,  // size() function pointer
    get_const_function__ImageBatch_Response__image,  // get_const(index) function pointer
    get_function__ImageBatch_Response__image,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ImageBatch_Response_message_members = {
  "custom_msg_srv::srv",  // message namespace
  "ImageBatch_Response",  // message name
  1,  // number of fields
  sizeof(custom_msg_srv::srv::ImageBatch_Response),
  ImageBatch_Response_message_member_array,  // message members
  ImageBatch_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ImageBatch_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ImageBatch_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ImageBatch_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace custom_msg_srv


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_msg_srv::srv::ImageBatch_Response>()
{
  return &::custom_msg_srv::srv::rosidl_typesupport_introspection_cpp::ImageBatch_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_srv, srv, ImageBatch_Response)() {
  return &::custom_msg_srv::srv::rosidl_typesupport_introspection_cpp::ImageBatch_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "custom_msg_srv/srv/detail/image_batch__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace custom_msg_srv
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers ImageBatch_service_members = {
  "custom_msg_srv::srv",  // service namespace
  "ImageBatch",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<custom_msg_srv::srv::ImageBatch>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t ImageBatch_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ImageBatch_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace custom_msg_srv


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<custom_msg_srv::srv::ImageBatch>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::custom_msg_srv::srv::rosidl_typesupport_introspection_cpp::ImageBatch_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::custom_msg_srv::srv::ImageBatch_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::custom_msg_srv::srv::ImageBatch_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_msg_srv, srv, ImageBatch)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<custom_msg_srv::srv::ImageBatch>();
}

#ifdef __cplusplus
}
#endif
