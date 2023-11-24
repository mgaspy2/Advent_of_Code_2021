#include "day14.h"

// assignment: https://adventofcode.com/2021/day/14

// parser for input data
void parser(Polymer *polymer) {
    ifstream file("../input_day14.txt");
    if (file.is_open()) {
        string key, value;
        getline(file, polymer->polymerName);        // reading and writing polymer name
        file.ignore(10, '\n');
        while (file >> key && getline(file, value, '>') && file >> value) {     // reading insertion rules
            polymer->insertionRules.insert(pair<string, string>(key, value));       // inserting rules into map
        }
    }
    file.close();

//    cout << polymer->polymerName << endl;
//    for (auto &rule : polymer->insertionRules)
//        cout << rule.first << "   " << rule.second << endl;
}

// function for inserting pairs into polymer
void pairInsertion(Polymer *polymer) {
    stack<char> polymerStack;       // stack for storing polymer chars
    string newPolymer = "";     // string for storing new polymer

    for (int i = 0; i < polymer->polymerName.length(); i++) {       // loop for going through polymer
        if (polymerStack.empty()) {
            polymerStack.push(polymer->polymerName[i]);     // if stack is empty, pushing first char to stack
        } else {
            string pair = "";
            pair += polymerStack.top();
            pair += polymer->polymerName[i];        // creating pair of chars
            if (polymer->insertionRules.find(pair) !=
                polymer->insertionRules.end()) {      // checking if pair is in insertion rules
                newPolymer += polymerStack.top();
                newPolymer += polymer->insertionRules[pair];        // if it is, inserting first char from pair and value from map
                polymerStack.pop();
                polymerStack.push(polymer->polymerName[i]);     // pushing second (current) char from pair to stack
            }
        }
    }

    newPolymer += polymerStack.top();       // adding last char from stack to new polymer
    polymer->polymerName = newPolymer;      // overwriting polymer name with new polymer

}

// function for inserting pairs into polymer multiple times
void pairInsertions(Polymer *polymer, int num) {
    for (int i = 0; i < num; i++) {
        pairInsertion(polymer);
    }
}

// function for counting score of polymer
int scoreCounter(Polymer *polymer) {
    for (auto letter: polymer->polymerName) {       // loop for counting score of polymer
        if (polymer->scoreMap.find(string(1, letter)) != polymer->scoreMap.end()) {     // checking if letter is in score map
            polymer->scoreMap[string(1, letter)]++;     // if it is, incrementing score
        } else {
            polymer->scoreMap.insert(
                    pair<string, int>(string(1, letter), 1));      // if it is not, inserting letter into score map
        }
    }

//    for (auto &rule: polymer->scoreMap)
//        cout << rule.first << "   " << rule.second << endl;       // printing score map

    int highestValue = -1, lowestValue = numeric_limits<int>::max(), score = 0;
    for (auto entry: polymer->scoreMap) {       // loop for finding highest and lowest value in score map
        if (entry.second > highestValue) {
            highestValue = entry.second;
        } else if (entry.second < lowestValue) {
            lowestValue = entry.second;
        }
    }

    score = highestValue - lowestValue;
    cout << "Day 14 score: " << score << endl;     // printing score
    return score;
}