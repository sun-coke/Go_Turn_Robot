#include <Go_Turn_Robot/GoTurn.h>
#include <cmath>

GoTurn::GoTurn(double goal_init,double speed_init):GoCMD(goal_init,speed_init){
    laps = goal/2.0/M_PI;
    if(laps!=0){
        ROS_INFO("robot should turn %d laps",laps); 
    }
}

geometry_msgs::Twist GoTurn::getCmdVel(const nav_msgs::Odometry::ConstPtr& ptr){
    double roll,pitch,yaw;  //Containers for r/p/y
    geometry_msgs::Twist turn_speed;  //msg quaternion
    tf::Quaternion tfq;  //tf quaternion
    tf::quaternionMsgToTF(ptr->pose.pose.orientation,tfq);  //msg quternion to tf quaternion
    tf::Matrix3x3(tfq).getRPY(roll,pitch,yaw);  //tf quaternion to Eular angle
    //tf::createQuaternionMsgFromRollPitchYaw(double r, double p, double y);  
    //Eular angle to tf quaternion
    if(getFirstTime()){
        start = yaw;
        destination = start + goal - 2*laps*M_PI;  //[-2PI,2PI]
        destination = destination>=M_PI?destination-2*M_PI:destination;  //range of yaw [-PI,PI]
        destination = destination<-M_PI?destination+2*M_PI:destination;
        ROS_INFO("Start yaw is %f rad",yaw);
        if(fabs(destination-goal)<TURN_THRESHOLD && fabs(goal-2*M_PI*laps)>TURN_THRESHOLD)
        {
            near_loop = true;
        }
        clearFirstTime();
    }
    distance = fabs(destination - yaw);  //goal yaw - destination yaw
    if(distance >= TURN_THRESHOLD)  //tolerance
    {
        near_loop = false;
        if(goal_sign)
        {
            turn_speed.angular.z=speed!=0.0?speed:0.3;
        }
        else
        {
            turn_speed.angular.z=speed!=0.0?-speed:-0.3;
        }
    }
    else
    {
        if(!near_loop)
        {
            near_loop = true;
            laps+=goal_sign?-1:1;
        }
        if(laps==(goal_sign?-1:1))  //stop
        {
            turn_speed.angular.z=0.0;
            setStop();
            ROS_INFO("Final yaw is %f",yaw);
        }
        else
        {
            if(goal_sign){
                turn_speed.angular.z=speed!=0.0?speed:0.3;
            }
            else
            {
                turn_speed.angular.z=speed!=0.0?-speed:-0.3;
            }
        }
    }
    return turn_speed;
}

