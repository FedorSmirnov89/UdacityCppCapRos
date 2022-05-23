/**
 * @file Turtle.h
 * @author Fedor Smirnov
 * @brief The header for the turtle class representing one turtle displayed by
 * the turtlesim node
 */

#ifndef TURTLE_H
#define TURTLE_H

#include <string>

#include "ros/ros.h"

#include "turtlesim/Pose.h"

using std::string;

class Turtle {

public:
  /**
   * @brief Construct a new Turtle object and positions it at the given
   * coordinates
   *
   * @param handle the ros handle
   * @param name the name of the turtle
   * @param init_x the initial x position
   * @param init_y the initial y position
   * @param theta the initial theta angle
   * @param speed the linear movement speed of the turtle
   * @param speed_ang the angular movement speed of the turtle
   */
  Turtle(ros::NodeHandle handle, string name, float init_x, float init_y,
         float theta, float speed, float speed_ang);
  ~Turtle();

  /**
   * @brief Triggers a movement step in which the turtle moves closer to the
   * provided coordinates.
   *
   * @param x_followed the target x position
   * @param y_followed the target y position
   * @param handle the ROS handle of this node
   */
  void chaseStep(float x_followed, float y_followed, ros::NodeHandle handle);

private:
  string name;
  float speed;
  float speed_ang;
  float x;
  float y;
  float theta;
};

#endif