/**
 * @file InputReader.h
 * @author Fedor Smirnov
 * @brief Prompts the user for a difficulty setting and returns the value chosen
 * by the user.
 *
 */

#ifndef INPUT_READER
#define INPUT_READER 1

/**
 * @brief Queries the user for the difficulty setting. Remains in an endless
 * loop until a valid option (1, 2, or 3) has been entered.
 *
 * @return int 1: easy, 2: medium; 3: hard
 */
int getDifficulty();

#endif