#ifndef __DESCRIPTOR_H__
#define __DESCRIPTOR_H__

#include <opencv2/opencv.hpp>
#include "common.hpp"
#include "parameters.hpp"

namespace uslam {

class Descriptor {
public:	
	explicit Descriptor(const DescriptorParameter &param) { param_ = param.params_; }
	virtual ~Descriptor() {}
	
	virtual void compute(cv::Mat &image, cv::Mat &keypoints, cv::Mat &descriptors) = 0;
	
	// input: key_, output: value_, return true if successed
	bool try_get_parameter(const std::string &key, std::string &value);

private:
	std::map<std::string, std::string> param_;	
	
}; // Descriptor
	
} // namespace uslam

#endif