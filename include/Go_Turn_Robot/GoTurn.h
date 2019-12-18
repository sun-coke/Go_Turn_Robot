#pragma once

#include <Go_Turn_Robot/GoCMD.h>
#define TURN_THRESHOLD 0.05

class GoTurn:public GoCMD{
    public:
        GoTurn(double goal_init=0.1,double speed_init=0.1);
        geometry_msgs::Twist getCmdVel(const nav_msgs::Odometry::ConstPtr&) override;

        virtual ~GoTurn(){}

    private:
        double start = 0.0,destination = 0.0;  //initial yaw,goal yaw
        int laps = 0;  //numbers of laps robot should turn
        bool near_loop = false;  //whether current destination is near goal destination
};
