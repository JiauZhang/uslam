_all_:
	$(Q)echo "\nplease specify target\n"

USLAMFLAGS = -std=c++11 -Wall

USLAM_LIB_BOOST = -lboost_program_options
USLAMLIBS = $(USLAM_LIB_BOOST)
USLAMFLAGS += $(USLAMLIBS)

USLAMINCLUDE = -I$(srctree)/include
USLAMINCLUDE += -I$(srctree)/include/ros
USLAMFLAGS += $(USLAMINCLUDE)

uslam: uslam.cpp
	$(Q)$(CPP) uslam.cpp -o uslam.o $(USLAMFLAGS)