
#include <string>
#include <iostream>


#include "ros/ros.h"

// messages
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"

// services
#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"






#include "./constants.h"

ros::Publisher velocity_publisher;
ros::Subscriber pose_subscriber;


/**
 * @brief Moves the robot in a straight line
 * 
 * @param speed movement speed
 * @param distance distance to move
 * @param isForward true if the robot is moved forward
 */
void move(){

    geometry_msgs::Twist vel_msg;

    // let's say we want to move into the x direction for 10 units

    vel_msg.linear.x = speedFollowOne;
    vel_msg.linear.y = 0;
    vel_msg.linear.z = 0;

    vel_msg.angular.x = 0;
    vel_msg.angular.y = 0;
    vel_msg.angular.z = 0;

    double current_dist = 0.0;

    ros::Rate loop_rate(loopRateNodes);

    do{

        std::cout << "publishing" <<"\n";
        velocity_publisher.publish(vel_msg);
        double t1 = ros::Time::now().toSec();
        current_dist += speedFollowOne;
        ros::spinOnce();
        loop_rate.sleep();
    }while(1);

    vel_msg.linear.x = 0;
    velocity_publisher.publish(vel_msg);

}


void printPosition(const turtlesim::Pose::ConstPtr &msg){    

    float x_pos = msg->x;
    float y_pos = msg->y;

    std::cout << "x " << x_pos << "\n";
    std::cout << "y " << y_pos << "\n";


}

void spawn(float x, float y, float theta, std::string name){

}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "example_turtle");

    ros::NodeHandle n;

    velocity_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

    // listen to the turtle position
    //pose_subscriber = n.subscribe<turtlesim::Pose>("/turtle1/pose", 1000, printPosition);

    // move the turtle into a direction
    //move();

    // kill the current turtle and respawn a new one

    ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Kill srv_kill;
    turtlesim::Spawn srv_spawn;

    srv_spawn.request.x = 10.0;
    srv_spawn.request.y = 10.0;
    srv_spawn.request.theta = 20.0;
    srv_spawn.request.name = "turtle2";

    //srv.request.name = "turtle1";

    client.call(srv_spawn);

    ros::spin();

    // last point -- check out who the teleop thingy writes to

    return 0;
}
