// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from custom_roi_srv:srv/ROI.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "custom_roi_srv/srv/detail/roi__struct.h"
#include "custom_roi_srv/srv/detail/roi__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_roi_srv__srv__roi__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[36];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_roi_srv.srv._roi.ROI_Request", full_classname_dest, 35) == 0);
  }
  custom_roi_srv__srv__ROI_Request * ros_message = _ros_message;
  ros_message->structure_needs_at_least_one_member = 0;

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_roi_srv__srv__roi__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ROI_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_roi_srv.srv._roi");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ROI_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  (void)raw_ros_message;

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__struct.h"
// already included above
// #include "custom_roi_srv/srv/detail/roi__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool custom_roi_srv__srv__roi__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("custom_roi_srv.srv._roi.ROI_Response", full_classname_dest, 36) == 0);
  }
  custom_roi_srv__srv__ROI_Response * ros_message = _ros_message;
  {  // x_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_min = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_min
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_min");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_min = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // x_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "x_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x_max = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y_max
    PyObject * field = PyObject_GetAttrString(_pymsg, "y_max");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y_max = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * custom_roi_srv__srv__roi__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of ROI_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("custom_roi_srv.srv._roi");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "ROI_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  custom_roi_srv__srv__ROI_Response * ros_message = (custom_roi_srv__srv__ROI_Response *)raw_ros_message;
  {  // x_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_min
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_min);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_min", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // x_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y_max
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y_max);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y_max", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
