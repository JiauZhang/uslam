cmake_minimum_required(VERSION 2.8.3)
project(rviz_viewer_bridge)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  visualization_msgs
)

include_directories(
	include ${catkin_INCLUDE_DIRS}
)

include_directories("../../../include/ros")
include_directories("../../../include")

find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})

# add_executable(rviz_viewer_bridge src/rviz_viewer_bridge.cpp)
# target_link_libraries(rviz_viewer_bridge ${catkin_LIBRARIES} ${Boost_LIBRARIES})

# add_library(rviz_viewer_bridge SHARED src/rviz_viewer_bridge.cpp ../../../src/viewer_factory.cpp)
add_library(rviz_viewer_bridge SHARED src/rviz_viewer_bridge.cpp)
target_link_libraries(rviz_viewer_bridge ${catkin_LIBRARIES} ${Boost_LIBRARIES})
