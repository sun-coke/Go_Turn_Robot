#pragma once
// #ifndef GO_CMD_H
// #define GO_CMD_H

#include <iostream>
#include <ros/ros.h>
#include <stdlib.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h>

class GoCMD{
    public:

        GoCMD(double goal_init=0.1, double speed_init=0.1);
        virtual ~GoCMD(){}

        void odomCB(const nav_msgs::Odometry::ConstPtr&);

        virtual geometry_msgs::Twist getCmdVel(const nav_msgs::Odometry::ConstPtr&)=0;

        void setStop();

        void clearFirstTime();

        bool getFirstTime () const;
        bool goal_sign = true;
    
    private:
        ros::NodeHandle nh;
        // ros::Subscriber odom_sub = nh.subscribe<nav_msgs::Odometry>("odom",1,&GoCMD::odomCB);
        ros::Subscriber odom_sub{nh.subscribe<nav_msgs::Odometry>("odom",1,boost::bind(&GoCMD::odomCB,this,_1))};  //odom publisher
        // ros::Publisher vel_pub{nh.advertise<geometry_msgs::Twist>("cmd_vel",1)};
        ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",1);  //velocity publisher
        geometry_msgs::Twist cmd_vel_msg;  //velocity msg

        bool need_stop = false;
        bool first_time = true;

    protected:
        double goal = 0.0;  //goal distance
        double distance = 0.0;  //distance to goal;
        double speed = 0.0;  //velocity m/s or rad/s
};
// #endif

