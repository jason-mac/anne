// clang-format off
#include <cstdio>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "PriorityQueue.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "Queue.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;
using std::string;

void simulate();
void printEvent(const Event anEvent);
void processArrival(Event arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine, 
                    bool &tellerAvailable, unsigned int &currentTime);
void processDeparture(Event departureEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine,
                      bool &tellerAvailable, unsigned int &currentTime);

int main() {
  simulate();
  return EXIT_SUCCESS;
}

void simulate() {
  Queue<Event>* bankLine = new(nothrow) Queue<Event>();
  PriorityQueue<Event>* eventPriorityQueue = new (nothrow) PriorityQueue<Event>();
  bool tellerAvailable = true;
  if(eventPriorityQueue == nullptr || bankLine == nullptr) {
    cout << "Failed Memory allocation. Terminationg program...";
    return;
  }
  string aLine = "";
  string delimiter = " ";
  size_t pos = 0;
  unsigned int customersProcessed = 0;
  unsigned int waitingTime = 0;

  while (getline(cin, aLine)) {
      pos = aLine.find(delimiter);
      string arrivalTimeString = aLine.substr(0, pos);
      aLine.erase(0, pos + delimiter.length());
      string transactionTimeString = aLine;
      int arrivalTimeInt = stoi(arrivalTimeString);
      int transactionTimeInt = stoi(transactionTimeString);
      Event newArrivalEvent('A', arrivalTimeInt, transactionTimeInt);
      eventPriorityQueue->enqueue(newArrivalEvent);
  }

  unsigned int currentTime = 0;
  cout << "Simulation Begins" << endl;
  while (!(eventPriorityQueue->isEmpty())) {
    // Get newEvent from eventPriorityQueue
    Event newEvent = eventPriorityQueue->peek();

    // Print the following incoming event
    printEvent(newEvent);

    // Get currentTime
    currentTime = newEvent.getTime();

    // Process event depending if arrival or departure
    if (newEvent.getType() == 'A') {
      processArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
    } else {
      try {                                                          // Try calculating the waiting time of the next incoming customer waiting in line, if there is one 
        waitingTime += currentTime - bankLine->peek().getTime();     // Formula for calculating the waiting time of the next customer
      } catch (EmptyDataCollectionException& e) {}                   // If the bankLine was empty catch the exception
      processDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
      //Increment customersProcessed after processing a departure
      customersProcessed++;
    }
  }
  double averageWaitingTime = static_cast<double>(waitingTime) / customersProcessed;
  cout << "Simulation Ends" << endl;
  cout << endl;
  cout << "Final Statistics:" << endl << endl;;
  cout << "    Total number of people processed: " << customersProcessed << endl;
  cout << "    Average amount of time spent waiting: " << averageWaitingTime << endl;
  delete eventPriorityQueue;
  delete bankLine;
}

// Printing event function
void printEvent(const Event anEvent) {
  if(anEvent.getType() == 'A') {
    cout << "Processing an arrival event at time:  " << std::setw(4) << anEvent.getTime() << endl;;
  } else {
    cout << "Processing a departure event at time: " << std::setw(4) << anEvent.getTime() << endl;;
  } 
}

void processArrival(Event arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine, 
                    bool &tellerAvailable, unsigned int &currentTime) {
  // dequeue the event
  eventPriorityQueue->dequeue();

  // Get customer data
  Event customer = arrivalEvent;

  // If the bankLine is empty and a teller is available, process them and setup a departure event
  if(bankLine->isEmpty() && tellerAvailable) {
    unsigned int departureTime = currentTime + customer.getLength();
    Event newDepartureEvent('D', departureTime);
    eventPriorityQueue->enqueue(newDepartureEvent);
    tellerAvailable = false;
  } else {
    // If the bankLine is not empty or there is not a teller avaible, add the customer to the bankline
    bankLine->enqueue(customer);
  }
}

void processDeparture(Event departureEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine,
                      bool &tellerAvailable, unsigned int &currentTime){
  // dequeue the top event
  eventPriorityQueue->dequeue();

  if(!(bankLine->isEmpty())) {
    // The next customer in line we get from the front of the bankLine
    Event customer = bankLine->peek();
    // Deqeue the front customer
    bankLine->dequeue();
    // Calculate Departure time 
    unsigned int departureTime = currentTime + customer.getLength();
    // Make new departure event with the given customer's departure data
    Event newDepartureEvent('D', departureTime);
    // Add the event to the PriorityQueue
    eventPriorityQueue->enqueue(newDepartureEvent);
  } else {
    // If the bank line is empty, then there is a teller available
    tellerAvailable = true;
  }
}
// clang-format on
