cmake_minimum_required(VERSION 2.8)
project(viewer)

add_compile_options(-std=c++11)

set(PANGOLIN_ROOT_DIR "/mnt/d/code/Pangolin")
set(PANGOLIN_INCLUDE_DIRS "${PANGOLIN_ROOT_DIR}/include" 
	"${PANGOLIN_ROOT_DIR}/build/src/include")
set(PANGOLIN_LIBRARIES "${PANGOLIN_ROOT_DIR}/build/src/libpangolin.so")
include_directories(${PANGOLIN_INCLUDE_DIRS})

set(EIGEN_ROOT_DIR "/mnt/d/code/Eigen")
include_directories(${EIGEN_ROOT_DIR})

find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(viewer init.cpp)
target_link_libraries(viewer ${PANGOLIN_LIBRARIES} ${Boost_LIBRARIES})