#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include <aris.hpp>
//#include "kaanh.h"
#include <atomic>
#include <string>
#include <filesystem>
#include "controller/interface.h"
#include "controller/pose.h"
#include "json.hpp"
using namespace aris::dynamic;

auto&cs = aris::server::ControlServer::instance();
// Á¬œÓ²¢·¢ËÍmsg //
aris::core::Socket client("client");
/*bool do_cmd(std::string command_in)
{
	try
	{
		auto target = cs.executeCmd(aris::core::Msg(command_in));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return true;
}
*/

bool exector(controller::interface::Request  &req,
	controller::interface::Response &res)
{
	ROS_INFO("controller: receive request from client: cmd=%s", req.cmd.c_str());
	/*std::string command_in;
	std::getline(std::cin, command_in);
	*/
	try
	{
		client.sendMsg(aris::core::Msg(req.cmd.c_str()));
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	res.return_code=1;
	ROS_INFO("controller: sending back response to client: [%ld]", (long int)res.return_code);
	return true;
}

int main(int argc,char ** argv)
{
	
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
	client.setOnLoseConnection([&](aris::core::Socket *sock)->int {	connectSocket(); return 0; });
	client.setOnReceivedMsg([&](aris::core::Socket *sock, aris::core::Msg &msg) ->int
	{
		std::cout << msg.toString() << std::endl;// 接收到的返回值
		
		return 0;
	});


	ros::init(argc, argv, "controller");
	ros::NodeHandle n;
	//controll the model in Rviz,topic: model_control
	ros::Publisher chatter_pub = n.advertise<std_msgs::String>("model_control", 1);
	//ros::Publisher chatter_pub = n.advertise<std_msgs::String>("kannh_topic", 1000);
	ros::Rate loop_rate(20);//defaultly 20
	ros::ServiceServer service = n.advertiseService("getcmd", exector);
	//auto xmlpath = std::filesystem::absolute(".");
	//const std::string xmlfile = "kaanh.xml";
	auto xmlpath = std::filesystem::absolute(".");//获取当前工程所在的路径
	auto uixmlpath = std::filesystem::absolute(".");
	const std::string xmlfile = "kaanh.xml";
	const std::string uixmlfile = "interface_kaanh.xml";
	xmlpath = xmlpath / xmlfile;
	uixmlpath = uixmlpath / uixmlfile;
	
	// public data
	std::mutex mut;
	std::vector<double> data(49,0.0);
	int status = 0;

	client.setOnReceivedMsg([&](aris::core::Socket *sock, aris::core::Msg &msg) ->int
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

	/*
	cs.resetController(kaanh::createControllerRokaeXB4().release());
	cs.resetModel(kaanh::createModelRokae().release());
	cs.resetPlanRoot(kaanh::createPlanRootRokaeXB4().release());
	cs.resetSensorRoot(new aris::sensor::SensorRoot);
    cs.saveXmlFile(xmlpath.string().c_str());	
    cs.loadXmlFile(xmlpath.string().c_str());
    //cs.interfaceRoot().loadXmlFile(uixmlpath.string().c_str());
    //cs.saveXmlFile(xmlpath.string().c_str());	
    cs.start();
    */
	//aris::plan::PlanTarget &target;
	//auto pq= std::vector<double>(target.model->partPool().size()*7);
	while (ros::ok())
	{
		{	

			std::unique_lock<std::mutex> lck(mut);

			if(status == 0)
			{
				std::cout <<"send"<<std::endl;
			//std::cout<<"1"<<std::endl;
				client.sendMsg(aris::core::Msg("get"));
			//std::cout<<"2"<<std::endl;
				status = 1;
			}
			else if(status == 2)
			{
				std::cout <<"updated"<<std::endl;

				/*for(int i=0;i<49;i++)
				{
					if(i == 0)
					{
						std::cout<<"data[49]: ";
					}
					std::cout<<data[i]<<"  ";
					if(i == 48)
					{
						std::cout<<std::endl;
					}
				}*/

				std_msgs::String msg;
				std::stringstream ss;
				ss<<"{";
				for(int i=0;i<49;i++)
				{
					ss<<data[i];
					if(i!=48)
					{
						ss<<",";
					}
				}
				ss<<"}";

				msg.data = ss.str();
				chatter_pub.publish(msg);

				status = 0;
			}
			else
			{

			}
		}
		ros::spinOnce();
		loop_rate.sleep();



		//auto target = cs.executeCmd(aris::core::Msg("get_part_pq"));
		//auto target = cs.executeCmd(aris::core::Msg("get"));
		//target->finished.wait();
		//auto &str = std::any_cast<std::string&>(target->ret);

		/*
		node::json j = cs.executeCmd(aris::core::Msg("get"));
		std::string s = j.dump();*/
		
		

		
		
		/*node::json j;
		j.parse(&str)
*/


		//std::copy(str.data(),str.data() + 49*sizeof(double), reinterpret_cast<char*>(data.data()));
		



		/*double pe[42]{0.0};
		aris::dynamic::s_pq2pe(data.data() + 0, pe, "123");
		aris::dynamic::s_pq2pe(data.data() + 7, pe+6, "123");
		aris::dynamic::s_pq2pe(data.data() + 14, pe+12, "123");
		aris::dynamic::s_pq2pe(data.data() + 21, pe+18, "123");
		aris::dynamic::s_pq2pe(data.data() + 28, pe+24, "123");
		aris::dynamic::s_pq2pe(data.data() + 35, pe+30, "123");
		aris::dynamic::s_pq2pe(data.data() + 42, pe+36, "123");		
		aris::dynamic::dsp(1,7,data.data());
		aris::dynamic::dsp(1,6,pe);
		aris::dynamic::dsp(1,7,data.data() + 7);
		aris::dynamic::dsp(1,6,pe + 6);
		aris::dynamic::dsp(1,7,data.data() + 14);
		aris::dynamic::dsp(1,6,pe + 12);
		*/
		//std::cout<<"data"<<data[0]<<std::endl;
		/*aris::PlanTarget &target;
		double pq[7][7],pe[7][6];
		target.model->partPool().getpartpq(pq[0]);
		aris::dynamic::s_pq2pe(pq[0],pe[0],"313");
		*/
		//controller::pose msg;
		//controller::rob_posture msg;
		/*do_cmd(get_part_pq);
		std::cout<<"pq[0]:   "<<pq[0]<<"pq[1]:   "<<pq[1]<<std::endl;
		*/
		/*
		for(int i=0;i<42;i++)
		{
			pe[i]=0;
		}
		*/

	}
	return 0;
}
