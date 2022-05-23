/**
 * @file TurtleController.h
 * @author Fedor Smirnov
 * @brief Used to manage a list of follower turtles and to react to the position
 * of the followed turtle by triggerring the movement of the managed turtles.
 */

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

  /**
   * @brief Adds a turtle to the list of managed follower turtles.
   *
   * @param turtle the turtle to add
   */
  void addManagedTurtle(Turtle &&turtle);

  /**
   * @brief Callback method used for subscribing to the coordinates of the
   * followed turtle.
   *
   * @param msg the message with the coordinates of the followed turtle.
   */
  void controlCallBack(const turtlesim::Pose::ConstPtr &msg);

private:
  vector<Turtle> managedTurtles;
  ros::NodeHandle handle;
};

#endif
