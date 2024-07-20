// clang-format off
/*
* BankSimApp.cpp
* 
* Description: Bank Simulation App that is event driven, which implements an algorithm as outlined in Section 13.4 of the document Bank Simulation
*              of our class textbook. The app makes use of Priority Queue ADT class implemented using a Minimum Binary Heap and a Queue ADT class implemented 
*              using an array
*
* Authors: Jason Mac, Jagyjot Parmar
* Last Modification: July 2024
*/
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

/* FUNCTION PROTOTYPES */

// Description: Simulate a bank with incoming and outgoing customers
void simulate();

// Description: Print an event out to the console
void printEvent(const Event anEvent);

//Description: Function for processing arrival events and adds departure events to the PriorityQueue
void processArrival(Event arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine, 
                    bool &tellerAvailable, unsigned int &currentTime);

// Description: Function for processing arrival events and adds departure events to PriorityQueue if there are more 
//              customers to be processed in bank line
void processDeparture(Event departureEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine,
                      bool &tellerAvailable, unsigned int &currentTime);

// Desciption: Main function that calls simulate to start bank simulation
int main() {
  simulate();
  return EXIT_SUCCESS;
}

/* FUNCTION DEFINITIONS */

// Description: Simulate a bank with incoming and outgoing customers
void simulate() {
  // Allocate memory for bank line
  Queue<Event>* bankLine = new(nothrow) Queue<Event>();

  // Allocate memory for Priority Queue
  PriorityQueue<Event>* eventPriorityQueue = new (nothrow) PriorityQueue<Event>();

  // Variable that indicates if a teller can process a customer in the bank line queue
  bool tellerAvailable = true;

  // Failed memory allocation, return early cannot run program
  if(eventPriorityQueue == nullptr || bankLine == nullptr) {
    cout << "Failed Memory allocation. Terminationg program...";
    return;
  }

  int arrivalTime;
  int transactionTime;

  // Incrementer variable for processing customers as they depart
  unsigned int customersProcessed = 0;

  // Variable for holding waiting times of all customers
  unsigned int waitingTimeTotal = 0;

  // Get the Data from Input File
  while (cin >> arrivalTime >> transactionTime) {
      // Create event for the given arrival time and transation time in file
      Event newArrivalEvent('A', arrivalTime, transactionTime);

      // enqueue the event into the Priority Queue
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
      try {                                                               // Try calculating the waiting time of the next incoming customer waiting in line, if there is one 
        waitingTimeTotal += currentTime - bankLine->peek().getTime();     // Formula for calculating the waiting time of the next customer
      } catch (EmptyDataCollectionException& e) {}                        // If the bankLine was empty catch the exception
      processDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
      //Increment customersProcessed after processing a departure
      customersProcessed++;
    }
  }
  double averageWaitingTime = static_cast<double>(waitingTimeTotal) / customersProcessed;
  cout << "Simulation Ends" << endl;
  cout << endl;
  cout << "Final Statistics:" << endl << endl;;
  cout << "    Total number of people processed: " << customersProcessed << endl;
  cout << "    Average amount of time spent waiting: " << averageWaitingTime << endl;
  delete eventPriorityQueue;
  delete bankLine;
}

// Description: Print an event out to the console
void printEvent(const Event anEvent) {
  if(anEvent.getType() == 'A') {
    cout << "Processing an arrival event at time:  " << std::setw(4) << anEvent.getTime() << endl;;
  } else {
    cout << "Processing a departure event at time: " << std::setw(4) << anEvent.getTime() << endl;;
  } 
}

//Description: Function for processing arrival events and adds departure events to the PriorityQueue
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

// Description: Function for processing arrival events and adds departure events to PriorityQueue if there are more 
//              customers to be processed in bank line
void processDeparture(Event departureEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine,
                      bool &tellerAvailable, unsigned int &currentTime){
  // dequeue the top event
  eventPriorityQueue->dequeue();

  // If line is not empty, process the next customer into a departure event
  if(!(bankLine->isEmpty())) {
    // Get the next customer in line we get from the front of the bankLine
    Event customer = bankLine->peek();
    // dequeue the front customer
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
