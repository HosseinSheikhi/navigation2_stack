
#include "nav2_ceiling_perception_plugin/ceiling_layer.hpp"

#include "nav2_costmap_2d/costmap_math.hpp"
#include "nav2_costmap_2d/footprint.hpp"
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

CeilingLayer::CeilingLayer()
{
}

// This method is called at the end of plugin initialization.
// It contains ROS parameter(s) declaration and initialization
// of need_recalculation_ variable.
void CeilingLayer::onInitialize()
{
  RCLCPP_INFO(node_->get_logger(), "CeilingLayer: initialized");

  declareParameter("enabled", rclcpp::ParameterValue(true));

  getParameters();
  matchSize();

  ceiling_map_sub_ = node_->create_subscription<nav_msgs::msg::OccupancyGrid>("/ceiling_perception/map", rclcpp::SystemDefaultsQoS(), std::bind(&CeilingLayer::ceiling_map_callback, this, std::placeholders::_1));
  // gives service to the static layer - cause static layer is the only one that changes them costmap size
  ceiling_ROI_srv_ = node_->create_service<custom_roi_srv::srv::ROI>("get_ceiling_roi",
                                                                     std::bind(&CeilingLayer::handle_ceiling_roi_service, this, std::placeholders::_1, std::placeholders::_2),
                                                                     rmw_qos_profile_default);
}

void CeilingLayer::getParameters() {
  node_->get_parameter(name_ + "." + "enabled", enabled_);
}


void nav2_ceiling_perception_plugin::CeilingLayer::handle_ceiling_roi_service(std::shared_ptr<custom_roi_srv::srv::ROI::Request> request,
                                std::shared_ptr<custom_roi_srv::srv::ROI::Response> response){
  RCLCPP_INFO(node_->get_logger(), "CeilingLayer: ceiling roi service called");
  response->x_min = roi_min_x_;
  response->y_min = roi_min_y_;
  response->x_max = roi_max_x_;
  response->y_max = roi_max_y_;
}


// The method is called to ask the plugin: which area of costmap it needs to update.
// Inside this method window bounds are re-calculated if need_recalculation_ is true
// and updated independently on its value.
void CeilingLayer::updateBounds(
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
CeilingLayer::onFootprintChanged()
{
  RCLCPP_DEBUG(rclcpp::get_logger(
      "nav2_costmap_2d"), "CeilingLayer::onFootprintChanged(): num footprint points: %lu",
    layered_costmap_->getFootprint().size());
}

// The method is called when costmap recalculation is required.
// It updates the costmap within its window bounds.

void CeilingLayer::ceiling_map_callback(nav_msgs::msg::OccupancyGrid::SharedPtr map){
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


void CeilingLayer::updateCosts(
  nav2_costmap_2d::Costmap2D & master_grid, int min_i, int min_j,
  int max_i,
  int max_j)
{

  RCLCPP_INFO(node_->get_logger(), "CeilingLayer: Update cost called");
  if(ceiling_map_.empty()) //means no map received
    return;
  unsigned int map_min_x{0}, map_min_y{0};
  unsigned int map_max_x{0}, map_max_y{0};
  // check if the layered_costmap is resized by static layer to cover ceiling layer
  if(!(worldToMap(roi_min_x_, roi_min_y_,map_min_x, map_min_y) && worldToMap(roi_max_x_, roi_max_y_,map_max_x,map_max_y))){
    RCLCPP_WARN(node_->get_logger(), "CeilingLayer: costmap layered is not resized yet");
    return;
  }

  if(counter==0) {
    // cause costmap_ is a union of map and ceiling, we dont have info for all the grids so init with no info
    for (unsigned int i = 0; i < ceiling_size_y_; ++i)
      for (unsigned int j = 0; j < ceiling_size_x_; ++j)
        costmap_[getIndex(j , i )] = NO_INFORMATION;
    counter++;
  }
  unsigned char * master_costmap_ = master_grid.getCharMap();
  unsigned int index =0;

  RCLCPP_INFO(node_->get_logger(), "CeilingLayer: update with new one");
  for (unsigned int i = 0; i < ceiling_size_y_; ++i)
    for (unsigned int j = 0; j < ceiling_size_x_; ++j) { // its crucial to iterate in a row major
      costmap_[getIndex(j+map_min_x, i+map_min_y)] = NO_INFORMATION;
      if (static_cast<int8_t>(ceiling_map_[index]) == 0 && master_costmap_[getIndex(j+map_min_x, i+map_min_y)]==NO_INFORMATION)
        costmap_[getIndex(j+map_min_x, i+map_min_y)] = FREE_SPACE;
      else if (static_cast<int8_t>(ceiling_map_[index]) == 100 && master_costmap_[getIndex(j+map_min_x, i+map_min_y)]==NO_INFORMATION)
        costmap_[getIndex(j+map_min_x, i+map_min_y)] = LETHAL_OBSTACLE;
      index++;
    }


  updateWithMax(master_grid, static_cast<int>(map_min_x), static_cast<int>(map_min_y), static_cast<int>(map_max_x), static_cast<int>(map_max_y));

  RCLCPP_INFO(node_->get_logger(), "CeilingLayer: Update cost end");
}

}  // namespace nav2_ceiling_perception_plugin

// This is the macro allowing a nav2_ceiling_perception_plugin::CeilingLayer class
// to be registered in order to be dynamically loadable of base type nav2_costmap_2d::Layer.
// Usually places in the end of cpp-file where the loadable class written.
#include "pluginlib/class_list_macros.hpp"
PLUGINLIB_EXPORT_CLASS(nav2_ceiling_perception_plugin::CeilingLayer, nav2_costmap_2d::Layer)
