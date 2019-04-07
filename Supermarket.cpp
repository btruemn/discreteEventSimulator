//
// Created by Ben Trueman on 2019-03-30.
//

#include "Supermarket.h"


int calculateShortestLine(const array<int, 6> &cashiers) {
    int minIndex = 0;
    for (int i = 1; i < cashiers.size(); i++) {
        if (cashiers.at(minIndex) > cashiers.at(i)) {
            minIndex = i;
        }
    }
    return minIndex;
}

void Supermarket::runSim(Store *store) {
    while (!store->eventQueue.empty()) {
        Event nextEvent = store->eventQueue.top();
        store->currentTime = nextEvent.eventTime;
        if(store->currentTime > SIM_LENGTH){ //prevent simulation from exceeding intended length
            break;
        }
        store->eventQueue.pop();
        int shortestLine;
        switch (nextEvent.event) {
            case ARRIVAL:
                shortestLine = calculateShortestLine(cashiers);
                nextEvent.line = shortestLine;
                nextEvent.totalServiceTime = cashiers.at(shortestLine) + nextEvent.duration;
                cashiers.at(shortestLine) += nextEvent.duration;
                nextEvent.eventTime = store->currentTime + cashiers.at(shortestLine);
                nextEvent.event = DEPARTURE;
                store->addEvent(nextEvent);
                break;
            case DEPARTURE:
                cashiers.at(nextEvent.line) -= nextEvent.duration;
        store->serviceTimes.push_back(nextEvent.totalServiceTime);
                break;
        }
    }
}
