//
// Created by hossein on 2/17/21.
//

#include "nav2_gradient_costmap_plugin/overhead_camera.h"

nav2_gradient_costmap_plugin::overhead_camera::overhead_camera::overhead_camera(std::string name,
                                                                                double pose_x,
                                                                                double pose_y,
                                                                                double pose_z):
                                                                                name_(name), pose_x_(pose_x), pose_y_(pose_y), pose_z_(pose_z)
{
  image_height_ = 480;
  image_width_ = 640;
  focal_x_ = focal_y_ = 381.362;
  x_0_ = 320.5;
  y_0_ = 240.5;
}

nav2_gradient_costmap_plugin::overhead_camera::overhead_camera::overhead_camera(std::string name,
                                                                                double pose_x,
                                                                                double pose_y,
                                                                                double pose_z,
                                                                                unsigned int image_height,
                                                                                unsigned int image_width):
                                                                                name_(name), pose_x_(pose_x), pose_y_(pose_y), pose_z_(pose_z),
                                                                                image_height_(image_height), image_width_(image_width)
{
  focal_x_ = focal_y_ = 381.362;
  x_0_ = 320.5;
  y_0_ = 240.5;
}
nav2_gradient_costmap_plugin::overhead_camera::overhead_camera::overhead_camera(std::string name,
                                                                                double pose_x,
                                                                                double pose_y,
                                                                                double pose_z,
                                                                                unsigned int image_height,
                                                                                unsigned int image_width,
                                                                                double focal_x,
                                                                                double focal_y,
                                                                                double x_0,
                                                                                double y_0):
                                                                                name_(name), pose_x_(pose_x), pose_y_(pose_y), pose_z_(pose_z),
                                                                                image_height_(image_height), image_width_(image_width),
                                                                                focal_x_(focal_x),
                                                                                focal_y_(focal_y),
                                                                                x_0_(x_0),
                                                                                y_0_(y_0)
{
}

bool
nav2_gradient_costmap_plugin::overhead_camera::overhead_camera::pixelToWorld(unsigned int x_pixel,
                                                                             unsigned int y_pixel,
                                                                             double &x_world,
                                                                             double &y_world)
{
  x_world = (static_cast<double>(x_pixel) - x_0_)*pose_z_/focal_x_ + pose_x_;
  y_world = -(static_cast<double>(y_pixel) - y_0_)*pose_z_/focal_y_ + pose_y_;
  if(x_world>= world_x_min_ && x_world <= world_x_max_ && y_world >= world_y_min_ && y_world <= world_y_max_)
    return true;
  else
    return false;
}

bool
nav2_gradient_costmap_plugin::overhead_camera::overhead_camera::worldToPixel(double x_world,
                                                                                  double y_world,
                                                                                  unsigned int &x_pixel,
                                                                                  unsigned int &y_pixel)
{
  x_pixel = static_cast<unsigned int>((x_world-pose_x_)*focal_x_/pose_z_+x_0_);
  y_pixel = static_cast<unsigned int>(-(y_world-pose_y_)*focal_y_/pose_z_+y_0_);
  if(x_pixel >= 0 && x_pixel <= image_width_ && y_pixel>=0 && y_pixel<=image_height_)
    return true;
  else
    return false;
}

void
nav2_gradient_costmap_plugin::overhead_camera::overhead_camera::image_cb(sensor_msgs::msg::Image::SharedPtr image) {
    cv_bridge::CvImagePtr cv_image_ptr = cv_bridge::toCvCopy(image);
    segmented_image_ = cv_image_ptr->image;
    cv::resize(segmented_image_, segmented_image_,
               cv::Size(image_width_, image_height_));
    //  cv::imshow(name_, segmented_image_);
    //  cv::waitKey(1);
    //  std::cout<<"image received"<<std::endl;
    update_ = true; // instance is update when image is being subscribed

}



bool nav2_gradient_costmap_plugin::overhead_camera::overhead_camera::isGridFree(std::vector<std::vector<bool>> & isFree){
  /*
   * This function is my killer, my lover (Leo Cohen), spent two days to find the bug is here and why!
   * First of all this function used to outputs a bool instead of a 2d-vector of bools, and I had to call it in every iteration, about 640*480 times!
   * And when it was the case, it was likely that a callback be called when we were in this function, so I used the mutex, and to prevent from overhead of calling this function I changed it to be called once for each camera
   */
  int neighbour_size = 5;
  cv::Mat temp;
  segmented_image_.copyTo(temp);
  if(temp.empty() || temp.cols!= static_cast<int>(image_width_) || temp.rows != static_cast<int>(image_height_) ){
    return false;
  }

  isFree.resize(image_height_, std::vector<bool>(image_width_));

  int white_pixels_counter=0;
  for( int x_pixel = 0 ; x_pixel< static_cast<int>(image_width_); x_pixel++)
    for( int y_pixel = 0; y_pixel< static_cast<int>(image_height_); y_pixel++){
      white_pixels_counter=0;
      for( int i = std::max(x_pixel-neighbour_size, 0); i<= std::min(x_pixel+neighbour_size,static_cast<int>(image_width_)-1); i++)
        for( int j = std::max(y_pixel-neighbour_size, 0); j<= std::min(y_pixel+neighbour_size,static_cast<int>(image_height_)-1); j++)
            if (int(temp.at<float>(j,i)) > 128) {
              white_pixels_counter++;
            }
      isFree[y_pixel][x_pixel]= (white_pixels_counter<40);
  }

  return true;
}

void nav2_gradient_costmap_plugin::overhead_camera::overhead_camera::worldFOV(double &min_x,
                                                                              double &min_y,
                                                                              double &max_x,
                                                                              double &max_y) {
  pixelToWorld(static_cast<unsigned int>(0),image_height_,min_x, min_y);
  pixelToWorld(image_width_,static_cast<unsigned int>(0), max_x, max_y);
  world_x_min_ = min_x;
  world_y_min_ = min_y;
  world_x_max_ = max_x;
  world_y_max_ = max_y;
}
