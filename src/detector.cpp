#include "detector.hpp"

namespace uslam {

Detector::Detector(const DetectorParameter &param)
{
	//std::map<std::string, std::string> &pm = param.params_;
	//std::map<std::string, std::string>::iterator it_ = param.params_.begin();
	//for (; it_ != param.params_.end(); it_++) {
	//	param_[it_->first] = it_->second;
	//}
	param_ = param.params_;
}

void Detector::detector_setup(const DetectorParameter &param)
{
	
}
	
std::string Detector::get_parameter(const std::string &key)
{
	return param_[key];
}	

bool Detector::has_parameter(const std::string &key)
{
	return param_.count(key);
}

bool Detector::try_get_parameter(const std::string &key, std::string &value)
{
	if (param_.count(key)) {
		value = param_[key];
		return true;
	}
	
	return false;
}
	
}