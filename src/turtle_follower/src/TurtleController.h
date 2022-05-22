
#ifndef T_CONTR
#define T_CONTR 1

#include "Turtle.h"
#include "turtlesim/Pose.h"
#include <vector>

#include "ros/ros.h"

using std::vector;

class TurtleController {

public:
  TurtleController(ros::NodeHandle handle);
  ~TurtleController();

  void addManagedTurtle(Turtle&& turtle);
  void controlCallBack(const turtlesim::Pose::ConstPtr &msg);

private:
  vector<Turtle> managedTurtles;
  ros::NodeHandle handle;
};

#endif
