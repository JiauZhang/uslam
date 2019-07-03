#ifndef __BRIEF_DESCRIPTOR__
#define __BRIEF_DESCRIPTOR__

#include "descriptor.hpp"
#include "common.hpp"
#include "parameters.hpp"
#include "descriptor_factory.hpp"

namespace uslam {
	
class BriefDescriptor: public Descriptor {
public:
	explicit BriefDescriptor(const DescriptorParameter &param);
	void compute(cv::Mat &image, cv::Mat &keypoints, cv::Mat &descriptors);

}; // class BriefDescriptor	
	
} // namespace uslam

#endif