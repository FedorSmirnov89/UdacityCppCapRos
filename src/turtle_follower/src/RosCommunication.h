#ifndef ROSCOMM_H
#define ROCCOMM_H 1

#include "ros/ros.h"
#include <string>
#include <vector>


using std::string;
using std::vector;

//void spawnFollower(ros::Nodehandle handle, std::string name, float xpos, float ypos);

void clearField(ros::NodeHandle handle);

void killControlledTurtle(ros::NodeHandle handle);

void spawnControlledTurtle(ros::NodeHandle handle);

void spawnTurtle(ros::NodeHandle handle, string name, float x, float y, float theta);

void reset(ros::NodeHandle handle);

void setPosition(ros::NodeHandle handle, string name, float x, float y, float theta);


#endif