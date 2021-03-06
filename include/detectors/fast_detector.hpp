#ifndef __ORB_DETECTOR__
#define __ORB_DETECTOR__

#include "detector.hpp"
#include "common.hpp"
#include "parameters.hpp"
#include "detector_factory.hpp"

namespace uslam {
	
class FastDetector: public Detector {	
public:
	explicit FastDetector(const DetectorParameter &param);
	void detect(cv::Mat &image_, vector<cv::KeyPoint> &kps_);
	void detect(vector<cv::Mat *> &bottom, vector<cv::Mat *> &top);
	//void detect(vector<Blob<float> *> input,  vector<Blob<float> *> output);
	
private:
	FASTDetectorParameter orb_param;
	
}; // ORBDetector

} // namespace uslam

#endif