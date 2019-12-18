#include <Go_Turn_Robot/GoCMD.h>

GoCMD::GoCMD(double goal_init,double speed_init):goal(goal_init),distance(goal_init),speed(speed_init){
    goal_sign=goal>=0;
    ROS_INFO("Set goal is %.3f",goal);
}

void GoCMD::odomCB(const nav_msgs::Odometry::ConstPtr& ptr){
    cmd_vel_msg = getCmdVel(ptr); 
    vel_pub.publish(cmd_vel_msg);  //publish cmd_vel topic

    if(need_stop){
        ROS_INFO("Done!");
        ros::shutdown();
    }
    return;
}

void GoCMD::setStop(){
    need_stop = true;
    return;
}

void GoCMD::clearFirstTime(){
    first_time = false;
    return;
}

bool GoCMD::getFirstTime() const{
    return first_time;
}
