#include "ros/ros.h"
#include "std_msgs/Float64.h"

#define _USE_MATH_DEFINES
#include <math.h>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "breathe_dude");
  ros::NodeHandle nh;

  int rate;

  double pivot_1; 
  double range_1;
  double ampt_1;
  
  double pivot_2;
  double range_2;
  double ampt_2;
  
  double pivot_3;
  double range_3;
  double ampt_3;
  
  double pivot_4;
  double range_4;
  double ampt_4;
  
  double pivot_5;
  double range_5;
  double ampt_5;
  
  double pivot_6;
  double range_6;
  double ampt_6;

  ros::Publisher shoulder_pan_joint_state_publisher = nh.advertise<std_msgs::Float64>("shoulder_pan_joint_position_controller/command",rate);
  ros::Publisher shoulder_lift_joint_state_publisher = nh.advertise<std_msgs::Float64>("shoulder_lift_joint_position_controller/command",rate);
  ros::Publisher elbow_joint_state_publisher = nh.advertise<std_msgs::Float64>("elbow_joint_position_controller/command",rate);
  ros::Publisher wrist_1_joint_state_publisher = nh.advertise<std_msgs::Float64>("wrist_1_joint_position_controller/command",rate);
  ros::Publisher wrist_2_joint_state_publisher = nh.advertise<std_msgs::Float64>("wrist_2_joint_position_controller/command",rate);
  ros::Publisher wrist_3_joint_state_publisher = nh.advertise<std_msgs::Float64>("wrist_3_joint_position_controller/command",rate);
  ros::Publisher finger_joint_state_publisher = nh.advertise<std_msgs::Float64>("finger_joint_position_controller/command",rate);

  std_msgs::Float64 vel_1;
  std_msgs::Float64 vel_2;
  std_msgs::Float64 vel_3;
  std_msgs::Float64 vel_4;
  std_msgs::Float64 vel_5;
  std_msgs::Float64 vel_6;
  std_msgs::Float64 vel_7;

  ros::Rate loop_rate(50);

  int i = 0;
  
  while (ros::ok())
  {
    

    vel_1.data = sin(ampt_1*2*M_PI*i/100.0)*range_1 + pivot_1 ;
    vel_2.data = sin(ampt_2*2*M_PI*i/100.0)*range_2 + pivot_2 ;
    vel_3.data = sin(ampt_3*2*M_PI*i/100.0)*range_3 + pivot_3 ;
    vel_4.data = sin(ampt_4*2*M_PI*i/100.0)*range_4 + pivot_4 ;
    vel_5.data = sin(ampt_5*2*M_PI*i/100.0)*range_5 + pivot_5 ;
    vel_6.data = sin(ampt_6*2*M_PI*i/100.0)*range_6 + pivot_6 ;
    vel_7.data = 0.85;

    shoulder_pan_joint_state_publisher.publish(vel_1);
    shoulder_lift_joint_state_publisher.publish(vel_2);
    elbow_joint_state_publisher.publish(vel_3);
    wrist_1_joint_state_publisher.publish(vel_4);
    wrist_2_joint_state_publisher.publish(vel_5);
    wrist_3_joint_state_publisher.publish(vel_6);
    finger_joint_state_publisher.publish(vel_7);

    if(i==0)
    {
      nh.getParam("breathe_dude/pivot_1", pivot_1);
      nh.getParam("breathe_dude/pivot_2", pivot_2);
      nh.getParam("breathe_dude/pivot_3", pivot_3);
      nh.getParam("breathe_dude/pivot_4", pivot_4);
      nh.getParam("breathe_dude/pivot_5", pivot_5);
      nh.getParam("breathe_dude/pivot_6", pivot_6);
      nh.getParam("breathe_dude/rate", rate);
      
      
      pivot_1 = pivot_1*1.0;
      pivot_2 = pivot_2*-M_PI;
      pivot_3 = pivot_3*M_PI;
      pivot_4 = pivot_4*-M_PI;
      pivot_5 = pivot_5*-M_PI;
      pivot_6 = pivot_6*-M_PI;
      
      
      
      nh.getParam("breathe_dude/range_1", range_1);
      nh.getParam("breathe_dude/range_2", range_2);
      nh.getParam("breathe_dude/range_3", range_3);
      nh.getParam("breathe_dude/range_4", range_4);
      nh.getParam("breathe_dude/range_5", range_5);
      nh.getParam("breathe_dude/range_6", range_6);
      
      nh.getParam("breathe_dude/ampt_1", ampt_1);
      nh.getParam("breathe_dude/ampt_2", ampt_2);
      nh.getParam("breathe_dude/ampt_3", ampt_3);
      nh.getParam("breathe_dude/ampt_4", ampt_4);
      nh.getParam("breathe_dude/ampt_5", ampt_5);
      nh.getParam("breathe_dude/ampt_6", ampt_6);
    }

  
    ros::spinOnce();


    loop_rate.sleep();

    ++i%=100;
  }


  return 0;

}
    
