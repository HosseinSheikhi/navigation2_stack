//
// Created by hossein on 2/17/21.
//

#ifndef NAV2_GRADIENT_COSTMAP_PLUGIN_NAV2_GRADIENT_COSTMAP_PLUGIN_OVERHEAD_CAMERA_H_
#define NAV2_GRADIENT_COSTMAP_PLUGIN_NAV2_GRADIENT_COSTMAP_PLUGIN_OVERHEAD_CAMERA_H_

#include "sensor_msgs/msg/image.hpp"
#include "opencv4/opencv2/opencv.hpp"
#include "opencv4/opencv2/highgui/highgui.hpp"
#include "cv_bridge/cv_bridge.h"
#include "iostream"
namespace nav2_gradient_costmap_plugin { namespace overhead_camera {
class overhead_camera {
 public:
  overhead_camera(std::string name, double pose_x, double pose_y, double pose_z);
  overhead_camera(std::string name, double pose_x, double pose_y, double pose_z, unsigned int image_height, unsigned int image_width);
  overhead_camera(std::string name, double pose_x, double pose_y, double pose_z, unsigned int image_height, unsigned int image_width,
                  double focal_x, double focal_y, double x_0, double y_0);

  inline bool isUpdate(){ return update_;}
  inline void setUpdate(bool update) {update_=update;}
  bool pixelToWorld( unsigned int x_pixel, unsigned int y_pixel, double &x_world, double &y_world);
  bool worldToPixel(double x_world, double y_world, unsigned int &x_pixel, unsigned int &y_pixel);
  void image_cb(sensor_msgs::msg::Image::SharedPtr image);
  bool isGridFree(std::vector<std::vector<bool>> & isFree);
  void worldFOV (double &min_x, double &min_y, double &max_x, double &max_y);
  inline bool coverWorld(double wx, double wy){
    if(world_x_min_ < wx && world_y_min_ < wy && world_x_max_ > wx && world_y_max_ > wy)
      return true;
    else
      return false;
  }

  private:
  std::string name_;
  unsigned int image_height_, image_width_;
  double pose_x_, pose_y_, pose_z_;
  double focal_x_, focal_y_, x_0_, y_0_;
  double world_x_min_, world_y_min_, world_x_max_, world_y_max_;
  cv::Mat segmented_image_;
  bool update_{false};
};

} }
#endif //NAV2_GRADIENT_COSTMAP_PLUGIN_NAV2_GRADIENT_COSTMAP_PLUGIN_OVERHEAD_CAMERA_H_
