[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# Build My World

### Folder contents

* [Build-My-World](https://github.com/scifiswapnil/Udacity-Robotics-ND/tree/master/Build-My-World)
    * model - gazebo building and model files
    * script - simple gazebo plugin files
    * world - gazebo world files

### Specifications 

* Building 
    * Structure is different than the one shown in the sample simulation world.
    * Single floor.
    * Enough space for robots to navigate.
    * At least one feature.
    * At least one color.
* Model Requirements 
    * Object is different than the one shown in the sample simulation world.
    * Object links are connected through joints. 
* Gazebo World
    * World is different than the one shown in the sample simulation world.
    * Contains the structure model.
    * Contains two instances of the object model.
    * Contains one model from the Gazebo online library.
* Plugin Requirement 
    * The plugin C++ code should print “Welcome to Swapnil’s World!” message.

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