//
// Created by Ben Trueman on 2019-03-30.
//

#ifndef DISCRETEEVENTSIMULATOR_BANK_H
#define DISCRETEEVENTSIMULATOR_BANK_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stdlib.h>
#include "Event.h"
#include "Store.h"
#define SIM_LENGTH 43200 //12 hours = 43,200 seconds
#define NUM_TELLERS 6
using namespace std;

class Bank {
private:
    std::queue<Event> bankQueue;
    int tellersAvailable = NUM_TELLERS;
    Store store;
public:
    void addBankCustomer(Event event);
    void runSim(Store *store);
};


#endif //DISCRETEEVENTSIMULATOR_BANK_H

