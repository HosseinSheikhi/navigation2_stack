# generated from ament_cmake_export_dependencies/cmake/ament_cmake_export_dependencies-extras.cmake.in

set(_exported_dependencies "ceiling_perception;rclcpp;nav2_costmap_2d;pluginlib;sensor_msgs;geometry_msgs;std_msgs;custom_roi_srv;OpenCV;cv_bridge")

find_package(ament_cmake_libraries QUIET REQUIRED)

# find_package() all dependencies
# and append their DEFINITIONS INCLUDE_DIRS, LIBRARIES, and LINK_FLAGS
# variables to ceiling_perception_DEFINITIONS, ceiling_perception_INCLUDE_DIRS,
# ceiling_perception_LIBRARIES, and ceiling_perception_LINK_FLAGS.
# Additionally collect the direct dependency names in
# ceiling_perception_DEPENDENCIES as well as the recursive dependency names
# in ceiling_perception_RECURSIVE_DEPENDENCIES.
if(NOT _exported_dependencies STREQUAL "")
  find_package(ament_cmake_core QUIET REQUIRED)
  set(ceiling_perception_DEPENDENCIES ${_exported_dependencies})
  set(ceiling_perception_RECURSIVE_DEPENDENCIES ${_exported_dependencies})
  set(_libraries)
  foreach(_dep ${_exported_dependencies})
    if(NOT ${_dep}_FOUND)
      find_package("${_dep}" QUIET REQUIRED)
    endif()
    # if a package provides modern CMake interface targets use them
    # exclusively assuming the classic CMake variables only exist for
    # backward compatibility
    set(use_modern_cmake FALSE)
    if(NOT "${${_dep}_TARGETS}" STREQUAL "")
      foreach(_target ${${_dep}_TARGETS})
        # only use actual targets
        # in case a package uses this variable for other content
        if(TARGET "${_target}")
          get_target_property(_include_dirs ${_target} INTERFACE_INCLUDE_DIRECTORIES)
          if(_include_dirs)
            list_append_unique(ceiling_perception_INCLUDE_DIRS "${_include_dirs}")
          endif()

          get_target_property(_imported_configurations ${_target} IMPORTED_CONFIGURATIONS)
          if(_imported_configurations)
            get_target_property(_imported_implib ${_target} IMPORTED_IMPLIB_${_imported_configurations})
            if(_imported_implib)
              list(APPEND _libraries "${_imported_implib}")
            else()
              get_target_property(_imported_location ${_target} IMPORTED_LOCATION_${_imported_configurations})
              if(_imported_location)
                list(APPEND _libraries "${_imported_location}")
              endif()
            endif()
          endif()

          get_target_property(_link_libraries ${_target} INTERFACE_LINK_LIBRARIES)
          if(_link_libraries)
            list(APPEND _libraries "${_link_libraries}")
          endif()
          set(use_modern_cmake TRUE)
        endif()
      endforeach()
    endif()
    if(NOT use_modern_cmake)
      if(${_dep}_DEFINITIONS)
        list_append_unique(ceiling_perception_DEFINITIONS "${${_dep}_DEFINITIONS}")
      endif()
      if(${_dep}_INCLUDE_DIRS)
        list_append_unique(ceiling_perception_INCLUDE_DIRS "${${_dep}_INCLUDE_DIRS}")
      endif()
      if(${_dep}_LIBRARIES)
        list(APPEND _libraries "${${_dep}_LIBRARIES}")
      endif()
      if(${_dep}_LINK_FLAGS)
        list_append_unique(ceiling_perception_LINK_FLAGS "${${_dep}_LINK_FLAGS}")
      endif()
      if(${_dep}_RECURSIVE_DEPENDENCIES)
        list_append_unique(ceiling_perception_RECURSIVE_DEPENDENCIES "${${_dep}_RECURSIVE_DEPENDENCIES}")
      endif()
    endif()
    if(_libraries)
      ament_libraries_deduplicate(_libraries "${_libraries}")
      list(APPEND ceiling_perception_LIBRARIES "${_libraries}")
    endif()
  endforeach()
endif()
