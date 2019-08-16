#include "common.hpp"
#include "fast_detector.hpp"
#include "check.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>

namespace uslam {

FastDetector::FastDetector(const DetectorParameter &param): Detector(param)
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
void FastDetector::detect(cv::Mat &image, vector<cv::KeyPoint> &kps)
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

void FastDetector::detect(vector<cv::Mat *> &bottom, vector<cv::Mat *> &top)
{
	top.resize(bottom.size(), NULL);
	
	for (int i=0; i<bottom.size(); i++) {
		cv::Mat *image = bottom[i];
		
		CHECK_PTR(image, "Invalid image data is given to FastDetector::detect");
		
		vector<cv::KeyPoint> kps;
		cv::Ptr<cv::FastFeatureDetector> cv_detector = cv::FastFeatureDetector::create();
		cv_detector->detect(*image, kps);
		
		//top[i] = keypoint_to_mat(kps);
		top[i] = NULL;
	}
}

REGISTER_DETECTOR_CLASS(Fast);
	
} // namespace uslam