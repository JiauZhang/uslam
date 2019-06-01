#include <iostream>
#include <cstring>
#include <string>

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
	
	const std::string image_path("./selfdriving.jpg");
	cv::Mat image = cv::imread(image_path.c_str());
	
	char key; 
	cv_bridge::CvImage out_msg; 
	ros::Rate loop_rate(1); 

	while (nh.ok() && key != 27) { 
			out_msg.header.stamp = ros::Time::now(); 
			out_msg.encoding = sensor_msgs::image_encodings::BGR8; 
			out_msg.image = image; 
			pub.publish(out_msg.toImageMsg()); 

			cv::imshow("image", out_msg.image); 

			key = cv::waitKey(1); 
			loop_rate.sleep(); 
	} 
	return 0;
}








