#include "rviz_viewer_bridge.hpp"
#include "parameters.hpp"

namespace uslam {
/*	
class RvizViewer: public RvizViewerBridge {
public:
	explicit RvizViewer(const ViewerParameter &param);
	// do nothing
};	
*/

class RvizViewer: public Viewer {
public:
	explicit RvizViewer(const ViewerParameter &param);
	
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
	RvizViewerBridge *rviz_viewer_bridge;	
};
	
} // namespace uslam