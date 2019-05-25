cmake_minimum_required(VERSION 2.8.3)
project(image_raw)

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

catkin_package(
 INCLUDE_DIRS
 LIBRARIES image_raw
 CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
# DEPENDS system_lib
)

include_directories(
include ${catkin_INCLUDE_DIRS}
)

add_executable(image_raw src/image_raw.cpp)
target_link_libraries(image_raw ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})


