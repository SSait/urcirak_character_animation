
cmake_minimum_required(VERSION 2.8.3)
project(urcirak_breathe)

## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs genmsg)


## Declare a catkin package
catkin_package()

## Build talker and listener
include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(breathe_dude breathe.cpp)
target_link_libraries(breathe_dude ${catkin_LIBRARIES})

