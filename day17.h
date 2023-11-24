#ifndef ADVENT_OF_CODE_2021_DAY17_H
#define ADVENT_OF_CODE_2021_DAY17_H

using namespace std;

struct Area {       // struct for storing the area of the target
    int x_min;
    int x_max;
    int y_min;
    int y_max;

    // constructor for the Area
    Area(int x1, int x2, int y1, int y2) : x_min(x1), x_max(x2), y_min(y1), y_max(y2) {}
};

class Probe {       // class for storing the probe's telemetry
    int x_velocity = 0;
    int y_velocity = 0;
    int x_position = 0;
    int y_position = 0;
    int max_yPos = 0;

    bool launch(int, int, Area);

public:
    int automaticLaunch(Area);
};

#endif //ADVENT_OF_CODE_2021_DAY17_H