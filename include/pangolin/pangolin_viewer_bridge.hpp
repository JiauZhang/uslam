#ifndef __INIT_H__
#define __INIT_H__

#include "viewer.hpp"
#include "viewer_factoty.hpp"
#include "parameters.hpp"

namespace uslam {

class PangolinViewerBridge: public Viewer
{
public:
	explicit PangolinViewerBridge(const ViewerParameter &param);
						
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
};

} // namespace uslam

#endif // __INIT_H__