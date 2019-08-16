#ifndef __DETECTOR_H__
#define __DETECTOR_H__

#include <opencv2/opencv.hpp>
#include "common.hpp"
#include "parameters.hpp"
#include "blob.hpp"

namespace uslam {

//template <typename Dtype>
class Detector {
public:	
	explicit Detector(const DetectorParameter &param);
	//virtual ~Detector() {}
	
	virtual void detect(cv::Mat &image, std::vector<cv::KeyPoint> &kps) = 0;
	virtual void detect(vector<cv::Mat *> &bottom, vector<cv::Mat *> &top) = 0;
	//virtual void detect(vector<Blob<float> *> input,  vector<Blob<float> *> output) = 0;
	virtual void load_parameter(std::string &file_name) {}
	virtual void detector_setup(const DetectorParameter &param);
	// you should never override this method !
	// you should first call 'has_parameter' to make sure the 'key_' exists !
	std::string get_parameter(const std::string &key);
	// you should never override this method !
	bool has_parameter(const std::string &key);
	// input: key_, output: value_, return true if successed
	bool try_get_parameter(const std::string &key, std::string &value);
	// you may need override this method if you have your own parameters
	virtual void init_parameter() {}
	
private:
	std::map<std::string, std::string> param_;
	
}; // Detector
	
} // namespace uslam

#endif