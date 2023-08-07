#include "ros/ros.h"
#include <sensor_msgs/Image.h>
#include <sensor_msgs/Imu.h>

// global variable to store the incoming cam and inu messages
sensor_msgs::ImuConstPtr imu_msg ;
sensor_msgs::ImageConstPtr img_msg ;

std::string ImuTopic = "/imu_topic";
std::string ImgTopic = "/img_topic";

// callback to get cam and imu msg
void imu_cb(const sensor_msgs::ImuConstPtr& msg)
{
    imu_msg = msg;

    std::cout << "imu_time : " << imu_msg->header.stamp.sec << std::endl;
}

void img_cb(const sensor_msgs::ImageConstPtr& msg)
{
    img_msg = msg;

    std::cout << "img_time : " << img_msg->header.stamp.sec << std::endl;
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"cam_imu_time_node");

    ros::NodeHandle n;

    ros::Subscriber imu_sub = n.subscribe(ImuTopic,100,imu_cb); 
    ros::Subscriber img_sub = n.subscribe(ImgTopic,100,img_cb); 

    // while(ros::ok())
    // {
    //     imu_sub = n.subscribe(ImuTopic,100,imu_cb);
    //     imu_sub = n.subscribe(ImgTopic,100,img_cb);

    //     std::cout << "imu_time : " << imu_msg->header.stamp.sec << std::endl;
    //     std::cout << "img_time : " << img_msg->header.stamp.sec << std::endl;



    // }
    ros::spin();
    ros::shutdown();

    return 0;
}