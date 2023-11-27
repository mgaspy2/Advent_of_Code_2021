#ifndef ADVENT_OF_CODE_2021_DAY14_H
#define ADVENT_OF_CODE_2021_DAY14_H

using namespace std;

class Polymer {     // class for storing polymer name, insertion rules and score map
public:
    string polymerName;
    map<string, string> insertionRules;
    map<string, int> scoreMap;
    int score;
};

void parser(Polymer *);

void pairInsertion(Polymer *);

void pairInsertions(Polymer *, int);

int scoreCounter(Polymer *);

void print(Polymer *);

#endif //ADVENT_OF_CODE_2021_DAY14_H