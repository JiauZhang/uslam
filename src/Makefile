_all_:
	$(Q)echo "\nplease specify target\n"

USLAMFLAGS = -std=c++11 -Wall

USLAM_LIB_BOOST = -lboost_program_options -lboost_thread -lboost_system
USLAMLIBS = $(USLAM_LIB_BOOST)
USLAMFLAGS += $(USLAMLIBS)

USLAM_LIB_OPENCV = -lopencv_core -lopencv_imgproc -lopencv_highgui
USLAMFLAGS += $(USLAM_LIB_OPENCV)

USLAM_LIB_DIRS = -L$(srctree)/ros/devel/lib
USLAM_LIB_TRANSPORTER = -ltransporter
USLAMFLAGS += $(USLAM_LIB_DIRS) $(USLAM_LIB_TRANSPORTER)

USLAMINCLUDE = -I$(srctree)/include
USLAMINCLUDE += -I$(srctree)/include/ros

ROS_ROOT_DIR = /opt/ros/melodic/include
USLAMINCLUDE += -I$(ROS_ROOT_DIR)

USLAMFLAGS += $(USLAMINCLUDE)

uslam.o: uslam.cpp
	$(Q)$(CPP) uslam.cpp -o uslam.o $(USLAMFLAGS)
	
viewer_factory: viewer_factory.cpp
	$(Q)$(CPP) $^ -shared -o libviewer_factory.so -I$(srctree)/include -std=c++11 -Wall