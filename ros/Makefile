CPPFLAGS += -std=c++11 -Wall
INCLUDE_OPENCV = `pkg-config opencv --cflags`
LIB_OPENCV = `pkg-config opencv --libs`
# INCLUDE = $(shell pkg-config --cflags opencv)
# LIBS = $(shell pkg-config --libs opencv)
INCS = ${INCLUDE_OPENCV}
LIBS = ${LIB_OPENCV}

CPPFLAGS += $(INCS) $(LIBS)

CPP = g++
CC = gcc

ros_lib:
	$(Q)echo "\nplease call in USLAM ROOT DIR and specify target"
	$(Q)echo "for example: make ros_lib_rviz_viewer\n"

fetch_image.o: fetch_image.cpp
# bad usage !!!
# $(CPP) $(CPPFLAGS) fetch_image.cpp -o fetch_image.o 
	$(CPP)  fetch_image.cpp -o fetch_image.o $(CPPFLAGS)


image_raw.o: image_raw.cpp
	$(CPP) image_raw.cpp -o image_raw.o $(CPPFLAGS)

rviz_viewer_bridge: src/rviz_viewer_bridge/src/rviz_viewer_bridge.cpp
	cd $(srctree)/ros && catkin_make rviz_viewer_bridge

clean:
	rm -rf *.o
