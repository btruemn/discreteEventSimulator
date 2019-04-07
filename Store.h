//
//  Store.hpp
//  benSimulator
//
//  Created by Sarah Schuster-Johnson on 4/7/19.
//  Copyright © 2019 Sarah Schuster-Johnsobn. All rights reserved.
//

#ifndef Store_hpp
#define Store_hpp

#include <stdio.h>
#include <queue>
#include <iostream>
#include "Event.h"
using std::cout;

class Store{
public:
    priority_queue<Event, vector<Event>, compareEventTime> eventQueue;
    double currentTime = 0;
    vector<double> serviceTimes;
    void addEvent(Event &event);
    void calcAvgServiceTime();
    void printEventInfo(const Event &event);
};
#endif /* Store_hpp */
