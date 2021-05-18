// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_msg_srv:srv/ImageBatch.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__TRAITS_HPP_
#define CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__TRAITS_HPP_

#include "custom_msg_srv/srv/detail/image_batch__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msg_srv::srv::ImageBatch_Request>()
{
  return "custom_msg_srv::srv::ImageBatch_Request";
}

template<>
inline const char * name<custom_msg_srv::srv::ImageBatch_Request>()
{
  return "custom_msg_srv/srv/ImageBatch_Request";
}

template<>
struct has_fixed_size<custom_msg_srv::srv::ImageBatch_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_msg_srv::srv::ImageBatch_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_msg_srv::srv::ImageBatch_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msg_srv::srv::ImageBatch_Response>()
{
  return "custom_msg_srv::srv::ImageBatch_Response";
}

template<>
inline const char * name<custom_msg_srv::srv::ImageBatch_Response>()
{
  return "custom_msg_srv/srv/ImageBatch_Response";
}

template<>
struct has_fixed_size<custom_msg_srv::srv::ImageBatch_Response>
  : std::integral_constant<bool, has_fixed_size<sensor_msgs::msg::Image>::value> {};

template<>
struct has_bounded_size<custom_msg_srv::srv::ImageBatch_Response>
  : std::integral_constant<bool, has_bounded_size<sensor_msgs::msg::Image>::value> {};

template<>
struct is_message<custom_msg_srv::srv::ImageBatch_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_msg_srv::srv::ImageBatch>()
{
  return "custom_msg_srv::srv::ImageBatch";
}

template<>
inline const char * name<custom_msg_srv::srv::ImageBatch>()
{
  return "custom_msg_srv/srv/ImageBatch";
}

template<>
struct has_fixed_size<custom_msg_srv::srv::ImageBatch>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_msg_srv::srv::ImageBatch_Request>::value &&
    has_fixed_size<custom_msg_srv::srv::ImageBatch_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_msg_srv::srv::ImageBatch>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_msg_srv::srv::ImageBatch_Request>::value &&
    has_bounded_size<custom_msg_srv::srv::ImageBatch_Response>::value
  >
{
};

template<>
struct is_service<custom_msg_srv::srv::ImageBatch>
  : std::true_type
{
};

template<>
struct is_service_request<custom_msg_srv::srv::ImageBatch_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_msg_srv::srv::ImageBatch_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__TRAITS_HPP_
