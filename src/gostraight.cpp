#include <stdlib.h>
#include <Go_Turn_Robot/GoStraight.h>

int main(int argc, char *argv[]){
    ros::init(argc, argv, "go_straight_robot");
    std::unique_ptr<GoStraight> go_stright_object_ptr;
    if(argc<3)
    {
        go_stright_object_ptr.reset(new GoStraight(argc==2?atof(argv[1]):0.1));
    }
    else if(argc==3)
    {
        go_stright_object_ptr.reset(new GoStraight(atof(argv[1]),atof(argv[2])));
    }
    ros::spin();
    return 0;
}   