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

void printEvent(const Event anEvent) {
  if(anEvent.getType() == 'A') {
    cout << "Processing an arrival event at time:   " << std::setw(4) << anEvent.getTime() << endl;;
  } else {
    cout << "Processing an departure event at time: " << std::setw(4) << anEvent.getTime() << endl;;
  } 
}

void processArrival(Event arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine, 
                    bool &tellerAvailable, unsigned int &currentTime) {
  eventPriorityQueue->dequeue();
  Event customer = arrivalEvent;
  if(bankLine->isEmpty() && tellerAvailable) {
    unsigned int departureTime = currentTime + customer.getLength();
    Event newDepartureEvent('D', departureTime);
    eventPriorityQueue->enqueue(newDepartureEvent);
    tellerAvailable = false;
  } else {
    bankLine->enqueue(customer);
  }
}

void processDeparture(Event departureEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine,
                      bool &tellerAvailable, unsigned int &currentTime){
  eventPriorityQueue->dequeue();
  if(!(bankLine->isEmpty())) {
    Event customer = bankLine->peek();
    bankLine->dequeue();
    unsigned int departureTime = currentTime + customer.getLength();
    Event newDepartureEvent('D', departureTime);
    eventPriorityQueue->enqueue(newDepartureEvent);
  } else {
    tellerAvailable = true;
  }
}


int main(int argc, char* argv[]) {
  Queue<Event>* bankLine = new(nothrow) Queue<Event>();
  PriorityQueue<Event>* eventPriorityQueue = new (nothrow) PriorityQueue<Event>();
  bool tellerAvailable = true;
  if(eventPriorityQueue == nullptr || bankLine == nullptr) {
    cout << "Failed Memory allocation. Terminationg program...";
    return EXIT_FAILURE;
  }
  string aLine = "";
  string delimiter = " ";
  size_t pos = 0;
  unsigned int customerCount = 0;
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
      customerCount++;
  }

  unsigned int currentTime = 0;
  cout << "Simulation Begins" << endl;
  while (!(eventPriorityQueue->isEmpty())) {
    Event newEvent = eventPriorityQueue->peek();
    printEvent(newEvent);
    currentTime = newEvent.getTime();
    if(newEvent.getType() == 'D') {
      try {
        waitingTime += currentTime - bankLine->peek().getTime(); 
      } catch (EmptyDataCollectionException& e) {}
    }
    if (newEvent.getType() == 'A') {
        processArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
    } else {
        processDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
    }
  }
  double averageWaitingTime = static_cast<double>(waitingTime) / customerCount;
  cout << "Simulation Ends" << endl;
  cout << endl;
  cout << "Final Statistics:" << endl;
  cout << "    Total number of people processed: " << customerCount << endl;
  cout << "    Average amount of time spent waiting: " << averageWaitingTime << endl;
  delete eventPriorityQueue;
  delete bankLine;
  return EXIT_SUCCESS;
}

// clang-format on
