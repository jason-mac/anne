// clang-format off
#include <cstdlib>
#include <iostream>
#include "PriorityQueue.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"
#include "Queue.h"


int main() {
  Event test1 = Event('D', 5, 60); 
  Event test2 = Event('A', 12, 34);
  Event test3 = Event('D', 30, 4);
  Event test4 = Event('');
  Event test5 = Event();
  Event test6 = Event();
  PriorityQueue<Event>* priorityQueue = new (nothrow) PriorityQueue<Event>();
  if(priorityQueue == nullptr) {
    cout << "Failed Memory allocation. Terminationg program...";
    return EXIT_FAILURE;
  }
  




  return EXIT_SUCCESS;
}

// clang-format on
