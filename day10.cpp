#include <iostream>
#include <fstream>
#include "day10.h"

// assignment: https://adventofcode.com/2021/day/10

// score map for syntax checker score
map<char, int> scoreMap = {
        {')', 3},
        {']', 57},
        {'}', 1197},
        {'>', 25137}
};

// function for parsing input file
void parser(vector<string> *navigation) {
    ifstream file("../input_day10.txt");

    if (file.is_open()) {      // checking if file is open
        string line;
        while (getline(file, line)) {
            navigation->push_back(line);       // pushing each line to vector
        }
    }
    file.close();
}

// print function for displaying found errors with chunkCheck()
void print(string chunk, int i, stack<char> chunkStack) {
    if (chunkStack.top() == '(')      // checking which bracket was expected
        cout << "Expected ) but found " << chunk[i] << " on " << i + 1 << ". position"
             << endl;     // printing error message
    else if (chunkStack.top() == '[')
        cout << "Expected ] but found " << chunk[i] << " on " << i + 1 << ". position" << endl;
    else if (chunkStack.top() == '{')
        cout << "Expected ] but found " << chunk[i] << " on " << i + 1 << ". position" << endl;
    else if (chunkStack.top() == '<')
        cout << "Expected > but found " << chunk[i] << " on " << i + 1 << ". position" << endl;

}

// function for checking if chunk is legal
int chunkCheck(string chunk) {
    stack<char> chunkStack;     // stack for storing opening brackets
    int score = 0;

    if (chunk[0] == ')' || chunk[0] == ']' || chunk[0] == '}' ||
        chunk[0] == '>') {     // if chunk starts with closing bracket it is illegal, no need to check further
        cout << "Illegal chunk \n" << endl;
        return scoreMap[chunk[0]];      // returning score for illegal chunk
    }

    for (int i = 0; i < chunk.length(); i++) {      // simple loop for going through all elements in chunk/line
        if (chunkStack.empty()) {
            chunkStack.push(
                    chunk[i]);      // if stack is empty there is no need for checking if current char is correct closing bracket, just pushing first bracket to stack
        } else {
            if (chunk[i] == ')' && chunkStack.top() == '(')       // checking if current char is correct closing bracket
                chunkStack.pop();       // if it is, popping last element from stack
            else if (chunk[i] == ']' && chunkStack.top() == '[')
                chunkStack.pop();
            else if (chunk[i] == '}' && chunkStack.top() == '{')
                chunkStack.pop();
            else if (chunk[i] == '>' && chunkStack.top() == '<')
                chunkStack.pop();
            else {
                if (chunk[i] == ')' && chunkStack.top() != '(') {
//                    print(chunk, i, chunkStack);       // printing error message
                    score = scoreMap[chunk[i]];        // getting score for illegal chunk
                    break;
                } else if (chunk[i] == ']' && chunkStack.top() != '[') {
//                    print(chunk, i, chunkStack);
                    score = scoreMap[chunk[i]];
                    break;
                } else if (chunk[i] == '}' && chunkStack.top() != '{') {
//                    print(chunk, i, chunkStack);
                    score = scoreMap[chunk[i]];
                    break;
                } else if (chunk[i] == '>' && chunkStack.top() != '<') {
//                    print(chunk, i, chunkStack);
                    score = scoreMap[chunk[i]];
                    break;
                }
                chunkStack.push(chunk[i]);      // if current char is opening bracket, pushing it to stack
            }
        }
    }
    return score;       // returning score for chunk
}

// function for checking syntax of navigation subsystem
int syntaxChecker(vector<string> navSubsystem) {
    int score = 0;
    for (string sys: navSubsystem) {     // simple loop for going through all lines in navSubsystems
        score += chunkCheck(sys);       // adding score for each line to total score
    }
    cout << "Day 10 score: " << score << endl;     // printing total score
    cout << endl;
    return score;       // returning total score
}