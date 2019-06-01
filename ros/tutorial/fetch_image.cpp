#include <iostream>
#include <cstring>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp> 

/*
#include <core.hpp>
#include <imgproc.hpp>
#include <highgui.hpp>
*/

int main(int argc, char **argv)
{
	const std::string image_path("./selfdriving.jpg");
	cv::Mat image = cv::imread(image_path.c_str());
	
	std::cout << "image size: " << image.rows \
			  << '-' << image.cols << std::endl;

	cv::imshow("fetch image", image);
	cv::waitKey();

	return 0;
}
