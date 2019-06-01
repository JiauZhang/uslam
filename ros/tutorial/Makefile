ros_tutorial:
	$(Q)echo "\nplease call in USLAM ROOT DIR and specify target"
	$(Q)echo "for example: make ros_tutorial_rviz_viewer\n"

RVIZ_VIEWER_LIB = 
RVIZ_VIEWER_LIB += -lboost_thread -lboost_system
RVIZ_VIEWER_LIB_DIRS = -L$(srctree)/ros/devel/lib
RVIZ_VIEWER_LIB += -lrviz_viewer_bridge $(RVIZ_VIEWER_LIB_DIRS)

RVIZ_VIEWER_INCLUDE = -I$(srctree)/include -I$(srctree)/include/ros \
					  -I/opt/ros/melodic/include

RVIZ_VIEWER_FLAGS = -std=c++11 -Wall $(RVIZ_VIEWER_LIB) $(RVIZ_VIEWER_INCLUDE)

rviz_viewer.o: rviz_viewer.cpp $(srctree)/src/rviz_viewer.cpp $(srctree)/src/viewer_factory.cpp
	$(Q)$(CPP) $^ -o rviz_viewer.o $(RVIZ_VIEWER_FLAGS)