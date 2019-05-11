#ifndef __TRANSPORTER_H__
#define __TRANSPORTER_H__

#include "image_data.hpp"

#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>

#include <opencv2/opencv.hpp>

class Transporter{
public:
	explicit Transporter(ImageData *IData);
	~Transporter();
	void transport(const sensor_msgs::ImageConstPtr& msg);
	void run(int argc, char **argv);
private:
	ImageData *IData;
};

#endif