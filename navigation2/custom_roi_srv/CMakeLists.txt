cmake_minimum_required(VERSION 3.5)
project(custom_roi_srv)
set(FastRTPS_INCLUDE_DIR /opt/ros/foxy/include)
set(FastRTPS_LIBRARY_RELEASE /opt/ros/foxy/lib/libfastrtps.so)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

set (INTERFACES_LIST
        "srv/ROI.srv"
        )


rosidl_generate_interfaces(${PROJECT_NAME}
        ${INTERFACES_LIST}
        DEPENDENCIES ${DEPENDENCIES_LIST}
 )

ament_export_dependencies(rosidl_default_runtime)
ament_package()
