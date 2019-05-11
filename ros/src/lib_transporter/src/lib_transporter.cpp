#include "transporter.hpp"

Transporter::Transporter(ImageData *IData) {
	this->IData = IData;
}

void Transporter::transport(const sensor_msgs::ImageConstPtr& msg)
{
    //ImageData &IData = ImageData::getInstance();
    IData->image_data_mutex.lock();
	
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

    cv_ptr->image.copyTo(IData->image);
	
    IData->image_data_mutex.unlock();
}

void Transporter::run(int argc, char **argv)
{
    ros::init(argc, argv, "image_transport");
	
    ros::NodeHandle nodeHandler;
    ros::Subscriber sub = nodeHandler.subscribe("/camera/image_raw", 1, &Transporter::transport, this);

    ros::spin();
}