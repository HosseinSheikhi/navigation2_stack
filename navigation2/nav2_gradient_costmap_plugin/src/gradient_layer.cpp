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
using nav2_costmap_2d::LETHAL_OBSTACLE;
using nav2_costmap_2d::INSCRIBED_INFLATED_OBSTACLE;
using nav2_costmap_2d::NO_INFORMATION;
using nav2_costmap_2d::FREE_SPACE;

namespace nav2_gradient_costmap_plugin
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
  declareParameter("enabled", rclcpp::ParameterValue(true));
  declareParameter("num_overhead_cameras", rclcpp::ParameterValue(0));
  declareParameter("overhead_topics", rclcpp::ParameterValue(overhead_topics_));
  declareParameter("camera_poses", rclcpp::ParameterValue(""));


  getParameters();
  matchSize();
  ceiling_ROI_srv_ = node_->create_service<custom_roi_srv::srv::ROI>("get_ceiling_roi",
                                                                     std::bind(&GradientLayer::handle_ceiling_roi_service, this, std::placeholders::_1, std::placeholders::_2),
                                                                     rmw_qos_profile_default);
  for(int cam_index=0; cam_index<num_overhead_cameras_;cam_index++){
  overhead_cameras_.emplace_back(std::make_shared<overhead_camera::overhead_camera>("cam "+std::to_string(cam_index+1), camera_poses_[cam_index][0], camera_poses_[cam_index][1], camera_poses_[cam_index][2]));
  camera_subs_.emplace_back(node_->create_subscription<sensor_msgs::msg::Image>(overhead_topics_[cam_index], rclcpp::SystemDefaultsQoS(), std::bind(&overhead_camera::overhead_camera::image_cb, overhead_cameras_[cam_index], std::placeholders::_1)));
  }



  calculateRoi();

}

void GradientLayer::getParameters() {

  node_->get_parameter(name_ + "." + "enabled", enabled_);
  node_->get_parameter(name_ + "." + "num_overhead_cameras", num_overhead_cameras_);
  node_->get_parameter(name_ + "." + "overhead_topics", overhead_topics_);

  if(overhead_topics_.size() != static_cast<unsigned long>(num_overhead_cameras_))
    RCLCPP_WARN(node_->get_logger(), "GradientLayer: number of overhead cameras doesn't match with overhead topics");


  std::string camera_poses_str;
  node_->get_parameter(name_ + "." + "camera_poses", camera_poses_str);
  std::string error;
  camera_poses_ = nav2_costmap_2d::parseVVF(camera_poses_str, error);
  if (!error.empty())
    RCLCPP_WARN(node_->get_logger(), "GradientLayer: error in parsing camera poses %s", error.c_str());
  if(camera_poses_.size() != static_cast<unsigned long>(num_overhead_cameras_))
    RCLCPP_WARN(node_->get_logger(), "GradientLayer: number of overhead cameras doesn't match with cameras positions");

}


void nav2_gradient_costmap_plugin::GradientLayer::handle_ceiling_roi_service(std::shared_ptr<custom_roi_srv::srv::ROI::Request> request,
                                std::shared_ptr<custom_roi_srv::srv::ROI::Response> response){
  RCLCPP_INFO(node_->get_logger(), "GradientLayer: ceiling roi service called");
  response->x_min = roi_min_x_;
  response->y_min = roi_min_y_;
  response->x_max = roi_max_x_;
  response->y_max = roi_max_y_;
}

