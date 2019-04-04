//
// Created by Ben Trueman on 2019-03-29.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stdlib.h>
#include <iomanip>
#include "Supermarket.h"
#include "Bank.h"

#define SIM_LENGTH 43200 //12 hours = 43,200 seconds
#define SECONDS_PER_MINUTE 60
using namespace std;

double get90thPercentile(vector<double> &serviceTimes, string name){
    sort(serviceTimes.begin(),serviceTimes.end());
    int service10thIndex = .1 * serviceTimes.size();
    int service50thIndex = .5 * serviceTimes.size();
    int service90thIndex = .9 * serviceTimes.size();

    double valueAt10th = serviceTimes.at(service10thIndex)/60;
    double valueAt50th = serviceTimes.at(service50thIndex)/60;
    double valueAt90th = serviceTimes.at(service90thIndex)/60;

//    cout << fixed << setprecision(2) << name << " service times in minutes: \n";
//    cout << "10th:\t" << valueAt10th << endl;
//    cout << "50th:\t" << valueAt50th << endl;
    return valueAt90th;
}

int main(int argc, const char *argv[]) {
    double customersPerMinute = atof(argv[1]);
    int customerMaxDurationSeconds = atof(argv[2]) * SECONDS_PER_MINUTE;
    int seed = stoi(argv[3]);

    Bank bank;
    Supermarket supermarket;
    srand(seed);
    //add customers
    int totalNumberOfCustomers = (customersPerMinute / SECONDS_PER_MINUTE) * SIM_LENGTH;

//    cout << "\nCustomers: " << totalNumberOfCustomers << endl << endl;

    for (int i = 0; i < totalNumberOfCustomers; i++) {
        Event newEvent;
        newEvent.customerId = i;
        newEvent.eventTime = rand() % SIM_LENGTH;
        newEvent.duration = rand() % customerMaxDurationSeconds;
        newEvent.event = ARRIVAL;
        bank.addEvent(newEvent);
        supermarket.addEvent(newEvent);
    }
    bank.runSim();
    double bank90th = get90thPercentile(bank.serviceTimes,"Bank");
//    bank.calcAvgServiceTime();

//    cout << endl;
    supermarket.runSim();
    double supermarket90th = get90thPercentile(supermarket.serviceTimes,"Supermarket");
    cout << fixed << setprecision(2) << bank90th << "\t" << supermarket90th << "\n";
//    supermarket.calcAvgServiceTime();
}
