#include "ros/ros.h"
#include <iostream>
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/NavSatFix.h"
#include <vectornav/Ins.h>
#include "vn/sensors.h"
#include "vn/compositedata.h"
#include "vn/util.h"
#include "rtcm_msgs/Message.h"
#include <cmath>
#include <string>
#include <sstream>

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include <rtcm_msgs/Message.h>


#include <vectornav/Ins.h>



using namespace std;


void msgcallback(const sensor_msgs::Imu::ConstPtr& msg)
{
	ROS_INFO("x1 msg=%6f", msg->linear_acceleration.x);
	ROS_INFO("y1 msg=%6f", msg->linear_acceleration.y);
	ROS_INFO("z1 msg=%6f", msg->linear_acceleration.z);


}
void msgcallback2(const sensor_msgs::NavSatFix::ConstPtr& msg)
{
	ROS_INFO("lat msg=%7f", msg->latitude);
	ROS_INFO("lon msg=%7f", msg->longitude);
	ROS_INFO("alt msg=%7f", msg->altitude);

}


int main(int argc, char** argv)
{

	
	ros::init(argc, argv, "imu_subscriber");
	ros::NodeHandle nh;
	ros::NodeHandle pn("~");

	ros::Subscriber ros_tutorial_sub = nh.subscribe("vectornav/IMU", 1000, msgcallback);
	ros::Subscriber ros_tutorial_rtk = nh.subscribe("raw_data/fix", 10, msgcallback2);



	ros::spin();
	return 0;
}

