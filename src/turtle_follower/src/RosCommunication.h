/**
 * @file RosCommunication.h
 * @author Fedor Smirnov
 * @brief Header file for the functions used to dispatch messages to communicate
 * with other ROS nodes.
 */

#ifndef ROSCOMM_H
#define ROCCOMM_H 1

#include "ros/ros.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

/**
 * @brief Clears the paths of the currently displayed turtles.
 *
 * @param handle The ROS handle of this node
 */
void clearField(ros::NodeHandle handle);

/**
 * @brief Kills the turtle controlled by user input.
 *
 * @param handle The ROS handle of this node
 */
void killControlledTurtle(ros::NodeHandle handle);

/**
 * @brief Spawns the controlled turtle on the point defined in the constants.
 *
 * @param handle The ROS handle of this node
 */
void spawnControlledTurtle(ros::NodeHandle handle);


void spawnTurtle(ros::NodeHandle handle, string name, float x, float y,
                 float theta);

void reset(ros::NodeHandle handle);

void setPosition(ros::NodeHandle handle, string name, float x, float y,
                 float theta);

#endif