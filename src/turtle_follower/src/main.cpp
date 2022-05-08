
#include "RosCommunication.h"
#include "Constants.h"
#include "Turtle.h"

int main(int argc, char **argv)
{
    // init ROS
    ros::init(argc, argv, "turtle_followers");
    ros::NodeHandle rosHandle;

    // wipe the board so that we start in a controlled state
    reset(rosHandle);
    
    
    // spawn the turtle which will be controlled by our actions

    spawnControlledTurtle(rosHandle);


    // spawn the follower turtles

    Turtle turtle(rosHandle, "follower", 1.1, 1.1, 0, 0.01, 0.01);

    // test: teleport the follower turtle

    


    return 0;
}
