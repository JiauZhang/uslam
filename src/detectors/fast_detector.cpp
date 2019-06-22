#include "common.hpp"
#include "fast_detector.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>

namespace uslam {

FASTDetector::FASTDetector(const DetectorParameter &param): Detector(param)
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
void FASTDetector::detect(cv::Mat &image, vector<cv::KeyPoint> &kps)
{
	std::cout << "FastDetector-detect" << std::endl;
	cv::Ptr<cv::FastFeatureDetector> cv_detector = cv::FastFeatureDetector::create();
	cv::GaussianBlur(image, image, cv::Size(7, 7), 2, 2, cv::BORDER_REFLECT_101);
	cv_detector->detect(image, kps);
}

// void ORBDetector::detect(vector<Blob<float> *> input,  vector<Blob<float> *> output)
// {
// 	
// }

REGISTER_DETECTOR_CLASS(FAST);
	
} // namespace uslam