// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from custom_msg_srv:srv/ImageBatch.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "custom_msg_srv/srv/detail/image_batch__rosidl_typesupport_introspection_c.h"
#include "custom_msg_srv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "custom_msg_srv/srv/detail/image_batch__functions.h"
#include "custom_msg_srv/srv/detail/image_batch__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg_srv__srv__ImageBatch_Request__init(message_memory);
}

void ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_fini_function(void * message_memory)
{
  custom_msg_srv__srv__ImageBatch_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_message_member_array[1] = {
  {
    "overhead_cameras_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(custom_msg_srv__srv__ImageBatch_Request, overhead_cameras_num),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_message_members = {
  "custom_msg_srv__srv",  // message namespace
  "ImageBatch_Request",  // message name
  1,  // number of fields
  sizeof(custom_msg_srv__srv__ImageBatch_Request),
  ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_message_member_array,  // message members
  ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_message_type_support_handle = {
  0,
  &ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_srv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_srv, srv, ImageBatch_Request)() {
  if (!ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_message_type_support_handle.typesupport_identifier) {
    ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ImageBatch_Request__rosidl_typesupport_introspection_c__ImageBatch_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "custom_msg_srv/srv/detail/image_batch__rosidl_typesupport_introspection_c.h"
// already included above
// #include "custom_msg_srv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "custom_msg_srv/srv/detail/image_batch__functions.h"
// already included above
// #include "custom_msg_srv/srv/detail/image_batch__struct.h"


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  custom_msg_srv__srv__ImageBatch_Response__init(message_memory);
}

void ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_fini_function(void * message_memory)
{
  custom_msg_srv__srv__ImageBatch_Response__fini(message_memory);
}

size_t ImageBatch_Response__rosidl_typesupport_introspection_c__size_function__Image__image(
  const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * ImageBatch_Response__rosidl_typesupport_introspection_c__get_const_function__Image__image(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__Image ** member =
    (const sensor_msgs__msg__Image **)(untyped_member);
  return &(*member)[index];
}

void * ImageBatch_Response__rosidl_typesupport_introspection_c__get_function__Image__image(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__Image ** member =
    (sensor_msgs__msg__Image **)(untyped_member);
  return &(*member)[index];
}

static rosidl_typesupport_introspection_c__MessageMember ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_member_array[1] = {
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(custom_msg_srv__srv__ImageBatch_Response, image),  // bytes offset in struct
    NULL,  // default value
    ImageBatch_Response__rosidl_typesupport_introspection_c__size_function__Image__image,  // size() function pointer
    ImageBatch_Response__rosidl_typesupport_introspection_c__get_const_function__Image__image,  // get_const(index) function pointer
    ImageBatch_Response__rosidl_typesupport_introspection_c__get_function__Image__image,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_members = {
  "custom_msg_srv__srv",  // message namespace
  "ImageBatch_Response",  // message name
  1,  // number of fields
  sizeof(custom_msg_srv__srv__ImageBatch_Response),
  ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_member_array,  // message members
  ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_type_support_handle = {
  0,
  &ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_srv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_srv, srv, ImageBatch_Response)() {
  ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_type_support_handle.typesupport_identifier) {
    ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ImageBatch_Response__rosidl_typesupport_introspection_c__ImageBatch_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_msg_srv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "custom_msg_srv/srv/detail/image_batch__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_service_members = {
  "custom_msg_srv__srv",  // service namespace
  "ImageBatch",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_Request_message_type_support_handle,
  NULL  // response message
  // custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_Response_message_type_support_handle
};

static rosidl_service_type_support_t custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_service_type_support_handle = {
  0,
  &custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_srv, srv, ImageBatch_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_srv, srv, ImageBatch_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_custom_msg_srv
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_srv, srv, ImageBatch)() {
  if (!custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_service_type_support_handle.typesupport_identifier) {
    custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_srv, srv, ImageBatch_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_msg_srv, srv, ImageBatch_Response)()->data;
  }

  return &custom_msg_srv__srv__detail__image_batch__rosidl_typesupport_introspection_c__ImageBatch_service_type_support_handle;
}
