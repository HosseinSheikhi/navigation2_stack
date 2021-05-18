// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_roi_srv/srv/detail/roi__rosidl_typesupport_introspection_c.h"
#include "custom_roi_srv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_roi_srv/srv/detail/roi__functions.h"
#include "custom_roi_srv/srv/detail/roi__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_roi_srv__srv__ROI_Request__init(message_memory);
}

void ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_fini_function(void * message_memory)
{
  custom_roi_srv__srv__ROI_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_roi_srv__srv__ROI_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_message_members = {
  "custom_roi_srv__srv",  // message namespace
  "ROI_Request",  // message name
  1,  // number of fields
  sizeof(custom_roi_srv__srv__ROI_Request),
  ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_message_member_array,  // message members
  ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_message_type_support_handle = {
  0,
  &ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_roi_srv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI_Request)() {
  if (!ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_message_type_support_handle.typesupport_identifier) {
    ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ROI_Request__rosidl_typesupport_introspection_c__ROI_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_roi_srv/srv/detail/roi__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_roi_srv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__functions.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_roi_srv__srv__ROI_Response__init(message_memory);
}

void ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_fini_function(void * message_memory)
{
  custom_roi_srv__srv__ROI_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_message_member_array[4] = {
  {
    "x_min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_roi_srv__srv__ROI_Response, x_min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_min",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_roi_srv__srv__ROI_Response, y_min),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_roi_srv__srv__ROI_Response, x_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_max",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_roi_srv__srv__ROI_Response, y_max),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_message_members = {
  "custom_roi_srv__srv",  // message namespace
  "ROI_Response",  // message name
  4,  // number of fields
  sizeof(custom_roi_srv__srv__ROI_Response),
  ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_message_member_array,  // message members
  ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_message_type_support_handle = {
  0,
  &ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_roi_srv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI_Response)() {
  if (!ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_message_type_support_handle.typesupport_identifier) {
    ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ROI_Response__rosidl_typesupport_introspection_c__ROI_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_roi_srv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_service_members = {
  "custom_roi_srv__srv",  // service namespace
  "ROI",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_Request_message_type_support_handle,
  NULL  // response message
  // custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_Response_message_type_support_handle
};

static rosidl_service_type_support_t custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_service_type_support_handle = {
  0,
  &custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_roi_srv
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI)() {
  if (!custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_service_type_support_handle.typesupport_identifier) {
    custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI_Response)()->data;
  }

  return &custom_roi_srv__srv__detail__roi__rosidl_typesupport_introspection_c__ROI_service_type_support_handle;
}
