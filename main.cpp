#include <iostream>
#include "day10.h"
#include "day14.h"

int main() {
// Day 10 ----------------------------------------------------------------------------------------------
//    ifstream file("../input_day10.txt");
//
//    if (!file.is_open()) {      // checking if file is open
//        cout << "Error opening file." << std::endl;
//        return 1; // Return an error code
//    }
//
//    vector<string> navSys;
//    string line;
//    while (getline(file, line)) {
//        navSys.push_back(line);
//    }
//    file.close();
//
//    syntaxChecker(navSys);
//    syntaxChecker(navSubsystems);

// Day 14 ----------------------------------------------------------------------------------------------
    Polymer day14Polymer;
    parser(&day14Polymer);
    pairInsertions(&day14Polymer, 10);
    cout << scoreCounter(&day14Polymer) << endl;
}
