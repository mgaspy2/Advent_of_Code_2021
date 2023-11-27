#include <iostream>
#include "day17.h"

// assignment: https://adventofcode.com/2021/day/17

// function for checking whether the probe hit the target at the specified speed parameters
bool Probe::launch(int xVel, int yVel, Area target) {
    x_velocity = xVel;
    y_velocity = yVel;

    while ((x_position <= target.x_max) && (y_position >= target.y_min)) {      // loop for simulation of probe's flight
        x_position += x_velocity;
        y_position += y_velocity;

        y_velocity -= 1;        // gravity
        if (x_velocity > 0)
            x_velocity -= 1;        // air resistance if probe is moving in x direction

        if (y_position > max_yPos)
            max_yPos = y_position;      // storing maximal y position

        if((x_position <= target.x_max)&&(x_position >= target.x_min)&&(y_position <= target.y_max)&&(y_position >= target.y_min)){     // checking if probe landed in target area
            return true;        // returning true if probe landed in target area
        }
    }
    return false;       // returning false if probe missed target
}

// function for searching the speed parameters of the probe to reach the highest y position
int Probe::automaticLaunch(Area target) {
    highestScore = target.y_min;        // variable for storing the highest score initialized with the lowest possible score
    for(int xVel = 0; xVel <= target.x_max; xVel++) {           // loop for searching the x velocity parameters
        for (int yVel = 0; (-yVel) >= target.y_min; yVel++) {       // loop for searching the y velocity parameters
            if (launch(xVel, yVel, target)) {       // checking if probe hit the target
                if (max_yPos > highestScore) {
                    highestScore = max_yPos;        // storing the highest score
                }
            }
            x_position = 0;     // resetting probe's telemetry
            y_position = 0;
            max_yPos = 0;
        }
    }
    cout << "Day 17 score: " << highestScore << endl;
    cout << endl;
    return highestScore;
}

// function for printing probe's telemetry and score
void Probe::print() {
    cout << "x velocity: " << x_velocity << endl;
    cout << "y velocity: " << y_velocity << endl;
    cout << "max y position: " << max_yPos << endl;
    cout << "highest score: " << highestScore << endl;
    cout << endl;
}
