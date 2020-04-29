#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <visualization_msgs/Marker.h>

class Marker {
private:
    ros::NodeHandle n;
    ros::Publisher marker_pub;
    ros::Subscriber odom_sub;
    visualization_msgs::Marker marker;
    double pickup[2] =  {-2.0, 0.0};
    double dropoff[2] = {0.0, 0.0};
    bool goal_reached;

	const int threshold_multiplier = 3;

public:
    Marker() 
    {
        marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
        odom_sub = n.subscribe("/odom", 1, &Marker::odomCallback, this);

        while (marker_pub.getNumSubscribers() < 1) {
            ROS_WARN_ONCE("Please create a subscriber to the marker");
            sleep(1);
        }   
        goal_reached = false;
        marker.header.frame_id = "map";
        marker.header.stamp = ros::Time::now();
        marker.ns = "add_markers";
        marker.id = 0;
        marker.type = visualization_msgs::Marker::CUBE;
        marker.action = visualization_msgs::Marker::ADD;
        marker.scale.x = 0.25;
        marker.scale.y = 0.25;
        marker.scale.z = 0.25;
        marker.color.r = 1.0f;
        marker.color.g = 0.0f;
        marker.color.b = 0.0f;
        marker.color.a = 1.0;
        marker.pose.position.x = pickup[0]+0.15;
        marker.pose.position.y = pickup[1];
        marker.lifetime = ros::Duration();
		marker_pub.publish(marker);

    }

    void odomCallback(const nav_msgs::Odometry::ConstPtr &msg) 
    {
        double goal_dist = ( sqrtf( std::pow( ( pickup[0]  - msg->pose.pose.position.x ),2.0 ) + std::pow( ( pickup[1]  - msg->pose.pose.position.y ),2.0 ) ) );
        double home_dist = ( sqrtf( std::pow( ( dropoff[0] - msg->pose.pose.position.x ),2.0 ) + std::pow( ( dropoff[1] - msg->pose.pose.position.y ),2.0 ) ) );
        if (goal_dist < 0.25)
        {
            goal_reached = true;
            sleep(2);
            marker.action = visualization_msgs::Marker::DELETE;
            marker_pub.publish(marker);
        }
        if (home_dist < 0.25 && goal_reached)
        {
            marker.action = visualization_msgs::Marker::ADD;
            marker.pose.position.x = dropoff[0]-0.15;
            marker.pose.position.y = dropoff[1];
            sleep(2);
            marker_pub.publish(marker);
        }

    }
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "add_markers");

    Marker Marker;
    ros::spin();

    return 0;
}
