#include "pangolin_viewer_bridge.hpp"
#include "parameters.hpp"

namespace uslam {
	
class PangolinViewer: public Viewer {
public:
	explicit PangolinViewer(const ViewerParameter &param);
	
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
	PangolinViewerBridge *pangolin_viewer_bridge;
};	
	
} // namespace uslam
