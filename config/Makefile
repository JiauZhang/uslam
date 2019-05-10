CPPFLAGS += -std=c++11 -Wall
LIB_BOOST = -lboost_program_options
LIBS = ${LIB_BOOST}

CPPFLAGS += $(LIBS)

CXX = g++

options.o: options.cpp
	$(CXX) options.cpp -o options.o $(CPPFLAGS)

clean:
	rm -rf *.o
