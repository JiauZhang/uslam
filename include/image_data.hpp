#ifndef __IMAGE_DATA__
#define __IMAGE_DATA__

#include <iostream>
#include <cstring>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp> 

class ImageData {
public:
	cv::Mat image;
	boost::mutex image_data_mutex;
	static ImageData& getInstance() {
		static ImageData singleton;
		return singleton;
	}

private:
	ImageData () {}
};

#endif
