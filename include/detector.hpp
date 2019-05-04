#ifndef __DETECTOR_H__
#define __DETECTOR_H__

namespace uslam {

class Detector {
public:	
	explicit Detector() {}
	virtual ~Detector() {}
	
	virtual void detect() = 0;
	
	
}; // Detector
	
} // namespace uslam

#endif