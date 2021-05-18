// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_msg_srv:srv/ImageBatch.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__BUILDER_HPP_
#define CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__BUILDER_HPP_

#include "custom_msg_srv/srv/detail/image_batch__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace custom_msg_srv
{

namespace srv
{

namespace builder
{

class Init_ImageBatch_Request_overhead_cameras_num
{
public:
  Init_ImageBatch_Request_overhead_cameras_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msg_srv::srv::ImageBatch_Request overhead_cameras_num(::custom_msg_srv::srv::ImageBatch_Request::_overhead_cameras_num_type arg)
  {
    msg_.overhead_cameras_num = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_srv::srv::ImageBatch_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_srv::srv::ImageBatch_Request>()
{
  return custom_msg_srv::srv::builder::Init_ImageBatch_Request_overhead_cameras_num();
}

}  // namespace custom_msg_srv


namespace custom_msg_srv
{

namespace srv
{

namespace builder
{

class Init_ImageBatch_Response_image
{
public:
  Init_ImageBatch_Response_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_msg_srv::srv::ImageBatch_Response image(::custom_msg_srv::srv::ImageBatch_Response::_image_type arg)
  {
    msg_.image = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_msg_srv::srv::ImageBatch_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_msg_srv::srv::ImageBatch_Response>()
{
  return custom_msg_srv::srv::builder::Init_ImageBatch_Response_image();
}

}  // namespace custom_msg_srv

#endif  // CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__BUILDER_HPP_
