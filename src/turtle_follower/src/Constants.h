#ifndef CONSTANTS_H
#define CONSTANTS_H 1

#include <string>

using std::string;

// numbers
const int loopRateNodes = 100;

const int speedFollowOne = 10;


// traits of the controlled turtle
const string controlledTurtleName = "turtle1";
const float controlledX = 5.2;
const float controlledY = 5.2;
const float controlledTheta = 1;

// file paths
const string easyPath = "./src/turtle_follower/configs/easy.txt";
const string mediumPath = "./src/turtle_follower/configs/medium.txt";
const string hardPath = "./src/turtle_follower/configs/hard.txt";

#endif

