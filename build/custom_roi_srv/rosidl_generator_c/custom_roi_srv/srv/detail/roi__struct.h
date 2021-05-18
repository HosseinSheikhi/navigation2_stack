// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_ROI_SRV__SRV__DETAIL__ROI__STRUCT_H_
#define CUSTOM_ROI_SRV__SRV__DETAIL__ROI__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ROI in the package custom_roi_srv.
typedef struct custom_roi_srv__srv__ROI_Request
{
  uint8_t structure_needs_at_least_one_member;
} custom_roi_srv__srv__ROI_Request;

// Struct for a sequence of custom_roi_srv__srv__ROI_Request.
typedef struct custom_roi_srv__srv__ROI_Request__Sequence
{
  custom_roi_srv__srv__ROI_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_roi_srv__srv__ROI_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ROI in the package custom_roi_srv.
typedef struct custom_roi_srv__srv__ROI_Response
{
  float x_min;
  float y_min;
  float x_max;
  float y_max;
} custom_roi_srv__srv__ROI_Response;

// Struct for a sequence of custom_roi_srv__srv__ROI_Response.
typedef struct custom_roi_srv__srv__ROI_Response__Sequence
{
  custom_roi_srv__srv__ROI_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_roi_srv__srv__ROI_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_ROI_SRV__SRV__DETAIL__ROI__STRUCT_H_
