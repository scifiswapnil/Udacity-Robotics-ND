[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# Go Chase It 

This project is about development of a robot with gazebo plugins that can track and follow a white colored ball in the gazebo world. 

### Folder contents

* [Go-Chase-It](https://github.com/scifiswapnil/Udacity-Robotics-ND/tree/master/Go-Chase-It)
    * catkin_ws 
        * src 
            * ball_chaser - package for ball chasing codes
            * my_robot - robot model and gazebo world           
            
### Screenshots 

Gazebo World         |  Gazebo robot model
:-------------------------:|:-------------------------:
![](https://github.com/scifiswapnil/Udacity-Robotics-ND/blob/master/Go-Chase-It/pictures/robot1.png)  |  ![](https://github.com/scifiswapnil/Udacity-Robotics-ND/blob/master/Go-Chase-It/pictures/ball_follower.png)

### Tasks 

* Robot model 
    * Lidar and camera sensors.
    * Gazebo plugins for the robot’s differential drive, lidar, and camera.
    * Housed inside the world
    * Significant changes from the sample taught in the project lesson.
    * Robot is stable when moving

* Gazebo world
    * Same as the world designed in the Build My World project or a new world that you design on the building editor for this project.
    * Includes a white-colored ball

* `drive_bot` requirements:
    * A ball_chaser/command_robot service.
    * Service accepts linear x and angular z velocities.
    * Service publishes to the the wheel joints.
    * Service returns the requested velocities.

* `process_image` requirements:
    * Subscribes to the robot’s camera image.
    * A function to analyze the image and determine the presence and position of a white ball.
    * Requests a service to drive the robot towards a white ball (when present).


* `world.launch` requirements:
    * Launch the world (which includes a white ball).
    * Launch the robot.

* `ball_chaser.launch` requirements:
    * Run the drive_bot C++ node.
    * Run the process_image C++ node.

### Installation 

* Go-Chase-It
    ```
    cd ~/Udacity-Robotics-ND/Go-Chase-It/catkin_ws
    catkin_make
    source devel/setup.bash
    export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:~/Udacity-Robotics-ND/Go-Chase-It/catkin_ws/src/my_robot/models/
    roslaunch my_robot world.launch &
    roslaunch ball_chaser ball_chaser.launch
    ```