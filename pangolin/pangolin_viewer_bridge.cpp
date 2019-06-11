#include "pangolin_viewer_bridge.hpp"

namespace uslam {

PangolinViewerBridge::PangolinViewerBridge(const ViewerParameter &param)
{
	pangolin::CreateWindowAndBind("Pangolin Viewer", param.window_width, param.window_height);
	
	// 3D Mouse handler requires depth testing to be enabled
    glEnable(GL_DEPTH_TEST);

    // Issue specific OpenGl we might need
    glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// bound: vertical(0.0, 1.0) horizontal(0.0, pixes)
	pangolin::CreatePanel("menu").SetBounds(0.0,1.0,0.0,pangolin::Attach::Pix(175));
    pangolin::Var<bool> menuFollowCamera("menu.Follow Camera",true,true);
    pangolin::Var<bool> menuShowPoints("menu.Show Points",true,true);
    pangolin::Var<bool> menuShowKeyFrames("menu.Show KeyFrames",true,true);
    pangolin::Var<bool> menuShowGraph("menu.Show Graph",true,true);
    pangolin::Var<bool> menuLocalizationMode("menu.Localization Mode",false,true);
    pangolin::Var<bool> menuReset("menu.Reset",false,false);

    // Define Camera Render Object (for view / scene browsing)
    pangolin::OpenGlRenderState s_cam(
		pangolin::ProjectionMatrix(param.window_width,param.window_height,param.fu, param.fv,
								   param.window_width / 2, param.window_height / 2, param.zmin, param.zmax),
		pangolin::ModelViewLookAt(param.pointx , param.pointy, param.pointz, 0, 0, 0, 0.0, -1.0, 0.0)
    );

    // Add named OpenGL viewport to window and provide 3D Handler
    pangolin::View& d_cam = pangolin::CreateDisplay()
		.SetBounds(0.0, 1.0, pangolin::Attach::Pix(175), 1.0, -param.window_width / (float)param.window_height)
		.SetHandler(new pangolin::Handler3D(s_cam)
	);

    pangolin::OpenGlMatrix Twc;
	Twc.SetIdentity();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	this->param = &param;
}

void PangolinViewerBridge::plot_camera(vector<vector<float> > &points)
{	
	glColor3f(0.0, 1.0, 0.0);
	
	glLineWidth(param->line_width);
	glBegin(GL_LINES);
	
	// optical center
	glVertex3f(points[0][0], points[0][1], points[0][2]);
	// p1
	glVertex3f(points[1][0], points[1][1], points[1][2]);
	// optical center
	glVertex3f(points[0][0], points[0][1], points[0][2]);
	// p2
	glVertex3f(points[2][0], points[2][1], points[2][2]);
	// optical center
	glVertex3f(points[0][0], points[0][1], points[0][2]);
	// p3
	glVertex3f(points[3][0], points[3][1], points[3][2]);
	// optical center
	glVertex3f(points[0][0], points[0][1], points[0][2]);
	// p4
	glVertex3f(points[4][0], points[4][1], points[4][2]);
	
	// p1
	glVertex3f(points[1][0], points[1][1], points[1][2]);
	// p2
	glVertex3f(points[2][0], points[2][1], points[2][2]);
	// p2
	glVertex3f(points[2][0], points[2][1], points[2][2]);
	// p3
	glVertex3f(points[3][0], points[3][1], points[3][2]);
	// p3
	glVertex3f(points[3][0], points[3][1], points[3][2]);
	// p4
	glVertex3f(points[4][0], points[4][1], points[4][2]);
	// p4
	glVertex3f(points[4][0], points[4][1], points[4][2]);
	// p1
	glVertex3f(points[1][0], points[1][1], points[1][2]);
	
	glEnd();
}
     
void PangolinViewerBridge::plot_frames()
{
	
}

void PangolinViewerBridge::add_frames(vector<vector<float> > &points)
{
	
}

void PangolinViewerBridge::clear_frames()
{
	
}
     
void PangolinViewerBridge::plot_points()
{
	
}

void PangolinViewerBridge::add_points(vector<float> &points)
{
	
}

void PangolinViewerBridge::clear_points()
{
	
}

} // namespace uslam