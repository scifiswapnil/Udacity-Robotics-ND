#!/bin/sh
cd $(pwd)/../..; catkin_make


export TURTLEBOT_GAZEBO_WORLD_FILE=$(pwd)/src/worlds/home_service.world

xterm  -e  " source devel/setup.bash; roscore " &
sleep 2
xterm  -e  " source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch"  & 
sleep 5
xterm  -e  " source devel/setup.bash; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=/home/robond/Udacity-Robotics-ND/Home-Service-Robot/catkin_ws/src/map/map.yaml" &
sleep 2
xterm  -e  " source devel/setup.bash; roslaunch add_markers rviz.launch" &
sleep 2
xterm  -e  " source devel/setup.bash; rosrun pick_objects pick_objects_node " &
sleep 2
xterm  -e  " source devel/setup.bash; rosrun add_markers add_markers_node " &