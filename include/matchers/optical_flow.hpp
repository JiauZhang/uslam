#ifndef __OPTICAL_FLOW_MATCHER__
#define __OPTICAL_FLOW_MATCHER__

#include "opencv/opencv.hpp>

namespace uslam {
	
class OpticalFlowMatcher: public Matcher {
public:
	explicit OpticalFlowMatcher(const MatcherParameter &param): Matcher(param) {}
	~OpticalFlowMatcher() {}
	
	void match(vector<cv::KeyPoint> &kps1, vector<cv::KeyPoint> &kps2);
	void match(vector<cv::Mat *> &bottom, vector<cv::Mat *> &top);
};	
	
} // namespace uslam

#endif