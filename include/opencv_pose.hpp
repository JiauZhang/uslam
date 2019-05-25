#ifndef __POSE_H__
#define __POSE_H__

namespace uslam {

#include <opencv2/core/core.hpp>
#include "pose.hpp"

// class OpenCVPose: public Pose<cv::Mat> {
// public:
// 	explicit OpenCVPose(cv::Mat &p): pose(p) {}
// };

template <typename Dtype>
Dtype Pose<Dtype>::transform(Dtype T, Dtype p)
{
	return T * p;
}

template <typename Dtype>
void Pose<Dtype>::make_points(float camera_size, vector<Dtype> points)
{
	float d = camera_size;
	//Camera is a pyramid. Define in camera coordinate system
	Dtype point();
	points.push_back((cv::Mat_<float>(4,1) << 0, 0, 0, 1));
	points.push_back((cv::Mat_<float>(4,1) << d, d*0.8, d*0.5, 1));
	points.push_back((cv::Mat_<float>(4,1) << d, -d*0.8, d*0.5, 1));
	points.push_back((cv::Mat_<float>(4,1) << -d, -d*0.8, d*0.5, 1));
	points.push_back((cv::Mat_<float>(4,1) << -d, d*0.8, d*0.5, 1));
}

template <typename Dtype>
Dtype Pose<Dtype>::inv()
{
	return pose.inv();
}

template class Pose<cv::Mat>;

} // namespace uslam
#endif