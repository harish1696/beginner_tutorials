# ROS BEGINNER TUTORIALS
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
---

## Overview
This program provides an introduction to publish and subscribe to topics in ROS. It uses a talker(publisher) node and listener(subscriber) node to illustrate it.

## Dependencies
This program works on a device running Ubuntu 16.04 and ROS Kinetic Kame

To install ROS Kinetic Kame in Ubuntu 16.04, follow the steps in this [link](http://wiki.ros.org/kinetic/Installation/Ubuntu)

To install catkin, follow the installation steps in this [link](http://wiki.ros.org/catkin)

## How to build
Open a terminal window and run the following commands

```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws
catkin_make
source devel/setup.bash
cd src
git clone https://github.com/harish1696/beginner_tutorials
cd ..
catkin_make
```

## How to run demo
Open a terminal window and run the following command to start the master.

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


