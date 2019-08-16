# ifndef __MATCHER__H__
# define __MATCHER__H__

#include "parameters.hpp"
#include "common.hpp"
#include <opencv2/opencv.hpp>

namespace uslam {
	
class Matcher {
public:	
	explicit Matcher(const MatcherParameter &param) { param_ = param.params_; }
	virtual ~Matcher() {}
	
	virtual void match(vector<cv::KeyPoint> &kps1, vector<cv::KeyPoint> &kps2) = 0;
	virtual void match(vector<cv::Mat *> &bottom, vector<cv::Mat *> &top) = 0;

private:
	std::map<std::string, std::string> param_;

}; // Matcher
	
} // namespace uslam

# endif