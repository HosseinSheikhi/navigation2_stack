// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from custom_msg_srv:srv/ImageBatch.idl
// generated code does not contain a copyright notice
#include "custom_msg_srv/srv/detail/image_batch__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool
custom_msg_srv__srv__ImageBatch_Request__init(custom_msg_srv__srv__ImageBatch_Request * msg)
{
  if (!msg) {
    return false;
  }
  // overhead_cameras_num
  return true;
}

void
custom_msg_srv__srv__ImageBatch_Request__fini(custom_msg_srv__srv__ImageBatch_Request * msg)
{
  if (!msg) {
    return;
  }
  // overhead_cameras_num
}

custom_msg_srv__srv__ImageBatch_Request *
custom_msg_srv__srv__ImageBatch_Request__create()
{
  custom_msg_srv__srv__ImageBatch_Request * msg = (custom_msg_srv__srv__ImageBatch_Request *)malloc(sizeof(custom_msg_srv__srv__ImageBatch_Request));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msg_srv__srv__ImageBatch_Request));
  bool success = custom_msg_srv__srv__ImageBatch_Request__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
custom_msg_srv__srv__ImageBatch_Request__destroy(custom_msg_srv__srv__ImageBatch_Request * msg)
{
  if (msg) {
    custom_msg_srv__srv__ImageBatch_Request__fini(msg);
  }
  free(msg);
}


bool
custom_msg_srv__srv__ImageBatch_Request__Sequence__init(custom_msg_srv__srv__ImageBatch_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  custom_msg_srv__srv__ImageBatch_Request * data = NULL;
  if (size) {
    data = (custom_msg_srv__srv__ImageBatch_Request *)calloc(size, sizeof(custom_msg_srv__srv__ImageBatch_Request));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msg_srv__srv__ImageBatch_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msg_srv__srv__ImageBatch_Request__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msg_srv__srv__ImageBatch_Request__Sequence__fini(custom_msg_srv__srv__ImageBatch_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msg_srv__srv__ImageBatch_Request__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msg_srv__srv__ImageBatch_Request__Sequence *
custom_msg_srv__srv__ImageBatch_Request__Sequence__create(size_t size)
{
  custom_msg_srv__srv__ImageBatch_Request__Sequence * array = (custom_msg_srv__srv__ImageBatch_Request__Sequence *)malloc(sizeof(custom_msg_srv__srv__ImageBatch_Request__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = custom_msg_srv__srv__ImageBatch_Request__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
custom_msg_srv__srv__ImageBatch_Request__Sequence__destroy(custom_msg_srv__srv__ImageBatch_Request__Sequence * array)
{
  if (array) {
    custom_msg_srv__srv__ImageBatch_Request__Sequence__fini(array);
  }
  free(array);
}


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
custom_msg_srv__srv__ImageBatch_Response__init(custom_msg_srv__srv__ImageBatch_Response * msg)
{
  if (!msg) {
    return false;
  }
  // image
  for (size_t i = 0; i < 3; ++i) {
    if (!sensor_msgs__msg__Image__init(&msg->image[i])) {
      custom_msg_srv__srv__ImageBatch_Response__fini(msg);
      return false;
    }
  }
  return true;
}

void
custom_msg_srv__srv__ImageBatch_Response__fini(custom_msg_srv__srv__ImageBatch_Response * msg)
{
  if (!msg) {
    return;
  }
  // image
  for (size_t i = 0; i < 3; ++i) {
    sensor_msgs__msg__Image__fini(&msg->image[i]);
  }
}

custom_msg_srv__srv__ImageBatch_Response *
custom_msg_srv__srv__ImageBatch_Response__create()
{
  custom_msg_srv__srv__ImageBatch_Response * msg = (custom_msg_srv__srv__ImageBatch_Response *)malloc(sizeof(custom_msg_srv__srv__ImageBatch_Response));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(custom_msg_srv__srv__ImageBatch_Response));
  bool success = custom_msg_srv__srv__ImageBatch_Response__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
custom_msg_srv__srv__ImageBatch_Response__destroy(custom_msg_srv__srv__ImageBatch_Response * msg)
{
  if (msg) {
    custom_msg_srv__srv__ImageBatch_Response__fini(msg);
  }
  free(msg);
}


bool
custom_msg_srv__srv__ImageBatch_Response__Sequence__init(custom_msg_srv__srv__ImageBatch_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  custom_msg_srv__srv__ImageBatch_Response * data = NULL;
  if (size) {
    data = (custom_msg_srv__srv__ImageBatch_Response *)calloc(size, sizeof(custom_msg_srv__srv__ImageBatch_Response));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = custom_msg_srv__srv__ImageBatch_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        custom_msg_srv__srv__ImageBatch_Response__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
custom_msg_srv__srv__ImageBatch_Response__Sequence__fini(custom_msg_srv__srv__ImageBatch_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      custom_msg_srv__srv__ImageBatch_Response__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

custom_msg_srv__srv__ImageBatch_Response__Sequence *
custom_msg_srv__srv__ImageBatch_Response__Sequence__create(size_t size)
{
  custom_msg_srv__srv__ImageBatch_Response__Sequence * array = (custom_msg_srv__srv__ImageBatch_Response__Sequence *)malloc(sizeof(custom_msg_srv__srv__ImageBatch_Response__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = custom_msg_srv__srv__ImageBatch_Response__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
custom_msg_srv__srv__ImageBatch_Response__Sequence__destroy(custom_msg_srv__srv__ImageBatch_Response__Sequence * array)
{
  if (array) {
    custom_msg_srv__srv__ImageBatch_Response__Sequence__fini(array);
  }
  free(array);
}
