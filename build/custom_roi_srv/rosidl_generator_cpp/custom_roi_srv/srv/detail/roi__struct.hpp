// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_ROI_SRV__SRV__DETAIL__ROI__STRUCT_HPP_
#define CUSTOM_ROI_SRV__SRV__DETAIL__ROI__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__custom_roi_srv__srv__ROI_Request __attribute__((deprecated))
#else
# define DEPRECATED__custom_roi_srv__srv__ROI_Request __declspec(deprecated)
#endif

namespace custom_roi_srv
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ROI_Request_
{
  using Type = ROI_Request_<ContainerAllocator>;

  explicit ROI_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ROI_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    custom_roi_srv::srv::ROI_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_roi_srv::srv::ROI_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_roi_srv::srv::ROI_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_roi_srv::srv::ROI_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_roi_srv::srv::ROI_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_roi_srv::srv::ROI_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_roi_srv::srv::ROI_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_roi_srv::srv::ROI_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_roi_srv::srv::ROI_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_roi_srv::srv::ROI_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_roi_srv__srv__ROI_Request
    std::shared_ptr<custom_roi_srv::srv::ROI_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_roi_srv__srv__ROI_Request
    std::shared_ptr<custom_roi_srv::srv::ROI_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ROI_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ROI_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ROI_Request_

// alias to use template instance with default allocator
using ROI_Request =
  custom_roi_srv::srv::ROI_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_roi_srv


#ifndef _WIN32
# define DEPRECATED__custom_roi_srv__srv__ROI_Response __attribute__((deprecated))
#else
# define DEPRECATED__custom_roi_srv__srv__ROI_Response __declspec(deprecated)
#endif

namespace custom_roi_srv
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ROI_Response_
{
  using Type = ROI_Response_<ContainerAllocator>;

  explicit ROI_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_min = 0.0f;
      this->y_min = 0.0f;
      this->x_max = 0.0f;
      this->y_max = 0.0f;
    }
  }

  explicit ROI_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x_min = 0.0f;
      this->y_min = 0.0f;
      this->x_max = 0.0f;
      this->y_max = 0.0f;
    }
  }

  // field types and members
  using _x_min_type =
    float;
  _x_min_type x_min;
  using _y_min_type =
    float;
  _y_min_type y_min;
  using _x_max_type =
    float;
  _x_max_type x_max;
  using _y_max_type =
    float;
  _y_max_type y_max;

  // setters for named parameter idiom
  Type & set__x_min(
    const float & _arg)
  {
    this->x_min = _arg;
    return *this;
  }
  Type & set__y_min(
    const float & _arg)
  {
    this->y_min = _arg;
    return *this;
  }
  Type & set__x_max(
    const float & _arg)
  {
    this->x_max = _arg;
    return *this;
  }
  Type & set__y_max(
    const float & _arg)
  {
    this->y_max = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    custom_roi_srv::srv::ROI_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const custom_roi_srv::srv::ROI_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<custom_roi_srv::srv::ROI_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<custom_roi_srv::srv::ROI_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      custom_roi_srv::srv::ROI_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<custom_roi_srv::srv::ROI_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      custom_roi_srv::srv::ROI_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<custom_roi_srv::srv::ROI_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<custom_roi_srv::srv::ROI_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<custom_roi_srv::srv::ROI_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__custom_roi_srv__srv__ROI_Response
    std::shared_ptr<custom_roi_srv::srv::ROI_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__custom_roi_srv__srv__ROI_Response
    std::shared_ptr<custom_roi_srv::srv::ROI_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ROI_Response_ & other) const
  {
    if (this->x_min != other.x_min) {
      return false;
    }
    if (this->y_min != other.y_min) {
      return false;
    }
    if (this->x_max != other.x_max) {
      return false;
    }
    if (this->y_max != other.y_max) {
      return false;
    }
    return true;
  }
  bool operator!=(const ROI_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ROI_Response_

// alias to use template instance with default allocator
using ROI_Response =
  custom_roi_srv::srv::ROI_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace custom_roi_srv

namespace custom_roi_srv
{

namespace srv
{

struct ROI
{
  using Request = custom_roi_srv::srv::ROI_Request;
  using Response = custom_roi_srv::srv::ROI_Response;
};

}  // namespace srv

}  // namespace custom_roi_srv

#endif  // CUSTOM_ROI_SRV__SRV__DETAIL__ROI__STRUCT_HPP_
