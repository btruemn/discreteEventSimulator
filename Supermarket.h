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
#include "Store.h"

#define SIM_LENGTH 43200 //12 hours = 43,200 seconds
#define NUM_TELLERS 6
using namespace std;

class Supermarket {
private:
    array<int, 6> cashiers;
    
public:
    void runSim(Store *store);
    void printEventInfo(const Event &event);
};

#endif //DISCRETEEVENTSIMULATOR_SUPERMARKET_H
