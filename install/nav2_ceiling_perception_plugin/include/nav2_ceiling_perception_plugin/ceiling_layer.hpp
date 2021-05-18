/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, 2013, Willow Garage, Inc.
 *  Copyright (c) 2020, Samsung R&D Institute Russia
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * Author: Eitan Marder-Eppstein
 *         David V. Lu!!
 *         Alexey Merzlyakov
 *
 * Reference tutorial:
 * https://navigation.ros.org/tutorials/docs/writing_new_costmap2d_plugin.html
 *********************************************************************/
#ifndef CEILING_LAYER_HPP_
#define CEILING_LAYER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "nav2_costmap_2d/layer.hpp"
#include "nav2_costmap_2d/layered_costmap.hpp"
#include "nav2_costmap_2d/costmap_layer.hpp"
#include "opencv4/opencv2/highgui.hpp"
#include "opencv4/opencv2/opencv.hpp"
#include "algorithm"
#include "std_msgs/msg/string.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "custom_roi_srv/srv/roi.hpp"
#include "cv_bridge/cv_bridge.h"
#include "memory.h"
#include <algorithm>

namespace nav2_ceiling_perception_plugin
{

class CeilingLayer : public nav2_costmap_2d::CostmapLayer
{
public:
  CeilingLayer();

  virtual void onInitialize();
  virtual void updateBounds(
    double robot_x, double robot_y, double robot_yaw, double * min_x,
    double * min_y,
    double * max_x,
    double * max_y);
  virtual void updateCosts(
    nav2_costmap_2d::Costmap2D & master_grid,
    int min_i, int min_j, int max_i, int max_j);

  virtual void reset()
  {
    return;
  }

  virtual void onFootprintChanged();
  virtual bool isClearable() {return false;}

private:

  double roi_min_x_{0}, roi_min_y_{0}, roi_max_x_{0}, roi_max_y_{0}; ///< ceiling_perception map ROI
  unsigned int ceiling_size_x_, ceiling_size_y_; ///< desired size of x and y in meter based on ceiling_perception map coverage
  double ceiling_origin_x_, ceiling_origin_y_; ///< (x,y) origin of ceiling_perception map
  double ceiling_resolution_; ///< resolution of ceiling_perception map, must be as same as SLAM's map in current implementation

  rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr ceiling_map_sub_; ///< subscribe to ceiling perception map
  void ceiling_map_callback(nav_msgs::msg::OccupancyGrid::SharedPtr map);///< callback for ceiling_perception map
  std::vector<signed char> ceiling_map_; ///< keeps a copy of ceiling_perception map


  rclcpp::Service<custom_roi_srv::srv::ROI>::SharedPtr ceiling_ROI_srv_; ///< gives service to static_layer to share the desired changes (costmap's size, origin, etc.)
  void handle_ceiling_roi_service(std::shared_ptr<custom_roi_srv::srv::ROI::Request> request,
                                  std::shared_ptr<custom_roi_srv::srv::ROI::Response> response);


  unsigned int counter = 0; ///< a temporary variable

  //parameters
  void getParameters(); ///< defines and reads parameters

};

}  // namespace nav2_ceiling_perception_plugin

#endif  // CEILING_LAYER_HPP_
