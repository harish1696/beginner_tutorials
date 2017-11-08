# ROS BEGINNER TUTORIALS
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---

## Overview
This program provides an introduction to publish and subscribe to topics in ROS. It uses a talker(publisher) node and listener(subscriber) node to illustrate it.

It now has a launchfile to launch the talker and listener nodes with roslaunch command and service to change the publishing message in the chatter topic using rosservice call. 

## Dependencies
This program works on a device running Ubuntu 16.04 and ROS Kinetic Kame.

To install ROS Kinetic Kame in Ubuntu 16.04, follow the steps in this [link](http://wiki.ros.org/kinetic/Installation/Ubuntu).

To install catkin, follow the installation steps in this [link](http://wiki.ros.org/catkin).

## How to build
Open a terminal window and run the following commands

```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin_make
source devel/setup.bash
cd src
git clone -b Week10_HW --single-branch https://github.com/harish1696/beginner_tutorials.git
cd ..
catkin_make
```

## How to run demo
1.Open a terminal window and run the following command to launch both the nodes

```
roslaunch beginner_tutorials Week10_HW.launch 
```

If you want to send a desired frequency to publish the messages using

```
roslaunch beginner_tutorials Week10_HW.launch freq:=1
```
 
2.Open a terminal window and run the following command to start the master.

```
roscore
```

Open a new terminal window and run the following command to run talker. 

```
cd ~/catkin_ws
source devel/setup.bash
rosrun beginner_tutorials talker
```

Open a new terminal window and run the following command to run listener.

```
cd ~/catkin_ws
source devel/setup.bash
rosrun beginner_tutorials listener
```

To stop the nodes/master press Ctrl+C to exit

##How to use the service
Follow either 1 or 2 so that you get published and subscribed message.
Now launch a new terminal window and run the following command

```
rosservice call /change_string desiredtext
```

Now the message published and subscribed changes to the desiredtext.




