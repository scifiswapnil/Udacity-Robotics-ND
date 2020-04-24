[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# Where Am I
This is the submissions repository for the Robotics NanoDegree(ND-209) course at Udacity. Following you will find folder-wise projects submitted during the course. This is an ongoing course that will continue till May 2020.

# Specification 

* ROS Package containing AMCL, teleop, robot, world and map files
* Screenshot(s) of localized robot in RViz
* Student's simulation setup should have the appropriate number of landmarks or geometric features to perform localization.
* Student's launch file contains all required nodes:
* Map Server node map_server
* AMCL node amcl
* Move Base node move_base
* The student's program should be able to launch without errors
* Student's robot could quickly localize itself after being tele-operated in the student's world, or given nav_goal target.


### Folder contents

* [Where-Am-I](https://github.com/scifiswapnil/Udacity-Robotics-ND/tree/master/Where-Am-I)
    * catkin_ws 
        * src 
            * pgm_map_creator - pgm_map_creator package
                * maps - contains updated map
                * world - contains updated world
            * my_robot - robot model and gazebo world
                * world - contains gazebo world file
                * models - contains mesh models
                * launch 
                    * movebase.launch - movebase params and node
                    * mapserver.launch - mapserver params and node
                    * amcl.launch - - amcl params and node
                    * world.launch - primary launch file
                    * robot_description.launch - robot description
    * screenshots - assignment screenshots
            

### Installation 

* Where-Am-I

   **Note** : Install the dependencies using following command 
    ```
    sudo apt-get install libignition-math2-dev protobuf-compiler ros-kinetic-navigation ros-kinetic-map-server ros-kinetic-move-base ros-kinetic-amcl
    ```
   
   __Terminal one__:
   ```
   cd ~/Udacity-Robotics-ND/Where-Am-I/catkin_ws
   catkin_make
   source devel/setup.bash
   roslaunch my_robot world.launch
   ```
   __Terminal two__:
   ```
   cd ~/Udacity-Robotics-ND/Where-Am-I/catkin_ws
   source devel/setup.bash
   roslaunch my_robot teleop.launch
   ```


