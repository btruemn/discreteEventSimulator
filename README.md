# discreteEventSimulator
Simulates the dynamics of bank and supermarket queueing systems. Each has 6 cashiers / checkers. The only difference between the two is that at the supermarket every cashier has their own line, while at the bank there's one line for all customers.

The program simulates 12 hours. Simulation time is measured in seconds using an integer. At the end of the day, the simulation shuts down. In effect, everyone currently waiting in line or being checked out is kicked out of the bank / store.

The simulation takes two parameters. First, customer arrival rate in terms of customers per minute. This is a double-precision value specified on the command line. The second parameter is maximum customer service time, measured in minutes. Again, this is a double-precision floating point value. The third parameter is a random number seed.

Customers at the supermarket never move between lines. When a customer arrives at the supermarket, they choose an empty checker if there are any. If there are no empty checkers, they choose the checker who will be ready first. A checker is ready after finishing their current customer and then processing all of the customers that are waiting.

A cashier at the bank is never idle when there are any customers in the line. A checker at the supermarket is never idle when there are any customers in their individual line, but may be idle when there are customers in other lines.

Before starting the simulation, event queue is populated with customer arrival events for the entire day. If 1 customer arrives per minute, then there should be a 1 in 60 chance of a customer arriving at every second of that day.
