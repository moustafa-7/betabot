#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from sensor_msgs.msg import LaserScan
from std_msgs.msg import Float32





class Random_mover:

    def __init__(self):

        self.range_center = Float32()
        self.range_left = Float32()
        self.range_right = Float32()
        self.range_left_front = Float32()
        self.range_right_front = Float32()

        self.normal_vel =0.2
        self.normal_angel_turn =1.57284
        self.last_ob_vel =0
        self.last_ob_angel =0.21845
        self.half_angel =1.57284


        self.pub = rospy.Publisher("cmd_vel", Twist, queue_size= 10)
        self.sub = rospy.Subscriber("scan",LaserScan, callback= self.update_readings)

        self.move()
        



    def update_readings(self,laser_scan):
        # self.range_center.data = laser_scan.ranges[999]
        # self.range_right.data = laser_scan.ranges[499]
        # self.range_right_front = laser_scan.ranges[749]
        # self.range_left.data = laser_scan.ranges[1499]
        # self.range_left_front = laser_scan.ranges[1294]


        self.range_center.data = laser_scan.ranges[1499]
        self.range_right.data = laser_scan.ranges[999]
        self.range_right_front = laser_scan.ranges[1249]
        self.range_left.data = laser_scan.ranges[0]
        self.range_left_front = laser_scan.ranges[1749]

        # rospy.loginfo("ranges %f ", self.range_center.ranges)


		

    def move(self):

        rospy.init_node('random_mover', anonymous=True)
        rate = rospy.Rate(10)
        twist_msg = Twist()
        
        while not rospy.is_shutdown():
            if (self.range_center.data>1):
                twist_msg.linear.x = self.normal_vel
                twist_msg.linear.y = 0
                twist_msg.linear.z = 0
                twist_msg.angular.x = 0
                twist_msg.angular.y = 0
                twist_msg.angular.z = 0
                self.pub.publish(twist_msg)

                if (self.range_left_front < 0.4):
                    twist_msg.linear.x = self.normal_vel
                    twist_msg.linear.y = 0
                    twist_msg.linear.z = 0
                    twist_msg.angular.x = 0
                    twist_msg.angular.y = 0
                    twist_msg.angular.z = -self.normal_angel_turn
                    self.pub.publish(twist_msg)

                elif (self.range_right_front < 0.4):
                    twist_msg.linear.x = self.normal_vel
                    twist_msg.linear.y = 0
                    twist_msg.linear.z = 0
                    twist_msg.angular.x = 0
                    twist_msg.angular.y = 0
                    twist_msg.angular.z = self.normal_angel_turn
                    self.pub.publish(twist_msg)


            else:

                if(self.range_left > 1 or  self.range_left_front > 1):
                    twist_msg.linear.x = 0
                    twist_msg.linear.y = 0
                    twist_msg.linear.z = 0
                    twist_msg.angular.x = 0
                    twist_msg.angular.y = 0
                    twist_msg.angular.z = self.normal_angel_turn
                    self.pub.publish(twist_msg)

                    
                elif(self.range_right > 1 or  self.range_right_front > 1):
                    twist_msg.linear.x = 0
                    twist_msg.linear.y = 0
                    twist_msg.linear.z = 0
                    twist_msg.angular.x = 0
                    twist_msg.angular.y = 0
                    twist_msg.angular.z = -self.normal_angel_turn
                    self.pub.publish(twist_msg)



                elif(self.range_right > self.range_left):
                    twist_msg.linear.x = 0
                    twist_msg.linear.y = 0
                    twist_msg.linear.z = 0
                    twist_msg.angular.x = 0
                    twist_msg.angular.y = 0
                    twist_msg.angular.z = -self.normal_angel_turn
                    self.pub.publish(twist_msg)

                    
                else:
                    twist_msg.linear.x =0
                    twist_msg.linear.y = 0
                    twist_msg.linear.z = 0
                    twist_msg.angular.x = 0
                    twist_msg.angular.y = 0
                    twist_msg.angular.z = self.normal_angel_turn
                    self.pub.publish(twist_msg)
            
            rate.sleep()





print ("begin trying")
try:
	# rospy.loginfo("begin") # range value in front of the bot
	print ("testing")
	r = Random_mover()
	print ("entered")
	# rospy.loginfo("yay") # range value in front of the bot
except rospy.ROSInterruptException:
	print("Oh shit!! here we go again")
	





                
					





            


















