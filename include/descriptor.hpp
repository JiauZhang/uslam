#ifndef __DESCRIPTOR_H__
#define __DESCRIPTOR_H__

namespace uslam {

class Descriptor {
public:	
	explicit Descriptor() {}
	virtual ~Descriptor() {}
	
	virtual void describe() = 0;
	
	
}; // Descriptor
	
} // namespace uslam

#endif