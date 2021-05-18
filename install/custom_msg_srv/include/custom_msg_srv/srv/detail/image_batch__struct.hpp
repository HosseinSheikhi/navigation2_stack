// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_msg_srv:srv/ImageBatch.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__STRUCT_HPP_
#define CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__custom_msg_srv__srv__ImageBatch_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_msg_srv__srv__ImageBatch_Request __declspec(deprecated)
#endif

namespace custom_msg_srv
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ImageBatch_Request_
{
  using Type = ImageBatch_Request_<ContainerAllocator>;

  explicit ImageBatch_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->overhead_cameras_num = 0ll;
    }
  }

  explicit ImageBatch_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->overhead_cameras_num = 0ll;
    }
  }

  // field types and members
  using _overhead_cameras_num_type =
    int64_t;
  _overhead_cameras_num_type overhead_cameras_num;

  // setters for named parameter idiom
  Type & set__overhead_cameras_num(
    const int64_t & _arg)
  {
    this->overhead_cameras_num = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msg_srv__srv__ImageBatch_Request
    std::shared_ptr<custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msg_srv__srv__ImageBatch_Request
    std::shared_ptr<custom_msg_srv::srv::ImageBatch_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageBatch_Request_ & other) const
  {
    if (this->overhead_cameras_num != other.overhead_cameras_num) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageBatch_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageBatch_Request_

// alias to use template instance with default allocator
using ImageBatch_Request =
  custom_msg_srv::srv::ImageBatch_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_msg_srv


// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__custom_msg_srv__srv__ImageBatch_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_msg_srv__srv__ImageBatch_Response __declspec(deprecated)
#endif

namespace custom_msg_srv
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ImageBatch_Response_
{
  using Type = ImageBatch_Response_<ContainerAllocator>;

  explicit ImageBatch_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->image.fill(sensor_msgs::msg::Image_<ContainerAllocator>{_init});
    }
  }

  explicit ImageBatch_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->image.fill(sensor_msgs::msg::Image_<ContainerAllocator>{_alloc, _init});
    }
  }

  // field types and members
  using _image_type =
    std::array<sensor_msgs::msg::Image_<ContainerAllocator>, 3>;
  _image_type image;

  // setters for named parameter idiom
  Type & set__image(
    const std::array<sensor_msgs::msg::Image_<ContainerAllocator>, 3> & _arg)
  {
    this->image = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_msg_srv__srv__ImageBatch_Response
    std::shared_ptr<custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_msg_srv__srv__ImageBatch_Response
    std::shared_ptr<custom_msg_srv::srv::ImageBatch_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ImageBatch_Response_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    return true;
  }
  bool operator!=(const ImageBatch_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ImageBatch_Response_

// alias to use template instance with default allocator
using ImageBatch_Response =
  custom_msg_srv::srv::ImageBatch_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_msg_srv

namespace custom_msg_srv
{

namespace srv
{

struct ImageBatch
{
  using Request = custom_msg_srv::srv::ImageBatch_Request;
  using Response = custom_msg_srv::srv::ImageBatch_Response;
};

}  // namespace srv

}  // namespace custom_msg_srv

#endif  // CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__STRUCT_HPP_
