# Go / Turn Robot
利用里程计数据以指定的位移和速度实现控制机器人直行 / 转弯。

## 一、安装
```
$ cd ~/catkin_ws/src
$ git clone https://github.com/sun-coke/Go_Turn_Robot.git
$ cd ~/catkin_ws && catkin_make   ///编译通过-安装成功
```

## 二、运行
```
$ roslaunch turtlebot3_gazebo turtlebot3_empty_world.launch
$ roslaunch go_straight_and_turn go_straight.launch distance:=0.5 velocity:=0.15 ///直行控制
$ roslaunch go_straight_and_turn go_turn.launch distance:=-1.57 velocity:=0.3 ///转弯控制
```

## 三、参数
1.odom_topic:


&ensp;&ensp;由里程计发布的话题(nav_msgs/Odometry)，launch文件默认/odom


2.cmd_vel_topic:


&ensp;&ensp;由机器人本体发布的话题(geometry_msgs/Twist)，launch文件默认/cmd_vel


3.distance:


&ensp;&ensp;机器人移动的直线距离和转角角度(m or rad)


4.velocity:


&ensp;&ensp;机器人移动的线速度和角速度(m/s or rad/s)


**其余默认参数以Turtlebot3为参考**

