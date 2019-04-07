//
// Created by Ben Trueman on 2019-03-30.
//

#ifndef DISCRETEEVENTSIMULATOR_EVENT_H
#define DISCRETEEVENTSIMULATOR_EVENT_H

#include <vector>

using namespace std;

enum EventType {
    ARRIVAL, DEPARTURE
};

struct Event {
    double eventTime; //time event will occur (first arrival time, then departure time)
    double duration; //how long the customer takes to be serviced
    double totalServiceTime = 0;
    int customerId;
    int line;
    EventType event;
};

struct compareEventTime {
    bool operator()(const Event &lhs, const Event &rhs) const {
        return lhs.eventTime > rhs.eventTime;
    }
};


#endif //DISCRETEEVENTSIMULATOR_EVENT_H

