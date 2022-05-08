
#include "Calculations.h"
#include <cmath>
#include <math.h>

float calcThetaStep(float thetaFollowed, float thetaFollower, float speed_ang) {
  // check whether we are in the overflow area
  if (thetaFollower > 1.57 && thetaFollowed < -1.57) {
    thetaFollowed = thetaFollowed + 6.28;
  } else if (thetaFollowed > 1.57 && thetaFollower < -1.57) {
    thetaFollower = thetaFollower + 6.28;
  }

  float result;

  if (abs(thetaFollowed - thetaFollower) < speed_ang) {
    result = abs(thetaFollowed - thetaFollower);
  } else {
    result = speed_ang;
  }

  if (thetaFollowed > thetaFollower) {
    return result;
  } else {
    return -result;
  }
}

float calculateFollowerTheta(float xFollowed, float yFollowed, float xFollower,
                             float yFollower) {

  float deltaX = xFollowed - xFollower;
  float deltaY = yFollowed - yFollower;
  return atan2(deltaY, deltaX);
}

float calcAbsDist(float xFollowed, float yFollowed, float xFollower,
                  float yFollower) {
  float deltaX = xFollowed - xFollower;
  float deltaY = yFollowed - yFollower;
  return sqrt(deltaX * deltaX + deltaY * deltaY);
}

float calcStep(float xFollowed, float yFollowed, float xFollower,
               float yFollower, float speed, bool xCalc) {
  float followed = xCalc ? xFollowed : yFollowed;
  float follower = xCalc ? xFollower : yFollower;

  float delta = followed - follower;
  float dist = calcAbsDist(xFollowed, yFollowed, xFollower, yFollower);
  float normalStep = delta / dist;
  float speedStep = normalStep * speed;
  if (abs(speedStep) < abs(delta)) {
    return speedStep;
  } else {
    return delta;
  }
}

float calcXStep(float xFollowed, float yFollowed, float xFollower,
                float yFollower, float speed) {
  return calcStep(xFollowed, yFollowed, xFollower, yFollower, speed, true);
}

float calcYStep(float xFollowed, float yFollowed, float xFollower,
                float yFollower, float speed) {
  return calcStep(xFollowed, yFollowed, xFollower, yFollower, speed, false);
}