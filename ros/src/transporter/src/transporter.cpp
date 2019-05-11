#include "transporter.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "image_transport");
	
	Transporter transporter = 
	
    ros::NodeHandle nodeHandler;
    ros::Subscriber sub = nodeHandler.subscribe("/camera/image_raw", 1, &transporter);

    ros::spin();
}

