//
// Created by Ben Trueman on 2019-03-30.
//

#include "Supermarket.h"

void Supermarket::printEventInfo(const Event &event) {
    cout << "Customer#: " << event.customerId << endl;
    cout << "Time: " << event.eventTime << endl;
    cout << "Duration: " << event.duration << endl;
    cout << "Event type: ";
    if (event.event == ARRIVAL) cout << "ARRIVAL\n" << endl;
    else cout << "DEPARTURE\n" << endl;
}

void Supermarket::calcAvgServiceTime() {
    double avgServiceTime = 0;
    for (double time: serviceTimes) {
        avgServiceTime += time;
    }
    avgServiceTime /= serviceTimes.size();
    avgServiceTime /= 60; //convert seconds to minutes
    cout << "Avg Service Time: " << avgServiceTime << endl;
}

void Supermarket::addEvent(Event event) {
    eventQueue.push(event);
}

int calculateShortestLine(const array<int, 6> &cashiers) {
    int minIndex = 0;
    for (int i = 1; i < cashiers.size(); i++) {
        if (cashiers.at(minIndex) > cashiers.at(i)) {
            minIndex = i;
        }
    }
    return minIndex;
}

void Supermarket::runSim() {
    while (!eventQueue.empty()) {
        Event nextEvent = eventQueue.top();
        currentTime = nextEvent.eventTime;
        if(currentTime > SIM_LENGTH){ //prevent simulation from exceeding intended length
            break;
        }
        eventQueue.pop();
        int shortestLine;
        switch (nextEvent.event) {
            case ARRIVAL:
                shortestLine = calculateShortestLine(cashiers);
                nextEvent.line = shortestLine;
                nextEvent.totalServiceTime = cashiers.at(shortestLine) + nextEvent.duration;
                cashiers.at(shortestLine) += nextEvent.duration;
                nextEvent.eventTime = currentTime + cashiers.at(shortestLine);
                nextEvent.event = DEPARTURE;
                addEvent(nextEvent);
                break;
            case DEPARTURE:
                cashiers.at(nextEvent.line) -= nextEvent.duration;
                serviceTimes.push_back(nextEvent.totalServiceTime);
                break;
        }
    }
}