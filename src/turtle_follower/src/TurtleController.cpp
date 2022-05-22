
#include "TurtleController.h"
#include <future>
#include <vector>

TurtleController::TurtleController(ros::NodeHandle handle) {
  this->managedTurtles = vector<Turtle>();
  this->handle = handle;
}

TurtleController::~TurtleController() {}

void TurtleController::addManagedTurtle(Turtle &&turtle) {
  this->managedTurtles.emplace_back(std::move(turtle));
}

void TurtleController::controlCallBack(const turtlesim::Pose::ConstPtr &msg) {
  float targetX = msg->x;
  float targetY = msg->y;

  std::vector<std::future<void>> futureVector = vector<std::future<void>>();
  
  for (Turtle &turtle : this->managedTurtles) {
    futureVector.emplace_back(
        std::async(&Turtle::chaseStep, &turtle, targetX, targetY, handle));    
  }

  for (std::future<void> &ftr : futureVector) {
    ftr.get();
  }
}