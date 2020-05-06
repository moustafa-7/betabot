#include "ros/ros.h"                          // ROS Default Header File
#include "betabot_msgs/move_square.h"
#include "math.h"

#include "nav_msgs/Odometry.h"
#include "geometry_msgs/Twist.h"

#include <stdlib.h>
#include <ctime>

#define _USE_MATH_DEFINES
#include <cmath>
#include<string>

struct Position{
double x,y,z;
};

struct Quaternion{
double x,y,z,w;
};

struct EulerAngles {
    double roll, pitch, yaw;
};

EulerAngles ToEulerAngles(Quaternion q) {
    EulerAngles angles;

    // roll (x-axis rotation)
    double sinr_cosp = 2 * (q.w * q.x + q.y * q.z);
    double cosr_cosp = 1 - 2 * (q.x * q.x + q.y * q.y);
    angles.roll = std::atan2(sinr_cosp, cosr_cosp);

    // pitch (y-axis rotation)
    double sinp = 2 * (q.w * q.y - q.z * q.x);
    if (std::abs(sinp) >= 1)
        angles.pitch = std::copysign(M_PI / 2, sinp); // use 90 degrees if out of range
    else
        angles.pitch = std::asin(sinp);

    // yaw (z-axis rotation)
    double siny_cosp = 2 * (q.w * q.z + q.x * q.y);
    double cosy_cosp = 1 - 2 * (q.y * q.y + q.z * q.z);
    angles.yaw = std::atan2(siny_cosp, cosy_cosp);

    return angles;
}





class Mover{
    
    protected:
    ros::NodeHandle nh;

    // ros::NodeHandle nh;                          // Node handle declaration
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);
    ros::Subscriber sub = nh.subscribe("odom",1000, &Mover::updateData, this);


    Position pos;
    Quaternion orient;

    double roll;
    double bitch;
    double yaw;

    double PI_2 = 1.57079632679;

    ros::ServiceServer move_square = nh.advertiseService("move_square",&Mover::move_it,this);

    public:
        Mover(){ ROS_INFO("Move Square is awake");}

        bool move_it(betabot_msgs::move_square::Request &request,
                    betabot_msgs::move_square::Response &response)
        {               
            ROS_INFO("Move Square called");
            
            geometry_msgs::Twist msg;
            
            Position inital_pos;
            Quaternion initial_orient;
            double initial_yaw;

            ros::Rate rate(24.);

               

            for(int j=0; j<request.repetitions;j++){
                for(int i=0; i<4; i++){
                    

                    inital_pos = pos;
                    initial_orient = orient;
                    initial_yaw = ToEulerAngles(initial_orient).yaw;

                    msg.linear.x = 0.1;
                    msg.angular.z = 0;

                    // msg.angular.z = 0.0;
                    while(ros::ok())
                    {   
                        if(check_distance(request.side,inital_pos,pos))
                        {
                        ROS_INFO("Distance Distance Distance");
                        pub.publish(msg);
                        // break;
                        }
                        else
                        {   
                            ROS_INFO("I broke----------------------------------------------------");
                            break;
                        }
                        rate.sleep();
                        ros::spinOnce();
                    }

                    msg.linear.x = 0;
                    msg.angular.z = 0.4;
                    while(ros::ok())
                    {
                        if(check_angle(initial_yaw, ToEulerAngles(orient).yaw))
                        {
                        ROS_INFO("Angle Angle Angle");
                        pub.publish(msg);
                        // break;
                        // ROS_INFO_STREAM("Sending random velocity command:"<<" linear="<<msg.angular.z);
                        }

                        else 
                        {
                            ROS_INFO("++++++++++++++++++++++++++++++++++++++++++++++++");
                            break;
                        }

                        rate.sleep();
                        ros::spinOnce();                        
                    }
                //    ros::spinOnce;
                }
            }
            response.success = true;
            return true;
        }
    
        bool check_angle(double angle_1, double angle_2)
        {             

            ROS_INFO("Check Angle called");

            // double diff = pow(angle_1 - angle_2+0.01,2);
            // double diff_2 = pow(PI_2,2);
            
            ROS_INFO_STREAM(abs(angle_1 - angle_2 - PI_2));

            if(abs(abs(angle_1 - angle_2) - PI_2) > 0.2)  return true;
            else return false;
        }

        bool check_distance(float dis, Position pose_1, Position pose_2)
        {
            ROS_INFO("Check distance called");
            float x_dis = pow(pose_1.x-pose_2.x,2);
            float y_dis = pow(pose_1.y-pose_2.y,2);
            float z_dis = pow(pose_1.z-pose_2.z,2);

            ROS_INFO_STREAM(pow((pow(x_dis + y_dis + z_dis,0.5) - dis),2));

            if(pow((pow(x_dis + y_dis + z_dis,0.5) - dis),2) > 0.02) return true;
            else { 
            ROS_INFO_STREAM(pow((pow(x_dis + y_dis + z_dis,0.5) - dis),2));
            return false; 
            }
        }


        void updateData(const nav_msgs::Odometry::ConstPtr& msg){
            ROS_INFO("hello from ODOM!!");
            pos.x = msg->pose.pose.position.x;
            pos.y = msg->pose.pose.position.y;
            pos.z = msg->pose.pose.position.z;
            orient.x = msg->pose.pose.orientation.x;
            orient.y = msg->pose.pose.orientation.y;
            orient.z = msg->pose.pose.orientation.z;
            orient.w = msg->pose.pose.orientation.w;
        }

};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mover");
    Mover mov; 
    ros::spin();
    return 0;
}





