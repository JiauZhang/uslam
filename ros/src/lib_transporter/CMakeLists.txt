cmake_minimum_required(VERSION 2.8.3)
project(lib_transporter)

# set_target_properties(lib_transporter PROPERTIES LINKER_LANGUAGE CXX)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories("../../../include")
include_directories("../../../include/ros")

find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(${Boost_INCLUDE_DIRS})

catkin_package(
 INCLUDE_DIRS
 LIBRARIES lib_transporter
 CATKIN_DEPENDS cv_bridge image_transport roscpp sensor_msgs std_msgs
)

include_directories(
include ${catkin_INCLUDE_DIRS}
)

# add_executable(lib_transporter src/transporter.hpp)
add_library(lib_transporter SHARED src/lib_transporter.cpp)
target_link_libraries(lib_transporter ${catkin_LIBRARIES} ${OpenCV_LIBRARIES} ${Boost_LIBRARIES})
#set(TARGET_COMPILE_FLAGS "${TARGET_COMPILE_FLAGS} -std=c++11") 
#set_target_properties(lib_transporter PROPERTIES COMPILE_FLAGS ${TARGET_COMPILE_FLAGS})


