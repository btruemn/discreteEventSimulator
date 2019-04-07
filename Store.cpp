//
//  Store.cpp
//  benSimulator
//
//  Created by Sarah Schuster-Johnson on 4/7/19.
//  Copyright © 2019 Sarah Schuster-Johnsobn. All rights reserved.
//

#include "Store.h"

void Store::calcAvgServiceTime() {
    double avgServiceTime = 0;
    cout << serviceTimes.size() << endl;
    for (double time: serviceTimes) {
        avgServiceTime += time;
    }
    avgServiceTime /= serviceTimes.size();
    avgServiceTime /= 60; //convert seconds to minutes
    cout << "Avg Service Time: " << avgServiceTime << endl;
}

void Store::addEvent(Event &event) {
    eventQueue.push(event);
}

void Store::printEventInfo(const Event &event) {
    cout << "Customer#: " << event.customerId << endl;
    cout << "Time: " << event.eventTime << endl;
    cout << "Duration: " << event.duration << endl;
    cout << "Event type: ";
    if (event.event == ARRIVAL) cout << "ARRIVAL\n" << endl;
    else cout << "DEPARTURE\n" << endl;
}

