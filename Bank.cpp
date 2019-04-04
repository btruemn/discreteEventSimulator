//
// Created by Ben Trueman on 2019-03-30.
//

#include "Bank.h"

void Bank::printEventInfo(const Event &event) {
    cout << "Customer#: " << event.customerId << endl;
    cout << "Time: " << event.eventTime << endl;
    cout << "Duration: " << event.duration << endl;
    cout << "Event type: ";
    if (event.event == ARRIVAL) cout << "ARRIVAL\n" << endl;
    else cout << "DEPARTURE\n" << endl;
}

void Bank::calcAvgServiceTime() {
    double avgServiceTime = 0;
    cout << serviceTimes.size() << endl;
    for (double time: serviceTimes) {
        avgServiceTime += time;
    }
    avgServiceTime /= serviceTimes.size();
    avgServiceTime /= 60; //convert seconds to minutes
    cout << "Avg Service Time: " << avgServiceTime << endl;
}

void Bank::addEvent(Event &event) {
    eventQueue.push(event);
}

void Bank::addBankCustomer(Event event) {
    bankQueue.push(event);
}

void Bank::runSim() {
    while (!eventQueue.empty()) {
        Event nextEvent = eventQueue.top();
        currentTime = nextEvent.eventTime;
        if(currentTime > SIM_LENGTH){ //prevent simulation from exceeding intended length
            break;
        }
        eventQueue.pop();
        switch (nextEvent.event) {
            case ARRIVAL:
                if (tellersAvailable) {
                    nextEvent.totalServiceTime = nextEvent.duration;
                    nextEvent.eventTime += nextEvent.duration;
                    nextEvent.event = DEPARTURE;
                    addEvent(nextEvent);
                    tellersAvailable--;
                } else {
                    addBankCustomer(nextEvent);
                }
                break;
            case DEPARTURE:
                if (!bankQueue.empty()) {
                    serviceTimes.push_back(nextEvent.totalServiceTime);
                    Event nextCustomer = bankQueue.front();
                    bankQueue.pop();
                    nextCustomer.totalServiceTime = currentTime - nextCustomer.eventTime + nextCustomer.duration;
                    nextCustomer.eventTime = currentTime + nextEvent.duration; //set departure time
                    nextCustomer.event = DEPARTURE;
                    addEvent(nextCustomer);
                } else {
                    serviceTimes.push_back(nextEvent.totalServiceTime);
                    tellersAvailable++;
                }
                break;
        }
    }
}