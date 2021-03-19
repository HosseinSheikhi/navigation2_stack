/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, 2013, Willow Garage, Inc.
 *  Copyright (c) 2015, Fetch Robotics, Inc.
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
 *********************************************************************/

#include "nav2_costmap_2d/static_layer.hpp"

#include <algorithm>
#include <memory>
#include <string>

#include "nav2_costmap_2d/costmap_math.hpp"
#include "pluginlib/class_list_macros.hpp"
#include "tf2/convert.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

PLUGINLIB_EXPORT_CLASS(nav2_costmap_2d::StaticLayer, nav2_costmap_2d::Layer)

using nav2_costmap_2d::NO_INFORMATION;
using nav2_costmap_2d::LETHAL_OBSTACLE;
using nav2_costmap_2d::FREE_SPACE;
using namespace std::chrono_literals;

namespace nav2_costmap_2d
{

StaticLayer::StaticLayer()
: map_buffer_(nullptr)
{
}

StaticLayer::~StaticLayer()
{
}

void
StaticLayer::onInitialize()
{
  global_frame_ = layered_costmap_->getGlobalFrameID();

  getParameters();

  rclcpp::QoS map_qos(10);  // initialize to default
  if (map_subscribe_transient_local_) {
    map_qos.transient_local();
    map_qos.reliable();
    map_qos.keep_last(1);
  }

  RCLCPP_INFO(
    node_->get_logger(),
    "Subscribing to the map topic (%s) with %s durability",
    map_topic_.c_str(),
    map_subscribe_transient_local_ ? "transient local" : "volatile");
  map_sub_ = node_->create_subscription<nav_msgs::msg::OccupancyGrid>(
    map_topic_, map_qos,
    std::bind(&StaticLayer::incomingMap, this, std::placeholders::_1));

  if (subscribe_to_updates_) {
    RCLCPP_INFO(node_->get_logger(), "Subscribing to updates");
    map_update_sub_ = node_->create_subscription<map_msgs::msg::OccupancyGridUpdate>(
      map_topic_ + "_updates",
      rclcpp::SystemDefaultsQoS(),
      std::bind(&StaticLayer::incomingUpdate, this, std::placeholders::_1));
  }

  //TODO if subscribe to ceiling
  ceiling_roi_client_ = node_->create_client<custom_roi_srv::srv::ROI>("get_ceiling_roi", rmw_qos_profile_default);
//  while (!ceiling_roi_client_->wait_for_service(5s)){
//    if (!rclcpp::ok()){
//      RCLCPP_ERROR(node_->get_logger(), "ROI Client interrupted while waiting for service to appear.");
//      assert(0);
//    }
//    RCLCPP_INFO(node_->get_logger(), "Waiting for ROI service to appear...");
//  }

  RCLCPP_INFO(node_->get_logger(), "ROI client created!!");
}

void
StaticLayer::activate()
{
}

void
StaticLayer::deactivate()
{
}

void
StaticLayer::reset()
{
  has_updated_data_ = true;
}

void
StaticLayer::getParameters()
{
  int temp_lethal_threshold = 0;
  double temp_tf_tol = 0.0;

  declareParameter("enabled", rclcpp::ParameterValue(true));
  declareParameter("subscribe_to_updates", rclcpp::ParameterValue(false));
  declareParameter("map_subscribe_transient_local", rclcpp::ParameterValue(true));
  declareParameter("transform_tolerance", rclcpp::ParameterValue(0.0));
  declareParameter("map_topic", rclcpp::ParameterValue(""));

  node_->get_parameter(name_ + "." + "enabled", enabled_);
  node_->get_parameter(name_ + "." + "subscribe_to_updates", subscribe_to_updates_);
  std::string private_map_topic, global_map_topic;
  node_->get_parameter(name_ + "." + "map_topic", private_map_topic);
  node_->get_parameter("map_topic", global_map_topic);
  if (!private_map_topic.empty()) {
    map_topic_ = private_map_topic;
  } else {
    map_topic_ = global_map_topic;
  }
  node_->get_parameter(
    name_ + "." + "map_subscribe_transient_local",
    map_subscribe_transient_local_);
  node_->get_parameter("track_unknown_space", track_unknown_space_);
  node_->get_parameter("use_maximum", use_maximum_);
  node_->get_parameter("lethal_cost_threshold", temp_lethal_threshold);
  node_->get_parameter("unknown_cost_value", unknown_cost_value_);
  node_->get_parameter("trinary_costmap", trinary_costmap_);
  node_->get_parameter("transform_tolerance", temp_tf_tol);

  // Enforce bounds
  lethal_threshold_ = std::max(std::min(temp_lethal_threshold, 100), 0);
  map_received_ = false;
  update_in_progress_.store(false);

  transform_tolerance_ = tf2::durationFromSec(temp_tf_tol);
}
void StaticLayer::ceiling_roi_callback(rclcpp::Client<custom_roi_srv::srv::ROI>::SharedFuture result_future){
  std::shared_ptr<custom_roi_srv::srv::ROI::Response> response = result_future.get();
  ceiling_min_x_ = response->x_min;
  ceiling_min_y_ = response->y_min;
  ceiling_max_x_ = response->x_max;
  ceiling_max_y_ = response->y_max;
  if(ceiling_min_x_!=0 || ceiling_min_y_!=0 || ceiling_max_x_!=0 || ceiling_max_y_!=0)
    ceiling_roi_received_ = true;

}

void StaticLayer::resizeCostmap(double static_map_origin_x,
                                       double static_map_origin_y,
                                       unsigned int static_map_width,
                                       unsigned int static_map_height,
                                       double static_map_resolution){

  // get ceiling layer ROI
  if(!ceiling_roi_received_) {
    auto request = std::make_shared<custom_roi_srv::srv::ROI::Request>();
    rclcpp::Client<custom_roi_srv::srv::ROI>::SharedFuture result_future =
        ceiling_roi_client_->async_send_request(
            request, std::bind(&StaticLayer::ceiling_roi_callback, this,
                               std::placeholders::_1));
  }

  double map_max_x = static_map_width*static_map_resolution + static_map_origin_x;
  double map_max_y = static_map_height*static_map_resolution + static_map_origin_y;

  // origin is min of map_origin and ceiling_origin
  // note that origin is Lower_Left point for all ceiling, map, and costmap
  double lower_left_x = std::min(static_map_origin_x, ceiling_min_x_);
  lower_left_x -= 1.0;
  double lower_left_y = std::min(static_map_origin_y, ceiling_min_y_);
  lower_left_y -= 1.0;

  double upper_right_x = std::max(map_max_x, ceiling_max_x_);
  upper_right_x += 1.0;
  double upper_right_y = std::max(map_max_y, ceiling_max_y_);
  upper_right_y += 1.0;
  unsigned int size_x = static_cast<unsigned int>(fabs(upper_right_x - lower_left_x)/static_map_resolution);
  unsigned int size_y = static_cast<unsigned int>(fabs(upper_right_y - lower_left_y)/static_map_resolution);


  // resize costmap if size, resolution or origin do not match
  Costmap2D * master = layered_costmap_->getCostmap();
  unsigned int master_size_x = master->getSizeInCellsX();
  unsigned int master_size_y = master->getSizeInCellsY();

  if(!layered_costmap_->isRolling() && (master_size_x != size_x || master_size_y != size_y || master->getOriginX() != lower_left_x || master->getOriginY() != lower_left_y )){
    // Update the size of the layered costmap to the union of master grid's size and new map (and all layers, including this one)
      layered_costmap_->resizeMap(
        size_x, size_y, static_map_resolution,
        lower_left_x,
        lower_left_y,
        false);
      RCLCPP_INFO(
        node_->get_logger(),
        "StaticLayer: Resizing costmap to origin at (%f,%f) and size %d X %d  lower_left:(%f,%f) - upper_right(%f,%f)",
          origin_x_, origin_y_, size_x_, size_y_, lower_left_x, lower_left_y, upper_right_x, upper_right_y);
  } else{
    RCLCPP_INFO(node_->get_logger(), "StaticLayer: no need to resize costmap");
  }

}



void
StaticLayer::processMap(const nav_msgs::msg::OccupancyGrid & new_map)
{
  std::lock_guard<Costmap2D::mutex_t> guard(*getMutex());
  RCLCPP_DEBUG(
      node_->get_logger(),
      "StaticLayer: Received a %d X %d map at %f m/pix", new_map.info.width,
      new_map.info.height,
      new_map.info.resolution);

  resizeCostmap(new_map.info.origin.position.x,
                       new_map.info.origin.position.y,
                       new_map.info.width,
                       new_map.info.height,
                       new_map.info.resolution);

  unsigned int size_x = new_map.info.width;
  unsigned int size_y = new_map.info.height;

  unsigned int index = 0;

  unsigned int drift_x;
  unsigned int drift_y;
  worldToMap(new_map.info.origin.position.x, new_map.info.origin.position.y, drift_x, drift_y);


  // cause costmap_ is a union of map and ceiling, we dont have info for all the grids
  for (unsigned int i = 0; i < size_y_; ++i)
    for (unsigned int j = 0; j < size_x_; ++j)
      costmap_[index++]=NO_INFORMATION;

  index = 0;
  // initialize the costmap with static data
  for (unsigned int i = 0; i < size_y; ++i) {
    for (unsigned int j = 0; j < size_x; ++j) {
        unsigned char value = new_map.data[index];
        costmap_[getIndex(j + drift_x,i+drift_y)] =interpretValue(value);
        ++index;
    }
  }


  map_frame_ = new_map.header.frame_id;

  x_ = drift_x;
  y_ = drift_y;
  width_ = new_map.info.width;
  height_ = new_map.info.height;
  has_updated_data_ = true;
  current_ = true;
}

void
StaticLayer::matchSize()
{
  // If we are using rolling costmap, the static map size is
  //   unrelated to the size of the layered costmap
  if (!layered_costmap_->isRolling()) {
    Costmap2D * master = layered_costmap_->getCostmap();
    resizeMap(
      master->getSizeInCellsX(), master->getSizeInCellsY(), master->getResolution(),
      master->getOriginX(), master->getOriginY());
  }
}

unsigned char
StaticLayer::interpretValue(unsigned char value)
{
  // check if the static value is above the unknown or lethal thresholds
  if (track_unknown_space_ && value == unknown_cost_value_) {
    return NO_INFORMATION;
  } else if (!track_unknown_space_ && value == unknown_cost_value_) {
    return FREE_SPACE;
  } else if (value >= lethal_threshold_) {
    return LETHAL_OBSTACLE;
  } else if (trinary_costmap_) {
    return FREE_SPACE;
  }

  double scale = static_cast<double>(value) / lethal_threshold_;
  return scale * LETHAL_OBSTACLE;
}

void
StaticLayer::incomingMap(const nav_msgs::msg::OccupancyGrid::SharedPtr new_map)
{
  std::lock_guard<Costmap2D::mutex_t> guard(*getMutex());
  if (!map_received_) {
    map_received_ = true;
    processMap(*new_map);
  }
  if (update_in_progress_.load()) {
    map_buffer_ = new_map;
  } else {
    processMap(*new_map);
    map_buffer_ = nullptr;
  }
}

void
StaticLayer::incomingUpdate(map_msgs::msg::OccupancyGridUpdate::ConstSharedPtr update)
{
  std::lock_guard<Costmap2D::mutex_t> guard(*getMutex());
  if (update->y < static_cast<int32_t>(y_) ||
    y_ + height_ < update->y + update->height ||
    update->x < static_cast<int32_t>(x_) ||
    x_ + width_ < update->x + update->width)
  {
    RCLCPP_WARN(
      node_->get_logger(),
      "StaticLayer: Map update ignored. Exceeds bounds of static layer.\n"
      "Static layer origin: %d, %d   bounds: %d X %d\n"
      "Update origin: %d, %d   bounds: %d X %d",
      x_, y_, width_, height_, update->x, update->y, update->width,
      update->height);
    return;
  }

  if (update->header.frame_id != map_frame_) {
    RCLCPP_WARN(
      node_->get_logger(),
      "StaticLayer: Map update ignored. Current map is in frame %s "
      "but update was in frame %s",
      map_frame_.c_str(), update->header.frame_id.c_str());
  }

  unsigned int di = 0;
  for (unsigned int y = 0; y < update->height; y++) {
    unsigned int index_base = (update->y + y) * size_x_;
    for (unsigned int x = 0; x < update->width; x++) {
      unsigned int index = index_base + x + update->x;
      costmap_[index] = interpretValue(update->data[di++]);
    }
  }

  x_ = update->x;
  y_ = update->y;
  width_ = update->width;
  height_ = update->height;
  has_updated_data_ = true;
  RCLCPP_INFO(node_->get_logger(), "StaticLayer new dim: %u  %u  %u  %u ", x_, y_, width_, height_);
}


void
StaticLayer::updateBounds(
  double /*robot_x*/, double /*robot_y*/, double /*robot_yaw*/, double * min_x,
  double * min_y,
  double * max_x,
  double * max_y)
{
  if (!map_received_) {
    return;
  }

  std::lock_guard<Costmap2D::mutex_t> guard(*getMutex());
  update_in_progress_.store(true);

  // If there is a new available map, load it.
  if (map_buffer_) {
    processMap(*map_buffer_);
    map_buffer_ = nullptr;
  }

  if (!layered_costmap_->isRolling() ) {
    if (!(has_updated_data_ || has_extra_bounds_)) {
      return;
    }
  }

  useExtraBounds(min_x, min_y, max_x, max_y);

  double wx, wy;

  mapToWorld(x_, y_, wx, wy);
  *min_x = std::min(wx, *min_x);
  *min_y = std::min(wy, *min_y);

  mapToWorld(x_ + width_, y_ + height_, wx, wy);
  *max_x = std::max(wx, *max_x);
  *max_y = std::max(wy, *max_y);
  has_updated_data_ = false;
}

void
StaticLayer::updateCosts(
  nav2_costmap_2d::Costmap2D & master_grid,
  int min_i, int min_j, int max_i, int max_j)
{
  if (!enabled_) {
    update_in_progress_.store(false);
    return;
  }
  if (!map_received_) {
    static int count = 0;
    // throttle warning down to only 1/10 message rate
    if (++count == 10) {
      RCLCPP_WARN(node_->get_logger(), "Can't update static costmap layer, no map received");
      count = 0;
    }
    update_in_progress_.store(false);
    return;
  }
  RCLCPP_INFO(node_->get_logger(), "StaticLayer: Size %u X %u ", size_x_, size_y_ );
//  RCLCPP_INFO(node_->get_logger(), "StaticLayer: Old updating box (%d , %d , %d , %d)", min_i, min_j, max_i, max_j);
  //RCLCPP_INFO(node_->get_logger(), "StaticLayer: new updating box (%u , %u , %u , %u)", x_, y_, x_+width_, y_+height_);

  if (!layered_costmap_->isRolling()) {

    // if not rolling, the layered costmap (master_grid) has same coordinates as this layer
    if (!use_maximum_) {
      updateWithTrueOverwrite(master_grid, min_i, min_j, max_i, max_j);
    } else {
      updateWithMax(master_grid,  min_i, min_j, max_i, max_j);
    }

  } else {
    // If rolling window, the master_grid is unlikely to have same coordinates as this layer
    unsigned int mx, my;
    double wx, wy;
    // Might even be in a different frame
    geometry_msgs::msg::TransformStamped transform;
    try {
      transform = tf_->lookupTransform(
        map_frame_, global_frame_, tf2::TimePointZero,
        transform_tolerance_);
    } catch (tf2::TransformException & ex) {
      RCLCPP_ERROR(node_->get_logger(), "StaticLayer: %s", ex.what());
      update_in_progress_.store(false);
      return;
    }
    // Copy map data given proper transformations
    tf2::Transform tf2_transform;
    tf2::fromMsg(transform.transform, tf2_transform);

    for (int i = min_i; i < max_i; ++i) {
      for (int j = min_j; j < max_j; ++j) {
        // Convert master_grid coordinates (i,j) into global_frame_(wx,wy) coordinates
        layered_costmap_->getCostmap()->mapToWorld(i, j, wx, wy);
        // Transform from global_frame_ to map_frame_
        tf2::Vector3 p(wx, wy, 0);
        p = tf2_transform * p;
        // Set master_grid with cell from map
        if (worldToMap(p.x(), p.y(), mx, my)) {
          if (!use_maximum_) {
            master_grid.setCost(i, j, getCost(mx, my));
          } else {
            master_grid.setCost(i, j, std::max(getCost(mx, my), master_grid.getCost(i, j)));
          }
        }
      }
    }
  }
  update_in_progress_.store(false);
}

}  // namespace nav2_costmap_2d
