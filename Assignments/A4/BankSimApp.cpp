/*
 * BankSimApp.cpp
 *
 * Description: Priority Queue implemented using the Binary Heap data collection
 * ADT class
 *
 * Author: Kyungryeong Kang and Sabrina Nguyen
 * Last Modification: July 2024
 *
 */
// Code inspired by section 13.4 from Assignment 4
#include "Event.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;

bool tellerAvailable = true;
int current_time = 0;

void processArrival(Event &arrivalEvent,
                    PriorityQueue<Event> &eventPriorityQueue,
                    Queue<Event> &bankLine);

void processDeparture(Event &departureEvent,
                      PriorityQueue<Event> &eventPriorityQueue,
                      Queue<Event> &bankLine);

void simulate();

int main(int argc, char *argv[]) {
  string aLine = "";
  string filename = "";
  string sign = "";
  string space = " ";
  size_t pos = 0;

  /*
  if (argc > 1) {
    sign = argv[1];
    if (sign == "<") {
      filename = argv[2];
    }
    ifstream myfile(filename);
    if (myfile.is_open()) {
      simulate();
    }

  } else {
    cout << "Unable to open file" << endl;
  }
*/
  simulate()

      return 0;
}

void simulate() {
  Queue<Event> bankLine;
  PriorityQueue<Event> eventPriorityQueue;
  string aLine = "";
  string filename = "";
  string sign = "";
  string space = " ";
  size_t pos = 0;
  int arrival_time;
  int transaction_time;
  while (getline(cin, aLine)) {
    pos = aLine.find(space);
    arrival_time = stoi(aLine.substr(0, pos));
    aLine.erase(0, pos + space.length());
    transaction_time = stoi(aLine.substr(pos + 1));
    Event newarrival('A', arrival_time, transaction_time);
    eventPriorityQueue.enqueue(newarrival);
  }
  while (!eventPriorityQueue.isEmpty()) {
    Event newEvent = eventPriorityQueue.peek();
    current_time = newEvent.getTime();
    if (newEvent.getType() == 'A') {
      processArrival(newEvent, eventPriorityQueue, bankLine);
    } else {
      processDeparture(newEvent, eventPriorityQueue, bankLine);
    }
  }
}

void processArrival(Event &arrivalEvent,
                    PriorityQueue<Event> &eventPriorityQueue,
                    Queue<Event> &bankLine) {
  eventPriorityQueue.dequeue();
  if (bankLine.isEmpty() && tellerAvailable) {
    int departure_time = current_time + arrivalEvent.getLength();
    Event newDepartureEvent('D', departure_time, 0);
    eventPriorityQueue.enqueue(newDepartureEvent);
    tellerAvailable = false;
  } else {
    bankLine.enqueue(arrivalEvent);
  }
}

void processDeparture(Event &departureEvent,
                      PriorityQueue<Event> &eventPriorityQueue,
                      Queue<Event> &bankLine) {
  eventPriorityQueue.dequeue();

  if (!bankLine.isEmpty()) {
    Event customer = bankLine.peek();
    bankLine.dequeue();

    int departure_time = current_time + customer.getLength();
    Event newDepartureEvent('D', departure_time, 0);
    eventPriorityQueue.enqueue(newDepartureEvent);
  } else {
    tellerAvailable = true;
  }
}
