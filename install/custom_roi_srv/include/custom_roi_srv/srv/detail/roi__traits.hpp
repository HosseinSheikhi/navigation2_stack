// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_ROI_SRV__SRV__DETAIL__ROI__TRAITS_HPP_
#define CUSTOM_ROI_SRV__SRV__DETAIL__ROI__TRAITS_HPP_

#include "custom_roi_srv/srv/detail/roi__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_roi_srv::srv::ROI_Request>()
{
  return "custom_roi_srv::srv::ROI_Request";
}

template<>
inline const char * name<custom_roi_srv::srv::ROI_Request>()
{
  return "custom_roi_srv/srv/ROI_Request";
}

template<>
struct has_fixed_size<custom_roi_srv::srv::ROI_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_roi_srv::srv::ROI_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_roi_srv::srv::ROI_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_roi_srv::srv::ROI_Response>()
{
  return "custom_roi_srv::srv::ROI_Response";
}

template<>
inline const char * name<custom_roi_srv::srv::ROI_Response>()
{
  return "custom_roi_srv/srv/ROI_Response";
}

template<>
struct has_fixed_size<custom_roi_srv::srv::ROI_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<custom_roi_srv::srv::ROI_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<custom_roi_srv::srv::ROI_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<custom_roi_srv::srv::ROI>()
{
  return "custom_roi_srv::srv::ROI";
}

template<>
inline const char * name<custom_roi_srv::srv::ROI>()
{
  return "custom_roi_srv/srv/ROI";
}

template<>
struct has_fixed_size<custom_roi_srv::srv::ROI>
  : std::integral_constant<
    bool,
    has_fixed_size<custom_roi_srv::srv::ROI_Request>::value &&
    has_fixed_size<custom_roi_srv::srv::ROI_Response>::value
  >
{
};

template<>
struct has_bounded_size<custom_roi_srv::srv::ROI>
  : std::integral_constant<
    bool,
    has_bounded_size<custom_roi_srv::srv::ROI_Request>::value &&
    has_bounded_size<custom_roi_srv::srv::ROI_Response>::value
  >
{
};

template<>
struct is_service<custom_roi_srv::srv::ROI>
  : std::true_type
{
};

template<>
struct is_service_request<custom_roi_srv::srv::ROI_Request>
  : std::true_type
{
};

template<>
struct is_service_response<custom_roi_srv::srv::ROI_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CUSTOM_ROI_SRV__SRV__DETAIL__ROI__TRAITS_HPP_
