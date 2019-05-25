#ifndef __POSE_H__
#define __POSE_H__

#include <vector>

template <typename Dtype>
class Pose {
public:
	explicit Pose(Dtype &p): pose(p) {}
	// T: transform matrix = [R, t; 0, 1], p: coord = [x, y, z, 1]
	virtual Dtype transform(Dtype T, Dtype p) = 0;
	virtual void make_points(float camera_size, vector<Dtype> points) = 0;
	virtual Dtype inv() = 0;
	
	Dtype pose;
};

#endif