#!/usr/bin/env python
import rospy

from learning_communication.msg import Complex

def callback(msg):
    print("Real:",msg.real)
    print("Imaginary:",msg.imaginary)

rospy.init_node('message_subscriber')

sub = rospy.Subscriber("complex",Complex,callback)

rospy.spin()
