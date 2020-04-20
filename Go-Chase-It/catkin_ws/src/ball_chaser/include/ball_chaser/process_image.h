#ifndef BALL_CHASER_PROCESS_IMAGE_H
#define BALL_CHASER_PROCESS_IMAGE_H


#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <geometry_msgs/Twist.h>

class process_image
{
private:
    ros::ServiceClient client;
    ros::Subscriber sub1;
    ros::NodeHandle n;
public:
    process_image();
    ~process_image();
    void process_image_callback(const sensor_msgs::Image img);
    void drive_robot(float lin_x, float ang_z);
};

#endif //  BALL_CHASER_PROCESS_IMAGE_H