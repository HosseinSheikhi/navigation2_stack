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
#include "nav2_gradient_costmap_plugin/gradient_layer.hpp"

#include "nav2_costmap_2d/costmap_math.hpp"
#include "nav2_costmap_2d/footprint.hpp"
#include "nav2_costmap_2d/array_parser.hpp"
#include "rclcpp/parameter_events_filter.hpp"
#include "string"
#include <chrono>
using namespace std::chrono;
using namespace std::chrono_literals;

using nav2_costmap_2d::LETHAL_OBSTACLE;
using nav2_costmap_2d::INSCRIBED_INFLATED_OBSTACLE;
using nav2_costmap_2d::NO_INFORMATION;
using nav2_costmap_2d::FREE_SPACE;

namespace nav2_ceiling_perception_plugin
{

GradientLayer::GradientLayer()
{
}

// This method is called at the end of plugin initialization.
// It contains ROS parameter(s) declaration and initialization
// of need_recalculation_ variable.
void
GradientLayer::onInitialize()
{
  RCLCPP_INFO(node_->get_logger(), "GradientLayer: initialized");

  declareParameter("enabled", rclcpp::ParameterValue(true));

  getParameters();
  matchSize();

  ceiling_map_sub_ = node_->create_subscription<nav_msgs::msg::OccupancyGrid>("/ceiling_perception/map", rclcpp::SystemDefaultsQoS(), std::bind(&GradientLayer::ceiling_map_callback, this, std::placeholders::_1));
  // gives service to the static layer - cause static layer is the only one that changes them costmap size
  ceiling_ROI_srv_ = node_->create_service<custom_roi_srv::srv::ROI>("get_ceiling_roi",
                                                                     std::bind(&GradientLayer::handle_ceiling_roi_service, this, std::placeholders::_1, std::placeholders::_2),
                                                                     rmw_qos_profile_default);



}

void GradientLayer::getParameters() {
  node_->get_parameter(name_ + "." + "enabled", enabled_);
}


void nav2_gradient_costmap_plugin::GradientLayer::handle_ceiling_roi_service(std::shared_ptr<custom_roi_srv::srv::ROI::Request> request,
                                std::shared_ptr<custom_roi_srv::srv::ROI::Response> response){
  RCLCPP_INFO(node_->get_logger(), "GradientLayer: ceiling roi service called");
  response->x_min = roi_min_x_;
  response->y_min = roi_min_y_;
  response->x_max = roi_max_x_;
  response->y_max = roi_max_y_;
}


// The method is called to ask the plugin: which area of costmap it needs to update.
// Inside this method window bounds are re-calculated if need_recalculation_ is true
// and updated independently on its value.
void
GradientLayer::updateBounds(
  double /*robot_x*/, double /*robot_y*/, double /*robot_yaw*/, double * min_x,
  double * min_y, double * max_x, double * max_y)
{
  // NOTE: Think we should not do any thing here, cause our layer is the latest layer and it bounds will not effect on other layers

  *min_x = std::min(roi_min_x_,*min_x);
  *min_y = std::min(roi_min_y_,*min_y);
  *max_x = std::max(roi_max_x_,*max_x);
  *max_y = std::max(roi_max_y_,*max_y);
}


// The method is called when footprint was changed.
// Here it just resets need_recalculation_ variable.
void
GradientLayer::onFootprintChanged()
{
  RCLCPP_DEBUG(rclcpp::get_logger(
      "nav2_costmap_2d"), "GradientLayer::onFootprintChanged(): num footprint points: %lu",
    layered_costmap_->getFootprint().size());
}

// The method is called when costmap recalculation is required.
// It updates the costmap within its window bounds.

void GradientLayer::ceiling_map_callback(nav_msgs::msg::OccupancyGrid::SharedPtr map){
  RCLCPP_INFO(node_->get_logger(), "map received");
  ceiling_origin_x_ = map->info.origin.position.x;
  ceiling_origin_y_ = map->info.origin.position.y;
  ceiling_size_x_ = map->info.width;
  ceiling_size_y_ = map->info.height;
  ceiling_resolution_ = map->info.resolution;
  ceiling_map_ = map->data;

  roi_min_x_ = ceiling_origin_x_;
  roi_min_y_ = ceiling_origin_y_;
  roi_max_x_ =ceiling_origin_x_ + ceiling_size_x_*ceiling_resolution_ ;
  roi_max_y_ = ceiling_origin_y_ + ceiling_size_y_*ceiling_resolution_;
}


void
GradientLayer::updateCosts(
  nav2_costmap_2d::Costmap2D & master_grid, int min_i, int min_j,
  int max_i,
  int max_j)
{
  RCLCPP_INFO(node_->get_logger(), "GradientLayer: Update cost called");

  // check if the layered_costmap is resized by static layer to cover ceiling layer
  if(!(worldToMap(roi_min_x_, roi_min_y_,map_min_x, map_min_y) && worldToMap(roi_max_x_, roi_max_y_,map_max_x,map_max_y))){
    RCLCPP_WARN(node_->get_logger(), "costmap layered is not resized yet");
    return;
  }

  if(counter==0) {
    // cause costmap_ is a union of map and ceiling, we dont have info for all the grids so init with no info
    for (unsigned int i = 0; i < ceiling_size_y_; ++i)
      for (unsigned int j = 0; j < ceiling_size_x_; ++j)
        costmap_[getIndex(j , i )] = NO_INFORMATION;
    counter++;
  }

  unsigned int biased_x, biased_y;
  worldToMap(ceiling_origin_x_, ceiling_origin_y_, biased_x, biased_y);
  unsigned int biased_index = master_grid.getIndex(biased_x, biased_y);
  unsigned int index =0;
  if(!ceiling_map_.empty()) { //means no map received
    RCLCPP_INFO(node_->get_logger(), "GradientLayer: update with new one");
    for (unsigned int i = 0; i < ceiling_size_y_; ++i)
      for (unsigned int j = 0; j < ceiling_size_x_; ++j) { // its crucial to iterate in a row major
        if (static_cast<int8_t>(ceiling_map_[index]) == 0)
          costmap_[getIndex(j+map_min_x, i+map_min_y)] = FREE_SPACE;
        else if (static_cast<int8_t>(ceiling_map_[index]) == 100)
          costmap_[getIndex(j+map_min_x, i+map_min_y)] = LETHAL_OBSTACLE;
        index++;
      }
  }

  updateWithOverwrite(master_grid, static_cast<int>(map_min_x), static_cast<int>(map_min_y), static_cast<int>(map_max_x), static_cast<int>(map_max_y));

  RCLCPP_INFO(node_->get_logger(), "GradientLayer: Update cost end");
}

}  // namespace nav2_ceiling_perception_plugin

// This is the macro allowing a nav2_ceiling_perception_plugin::GradientLayer class
// to be registered in order to be dynamically loadable of base type nav2_costmap_2d::Layer.
// Usually places in the end of cpp-file where the loadable class written.
#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(nav2_gradient_costmap_plugin::GradientLayer, nav2_costmap_2d::Layer)
