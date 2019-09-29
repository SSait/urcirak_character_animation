# urcirak_character_animation

mkdir -p ~/cakin_ws/src
cd ~/catkin_ws
catkin_make
source ˜/caktin_ws/devel/setup.bash


• Launching
Robot visualization with gazebo.
roslaunch urcirak_gazebo urcirak.launch limited:=true gui:=true

Robot visualization with Rviz.
roslaunch urcirak_description urcirak_rviz.launch

Gazebo moveit Rviz interface for motion planning.
roslaunch urcirak_breathe urcirak_brethe.launch

Gazebo simulation for character animation.
roslaunch urcirak_breathe urcirak_breate.launch

• Interaction with cirak
After launching gazebo simulation for character animation, it can be seen the robot arm imitating breathing in default parameters. Open a new terminal and change the directory to configuration file.

cd ~/catkin_ws/src/cirak_breathe/config
make yep
make nop
make ohgod
