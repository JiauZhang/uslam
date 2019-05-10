cmake_minimum_required(VERSION 2.8.3)
project(transporter)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# include_directories("../../../../")

catkin_package(
 INCLUDE_DIRS
 LIBRARIES transporter
 CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
# DEPENDS system_lib
)

include_directories(
include ${catkin_INCLUDE_DIRS}
)

add_executable(transporter src/transporter.cpp)
target_link_libraries(transporter ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


