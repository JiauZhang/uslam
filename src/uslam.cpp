#include "image_data.hpp"
#include "transporter.hpp"

#include <boost/thread.hpp>

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv)
{
	ImageData &IData = ImageData<cv::Mat>::getInstance();
	Transporter transporter(&IData);
	/*
	boost::thread image_data(boost::bind(\
				&Transporter::run, &transporter, \
				argc, argv))
	;
	image_data.join();
	*/
	
	transporter.run(argc, argv);
	
	std::cout << "uslam finished !" << std::endl;
	
	return 0;
}