#include "common.hpp"
#include "detector.hpp"
#include "detector_factory.hpp"
#include "parameters.hpp"
#include "io.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace uslam;

// ./test_orb_detector.o config_file_name test_image.png

int main(int argc, char **argv)
{
	if (argc != 3) {
		std::cout << "Usage: ./test_orb_detector file_name test_image.png" << std::endl;
		return -1;
	}
	
	const std::string file_name(argv[1]);

	std::map<std::string, std::map<std::string, std::string>> parameters;

	uslam::read_parameter_from_file(file_name, parameters);

	DetectorParameter param;
	shared_ptr<Detector> detector;
	std::cout << "instance detector" << std::endl;
	if (parameters.count("[detector]")) {
		std::cout << "has detector" << std::endl;
		std::map<std::string, std::string> &detector_params = parameters["[detector]"];
		param.params_ = detector_params;
		std::string log;
		
		CHECK_NE(detector_params.count("type"), 0, \
			"you must give a detector type when the [detector] object is given !");
		
		param.type = detector_params["type"];	
		std::cout << "has detector type:" << param.type << std::endl;
		detector = DetectorRegistry::CreateDetector(param);
		
		CHECK_PTR(detector.get(), "create detector failed !");
	}
	std::cout << "image process" << std::endl;
	cv::Mat image = cv::imread(argv[2]);
	if (!image.empty()) {
		vector<cv::KeyPoint> kps;	
		detector->detect(image, kps);	
		// draw keypoint rectangle
		// cv::drawKeypoints(image, kps, image);
		// show image
		// cv::imshow("test_fast_detector", image);
		// cv::waitKey(0);
	}
	
	return 0;
}