#ifndef ADVENT_OF_CODE_2021_DAY14_H
#define ADVENT_OF_CODE_2021_DAY14_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <limits>

using namespace std;

class Polymer {     // class for storing polymer name, insertion rules and score map
public:
    string polymerName;
    map<string, string> insertionRules;
    map<string, int> scoreMap;
};

void parser(Polymer *);

void pairInsertion(Polymer *);

void pairInsertions(Polymer *, int);

int scoreCounter(Polymer *);

#endif //ADVENT_OF_CODE_2021_DAY14_H