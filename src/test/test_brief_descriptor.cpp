#include "common.hpp"
#include "descriptor.hpp"
#include "descriptor_factory.hpp"
#include "parameters.hpp"
#include "io.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace uslam;

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: /PATH/TO/bin /PATH/TO/config_file" << std::endl;
		return -1;
	}

	const std::string file_name(argv[1]);

	std::map<std::string, std::map<std::string, std::string>> parameters;

	uslam::read_parameter_from_file(file_name, parameters);

	if (parameters.count("[descriptor]")) {
		DescriptorParameter param;
		shared_ptr<Descriptor> descriptor;
		
		std::cout << "has descriptor" << std::endl;
		param.params_ = parameters["[descriptor]"]; 
		
		CHECK_NE(param.params_.count("type"), 0, \
			"you must give a descriptor type when the [descriptor] object is given !");
		
		param.type = param.params_["type"];	
		std::cout << "has detector type:" << param.type << std::endl;
		descriptor = DescriptorRegistry::CreateDescriptor(param);
		
		CHECK_PTR(descriptor.get(), "create detector failed !");
		
		cv::Mat img, kpts, desc;
		
		descriptor->compute(img, kpts, desc);
		
		std::cout << "test finished" << std::endl;
	} else {
		std::cout << "no descriptor" << std::endl;
		return -1;
	}
	
}