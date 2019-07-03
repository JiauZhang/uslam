#include "brief_descriptor.hpp"

namespace uslam {

BriefDescriptor::BriefDescriptor(const DescriptorParameter &param): Descriptor(param)
{
	std::cout << "init BriefDescriptor" << std::endl;
}

void BriefDescriptor::compute(cv::Mat &image, cv::Mat &keypoints, cv::Mat &descriptors)
{
	std::cout << "BriefDescriptor compute" << std::endl;
}	

REGISTER_DESCRIPTOR_CLASS(Brief);
	
} // namespace uslam