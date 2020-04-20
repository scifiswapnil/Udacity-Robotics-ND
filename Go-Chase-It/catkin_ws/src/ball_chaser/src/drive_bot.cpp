
#include <drive_bot.h>

drive_bot::drive_bot()
{
    motor_command_publisher = n.advertise<geometry_msgs::Twist>("/my_robot/cmd_vel", 10);
    service = n.advertiseService("/ball_chaser/command_robot", &drive_bot::command_executor, this);
}

drive_bot::~drive_bot()
{
}

bool drive_bot::command_executor(ball_chaser::DriveToTarget::Request &req,
                                 ball_chaser::DriveToTarget::Response &resp)
{
    ROS_INFO_STREAM("service callback");
    geometry_msgs::Twist cmd;
    cmd.linear.x = req.linear_x;
    cmd.angular.z = req.angular_z;
    motor_command_publisher.publish(cmd);
    resp.msg_feedback = to_str(req.linear_x) + "," + to_str(req.angular_z);
    return true;
}

int main(int argc, char **argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");
    drive_bot db;
    ros::spin();

    return 0;
}