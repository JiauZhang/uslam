#ifndef __TRANSPORTER_H__
#define __TRANSPORTER_H__

#include "image_data.hpp"

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>

#include <opencv2/opencv.hpp>

class Transporter{
public:
	explicit Transporter(ImageData &IData);
	~Transporter();
	void transport(const sensor_msgs::ImageConstPtr& msg);
	void run();
private:
	ImageData &IData;
};

Ttransporter::Ttransporter(ImageData &IData) {
	this->IData = IData;
}

void Ttransporter::transport(const sensor_msgs::ImageConstPtr& msg)
{
    ImageData &IData = ImageData::getInstance();
    IData.image_data_mutex.lock();
	
    cv_bridge::CvImageConstPtr cv_ptr;
    try
    {
        cv_ptr = cv_bridge::toCvShare(msg);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("cv_bridge exception: %s", e.what());
        return;
    }

    ROS_ASSERT(cv_ptr->image.channels()==3 || cv_ptr->image.channels()==1);

    cv_ptr->image.copyTo(IData.image);
	
    IData.image_data_mutex.unlock();
}

void Ttransporter::run(int argc, char **argv)
{
    ros::init(argc, argv, "image_transport");
	
    ros::NodeHandle nodeHandler;
    ros::Subscriber sub = nodeHandler.subscribe("/camera/image_raw", 1, &transport);

    ros::spin();
}

#endif