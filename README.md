[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# Udacity-Robotics-ND
This is the submissions repository for the Robotics NanoDegree(ND-209) course at Udacity. Following you will find folder-wise projects submitted during the course. This is an ongoing course that will continue till May 2020.


### Folder contents
* [Build-My-World](https://github.com/scifiswapnil/Udacity-Robotics-ND/tree/master/Build-My-World)
* [Go-Chase-It](https://github.com/scifiswapnil/Udacity-Robotics-ND/tree/master/Go-Chase-It)
    * catkin_ws 
        * src 
            * ball_chaser - package for ball chasing codes
            * my_robot - robot model and gazebo world
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
* Build-My-world 
    ```
    cd ~/Udacity-Robotics-ND/Build-My-Work/
    mkdir build
    cmake .. 
    make
    export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:~/Udacity-Robotics-ND/Build-My-Work/build
    export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:~/Udacity-Robotics-ND/Build-My-Work/model
    ```
* Go-Chase-It
    ```
    cd ~/Udacity-Robotics-ND/Go-Chase-It/catkin_ws
    catkin_make
    source devel/setup.bash
    export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:~/Udacity-Robotics-ND/Go-Chase-It/catkin_ws/src/my_robot/models/
    roslaunch my_robot world.launch
    roslaunch ball_chaser ball_chaser.launch
    ```
    
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


