#include "descriptor.hpp"
#include <opencv2/opencv.hpp>
#include "common.hpp"
#include "parameters.hpp"

namespace uslam {

bool Descriptor::try_get_parameter(const std::string &key, std::string &value)
{
	if (param_.count(key)) {
		value = param_[key];
		return true;
	}
	
	return false;
}	
	
} // namespace uslam