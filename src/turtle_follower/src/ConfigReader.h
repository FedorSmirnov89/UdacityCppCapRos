
#ifndef CONFIG_READ
#define CONFIG_READ 1

#include <vector>
#include <string>

using std::vector;
using std::string;

struct turtle_info{
    float x_pos;
    float y_pos;
    float thetha;
    float speed;
    float speed_ang;
    string name;
};


vector<turtle_info> readInput(string fileName);

#endif
