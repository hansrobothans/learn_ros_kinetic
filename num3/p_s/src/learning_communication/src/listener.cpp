#include "ros/ros.h"
#include "std_msgs/String.h"
 
//接收到订阅消息后，会进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
    ROS_INFO("I heard :[%s]",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    //ros节点初始化
    ros::init(argc,argv,"listener");

    //创建节点句柄
    ros::NodeHandle n;

    //创建一个Publisher，发布名为chatter的topic，消息类型为std_msgs::string
    ros::Subscriber sub = n.subscribe("chatter",1000,chatterCallback);

    //循环等待回调函数
    ros::spin();

    return 0;
}
