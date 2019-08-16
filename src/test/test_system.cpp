#include "common.hpp"
#include "detector.hpp"
#include "detector_factory.hpp"
#include "descriptor.hpp"
#include "descriptor_factory.hpp"
#include "matcher.hpp"
#include "matcher_factory.hpp"
#include "parameters.hpp"
#include "io.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace uslam;

// ./test_system.o config_file_name image_left.png image_right.png

int main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Usage: ./test_system.o config_file_name image_left.png image_right.png" << std::endl;
		return -1;
	}
	
	const std::string file_name(argv[1]);

	std::map<std::string, std::map<std::string, std::string>> parameters;

	uslam::read_parameter_from_file(file_name, parameters);

	DetectorParameter detector_param;
	DescriptorParameter descriptor_param;
	MatcherParameter matcher_param;
	shared_ptr<Detector> detector;
	shared_ptr<Descriptor> descriptor;
	shared_ptr<Matcher> matcher;
	// detector
	std::cout << "instance detector" << std::endl;
	
	CHECK_NE(parameters.count("[detector]"), 0, "no detector is given !\n");
	
	std::cout << "has detector" << std::endl;
	std::map<std::string, std::string> &detector_params = parameters["[detector]"];
	detector_param.params_ = detector_params;
	
	CHECK_NE(detector_params.count("type"), 0, \
		"you must give a detector type when the [detector] object is given !");
	
	detector_param.type = detector_params["type"];	
	std::cout << "has detector type:" << detector_param.type << std::endl;
	detector = DetectorRegistry::CreateDetector(detector_param);
	
	CHECK_PTR(detector.get(), "create detector failed !");
	
	// descriptor
	std::cout << "instance descriptor" << std::endl;
	
	CHECK_NE(parameters.count("[descriptor]"), 0, "no descriptor is given !\n");

	std::cout << "has descriptor" << std::endl;
	std::map<std::string, std::string> &descriptor_params = parameters["[descriptor]"];
	descriptor_param.params_ = descriptor_params;
	
	CHECK_NE(descriptor_params.count("type"), 0, \
		"you must give a descriptor type when the [descriptor] object is given !");
	
	descriptor_param.type = descriptor_params["type"];	
	std::cout << "has descriptor type:" << descriptor_param.type << std::endl;
	descriptor = DescriptorRegistry::CreateDescriptor(descriptor_param);
	
	CHECK_PTR(descriptor.get(), "create descriptor failed !");
	
	// matcher
	std::cout << "instance matcher" << std::endl;
	
	CHECK_NE(parameters.count("[matcher]"), 0, "no matcher is given !\n");
	
	std::cout << "has matcher" << std::endl;
	std::map<std::string, std::string> &matcher_params = parameters["[matcher]"];
	matcher_param.params_ = matcher_params;
	
	CHECK_NE(matcher_params.count("type"), 0, \
		"you must give a matcher type when the [matcher] object is given !");
	
	matcher_param.type = matcher_params["type"];	
	std::cout << "has matcher type:" << matcher_param.type << std::endl;
	matcher = MatcherRegistry::CreateMatcher(matcher_param);
	
	CHECK_PTR(matcher.get(), "create matcher failed !");
	
	std::cout << "starting system process" << std::endl;
	
	cv::Mat image = cv::imread(argv[2]);
	if (!image.empty()) {
		vector<cv::KeyPoint> kps;	
		detector->detect(image, kps);	
	}
	
	std::cout << "system finished !" << std::endl;
	
	return 0;
}