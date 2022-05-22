
#include "Turtle.h"
#include "Calculations.h"
#include "Constants.h"
#include "RosCommunication.h"

Turtle::Turtle(ros::NodeHandle handle, string name, float x, float y,
               float theta, float speed, float speed_ang) {
  // spawn the turtle on the provided position
  this->speed = speed;
  this->speed_ang = speed_ang;
  this->name = name;
  this->x = x;
  this->y = y;
  this->theta = theta;

  spawnTurtle(handle, name, x, y, theta);
}

Turtle::~Turtle() {}

/**
 * @brief Method to make a step toward the followed turtle
 *
 * @param handle
 */
void Turtle::chaseStep(float x_followed, float y_followed,
                       ros::NodeHandle handle) {
  float targetTheta = calculateFollowerTheta(x_followed, y_followed, x, y);
  if (abs(targetTheta - this->theta) < 0.0001) {
    // angle points towards followed -> move towards
    this->x = this->x + calcXStep(x_followed, y_followed, x, y, speed);
    this->y = this->y + calcYStep(x_followed, y_followed, x, y, speed);
  } else {
    // angle wrong -> adjust the angle
    this->theta =
        this->theta + calcThetaStep(targetTheta, this->theta, speed_ang);
  }
  setPosition(handle, this->name, this->x, this->y, this->theta);
}
