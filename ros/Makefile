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

fetch_image.o: fetch_image.cpp
# bad usage !!!
# $(CPP) $(CPPFLAGS) fetch_image.cpp -o fetch_image.o 
	$(CPP)  fetch_image.cpp -o fetch_image.o $(CPPFLAGS)

clean:
	rm -rf *.o
