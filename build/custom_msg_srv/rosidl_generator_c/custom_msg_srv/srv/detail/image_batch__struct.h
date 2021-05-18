// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_msg_srv:srv/ImageBatch.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__STRUCT_H_
#define CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ImageBatch in the package custom_msg_srv.
typedef struct custom_msg_srv__srv__ImageBatch_Request
{
  int64_t overhead_cameras_num;
} custom_msg_srv__srv__ImageBatch_Request;

// Struct for a sequence of custom_msg_srv__srv__ImageBatch_Request.
typedef struct custom_msg_srv__srv__ImageBatch_Request__Sequence
{
  custom_msg_srv__srv__ImageBatch_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_srv__srv__ImageBatch_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in srv/ImageBatch in the package custom_msg_srv.
typedef struct custom_msg_srv__srv__ImageBatch_Response
{
  sensor_msgs__msg__Image image[3];
} custom_msg_srv__srv__ImageBatch_Response;

// Struct for a sequence of custom_msg_srv__srv__ImageBatch_Response.
typedef struct custom_msg_srv__srv__ImageBatch_Response__Sequence
{
  custom_msg_srv__srv__ImageBatch_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_msg_srv__srv__ImageBatch_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_MSG_SRV__SRV__DETAIL__IMAGE_BATCH__STRUCT_H_
