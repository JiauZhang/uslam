#ifndef __RVIZ_VIEWER__
#define __RVIZ_VIEWER__

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <opencv2/core/core.hpp>

#include "viewer.hpp"
#include "common.hpp"
#include "parameters.hpp"

namespace uslam {

class ViewerParameter;
class Viewer;
	
class RvizViewerBridge: public Viewer {
public:
	//explicit RvizViewer(float camera_size=0.04, float point_size=0.01, float frame_size=0.04);
	//explicit RvizViewer(int argc, char **argv, 
	//					float camera_size, float point_size, float frame_size);
	explicit RvizViewerBridge(const ViewerParameter &param);
						
	void plot_camera(vector<vector<float> > &points);
	
	void plot_frames();
	void add_frames(vector<vector<float> > &points);
	void clear_frames();
	
    void plot_points();
	void add_points(vector<float> &points);
	void clear_points();
	
	void plot_lines() {};
	void add_lines(vector<vector<float> > &points) {};
	void clear_lines() {};
	
private:	
	//float camera_size;
	//float point_size;
	//float frame_size;

	//ros::NodeHandle nh;
	// You must call ros::init() before creating the first NodeHandle
	// so nh only can instance in member function and static
    ros::Publisher publisher;

    visualization_msgs::Marker VCamera;
    visualization_msgs::Marker VPoints;
    visualization_msgs::Marker VFrames;
};

} // namespace uslam


#endif