[![Udacity - Robotics NanoDegree Program](https://s3-us-west-1.amazonaws.com/udacity-robotics/Extra+Images/RoboND_flag.png)](https://www.udacity.com/robotics)

# Map My World
This project is about creating a 2D occupancy grid and 3D octomap from a simulated environment using our own robot with the RTAB-Map package.


### Tasks 
* Student's map should contain at least 3 loop closures and the occupancy grid is identifiable
* ROS Package: robot and RTABMAP
* Db file generated (could be link to file if oversized)

### Folder contents

 * catkin_ws 
     * src 
         * my_robot - robot model and gazebo world
             * worlds - contains gazebo world file
             * models - contains mesh models
             * maps - Collected maps 
             * rviz - rviz configuration file
             * config - pkg configuration files
             * launch 
                 * movebase.launch - movebase params and node
                 * mapserver.launch - mapserver params and node
                 * amcl.launch - - amcl params and node
                 * world.launch - primary launch file
                 * robot_description.launch - robot description
                 * localization.launch - RTABMAP for localization 
                 * mappging.launch - RTABMAP for mapping 
                 * rtabmap_viz.launch - RTABMAP visualizer  
 * pictures - assignment screenshots
            
### Screenshots 

Basic Gazebo World         |  Mapped using RTABMAP
:-------------------------:|:-------------------------:
![](https://github.com/scifiswapnil/Udacity-Robotics-ND/blob/master/Map-My-World/pictures/world_gazebo.png)  |  ![](https://github.com/scifiswapnil/Udacity-Robotics-ND/blob/master/Map-My-World/pictures/world_map_3d.png)

Gazebo World with loops    |  Mapped using RTABMAP
:-------------------------:|:-------------------------:
![](https://github.com/scifiswapnil/Udacity-Robotics-ND/blob/master/Map-My-World/pictures/loop_world_gazebo.png)  |  ![](https://github.com/scifiswapnil/Udacity-Robotics-ND/blob/master/Map-My-World/pictures/loop_world_map_3d.png)

### RTABMAP database files 

Basic gazebo World : [Google Drive link](https://drive.google.com/file/d/1-AN5KGv-7xNWNLgWHd8p9uzGiajlNyih/view?usp=sharing)

Gazebo World with loops : [Google Drive link](https://drive.google.com/file/d/1ZY6xa8jYTW083mPvd_phDHyVDWCJNyIT/view?usp=sharing)

**Note :** *Recommended to download the files, rename to rtabmap.db and paste in "~/Udacity-Robotics-ND/Map-My-World/catkin_ws/src/my_robot/map" to avoid changes in launch files*

### Installation and execution

**Note :** *Need to install Dependencies before use.*

Dependencies

``` sudo apt install ros-kinetic-rtabmap ros-kinetic-rtabmap-ros```

Build the workspace after installation of dependencies : 

```
cd ~/Udacity-Robotics-ND/Map-My-World/catkin_ws
catkin_make
source devel/setup.bash
```

For Mapping :

``` 
roslaunch my_robot mapping.launch
```

For Localization : 

``` 
roslaunch my_robot localization.launch
```
For teleop :

``` 
roslaunch my_robot teleop.launch
```

