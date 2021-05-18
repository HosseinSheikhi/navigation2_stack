// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "custom_roi_srv/msg/rosidl_typesupport_c__visibility_control.h"
#include "custom_roi_srv/srv/detail/roi__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace custom_roi_srv
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ROI_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ROI_Request_type_support_ids_t;

static const _ROI_Request_type_support_ids_t _ROI_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ROI_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ROI_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ROI_Request_type_support_symbol_names_t _ROI_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_roi_srv, srv, ROI_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI_Request)),
  }
};

typedef struct _ROI_Request_type_support_data_t
{
  void * data[2];
} _ROI_Request_type_support_data_t;

static _ROI_Request_type_support_data_t _ROI_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ROI_Request_message_typesupport_map = {
  2,
  "custom_roi_srv",
  &_ROI_Request_message_typesupport_ids.typesupport_identifier[0],
  &_ROI_Request_message_typesupport_symbol_names.symbol_name[0],
  &_ROI_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ROI_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ROI_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_roi_srv

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_custom_roi_srv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_roi_srv, srv, ROI_Request)() {
  return &::custom_roi_srv::srv::rosidl_typesupport_c::ROI_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_roi_srv/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_roi_srv
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ROI_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ROI_Response_type_support_ids_t;

static const _ROI_Response_type_support_ids_t _ROI_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ROI_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ROI_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ROI_Response_type_support_symbol_names_t _ROI_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_roi_srv, srv, ROI_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI_Response)),
  }
};

typedef struct _ROI_Response_type_support_data_t
{
  void * data[2];
} _ROI_Response_type_support_data_t;

static _ROI_Response_type_support_data_t _ROI_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ROI_Response_message_typesupport_map = {
  2,
  "custom_roi_srv",
  &_ROI_Response_message_typesupport_ids.typesupport_identifier[0],
  &_ROI_Response_message_typesupport_symbol_names.symbol_name[0],
  &_ROI_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t ROI_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ROI_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_roi_srv

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_custom_roi_srv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, custom_roi_srv, srv, ROI_Response)() {
  return &::custom_roi_srv::srv::rosidl_typesupport_c::ROI_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_roi_srv/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_roi_srv
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _ROI_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ROI_type_support_ids_t;

static const _ROI_type_support_ids_t _ROI_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _ROI_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _ROI_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _ROI_type_support_symbol_names_t _ROI_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, custom_roi_srv, srv, ROI)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, custom_roi_srv, srv, ROI)),
  }
};

typedef struct _ROI_type_support_data_t
{
  void * data[2];
} _ROI_type_support_data_t;

static _ROI_type_support_data_t _ROI_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _ROI_service_typesupport_map = {
  2,
  "custom_roi_srv",
  &_ROI_service_typesupport_ids.typesupport_identifier[0],
  &_ROI_service_typesupport_symbol_names.symbol_name[0],
  &_ROI_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t ROI_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ROI_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace custom_roi_srv

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_custom_roi_srv
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, custom_roi_srv, srv, ROI)() {
  return &::custom_roi_srv::srv::rosidl_typesupport_c::ROI_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
