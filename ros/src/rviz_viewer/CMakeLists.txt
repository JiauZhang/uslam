cmake_minimum_required(VERSION 2.8.3)
project(rviz_viewer)

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

add_executable(rviz_viewer src/rviz_viewer.cpp)
target_link_libraries(rviz_viewer ${catkin_LIBRARIES} ${Boost_LIBRARIES})
