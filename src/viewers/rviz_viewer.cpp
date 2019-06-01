#include "rviz_viewer.hpp"
#include <iostream>
#include <exception>      // std::exception

namespace uslam {
	
RvizViewer::RvizViewer(const ViewerParameter &param) 
{
	try {
		rviz_viewer_bridge = new RvizViewerBridge(param);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
}

void RvizViewer::plot_camera(vector<vector<float> > &points)
{
	rviz_viewer_bridge->plot_camera(points);
}

void RvizViewer::plot_frames()
{
	rviz_viewer_bridge->plot_frames();
}

void RvizViewer::add_frames(vector<vector<float> > &points)
{
	rviz_viewer_bridge->add_frames(points);
}

void RvizViewer::clear_frames()
{
	rviz_viewer_bridge->clear_frames();
}

void RvizViewer::plot_points()
{
	rviz_viewer_bridge->plot_points();
}

void RvizViewer::add_points(vector<float> &points)
{
	rviz_viewer_bridge->add_points(points);
}

void RvizViewer::clear_points()
{
	rviz_viewer_bridge->clear_points();
}

REGISTER_VIEWER_CLASS(Rviz);	
	
} // namespace uslam