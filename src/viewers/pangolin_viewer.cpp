#include "pangolin_viewer.hpp"
#include <iostream>
#include <exception>      // std::exception

namespace uslam {

PangolinViewer::PangolinViewer(const ViewerParameter &param) 
{
	try {
		pangolin_viewer_bridge = new PangolinViewerBridge(param);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}	
}

void PangolinViewer::plot_camera(vector<vector<float> > &points)
{
	pangolin_viewer_bridge->plot_camera(points);
}

void PangolinViewer::plot_frames()
{
	pangolin_viewer_bridge->plot_frames();
}

void PangolinViewer::add_frames(vector<vector<float> > &points)
{
	pangolin_viewer_bridge->add_frames(points);
}

void PangolinViewer::clear_frames()
{
	pangolin_viewer_bridge->clear_frames();
}

void PangolinViewer::plot_points()
{
	pangolin_viewer_bridge->plot_points();
}

void PangolinViewer::add_points(vector<float> &points)
{
	pangolin_viewer_bridge->add_points(points);
}

void PangolinViewer::clear_points()
{
	pangolin_viewer_bridge->clear_points();
}

REGISTER_VIEWER_CLASS(Pangolin);

} // namespace uslam