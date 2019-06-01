#ifndef __VIEWER_H__
#define __VIEWER_H__

#include <string>
#include <cstring>
#include <vector>

#include "viewer_factory.hpp"
#include "common.hpp"
#include "parameters.hpp"

namespace uslam {

class Viewer {
public:
	//explicit Viewer(int argc, char **argv);
	//virtual void plot_camera(Pose<Dtype> pose) = 0;
	//virtual void plot_frames(Pose<Dtype> pose) = 0;
	//virtual void plot_points(Pose<Dtype> pose) = 0;
	/*
		optical center = [0, 0, 0]
				|
		 p3 	|      p4
				|  
	  --------------------->y
				|    | d 
		 p2 	|----- p1
				| 0.8d
				x
		p1 = [d, d*0.8, d*0.5]
		p2 = [d, -d*0.8, d*0.5]
		p3 = [-d, -d*0.8, d*0.5]
		p4 = [-d, d*0.8, d*0.5]
	*/
	// points are relative to the world coordinate system
	// so you must transform local coordinate system(camera coordinate system) points 
	// to the world coordinate system efore calling this function
	/*
		points[0] = optical center
		points[1] = p1
		points[2] = p2
		points[3] = p3
		points[4] = p4
	*/
	virtual void plot_camera(vector<vector<float> > &points) = 0;
	
	virtual void plot_frames() = 0;
	virtual void add_frames(vector<vector<float> > &points) = 0;
	virtual void clear_frames() = 0;
	
    virtual void plot_points() = 0;
	virtual void add_points(vector<float> &points) = 0;
	virtual void clear_points() = 0;
	
	virtual void plot_lines() = 0;
	virtual void add_lines(vector<vector<float> > &points) = 0;
	virtual void clear_lines() = 0;
	
	//ViewerParameter param;
}; 

} // namespace uslam

#endif