#pragma once
//#ifndef GO_STRAIGHT_H
//#define GO_STRAIGHT_H

#include <Go_Turn_Robot/GoCMD.h>

class GoStraight:public GoCMD{
    public:
        using GoCMD::GoCMD;
        geometry_msgs::Twist getCmdVel(const nav_msgs::Odometry::ConstPtr&) override;  //return velocity commond to robot

        virtual ~GoStraight(){};
    
    private:
        double start[2]{0.0,0.0};  //initial coordinate

};
//#endif
