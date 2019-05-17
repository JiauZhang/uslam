#include <iostream>
#include <cstring>
#include <string>
#include <vector>

#include <ros/ros.h> 
#include <image_transport/image_transport.h> 
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp> 
#include <cv_bridge/cv_bridge.h> 

using namespace std;
using namespace cv;

int main(int argc, char** argv) 
{
	ros::init(argc, argv, "image_publisher"); 
	ros::NodeHandle nh; 
	image_transport::ImageTransport it(nh); 
	image_transport::Publisher pub = it.advertise("/camera/image_raw", 1);
	
	int count = 0;
	vector<std::string> image_path;
	image_path.push_back("1.png");
	image_path.push_back("2.png");
	
	char key; 
	cv_bridge::CvImage out_msg; 
	ros::Rate loop_rate(1); 

	while (nh.ok() && key != 27) { 
		cv::Mat image = cv::imread(image_path[count].c_str());
		out_msg.header.stamp = ros::Time::now(); 
		out_msg.encoding = sensor_msgs::image_encodings::BGR8; 
		out_msg.image = image; 

		count++;
		if (count > 1)
			count = 0;

		cv::imshow("image_raw", image); 

		pub.publish(out_msg.toImageMsg()); 

		key = cv::waitKey(1); 
		loop_rate.sleep(); 
	} 
	return 0;
}








