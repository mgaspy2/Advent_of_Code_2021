#include <iostream>
#include "day10.h"
#include "day14.h"

int main() {
// Day 10 ----------------------------------------------------------------------------------------------
//    vector<string> navSys;
//    parser(&navSys);
//    syntaxChecker(navSys);

// Day 14 ----------------------------------------------------------------------------------------------
    Polymer day14Polymer;
    parser(&day14Polymer);
    pairInsertions(&day14Polymer, 10);
    scoreCounter(&day14Polymer);
}