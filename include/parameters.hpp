#ifndef __FACTORY_PARAMETER__
#define __FACTORY_PARAMETER__

// TODO: read config from FILE.cfg by using boost::program_options
namespace uslam {
	
class CameraParameter {
	// camera frames per second
	float fps;
	// image size
	unsigned int image_width;
	unsigned int image_height;
	unsigned int image_channel;
	// camera calibration parameters
	float fu;
	float fv;
	float u0;
	float v0;
	// camera distortion parameters
	float k1;
	float k2;
	float p1;
	float p2;
}; // CameraParameter

class ViewerParameter {
public:
	ViewerParameter(): argc(0), argv(NULL) {}
	// camera size
	float camera_size;
	// point size
	float point_size;
	// frame size
	float frame_size;
	// line width
	float line_width;
	// for ros::init(argc, argv, "xxx")
	int argc;
	char **argv;
	// viewer type, such as Rviz, Pangolin
	std::string type;
	// frames per second
	float fps;
	// image size
	unsigned int image_width;
	unsigned int image_height;
	unsigned int image_channel;
	// for pangolin: window size
	unsigned int window_width;
	unsigned int window_height;
	// for pangolin: project matrix
	float fu;
	float fv;
	float u0;
	float v0;
	float zmin;
	float zmax;
	float pointx;
	float pointy;
	float pointz;
	
}; // ViewerParameter

class DetectorParameter {
public:
	DetectorParameter(): param(NULL) {}	
	std::string name;
	std::string type;
	// FASTDetectorParameter * and so on.
	void *param;
	std:: string file_name;
	
	std::map<std::string, std::string> params_;
	
}; // class DetectorParameter

class FASTDetectorParameter {
public:
	FASTDetectorParameter(): grid_size(16), grid_x(0), grid_y(0) {}
	// default grid_size = 16
	unsigned int grid_size;
	unsigned int grid_x;
	unsigned int grid_y;
	
	CameraParameter *camera;
}; // class FASTDetectorParameter

class DescriptorParameter {
public:
	std::string name;
	std::string type;
	// manager descriptor parameters
	std::map<std::string, std::string> params_;
	
}; // class DescriptorParameter

class MatcherParameter {
public:
	std::string name;
	std::string type;
	// manager descriptor parameters
	std::map<std::string, std::string> params_;
	
}; // class DescriptorParameter
	
} // namespace uslam

#endif