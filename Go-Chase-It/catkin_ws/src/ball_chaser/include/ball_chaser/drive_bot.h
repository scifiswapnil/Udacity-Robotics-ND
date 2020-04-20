#ifndef BALL_CHASER_DRIVE_BOT_H
#define BALL_CHASER_DRIVE_BOT_H

#include "ros/ros.h"
#include <ros/console.h>
#include "geometry_msgs/Twist.h"
#include <ball_chaser/DriveToTarget.h>

template <typename Type>
std::string to_str(const Type &t)
{
    std::ostringstream os;
    os << t;
    return os.str();
}

class drive_bot
{
private:
    ros::NodeHandle n;
    ros::Publisher motor_command_publisher;
    ros::ServiceServer service;

public:
    drive_bot();
    ~drive_bot();
    bool command_executor(ball_chaser::DriveToTarget::Request &req, ball_chaser::DriveToTarget::Response &resp);
};

#endif //  BALL_CHASER_DRIVE_BOT_H