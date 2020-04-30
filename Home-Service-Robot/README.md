[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# Map My World

This is the final project for the robotics nanodegree program, which tests all the learnings from the course.  Objective of the project is to develop a code that allows turtlebot to be used a home service robot in a simulation, which has capability to map, localize and perform path planning, 


### Tasks 
* Student's simulation world and robot could properly load in Gazebo.
* The student should write a test_slam.sh script file and launch it to manually test SLAM.
* Student created a functional map of the environment which would be used for localization and navigation tasks.
* The student's robot could navigate in the environment after a 2D Nav Goal command is issued. The student created a test_navigation.sh script file to launch it for manual navigation test.
* "The student created a pick_objects.sh file that will send multiple goals for the robot to reach. The robot travels to the desired pickup zone, displays a message that it reached its destination, waits 5 seconds, travels to the desired drop off zone, and displays a message that it reached the drop off zone."
* The student should write a add_marker.sh file that will publish a marker to rviz. The marker should initially be published at the pickup zone. After 5 seconds it should be hidden. Then after another 5 seconds it should appear at the drop off zone.
* The student should write a home_service.sh file that will run all the nodes in this project.
  * The student's home service robot should be simulated as follow:
  * Initially show the marker at the pickup zone.
  * Hide the marker once your robot reach the pickup zone.
  * Wait 5 seconds to simulate a pickup.
  * Show the marker at the drop off zone once your robot reaches it.

### Folder contents

 * catkin_ws 
     * src 
        * add_markers - package for marker visualization.
        * gmapping - gmapping package for mapping (git submodule) 
        * map - collected maps.
        * pick_objects - package for publishing move base goals 
        * rvizConfig - rviz config files
        * scripts - scripts to run the codes and simulation 
          * add_marker.sh - for visualizing markers in rviz
          * home_service.sh - for complete end-to-end simulation 
          * pick_objects.sh - for mutliple move base goal publishing 
          * test_navigation.sh - for starting the simulation world with robot, movebase and teleop
          * test_slam.sh - for testing mapping and localization with teleop
        * turtlebot - turtlebot dep. (git submodule)
        * turtlebot_gazebo - turtlebot gazebo simulation (git submodule)
        * turtlebot_interaction - turtlebot rviz and other files for visualization (git submodule)
        * world - for gazebo world files
 * pictures - assignment screenshots
            
### Screenshots 

Gazebo World         |  rviz visualization
:-------------------------:|:-------------------------:
![](https://github.com/scifiswapnil/Udacity-Robotics-ND/blob/master/Home-Service-Robot/pictures/homeserviceworld.png)  |  ![](https://github.com/scifiswapnil/Udacity-Robotics-ND/blob/master/Home-Service-Robot/pictures/homeservicerviz.png)

### Installation 

**Note :** *Need to install Dependencies before use and follow the installation instructions for getting the submodules in the workspace*

Dependencies

```
   sudo apt update
   sudo apt upgrade
   sudo apt install xterm
   sudo apt install ros-kinetic-map-server  ros-kinetic-move-base ros-kinetic-navigation ros-kinetic-amcl 
   sudo apt install ros-kinetic-gazebo-ros-control ros-kinetic-joint-state ros-kinetic-joint-state-controller ros-kinetic-effort-controllers 
   sudo apt install ros-kinetic-velocity-controllers ros-kinetic-openslam-gmapping ros-kinetic-joy 
   sudo apt install ros-kinetic-yocs-*
   sudo apt install ros-kinetic-kobuki*
```

Build the workspace after installation of dependencies : 

```
git clone --recurse-submodules https://github.com/scifiswapnil/Udacity-Robotics-ND.git
cd ~/Udacity-Robotics-ND/Home-Service-World/catkin_ws
catkin_make
source devel/setup.bash
```
For complete simulation :

``` 
cd src/scripts
./home_service.sh
```

for visualizing markers in rviz :

``` 
cd src/scripts
./add_marker.sh
```

for mutliple move base goal publishing :

``` 
cd src/scripts
./pick_objects.sh 
```

for starting the simulation world with robot, movebase and teleop

``` 
cd src/scripts
./test_navigation.sh 
```

for testing mapping and localization with teleop:

``` 
cd src/scripts
./test_slam.sh 
```

