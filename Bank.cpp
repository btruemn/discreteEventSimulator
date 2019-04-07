//
// Created by Ben Trueman on 2019-03-30.
//

#include "Bank.h"

void Bank::addBankCustomer(Event event) {
    bankQueue.push(event);
}

void Bank::runSim(Store *store) {
    while (!store->eventQueue.empty()) {
        Event nextEvent = store->eventQueue.top();
        store->currentTime = nextEvent.eventTime;
        if(store->currentTime > SIM_LENGTH){ //prevent simulation from exceeding intended length
            break;
        }
        store->eventQueue.pop();
        switch (nextEvent.event) {
            case ARRIVAL:
                if (tellersAvailable) {
                    nextEvent.totalServiceTime = nextEvent.duration;
                    nextEvent.eventTime += nextEvent.duration;
                    nextEvent.event = DEPARTURE;
                    store->addEvent(nextEvent);
                    tellersAvailable--;
                } else {
                    addBankCustomer(nextEvent);
                }
                break;
            case DEPARTURE:
                if (!bankQueue.empty()) {
                    store->serviceTimes.push_back(nextEvent.totalServiceTime);
                    Event nextCustomer = bankQueue.front();
                    bankQueue.pop();
                    nextCustomer.totalServiceTime = store->currentTime - nextCustomer.eventTime + nextCustomer.duration;
                    nextCustomer.eventTime = store->currentTime + nextEvent.duration; //set departure time
                    nextCustomer.event = DEPARTURE;
                    store->addEvent(nextCustomer);
                } else {
                    store->serviceTimes.push_back(nextEvent.totalServiceTime);
                    tellersAvailable++;
                }
                break;
        }
    }
}
