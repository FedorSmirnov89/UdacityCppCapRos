/**
 * @file Turtle.h
 * @author fedor
 * @brief The header for the turtle class representing one turtle displayed by
 * the turtlesim node
 * @version 0.1
 * @date 2022-04-27
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef TURTLE_H
#define TURTLE_H

#include <string>

#include "ros/ros.h"

#include "turtlesim/Pose.h"


using std::string;

class Turtle {
private:
  string name;
  float speed;
  float speed_ang;
  float x;
  float y;
  float theta;

  float x_followed;
  float y_followed;
  float theta_followed;

  bool chasing;

public:
  /**
   * @brief Construct a new Turtle object and positions it at the given
   * coordinates
   *
   * @param handle the ros handle
   * @param init_x the initial x position
   * @param init_y the initial y position
   * @param speed the movement speed of the turtle
   */
  Turtle(ros ::NodeHandle handle, string name, float init_x, float init_y,
         float theta, float speed, float speed_ang);
  ~Turtle();

private:
  void chaseLoop(ros::NodeHandle handle);
  void chaseStep(ros::NodeHandle handle);
  void updatePositionFollowed(ros::NodeHandle handle);
  void positionPublishCallBack(const turtlesim::Pose::ConstPtr &msg);
};

#endif