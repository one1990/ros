#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "controller/rob_param.h"
#include "controller/pose.h"
#include "controller/interface.h"
#include <cmath>

#include <cstdlib>
#include "controller/setpos.h"
#include "controller/motorpos.h"

double threshold = 0.01;
bool power_on=false;
int d[3]={0,0,0};;//the directiong to move the robot 
int angle_steer = 0;//he parameter to control steering engine
int angle_get[3] ={0,0,0};
bool lock=false;
bool reset_a =false, reset_b = false, reset_c = false, reset_all = false;

void call_service(ros::ServiceClient & cmd_client,std::string cmd_in)
{
  controller::interface srv;
  srv.request.cmd = cmd_in;
  if (cmd_client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.return_code);
  }
  else
  {
    //ROS_ERROR("Failed to call service controller");
    return;
  }
  return;
}

//void call_service2(ros::ServiceClient & client2,uint16_t cmd_in)
void call_service2(ros::ServiceClient & client2,std_msgs::String cmd_in)
{
  controller::setpos srv;
  srv.request.cmd = cmd_in.data;
  client2.call(srv);
  return;
}

void chatterCallBack(const controller::rob_param::ConstPtr& msg)//?????
{	
	//ROS_INFO("listener recieve from joy msg->x:[%d]", msg->x);
	ROS_INFO("in listener command box");
	if(msg->forward_back>0.00 && msg->x ==1) 
    {
      d[0]=1;
      reset_a =false; 
      reset_b = false; 
      reset_c = false; 
      reset_all = false;
    }
	else if (msg->forward_back<0.00 && msg->x ==1) 
	{
		d[0]=-1;
		reset_a =false; 
		reset_b = false; 
		reset_c = false; 
		reset_all = false;
	}
	else 
	{
		d[0] = 0;
		reset_a =false; 
		reset_b = false; 
		reset_c = false; 
		reset_all = false;
	}
	if(msg->forward_back>0.00 && msg->y ==1) 
	{
	d[1]=1;
	reset_a =false; 
	reset_b = false; 
	reset_c = false; 
	reset_all = false;
	}
	else if (msg->forward_back<0.00 && msg->y ==1) 
	{   
	d[1]=-1;
	reset_a =false; 
	reset_b = false; 
	reset_c = false; 
	reset_all = false;
	}
	else
	{
	d[1]=0;
	reset_a =false; 
	reset_b = false; 
	reset_c = false; 
	reset_all = false;
	}
	if(msg->forward_back>0.00 && msg->z ==1) 
	{
	d[2]=1;
	reset_a =false; 
	reset_b = false; 
	reset_c = false; 
	reset_all = false;
	}
	else if (msg->forward_back<0.00 && msg->z ==1) 
	{
	d[2]=-1;
	reset_a =false; 
	reset_b = false; 
	reset_c = false; 
	reset_all = false;
	}
	else
	{
	d[2]=0;
	reset_a =false; 
	reset_b = false; 
	reset_c = false; 
	reset_all = false;
	}
	if(msg->rx ==1) reset_a = true;
	if(msg->ry ==1) reset_b = true;
	if(msg->rz <=-0.9) reset_c = true;
	if(msg->start ==1) reset_all = true;
}

void chatterCallBack2(const std_msgs::String::ConstPtr& msg)
{
	//ROS_INFO("Get angle_get: %ld", msg->angular);

    if(angle_get[0]==0 && angle_get[1]==0 && angle_get[2]==0)
    {
        std::stringstream ss(msg->data);
        char c;
        std::cout<<"msg.received.str"<<msg->data<<std::endl;
        //the content of c is "{";
        ss>>c;
        for(int i=0;i<3;++i)
		{
			ss>>angle_get[i];
			if(i==0)
			{
			std::cout<<"first pos recieved: ";
			}
			std::cout<<angle_get[i]<<"  ";
			if(i==2)
			{
			std::cout<<std::endl;
			}
			//the content of c is Symbol",";
			ss>>c;
			lock = true;
		}
    }
	
	//angle_steer = angle_get;
}

int main(int argc,char ** argv)
{
	ros::init(argc, argv, "steering_engine");
	ros::NodeHandle n;
	ros::ServiceClient client2 = n.serviceClient<controller::setpos>("gettargetpos");
	//ros::Rate loop_rate(1);
	ros::Rate loop_rate(30);

	ros::Subscriber sub2 = n.subscribe("motorpos_topic",1,chatterCallBack2);

	ros::Subscriber sub = n.subscribe("dynamixel_joy_topic",1,chatterCallBack);

	//controller::setpos::Request msg1;
	std_msgs::String msg1;

	while (ros::ok())
  	{
        //the param lock is to ensure the chatterCallBack2 function is to be run first,and then the while Loop.
        if(lock)
        {
          for(int i=0;i<3;i++)
          {
          angle_get[i] += 2 * d[i];
          angle_get[i] = std::max(0,angle_get[i]);
          angle_get[i] = std::min(350,angle_get[i]);
            if(i==0)
            {
              std::cout<<"Target pos recieved: ";
            }
            std::cout<<angle_get[i]<<"  ";
            if(i==2)
            {
              std::cout<<std::endl;
            }
          }
          if(reset_a) angle_get[0] = 0;
          if(reset_b) angle_get[1] = 0;
          if(reset_c) angle_get[2] = 0;
          if(reset_all)
            {
              angle_get[0] = 0;
              angle_get[1] = 0;
              angle_get[2] = 0;
            }
          std::stringstream ss;
          ss<<"{";
          for(int i=0;i<3;i++)
          {
            ss<<angle_get[i];
            if(i!=2)
            {
              ss<<",";
            }
          }
          ss<<"}";
          //msg1.data = ss.str();
          msg1.data = ss.str();        
          call_service2(client2,msg1);
        }
  		
    	//call_service(cmd_client,cmd);
    	ros::spinOnce();
    	loop_rate.sleep();
  	}
	return 0;
}