
#include "Constants.h"

#include "RosCommunication.h"

#include "ros/ros.h"

#include "turtlesim/Kill.h"
#include "turtlesim/Spawn.h"
#include "turtlesim/TeleportAbsolute.h"

#include "std_srvs/Empty.h"


void setPosition(ros::NodeHandle handle, string name, float x, float y, float theta){
    string serviceName = "/" + name + "/teleport_absolute";
    ros::ServiceClient client = handle.serviceClient<turtlesim::TeleportAbsolute>(serviceName);
    turtlesim::TeleportAbsolute srv_teleport;
    srv_teleport.request.x = x;
    srv_teleport.request.y = y;
    srv_teleport.request.theta = theta;
    client.call(srv_teleport);
}

void spawnTurtle(ros::NodeHandle handle, string name, float x, float y,
                 float theta) {
  ros::ServiceClient client = handle.serviceClient<turtlesim::Spawn>("/spawn");
  turtlesim::Spawn srv_spawn;
  srv_spawn.request.x = x;
  srv_spawn.request.y = y;
  srv_spawn.request.theta = theta;
  srv_spawn.request.name = name;
  client.call(srv_spawn);
}

void reset(ros::NodeHandle handle){
    ros::ServiceClient client = handle.serviceClient<std_srvs::Empty>("/reset");
    std_srvs::Empty srv_empty;
    client.call(srv_empty);
}

void spawnControlledTurtle(ros::NodeHandle handle) {
  spawnTurtle(handle, controlledTurtleName, controlledX,
              controlledY, controlledTheta);
}

void killControlledTurtle(ros::NodeHandle handle) {
  ros::ServiceClient client = handle.serviceClient<turtlesim::Kill>("/kill");
  turtlesim::Kill srv_kill;
  srv_kill.request.name = controlledTurtleName;
  client.call(srv_kill);
}

void clearField(ros::NodeHandle handle) {
  ros::ServiceClient client = handle.serviceClient<std_srvs::Empty>("/clear");
  std_srvs::Empty srv_empty;
  client.call(srv_empty);
}