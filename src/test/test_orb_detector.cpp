#include "common.hpp"
#include "detector.hpp"
#include "detector_factory.hpp"
#include "parameters.hpp"
#include "io.hpp"

using namespace uslam;

// ./test_orb_detector.o config_file_name

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./test_orb_detector file_name" << std::endl;
		return -1;
	}
	
	const std::string file_name(argv[1]);

	std::map<std::string, std::map<std::string, std::string>> parameters;

	uslam::read_parameter_from_file(file_name, parameters);
	
	DetectorParameter param;
	shared_ptr<Detector> detector;
	
	if (parameters.count("[detector]")) {
		std::map<std::string, std::string> &detector_params = parameters["[detector]"];
		param.params_ = detector_params;
		try {
			if (detector_params.count("type")) {
				param.type = detector_params["type"];		
				detector = DetectorRegistry::CreateDetector(param);
			} else {
				throw -1;
			}
		} catch (int &e_) {
			std::cout << "you have to provide the detector [type], such as [orb] and so on" \
				      << std::endl;
			exit(1);		  
		}
	}
	
	cv::Mat image;
	vector<cv::KeyPoint> kps;
	
	detector->detect(image, kps);
	
	// draw keypoint rectangle
	
	// show image
	//cv::imshow("test_orb_detector", image);
	//cv::waitKey(0);
	
	return 0;
}