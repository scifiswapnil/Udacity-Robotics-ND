#include <process_image.h>

process_image::process_image()
{
    ros::service::waitForService("/ball_chaser/command_robot");
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");
    sub1 = n.subscribe<sensor_msgs::Image>("/my_robot/camera/color/image_raw", 10, &process_image::process_image_callback, this);
}

process_image::~process_image()
{
}

// This function calls the command_robot service to drive the robot in the specified direction
void process_image::drive_robot(float lin_x, float ang_z)
{
    ball_chaser::DriveToTarget cmd_data;
    cmd_data.request.linear_x = lin_x;
    cmd_data.request.angular_z = ang_z;
    if (client.call(cmd_data))
    {
        ROS_INFO_STREAM(" command_robot called");
    }
    else
    {
        ROS_INFO_STREAM("command_robot call failed");
    }
}

// This callback function continuously executes and reads the image data
void process_image::process_image_callback(const sensor_msgs::Image img)
{

    int white_pixel = 255;
    float white_moment = -1;
    float num_white_pixels = 0;
    ROS_INFO_STREAM("image callback");
    for (int i = 0; i < img.height; i++)
    {
        for (int j = 0; j < img.step; j++)
        {
            if (img.data[i * img.step + j] == white_pixel && img.data[i * img.step + j + 1] == white_pixel && img.data[i * img.step + j + 2] == white_pixel)
            {
                white_moment = white_moment + j - img.step / 2.0;
                num_white_pixels = num_white_pixels + 1.0;
            }
        }
    }
    white_moment = white_moment / num_white_pixels;
    if (num_white_pixels > 0)
    {
        drive_robot(0.5, -3.0 / img.step * white_moment);
    }
    else
    {
        drive_robot(0, 0);
    }
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "process_image");
    process_image pi;
    ros::spin();
    return 0;
}