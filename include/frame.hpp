#ifndef __FRAME_H__
#define __FRAME_H__

#include <vector>

namespace uslam {
class Frame {
	Frame() {}
	virtual ~Frame() {}
	
	vector<int> shape() {return shape_;}
	
	
	vector<int> shape_;
};	
	
} // namespace uslam

#endif