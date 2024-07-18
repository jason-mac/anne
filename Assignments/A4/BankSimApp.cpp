// clang-format off
#include <cstdio>
#include <iostream>
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

void processArrival(Event arrivalEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine, 
                    bool &tellerAvailable, unsigned int &currentTime) {
  eventPriorityQueue->dequeue();
  Event customer = arrivalEvent;
  if(bankLine->isEmpty() && tellerAvailable) {
    unsigned int departureTime = customer.getTime() + customer.getLength();
    Event newDepartureEvent('D', departureTime);
    eventPriorityQueue->enqueue(newDepartureEvent);
    tellerAvailable = false;
  } else {
    bankLine->enqueue(customer);
  }
}

void processDeparture(Event departureEvent, PriorityQueue<Event>* eventPriorityQueue, Queue<Event>* bankLine,
                      bool &tellerAvailable, unsigned int &currentTime){
  if(!(bankLine->isEmpty())) {
    Event customer = bankLine->peek();
    bankLine->dequeue();
    unsigned int departureTime = currentTime + customer.getTime();
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
  string displayString = "display";
  string aLine = "";
  string timeString = "";
  string lengthString = "";
  string filename = "";
  string delimiter = " ";
  size_t pos = 0;
  if(argc < 1) {
    filename = argv[1];
    ifstream myfile(filename);
    if(myfile.is_open()) {
      while(getline(myfile, aLine)) {
        pos = aLine.find(delimiter);
        string arrivalTimeString = aLine.substr(0, pos);
        aLine.erase(0, pos + delimiter.length());
        string transactionTimeString = aLine;
        int arrivalTimeInt = stoi(arrivalTimeString);
        int transactionTimeInt = stoi(transactionTimeString);
        Event newArrivalEvent('A', arrivalTimeInt, transactionTimeInt);
        eventPriorityQueue->enqueue(newArrivalEvent);
      }
      while(!(eventPriorityQueue->isEmpty())) {
        Event newEvent = eventPriorityQueue->peek();
        unsigned int currentTime = newEvent.getTime();
        if(newEvent.getType() == 'A') {
          processArrival(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
        } else {
          processDeparture(newEvent, eventPriorityQueue, bankLine, tellerAvailable, currentTime);
        }
      }
    } else {
      cout << "file could no be openned";
    }
  } else {
    cout << "No file name given";
  }




  return EXIT_SUCCESS;
}

// clang-format on
