#include "common.hpp"
#include "orb_detector.hpp"

namespace uslam {

ORBDetector::ORBDetector(const DetectorParameter &param): Detector(param)
{
	std::string str_param;
	if (try_get_parameter("grid_size", str_param)) {
		std::cout << "get [grid_size] successed" << std::endl;
		orb_param.grid_size = std::stoi(str_param);
	} else {
		std::cout << "dont have [grid_size] parameter" << std::endl;
	}
}

// this method will change original image data	
void ORBDetector::detect(cv::Mat &image_, vector<cv::KeyPoint> &kps_)
{
	std::cout << "ORBDetector-detect" << std::endl;
	//cv::GaussianBlur(image_, image_, cv::Size(7, 7), 2, 2, cv::BORDER_REFLECT_101);
}

REGISTER_DETECTOR_CLASS(ORB);
	
} // namespace uslam