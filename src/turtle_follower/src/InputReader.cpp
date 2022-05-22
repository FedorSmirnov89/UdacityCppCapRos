
#include "InputReader.h"
#include <iostream>
#include <limits>
#include <ios>
#include <string>

using std::cin;
using std::cout;
using std::string;

int getDifficulty() {

  while (true) {
    cout << "Please enter the desired difficulty: ";
    cout << "1: easy; 2: medium; 3: hard.\n";

    int userChoice;
    string wrongInput;

    cin >> userChoice;

    if (!cin.fail()){
        if (userChoice == 1 || userChoice == 2 || userChoice == 3){
            return userChoice;
        }else{
            cout << "Invalid entry. The only valid choices are 1, 2, or 3.\n\n";
        }
    }else{
        cin.clear();
        cin >> wrongInput;
        cout << "you entered \"" << wrongInput << "\"\n";
        cout << "Please enter a number, not a string.\n\n";
    }    
  }
}