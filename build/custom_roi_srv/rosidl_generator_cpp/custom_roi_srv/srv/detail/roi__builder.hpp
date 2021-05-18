// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_ROI_SRV__SRV__DETAIL__ROI__BUILDER_HPP_
#define CUSTOM_ROI_SRV__SRV__DETAIL__ROI__BUILDER_HPP_

#include "custom_roi_srv/srv/detail/roi__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_roi_srv
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_roi_srv::srv::ROI_Request>()
{
  return ::custom_roi_srv::srv::ROI_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace custom_roi_srv


namespace custom_roi_srv
{

namespace srv
{

namespace builder
{

class Init_ROI_Response_y_max
{
public:
  explicit Init_ROI_Response_y_max(::custom_roi_srv::srv::ROI_Response & msg)
  : msg_(msg)
  {}
  ::custom_roi_srv::srv::ROI_Response y_max(::custom_roi_srv::srv::ROI_Response::_y_max_type arg)
  {
    msg_.y_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_roi_srv::srv::ROI_Response msg_;
};

class Init_ROI_Response_x_max
{
public:
  explicit Init_ROI_Response_x_max(::custom_roi_srv::srv::ROI_Response & msg)
  : msg_(msg)
  {}
  Init_ROI_Response_y_max x_max(::custom_roi_srv::srv::ROI_Response::_x_max_type arg)
  {
    msg_.x_max = std::move(arg);
    return Init_ROI_Response_y_max(msg_);
  }

private:
  ::custom_roi_srv::srv::ROI_Response msg_;
};

class Init_ROI_Response_y_min
{
public:
  explicit Init_ROI_Response_y_min(::custom_roi_srv::srv::ROI_Response & msg)
  : msg_(msg)
  {}
  Init_ROI_Response_x_max y_min(::custom_roi_srv::srv::ROI_Response::_y_min_type arg)
  {
    msg_.y_min = std::move(arg);
    return Init_ROI_Response_x_max(msg_);
  }

private:
  ::custom_roi_srv::srv::ROI_Response msg_;
};

class Init_ROI_Response_x_min
{
public:
  Init_ROI_Response_x_min()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ROI_Response_y_min x_min(::custom_roi_srv::srv::ROI_Response::_x_min_type arg)
  {
    msg_.x_min = std::move(arg);
    return Init_ROI_Response_y_min(msg_);
  }

private:
  ::custom_roi_srv::srv::ROI_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_roi_srv::srv::ROI_Response>()
{
  return custom_roi_srv::srv::builder::Init_ROI_Response_x_min();
}

}  // namespace custom_roi_srv

#endif  // CUSTOM_ROI_SRV__SRV__DETAIL__ROI__BUILDER_HPP_
