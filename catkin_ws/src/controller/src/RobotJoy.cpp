#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <sstream>
#include "controller/rob_param.h"

// create the RobotJoy class and define the joyCallback function that will take a joy msg
class RobotJoy
{
	public:
		RobotJoy();

		void joyrobotCallback(const sensor_msgs::Joy::ConstPtr& joy);
		void joydynamixelCallback(const sensor_msgs::Joy::ConstPtr& joy);
		ros::NodeHandle nh_;
		ros::Publisher robot_pub_;
		ros::Publisher dynamixel_pub_;
		ros::Subscriber joy_robot_sub_;
		ros::Subscriber joy_dynamixel_sub_;
};

RobotJoy::RobotJoy()
{
	// create a publisher that will publish the cmd from xbox //
	robot_pub_ = nh_.advertise<controller::rob_param>("robot_joy_topic", 1);
	dynamixel_pub_ = nh_.advertise<controller::rob_param>("dynamixel_joy_topic", 1);

	// subscribe to the joystick topic //
	joy_robot_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 1, &RobotJoy::joyrobotCallback, this);
	joy_dynamixel_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 1, &RobotJoy::joydynamixelCallback, this);
}

int x_j1=2, y_j2 = 3, z_j3 =5 ,rx_j4 = 0,ry_j5 = 1,rz_j6 = 5,forward_back=1,start=7,gear=7; 
int select_mode=6;
int rs_button = 4, md_ds_button = 6, rc_en_button =4, start_stop =3;

void RobotJoy::joyrobotCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
	controller::rob_param msg;

    msg.x = joy->buttons[x_j1];
    msg.y = joy->buttons[y_j2];
    msg.z = joy->buttons[z_j3];
    msg.rx = joy->buttons[rx_j4];
    msg.ry = joy->buttons[ry_j5];
    msg.rz = joy->axes[rz_j6];
    msg.j1 = joy->buttons[x_j1];
    msg.j2 = joy->buttons[y_j2];
    msg.j3 = joy->buttons[z_j3];
    msg.j4 = joy->buttons[rx_j4];
    msg.j5 = joy->buttons[ry_j5];
    msg.j6 = joy->axes[rz_j6];
    msg.select_mode = joy->buttons[select_mode];
    msg.start = joy->buttons[start];
    msg.forward_back = joy->axes[forward_back];
    msg.gear = joy->axes[gear];
    msg.rs_button = joy->buttons[rs_button];
    msg.md_ds_button = joy->axes[md_ds_button];
    msg.rc_en_button = joy->axes[rc_en_button];
    msg.start_stop = joy->axes[start_stop];

    robot_pub_.publish(msg);
}

void RobotJoy::joydynamixelCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
	controller::rob_param msg;

    msg.x = joy->buttons[x_j1];
    msg.y = joy->buttons[y_j2];
    msg.z = joy->buttons[z_j3];
    msg.rx = joy->buttons[rx_j4];
    msg.ry = joy->buttons[ry_j5];
    msg.rz = joy->axes[rz_j6];
    msg.j1 = joy->buttons[x_j1];
    msg.j2 = joy->buttons[y_j2];
    msg.j3 = joy->buttons[z_j3];
    msg.j4 = joy->buttons[rx_j4];
    msg.j5 = joy->buttons[ry_j5];
    msg.j6 = joy->axes[rz_j6];
    msg.select_mode = joy->buttons[select_mode];
    msg.start = joy->buttons[start];
    msg.forward_back = joy->axes[forward_back];
    msg.gear = joy->axes[gear];
    msg.rs_button = joy->buttons[rs_button];
    msg.md_ds_button = joy->axes[md_ds_button];
    msg.rc_en_button = joy->axes[rc_en_button];
    msg.start_stop = joy->axes[start_stop];

    dynamixel_pub_.publish(msg);
}

int main(int argc, char** argv)
{
	sensor_msgs::Joy::ConstPtr joy;

	// initialize our ROS node, create a robot_joy, and spin our node until Ctrl-C is pressed
	ros::init(argc, argv, "RobotJoy");
  
	RobotJoy robot_joy;
  
    ros::Rate loop_rate(20);
    ros::spin();
    loop_rate.sleep();
}

