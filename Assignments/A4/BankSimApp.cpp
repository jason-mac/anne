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


int main(int argc, char* argv[]) {
  unsigned int currentTime = 0;
  PriorityQueue<Event>* priorityQueue = new (nothrow) PriorityQueue<Event>();
  if(priorityQueue == nullptr) {
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
  if(argc > 1) {
    filename = argv[1];
    ifstream myfile(filename);
    if(myfile.is_open()) {
      pos = aLine.find(delimiter);
      string timeString = aLine.substr(0, pos);
      aLine.erase(0, pos + delimiter.length());
      string lengthString = aLine;
      int timeInt = stoi(timeString);
      int lengthInt = stoi(lengthString);
      Event anEvent('A', timeInt, lengthInt);
      priorityQueue->enqueue(anEvent);
    } else {
      cout << "file could no be openned";
    }
  } else {
    cout << "No file name given";
  }




  return EXIT_SUCCESS;
}

// clang-format on
