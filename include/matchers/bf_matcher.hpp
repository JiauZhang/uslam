#ifndef __BF_MATCHER__
#define __BF_MATCHER__

namespace uslam {
	
class BFMatcher: public Matcher {
public:
	explicit BFMatcher(const MatcherParameter &param): Matcher(param) {}
	~BFMatcher() {}
	
	void match(vector<cv::KeyPoint> &kps1, vector<cv::KeyPoint> &kps2);
	void match(vector<cv::Mat *> &bottom, vector<cv::Mat *> &top);
};	
	
} // namespace uslam

#endif