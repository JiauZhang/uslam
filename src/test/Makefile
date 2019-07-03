test__all:
	$(Q)echo "\nplease call in USLAM ROOT DIR and specify target"
	$(Q)echo "for example: make test_io\n"

TEST_IO_INCLUDE = -I$(srctree)/include/util -std=c++11 -Wall
	
io.o: test_io.cpp $(srctree)/src/util/io.cpp
	$(Q)$(CPP) $^ -o io.o $(TEST_IO_INCLUDE)

# include files	
COMMON_INCLUDE =  \
					-I$(srctree)/include/util -std=c++11 -Wall \
					-I$(srctree)/include \
					-I$(srctree)/include/detectors \
					-I$(srctree)/include/descriptors

# opencv
# opencv_imgcodecs for imread, opencv_features2d for detectors and drawKeypoints
OPENCV_INCLUDE = -I/usr/include/opencv
OPENCV_LIBRARY = \
					-lopencv_core -lopencv_imgproc -lopencv_highgui \
					-lopencv_imgcodecs -lopencv_features2d

# undefined reference to foo(), it means you should add relevent libs to linker !
FAST_DETECTOR_INCLUDE = \
						-I/usr/include/opencv \
						-lopencv_core -lopencv_imgproc -lopencv_highgui \
						-lopencv_imgcodecs -lopencv_features2d \
						$(COMMON_INCLUDE)

FAST_DETECTOR_SRC = \
					test_fast_detector.cpp $(srctree)/src/detector.cpp \
					$(srctree)/src/util/io.cpp $(srctree)/src/detectors/fast_detector.cpp \
					$(srctree)/src/util/check.cpp
				   
fast_detector.o: $(FAST_DETECTOR_SRC)
	$(CPP) $^ -o fast_detector.o $(FAST_DETECTOR_INCLUDE)

BLOB_SRC = test_blob.cpp $(srctree)/src/blob.cpp $(srctree)/src/util/check.cpp
BLOB_INCLUDE = -I$(srctree)/include -I$(srctree)/include/util
	
blob.o: $(BLOB_SRC)
	$(Q)$(CPP) $^ -o blob.o $(BLOB_INCLUDE)

BRIEF_DESCRIPTOR_INCLUDE = \
							$(COMMON_INCLUDE) \
							$(OPENCV_INCLUDE) \
							$(OPENCV_LIBRARY)
BRIEF_DESCRIPTOR_SRC = \
						test_brief_descriptor.cpp $(srctree)/src/util/check.cpp \
						$(srctree)/src/util/io.cpp $(srctree)/src/descriptors/brief_descriptor.cpp \
						$(srctree)/src/descriptor.cpp
	
brief_descriptor.o: $(BRIEF_DESCRIPTOR_SRC)
	$(CPP) $^ -o brief_descriptor.o $(BRIEF_DESCRIPTOR_INCLUDE)
	
