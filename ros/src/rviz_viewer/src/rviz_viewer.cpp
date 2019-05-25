#include <vector>

#include <boost/thread.hpp>
#include "rviz_viewer.hpp"

void delay(int seconds)
{
	boost::thread::sleep(boost::get_system_time() \
						 + boost::posix_time::seconds(seconds));
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "rviz_viewer");
	
	Viewer *viewer = new RvizViewer(argc, argv);
	
	float d = 0.04;
	bool add = true;
	
	while (1) {
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
		
		delay(1);
	}
	
	
	return 0;
}
