#include <boost/thread.hpp>

#include "common.hpp"
#include "viewer.hpp"
#include "viewer_factory.hpp"

using namespace uslam;

void delay(int seconds)
{
	boost::thread::sleep(boost::get_system_time() \
						 + boost::posix_time::seconds(seconds));
}

int main(int argc, char **argv)
{	
	//Viewer *viewer = new RvizViewer(argc, argv);
	
	ViewerParameter param;
	param.argc = argc;
	param.argv = argv;
	param.type = "Rviz";
	
	//std::cout << "type list: \n" << ViewerRegistry::ViewerTypeListString() << std::endl;
	
	static shared_ptr<Viewer> viewer = ViewerRegistry::CreateViewer(param);
	
	if (viewer == NULL)
		return -1;
	
	float d = 0.04;
	bool add = true;
	unsigned int iters = 0;
	
	while (iters++ <= 15) {
		vector<vector<float> > points;
		vector<float> temp;
		temp.push_back(0.0);
		temp.push_back(0.0);
		temp.push_back(0.0);
		points.push_back(temp);
		temp.clear();
		temp.push_back(d);
		temp.push_back(d*0.8);
		temp.push_back(d*0.5);
		points.push_back(temp);
		temp.clear();
		temp.push_back(d);
		temp.push_back(-d*0.8);
		temp.push_back(d*0.5);
		points.push_back(temp);
		temp.clear();
		temp.push_back(-d);
		temp.push_back(-d*0.8);
		temp.push_back(d*0.5);
		points.push_back(temp);
		temp.clear();
		temp.push_back(-d);
		temp.push_back(d*0.8);
		temp.push_back(d*0.5);
		points.push_back(temp);
		temp.clear();
		
		viewer->plot_camera(points);
		
		if (add) {
			d += 0.005;
			if (d > 0.1)
				add = false;
		} else {
			d -= 0.005;
			if (d < 0.04)
				add = true;
		}

		std::cout << "iters: " << iters << std::endl;
		
		delay(1);
	}
	
	
	return 0;
}
