//
// Created by Ben Trueman on 2019-03-30.
//

#ifndef DISCRETEEVENTSIMULATOR_SUPERMARKET_H
#define DISCRETEEVENTSIMULATOR_SUPERMARKET_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stdlib.h>
#include <array>
#include "Event.h"

#define SIM_LENGTH 43200 //12 hours = 43,200 seconds
#define NUM_TELLERS 6
using namespace std;

class Supermarket {
private:
    priority_queue<Event, vector<Event>, compareEventTime> eventQueue;
    array<int, 6> cashiers;
    double currentTime = 0;

public:
    vector<double> serviceTimes;
    void addEvent(Event event);
    void runSim();
    void calcAvgServiceTime();
    void printEventInfo(const Event &event);
};

#endif //DISCRETEEVENTSIMULATOR_SUPERMARKET_H
