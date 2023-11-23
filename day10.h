#ifndef ADVENT_OF_CODE_2021_DAY10_H
#define ADVENT_OF_CODE_2021_DAY10_H

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <map>

using namespace std;

extern vector<string> navSubsystems;
extern map<char, int> scoreMap;

void print(string, int, stack<char>);
int chunkCheck(string);
int syntaxChecker(vector<string>);

#endif //ADVENT_OF_CODE_2021_DAY10_H
