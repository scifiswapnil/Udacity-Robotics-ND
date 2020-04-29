#!/bin/sh
cd $(pwd)/../..; catkin_make

export TURTLEBOT_GAZEBO_WORLD_FILE=$(pwd)/src/worlds/home_service.world

xterm  -e  " source devel/setup.bash; roscore " &
sleep 2
xterm  -e  " source devel/setup.bash; roslaunch turtlebot_gazebo turtlebot_world.launch"  & 
sleep 5
xterm  -e  " source devel/setup.bash; roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 2
xterm  -e  " source devel/setup.bash; roslaunch turtlebot_rviz_launchers view_teleop_navigation.launch" 