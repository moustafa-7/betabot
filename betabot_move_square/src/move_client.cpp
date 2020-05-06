#include "ros/ros.h"                         // ROS Default Header File
#include "betabot_msgs/move_square.h"
#include "betabot_msgs/move_squareRequest.h"
#include "betabot_msgs/move_squareResponse.h"
#include <iostream>
#include <cstdlib>



int main(int argc, char **argv)
{
    ros::init(argc, argv, "move_square_client");
    ros::NodeHandle nh;



    ros::ServiceClient move_square = nh.serviceClient<betabot_msgs::move_square>("move_square");

    ROS_INFO("cmd : rosrun move_servic service_client arg0 arg1");

    

    betabot_msgs::move_squareRequest move_req;
    betabot_msgs::move_squareResponse move_res;

    move_req.side = atoll(argv[1]);
    move_req.repetitions = atoll(argv[2]);
    


    move_square.call(move_req, move_res);
    ros::spin();

    return 0;
}