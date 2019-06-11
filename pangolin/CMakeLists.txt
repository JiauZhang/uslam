cmake_minimum_required(VERSION 2.8)
project(pangolin_viewer_bridge)

add_compile_options(-std=c++11)

set(PANGOLIN_ROOT_DIR "/mnt/d/code/Pangolin")
set(PANGOLIN_INCLUDE_DIRS "${PANGOLIN_ROOT_DIR}/include" 
	"${PANGOLIN_ROOT_DIR}/build/src/include"
	"/mnt/d/code/uslam/include"
	"/mnt/d/code/uslam/include/pangolin")
set(PANGOLIN_LIBRARIES "${PANGOLIN_ROOT_DIR}/build/src/libpangolin.so")
include_directories(${PANGOLIN_INCLUDE_DIRS})

set(EIGEN_ROOT_DIR "/mnt/d/code/Eigen")
include_directories(${EIGEN_ROOT_DIR})

# find_package(Boost REQUIRED)
# include_directories(${Boost_INCLUDE_DIRS})

# find_package(OpenCV REQUIRED)
# include_directories(${OpenCV_INCLUDE_DIRS})

# add_executable(pangolin_viewer_bridge pangolin_viewer_bridge.cpp)
# target_link_libraries(pangolin_viewer_bridge ${PANGOLIN_LIBRARIES} ${Boost_LIBRARIES})

add_library(pangolin_viewer_bridge SHARED pangolin_viewer_bridge.cpp)
target_link_libraries(pangolin_viewer_bridge ${PANGOLIN_LIBRARIES})