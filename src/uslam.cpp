#include "image_data.hpp"
#include "transporter.hpp"

#include <boost/thread.hpp>

#include <iostream>

int main(int argc, char **argv)
{
	ImageData &IData = ImageData::getInstance();
	Transporter transporter(&IData);
	
	boost::thread image_data(boost::bind(\
				&Transporter::run, &transporter, \
				argc, argv))
	;
	image_data.join();
	std::cout << "uslam finished !" << std::endl;
	
	return 0;
}