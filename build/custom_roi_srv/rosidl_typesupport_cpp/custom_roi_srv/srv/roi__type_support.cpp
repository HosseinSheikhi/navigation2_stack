// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "custom_roi_srv/srv/detail/roi__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace custom_roi_srv
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ROI_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ROI_Request_type_support_ids_t;

static const _ROI_Request_type_support_ids_t _ROI_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_roi_srv, srv, ROI_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_roi_srv, srv, ROI_Request)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ROI_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_roi_srv

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_roi_srv::srv::ROI_Request>()
{
  return &::custom_roi_srv::srv::rosidl_typesupport_cpp::ROI_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_roi_srv, srv, ROI_Request)() {
  return get_message_type_support_handle<custom_roi_srv::srv::ROI_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_roi_srv
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ROI_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ROI_Response_type_support_ids_t;

static const _ROI_Response_type_support_ids_t _ROI_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_roi_srv, srv, ROI_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_roi_srv, srv, ROI_Response)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ROI_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_roi_srv

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<custom_roi_srv::srv::ROI_Response>()
{
  return &::custom_roi_srv::srv::rosidl_typesupport_cpp::ROI_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, custom_roi_srv, srv, ROI_Response)() {
  return get_message_type_support_handle<custom_roi_srv::srv::ROI_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace custom_roi_srv
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _ROI_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _ROI_type_support_ids_t;

static const _ROI_type_support_ids_t _ROI_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
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
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, custom_roi_srv, srv, ROI)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, custom_roi_srv, srv, ROI)),
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
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_ROI_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace custom_roi_srv

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<custom_roi_srv::srv::ROI>()
{
  return &::custom_roi_srv::srv::rosidl_typesupport_cpp::ROI_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
