#include "rviz_viewer_bridge.hpp"

//using uslam::RvizViewerBridge;

namespace uslam {

RvizViewerBridge::RvizViewerBridge(const ViewerParameter &param)
{
	int argc = param.argc;
	char **argv = param.argv;
	ros::init(argc, argv, "rviz_viewer");
	static ros::NodeHandle nh;
	
	const char *frame_id = "/uslam/world";
    const char *camera_namespace = "Camera";
	const char *points_namespace = "Points";
	const char *frames_namesapce = "Frames";
		
	//Configure Camera	
    VCamera.header.frame_id = frame_id;
    VCamera.ns = camera_namespace;
    VCamera.id=0;
    VCamera.type = visualization_msgs::Marker::LINE_LIST;
    VCamera.scale.x=0.01;//0.2; 0.03
    VCamera.pose.orientation.w=1.0;
    VCamera.action=visualization_msgs::Marker::ADD;
    VCamera.color.g=1.0f;
    VCamera.color.a = 1.0;

	//Configure KeyFrames
    VFrames.header.frame_id = frame_id;
    VFrames.ns = frames_namesapce;
    VFrames.id=1;
    VFrames.type = visualization_msgs::Marker::LINE_LIST;
    VFrames.scale.x=0.005;
    VFrames.pose.orientation.w=1.0;
    VFrames.action=visualization_msgs::Marker::ADD;
    VFrames.color.b=1.0f;
    VFrames.color.a = 1.0;

	//Configure Points
    VPoints.header.frame_id = frame_id;
    VPoints.ns = points_namespace;
    VPoints.id=2;
    VPoints.type = visualization_msgs::Marker::POINTS;
    VPoints.scale.x=0.01;
    VPoints.scale.y=0.01;
    VPoints.pose.orientation.w=1.0;
    VPoints.action=visualization_msgs::Marker::ADD;
    VPoints.color.a = 1.0;
	
	//Configure Publisher
    publisher = nh.advertise<visualization_msgs::Marker>("uslam/map", 10);

    publisher.publish(VCamera);
    publisher.publish(VFrames);
    publisher.publish(VPoints);
}

void RvizViewerBridge::plot_camera(vector<vector<float> > &points)
{	
	VCamera.points.clear();

	geometry_msgs::Point msgs_o,msgs_p1, msgs_p2, msgs_p3, msgs_p4;
	msgs_o.x = points[0][0];
	msgs_o.y = points[0][1];
	msgs_o.z = points[0][2];
	msgs_p1.x = points[1][0];
	msgs_p1.y = points[1][1];
	msgs_p1.z = points[1][2];
	msgs_p2.x = points[2][0];
	msgs_p2.y = points[2][1];
	msgs_p2.z = points[2][2];
	msgs_p3.x = points[3][0];
	msgs_p3.y = points[3][1];
	msgs_p3.z = points[3][2];
	msgs_p4.x = points[4][0];
	msgs_p4.y = points[4][1];
	msgs_p4.z = points[4][2];

	VCamera.points.push_back(msgs_o);
	VCamera.points.push_back(msgs_p1);
	VCamera.points.push_back(msgs_o);
	VCamera.points.push_back(msgs_p2);
	VCamera.points.push_back(msgs_o);
	VCamera.points.push_back(msgs_p3);
	VCamera.points.push_back(msgs_o);
	VCamera.points.push_back(msgs_p4);
	VCamera.points.push_back(msgs_p1);
	VCamera.points.push_back(msgs_p2);
	VCamera.points.push_back(msgs_p2);
	VCamera.points.push_back(msgs_p3);
	VCamera.points.push_back(msgs_p3);
	VCamera.points.push_back(msgs_p4);
	VCamera.points.push_back(msgs_p4);
	VCamera.points.push_back(msgs_p1);

	VCamera.header.stamp = ros::Time::now();

	publisher.publish(VCamera);
}

void RvizViewerBridge::plot_frames()
{
	VFrames.header.stamp = ros::Time::now();
	publisher.publish(VFrames);
}

void RvizViewerBridge::add_frames(vector<vector<float> > &points)
{
	geometry_msgs::Point msgs_o,msgs_p1, msgs_p2, msgs_p3, msgs_p4;
	msgs_o.x = points[0][0];
	msgs_o.y = points[0][1];
	msgs_o.z = points[0][2];
	msgs_p1.x = points[1][0];
	msgs_p1.y = points[1][1];
	msgs_p1.z = points[1][2];
	msgs_p2.x = points[2][0];
	msgs_p2.y = points[2][1];
	msgs_p2.z = points[2][2];
	msgs_p3.x = points[3][0];
	msgs_p3.y = points[3][1];
	msgs_p3.z = points[3][2];
	msgs_p4.x = points[4][0];
	msgs_p4.y = points[4][1];
	msgs_p4.z = points[4][2];

	VFrames.points.push_back(msgs_o);
	VFrames.points.push_back(msgs_p1);
	VFrames.points.push_back(msgs_o);
	VFrames.points.push_back(msgs_p2);
	VFrames.points.push_back(msgs_o);
	VFrames.points.push_back(msgs_p3);
	VFrames.points.push_back(msgs_o);
	VFrames.points.push_back(msgs_p4);
	VFrames.points.push_back(msgs_p1);
	VFrames.points.push_back(msgs_p2);
	VFrames.points.push_back(msgs_p2);
	VFrames.points.push_back(msgs_p3);
	VFrames.points.push_back(msgs_p3);
	VFrames.points.push_back(msgs_p4);
	VFrames.points.push_back(msgs_p4);
	VFrames.points.push_back(msgs_p1);
}

void RvizViewerBridge::clear_frames()
{
	VFrames.points.clear();
}

void RvizViewerBridge::plot_points()
{
	VPoints.header.stamp = ros::Time::now();
	publisher.publish(VPoints);
}

void RvizViewerBridge::add_points(vector<float> &points)
{
	geometry_msgs::Point p;
	p.x = points[0];
	p.y = points[1];
	p.z = points[2];
	VPoints.points.push_back(p);
}

void RvizViewerBridge::clear_points()
{
	VPoints.points.clear();
}

} // namespace uslam
