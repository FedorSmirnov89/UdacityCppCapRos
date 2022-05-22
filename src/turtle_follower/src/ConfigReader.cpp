#include "ConfigReader.h"

#include <iostream>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::istringstream;
using std::cout;

vector<turtle_info> readInput(string fileName){

    vector<turtle_info> result;
    string line;
    ifstream configFile(fileName);

    if (configFile.is_open()){
        while(getline(configFile, line)){
            istringstream iss (line);

            float xPos;
            float yPos;
            float thetha;
            float speed;
            float speed_ang;
            string name;

            iss >> xPos;
            iss >> yPos;
            iss >> thetha;
            iss >> speed;
            iss >> speed_ang;
            iss >> name;
            
            struct turtle_info entry = {xPos, yPos, thetha, speed, speed_ang, name};
            result.push_back(entry);
        }
        configFile.close();
    }else{
        cout << "error";        
    }    
    return result;
}