void nav2_gradient_costmap_plugin::GradientLayer::calculateRoi() {
  RCLCPP_INFO(node_->get_logger(), "GradientLayer: calculating desired size");
  std::vector<std::vector<double>> FOVBoxes;
  double x1_min, y1_min, x1_max, y1_max;

  for(int cam_index=0; cam_index<num_overhead_cameras_;cam_index++) {
    overhead_cameras_[cam_index]->worldFOV(x1_min, y1_min, x1_max, y1_max);
    FOVBoxes.push_back(std::vector<double>{x1_min, y1_min, x1_max, y1_max});
  }

  roi_min_x_ = boxMin(FOVBoxes, 0);
  roi_min_y_ = boxMin(FOVBoxes, 1);

  roi_max_x_ = boxMax(FOVBoxes, 2);
  roi_max_y_ = boxMax(FOVBoxes, 3);
  ceiling_size_x_ = static_cast<unsigned int>(fabs(roi_max_x_ - roi_min_x_)/resolution_);
  ceiling_size_y_ = static_cast<unsigned int>(fabs(roi_max_y_ - roi_min_y_)/resolution_);
  RCLCPP_INFO(node_->get_logger(), "GradientLayer: ceiling roi service called min(%f,%f) - max(%f,%f)",roi_min_x_,roi_min_y_, roi_max_x_, roi_max_y_ );


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

void
GradientLayer::updateCosts(
  nav2_costmap_2d::Costmap2D & master_grid, int min_i, int min_j,
  int max_i,
  int max_j)
{



  unsigned char * master_costmap_ = master_grid.getCharMap();
  //RCLCPP_INFO(node_->get_logger(), "GradientLayer: Size %u X %u ", size_x_, size_y_ );
  std::lock_guard<Costmap2D::mutex_t> guard(*getMutex());

  unsigned int temp_min_x, temp_min_y;
  unsigned int temp_max_x, temp_max_y;
  if(!(worldToMap(roi_min_x_, roi_min_y_,temp_min_x, temp_min_y) && worldToMap(roi_max_x_, roi_max_y_,temp_max_x,temp_max_y))){
    RCLCPP_WARN(node_->get_logger(), "costmap layered not resized yet");
    return;
  }

  if(counter++%5!=0){
    RCLCPP_INFO(node_->get_logger(), "GradientLayer: update with old one");
    //RCLCPP_INFO(node_->get_logger(), "GradientLayer: ceiling roi min(%f,%f) - max(%f,%f)",roi_min_x_,roi_min_y_, roi_max_x_, roi_max_y_ );
    unsigned int min_x_map, min_y_map;
    worldToMap(roi_min_x_, roi_min_y_, min_x_map, min_y_map);

    unsigned int max_x_map, max_y_map;
    worldToMap(roi_max_x_, roi_max_y_, max_x_map, max_y_map);
    //RCLCPP_INFO(node_->get_logger(), "GradientLayer: new updating box (%u , %u , %u , %u)", min_x_map, min_y_map, max_x_map, max_y_map);
    updateWithOverwrite(master_grid, min_x_map, min_y_map, max_x_map, max_y_map);
    return;
  }
  RCLCPP_INFO(node_->get_logger(), "GradientLayer: update with new one");

  unsigned int index=0;
  // cause costmap_ is a union of map and ceiling, we dont have info for all the grids so init with no info
  for (unsigned int i = 0; i < ceiling_size_y_; ++i)
    for (unsigned int j = 0; j < ceiling_size_x_; ++j)
      costmap_[getIndex(j + temp_min_x, i + temp_min_y)] = NO_INFORMATION;


  for(int cam_index = 0; cam_index<num_overhead_cameras_; cam_index++) {
    if (overhead_cameras_[cam_index]->isUpdate()) {
      std::vector<std::vector<bool>> isFree;
      if(overhead_cameras_[cam_index]->isGridFree(isFree)){
      for (unsigned int x_pixel = 0; x_pixel < 640; x_pixel++) {
        for (unsigned int y_pixel = 0; y_pixel < 480; y_pixel++) {
          double x_world, y_world;
          if (overhead_cameras_[cam_index]->pixelToWorld(x_pixel, y_pixel, x_world,y_world)) {
            unsigned int x_map, y_map;
            if (worldToMap(x_world, y_world, x_map, y_map)) {
                unsigned int index = master_grid.getIndex(x_map, y_map);
                if(master_costmap_[index]==NO_INFORMATION)
                  costmap_[index] = (isFree[y_pixel][x_pixel] ? FREE_SPACE : LETHAL_OBSTACLE);
            } else {
//               RCLCPP_WARN(node_->get_logger(), "GradientLayer: worldToMap was not successful");
            }
          } else {
            RCLCPP_WARN(node_->get_logger(),
                        "GradientLayer: pixelToWorld was not successful");
          }
        }
      }
      }else{
        RCLCPP_WARN(node_->get_logger(), "GradientLayer: Mat was empty in isGreedFree function. camera number: %d", cam_index+1);
      }
    }
  }

  //RCLCPP_INFO(node_->get_logger(), "GradientLayer: ceiling roi min(%f,%f) - max(%f,%f)",roi_min_x_,roi_min_y_, roi_max_x_, roi_max_y_ );
  unsigned int min_x_map, min_y_map;
  worldToMap(roi_min_x_, roi_min_y_, min_x_map, min_y_map);

  unsigned int max_x_map, max_y_map;
  worldToMap(roi_max_x_, roi_max_y_, max_x_map, max_y_map);
  //RCLCPP_INFO(node_->get_logger(), "GradientLayer: new updating box (%u , %u , %u , %u)", min_x_map, min_y_map, max_x_map, max_y_map);
  updateWithOverwrite(master_grid, min_x_map, min_y_map, max_x_map, max_y_map);


}

}  // namespace nav2_gradient_costmap_plugin

// This is the macro allowing a nav2_gradient_costmap_plugin::GradientLayer class
// to be registered in order to be dynamically loadable of base type nav2_costmap_2d::Layer.
// Usually places in the end of cpp-file where the loadable class written.
#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(nav2_gradient_costmap_plugin::GradientLayer, nav2_costmap_2d::Layer)
