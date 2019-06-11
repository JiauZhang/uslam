test__all:
	$(Q)echo "\nplease call in USLAM ROOT DIR and specify target"
	$(Q)echo "for example: make test_io\n"

TEST_IO_INCLUDE = -I$(srctree)/include/util -std=c++11 -Wall
	
io.o: test_io.cpp $(srctree)/src/util/io.cpp
	$(Q)$(CPP) $^ -o io.o $(TEST_IO_INCLUDE)

# include files	
ORB_DETECTOR_INCLUDE =  \
						-I$(srctree)/include/util -std=c++11 -Wall \
						-I$(srctree)/include \
						-I$(srctree)/include/detectors

# opencv
ORB_DETECTOR_INCLUDE += \
						-I/usr/include/opencv \
						-lopencv_core -lopencv_imgproc -lopencv_highgui

ORB_DETECTOR_SRC = \
					test_orb_detector.cpp $(srctree)/src/detector.cpp \
					$(srctree)/src/util/io.cpp $(srctree)/src/detectors/orb_detector.cpp
				   
orb_detector.o: $(ORB_DETECTOR_SRC)
	$(Q)$(CPP) $^ -o orb_detector.o $(ORB_DETECTOR_INCLUDE)
	
