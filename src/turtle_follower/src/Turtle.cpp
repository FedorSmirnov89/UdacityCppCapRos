
#include "Turtle.h"
#include "Calculations.h"
#include "Constants.h"
#include "RosCommunication.h"

#include <stdlib.h>
#include <thread>

Turtle::Turtle(ros::NodeHandle handle, string name, float x, float y,
               float theta, float speed, float speed_ang) {
  // spawn the turtle on the provided position
  this->speed = speed;
  this->speed_ang = speed_ang;
  this->name = name;
  this->chasing = true;
  this->x = x;
  this->y = y;
  this->theta = theta;

  this->x_followed = 0;
  this->y_followed = 0;
  this->theta_followed = 0;
  spawnTurtle(handle, name, x, y, theta);

  std::thread positionThread(&Turtle::updatePositionFollowed, this, handle);
  std::thread chaseThread(&Turtle::chaseLoop, this, handle);
  // updatePositionFollowed(handle);
  // chaseLoop(handle);
  positionThread.join();
  chaseThread.join();
}

Turtle::~Turtle() {}

/**
 * @brief Iteratively repeated method where the follower moves towards the
 * controlled turtle
 *
 * @param handle
 */
void Turtle::chaseLoop(ros::NodeHandle handle) {
  ros::Rate loop_rate(loopRateNodes);

  while (chasing && ros::ok()) {
    chaseStep(handle);
    ros::spinOnce();
    loop_rate.sleep();
  }
}

/**
 * @brief Method to make a step toward the followed turtle
 *
 * @param handle
 */
void Turtle::chaseStep(ros::NodeHandle handle) {

  float targetTheta = calculateFollowerTheta(x_followed, y_followed, x, y);

  if (abs(targetTheta - theta) < 0.0001) {
    // angle points towards followed -> move towards
    ROS_INFO("moving");
    this->x = x + calcXStep(x_followed, y_followed, x, y, speed);
    this->y = y + calcYStep(x_followed, y_followed, x, y, speed);
  } else {
    // angle wrong -> adjust the angle
    ROS_INFO("adjusting angle");
    this->theta = theta + calcThetaStep(targetTheta, theta, speed_ang);    
  }
  setPosition(handle, this->name, x, y, theta);
}

void Turtle::positionPublishCallBack(const turtlesim::Pose::ConstPtr &msg) {
  this->x_followed = msg->x;
  this->y_followed = msg->y;
  this->theta_followed = msg->theta;
}

/**
 * @brief Updates the position of the turtle that is being followed.
 *
 * @param handle
 */
void Turtle::updatePositionFollowed(ros::NodeHandle handle) {
  ros::Subscriber sub = handle.subscribe(
      "/turtle1/pose", 1000, &Turtle::positionPublishCallBack, this);
  ros::spin();
}
