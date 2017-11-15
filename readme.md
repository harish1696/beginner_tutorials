# ROS BEGINNER TUTORIALS
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---

## Overview
This program provides an introduction to publish and subscribe to topics in ROS. It uses a talker(publisher) node and listener(subscriber) node to illustrate it.

It also has a launchfile to launch the talker and listener nodes with roslaunch command and service to change the publishing message in the chatter topic using rosservice call. 

It now can broadcast tf frames when the talker node is launched. The launch file has been modified to enable/disable rosbag feature that can record messaged published to all topics. Test cases have been implemented using gtest and rostest.

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
git clone -b Week11_HW --single-branch https://github.com/harish1696/beginner_tutorials.git
cd ..
catkin_make
```

## How to run demo
Use either 1 or 2.

1.Open a terminal window and run the following command to launch both the nodes

```
roslaunch beginner_tutorials Week11_HW.launch 
```

If you want to send a desired frequency to publish the messages using

```
roslaunch beginner_tutorials Week11_HW.launch freq:=1
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

## How to use the service
Follow either 1 or 2 so that you get published and subscribed message.
Now launch a new terminal window and run the following command

```
rosservice call /change_string desiredtext
```

Now the message published and subscribed changes to the desiredtext.

## How to Inspect tf frames
When talker node is running, it broadcasts tf transform to /talk with respect to /world. tf_echo command can be use to view the broadcasted transform. After running roscore and talker node in two seperate terminals, run the following command in a new terminal window

```
rosrun tf tf_echo /world /talk
```

This can also be visualized in the form of a graph by using the following command

```
rosrun tf view_frames
```

The above command generates a pdf file. TO view it type the following command

```
evince frames.pdf
```

## How to run rostest
To run the tests implemented using gtest and rostest for the first time, run the following command

```
catkin_make run_tests_beginner_tutorials
```

Later, the following command can be used to run the tests

```
source devel/setup.bash
rostest beginner_tutorials test.launch
```

## How to record bag files with launch command
The following command can be used to generate a rosbag file in the Results directory with launch command

```
roslaunch beginner_tutorials Week11_HW.launch record:=enable
```

The generated bag file contains recorded messages published to all topics which can be played back later.

## How to inspect rosbag file
To get more information about the generated rosbag file, go to the Results directory and run the following command

```
rosbag info pub.bag
```

## How to play a rosbag file while listener node is running 
The generated rosbag file can also be used to play the recorded messages in all topics. For example, run the listener node. Open a new terminal window and go to the Results directory. Now, run the following command

```
rosbag play pub.bag
```

You will now see the listener node showing messages played by the rosbag file.

