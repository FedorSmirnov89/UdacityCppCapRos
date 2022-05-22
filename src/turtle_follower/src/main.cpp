
#include "ConfigReader.h"
#include "Constants.h"
#include "InputReader.h"
#include "RosCommunication.h"
#include "Turtle.h"
#include "TurtleController.h"

#include <iostream>
#include <string>

int main(int argc, char **argv) {
  // init ROS
  ros::init(argc, argv, "turtle_followers");
  ros::NodeHandle rosHandle;

  // Ask the user to provide a difficulty level
  int chosenDifficulty = getDifficulty();
  string configFilePath;

  // Set the config file path resulting from the chosen difficulty
  if (chosenDifficulty == 1) {
    configFilePath = easyPath;
  } else if (chosenDifficulty == 2) {
    configFilePath = mediumPath;
  } else {
    configFilePath = hardPath;
  }

  // Read the config file and get the follower settings
  vector<turtle_info> followersInfo = readInput(configFilePath);

  // START OF THE BOARD MANIPULATION

  // wipe the board so that we start in a controlled state
  reset(rosHandle);

  // spawn the turtle which will be controlled by our actions
  spawnControlledTurtle(rosHandle);

  TurtleController controller(rosHandle);

  // spawn the follower turtles -- each turtle spawned in its own thread
  for (turtle_info followerInfo : followersInfo) {
    Turtle followerTurtle(rosHandle, followerInfo.name, followerInfo.x_pos,
                          followerInfo.y_pos, followerInfo.thetha,
                          followerInfo.speed, followerInfo.speed_ang);
    controller.addManagedTurtle(std::move(followerTurtle));
  }

  // subscribe to the lead position and start spinning

  ros::Subscriber sub = rosHandle.subscribe(
      "/turtle1/pose", 1000, &TurtleController::controlCallBack, &controller);
  ros::spin();

  return 0;
}
