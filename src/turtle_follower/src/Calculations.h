#ifndef CALCULATIONS_H
#define CALCULATIONS_H 1

/**
 * @brief Calculates the angle which a follower turtle would have to assume to
 * be facing into the direction of the followed turtle.
 *
 * @param xFollowed
 * @param yFollowed
 * @param xFollower
 * @param yFollower
 * @return float
 */
float calculateFollowerTheta(float xFollowed, float yFollowed, float xFollower,
                             float yFollower);

/**
 * @brief Calculates the angle step to make
 *
 */
float calcThetaStep(float thetaFollowed, float thetaFollower, float speed_ang);

/**
 * @brief Calculates the step to take into the X direction
 *
 * @param xFollowed
 * @param yFollowed
 * @param xFollower
 * @param yFollower
 * @param speed
 * @return float
 */
float calcXStep(float xFollowed, float yFollowed, float xFollower,
                float yFollower, float speed);

/**
 * @brief Calculates the step to take into the Y direction
 *
 * @param xFollowed
 * @param yFollowed
 * @param xFollower
 * @param yFollower
 * @param speed
 * @return float
 */
float calcYStep(float xFollowed, float yFollowed, float xFollower,
                float yFollower, float speed);

#endif