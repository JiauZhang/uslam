#include "image_data.hpp"
#include "transporter.hpp"

#include <boost/thread.hpp>

int main(int argc, char **argv)
{
	ImageData &IData = ImageData::getInstance();
	Transporter transporter(&IData);
	
	boost::thread image_data(boost::bind(\
				&transporter.run, \
				argc, argv))
	;
	
	
	return 0;
}