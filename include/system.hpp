#ifndef __SYSTEM__HPP_
#define __SYSTEM__HPP_

#include "common.hpp"
#include <opencv2/opencv.hpp>

namespace uslam {

class System {
public:
	explicit System(string &config_file);
	
protected:
	vector<vector<cv::Mat *>> input_;
	vector<vector<cv::Mat *>> output_;
	
	typedef void Function_(vector<cv::Mat *> input, vector<cv::Mat *> output>;
	vector<Function_> functions_;
	
	Detector *detector_;
	Descriptor *descriptor_;
	Matcher *matcher_;
	
}; // class System

}
#endif