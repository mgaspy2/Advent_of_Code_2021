#include "day14.h"

// assignment: https://adventofcode.com/2021/day/14

//string polyTemplate = "NNCB";
//vector<string> insertionRules = {
//        "CH -> B",
//        "HH -> N",
//        "CB -> H",
//        "NH -> C",
//        "HB -> C",
//        "HC -> B",
//        "HN -> C",
//        "NN -> C",
//        "BH -> H",
//        "NC -> B",
//        "NB -> B",
//        "BN -> B",
//        "BB -> N",
//        "BC -> B",
//        "CC -> N",
//        "CN -> C",
//};

void parser(Polymer *polymer) {
    ifstream file("../input_day14.txt");
    if (file.is_open()) {
        string key, value;
        getline(file, polymer->polymerName);
        file.ignore(10, '\n');
        while (file >> key && getline(file, value, '>') && file >> value) {
            polymer->insertionRules.insert(pair<string, string>(key, value));
        }
    }
    file.close();

//    cout << polymer->polymerName << endl;
//    for (auto &rule : polymer->insertionRules)
//        cout << rule.first << "   " << rule.second << endl;
}

void pairInsertion(Polymer *polymer) {
    stack<char> polymerStack;
    string newPolymer = "";

    for (int i = 0; i < polymer->polymerName.length(); i++) {
        if (polymerStack.empty()) {
            polymerStack.push(polymer->polymerName[i]);
        } else {
            string pair = "";
            pair += polymerStack.top();
            pair += polymer->polymerName[i];
            if (polymer->insertionRules.find(pair) != polymer->insertionRules.end()) {
                newPolymer += polymerStack.top();
                newPolymer += polymer->insertionRules[pair];
                polymerStack.pop();
                polymerStack.push(polymer->polymerName[i]);
            }
        }
    }

    newPolymer += polymerStack.top();
    polymer->polymerName = newPolymer;
}

void pairInsertions(Polymer *polymer, int num) {
    for (int i = 0; i < num; i++) {
        pairInsertion(polymer);
//        cout << polymer->polymerName << endl;
    }
}

int scoreCounter(Polymer *polymer) {
    for (auto letter: polymer->polymerName) {
        if (polymer->scoreMap.find(string(1, letter)) != polymer->scoreMap.end()) {
            polymer->scoreMap[string(1, letter)]++;
        } else {
            polymer->scoreMap.insert(pair<string, int>(string(1, letter), 1));
        }


    }

    for (auto &rule: polymer->scoreMap)
        cout << rule.first << "   " << rule.second << endl;

    int highestValue = -1, lowestValue = numeric_limits<int>::max(), score = 0;
    for (auto entry: polymer->scoreMap) {
        if (entry.second > highestValue) {
            highestValue = entry.second;
        } else if (entry.second < lowestValue) {
            lowestValue = entry.second;
        }
    }

    score = highestValue - lowestValue;
    cout << "highestValue: " << highestValue << endl;
    cout << "lowestValue: " << lowestValue << endl;
    return score;
}
