#ifndef __ORB_DETECTOR__
#define __ORB_DETECTOR__

#include "detector.hpp"
#include "common.hpp"
#include "parameters.hpp"
#include "detector_factory.hpp"

namespace uslam {
	
class ORBDetector: public Detector {	
public:
	explicit ORBDetector(const DetectorParameter &param);
	void detect(cv::Mat &image_, vector<cv::KeyPoint> &kps_);
	
private:
	ORBDetectorParameter orb_param;
	
}; // ORBDetector

} // namespace uslam

#endif