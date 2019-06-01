#ifndef __FACTORY_PARAMETER__
#define __FACTORY_PARAMETER__

namespace uslam {
	
class ViewerParameter {
public:
	ViewerParameter(): argc(0), argv(NULL) {}
	// for ros::init(argc, argv, "xxx")
	int argc;
	char **argv;
	// viewer type, such as Rviz, Pangolin
	std::string type;
};
	
} // namespace uslam

#endif