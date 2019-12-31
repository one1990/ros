#include "ros/ros.h"
#include "std_msgs/String.h"
#include <aris.hpp>
#include <sensor_msgs/Imu.h>
#include <sstream>
//#include "controller/pose.h"
//#include "controller/interface.h"
#include <cmath>
auto&cs = aris::server::ControlServer::instance();
// Á¬œÓ²¢·¢ËÍmsg //
aris::core::Socket client("client");

/*void call_service(ros::ServiceClient & cmd_client,std::string cmd_in)
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
}*/
std::string cmd;
double imu_receive[4]={0.0,0.0,0.0,0.0};
void chatterCallBack(const sensor_msgs::Imu::ConstPtr& msg)//?????
{	
	//ROS_INFO("listener recieve from joy msg->x:[%d]", msg->x);
	ROS_INFO("in yt_listener command box");
	//.c_str()
        imu_receive[0] = msg->orientation.x * 5.1429 /57.3;
        imu_receive[1] = msg->orientation.y * 5.1429 /57.3;
        imu_receive[2] = msg->orientation.z * 5.1429 /57.3;
        imu_receive[3] = msg->orientation.w * 5.1429 /57.3;
	std::cout<<"imu0: "<<imu_receive[0]<<std::endl;
	std::cout<<"imu1: "<<imu_receive[1]<<std::endl;
	std::cout<<"imu2: "<<imu_receive[2]<<std::endl;
	std::cout<<"imu3: "<<imu_receive[3]<<std::endl;
  cmd = "upt --Eulerx="+std::to_string(imu_receive[0]) +" --Eulery=" + 
        std::to_string(imu_receive[1]) +" --Eulerz=" + std::to_string(imu_receive[2])+" --Eulerw=" + std::to_string(imu_receive[3]);
  //client.sendMsg(aris::core::Msg(cmd.c_str()));

}
int main(int argc,char ** argv)
{
	ros::init(argc, argv, "yt_listener");
	ros::NodeHandle n;
	//ros::ServiceClient cmd_client = n.serviceClient<controller::interface>("getcmd");
	
  //socket
  client.setConnectType(aris::core::Socket::TCP);
  client.setRemoteIP("127.0.0.1");
  client.setPort("5867"); 
  auto connectSocket = [&]()->void
  {
    for (;;)
    {
      try
      {
        client.connect();
        break;
      }
      catch (std::exception &e)
      {
        std::cout << "failed to connect server, will retry in 1 second" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
      }
    }
  };
  connectSocket();
  client.setOnLoseConnection([&](aris::core::Socket *sock)->int { connectSocket(); return 0; });
  client.setOnReceivedMsg([&](aris::core::Socket *sock, aris::core::Msg &msg) ->int
  {
    std::cout << msg.toString() << std::endl;// 接收到的返回值
    
    return 0;
  });
//socket2
 /*   client.setOnReceivedMsg([&](aris::core::Socket *sock, aris::core::Msg &msg) ->int
  {
    auto j = nlohmann::json::parse(msg.toString());// 接收到的返回值 
    
    try
    {
      std::vector<double> vec = j["part_pq"];
      std::unique_lock<std::mutex> lck(mut);
      status = 2;
      data = vec;
    }
    catch(...)
    {

    }

    return 0;
  });
*/

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            





	ros::Subscriber sub = n.subscribe("IMU_data",1,chatterCallBack);
	ros::Rate loop_rate(20);
	while (ros::ok())
  	{
/*        if(en_cmd)
        {
            for(int i=0; i<cmd_vec.size(); i++)
            {
            call_service(cmd_client,cmd_vec[i]);
            }
        }
*/  	
      client.sendMsg(aris::core::Msg(cmd.c_str()));	
    	//call_service(cmd_client,cmd);
    	ros::spinOnce();
    	loop_rate.sleep();
  	}
	return 0;
}
