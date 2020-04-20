# Udacity-Robotics-ND
This is the submissions repository for the Robotics NanoDegree(ND-209) course at Udacity. Following you will find folder-wise projects submitted during the course. This is an ongoing course that will continue till May 2020.

### Folder contents
* [Build-My-World](https://github.com/scifiswapnil/Udacity-Robotics-ND/tree/master/Build-My-World)
* [Go-Chase-It](https://github.com/scifiswapnil/Udacity-Robotics-ND/tree/master/Go-Chase-It)

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