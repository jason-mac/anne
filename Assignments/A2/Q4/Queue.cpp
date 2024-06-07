// clang-format off
/* 
 * Queue.cpp - This current version of Queue class does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class.
 *
 * Class Invariant: Queue maintained in FIFO order.
 *
 * Author: Jason Mac
 * Date: May 2024
 */
 
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue() {
  elements = new int[INITIAL_CAPACITY];
}

// Description: Copy Constructor
Queue::Queue(const Queue& rhs) {
  this->deepCopy(rhs);
}

// Description: Destructor
// Postcondition: Stuff
Queue::~Queue() { 
  delete[] elements;
}

Queue& Queue::operator=(const Queue& rhs) {
  delete[] elements;
  this->deepCopy(rhs);
  return *this;
}
// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
  if(elementCount == capacity) {
    int newSize = capacity * 2;
    int* newArray = getNewSizeArray(newSize);
    delete[] elements;
    elements = newArray;
    elements[elementCount] = newElement;
    elementCount++;
    frontindex = 0;
    backindex = elementCount;
    return;
  }
  elementCount++;
  elements[backindex] = newElement;
  backindex = (backindex + 1) % capacity;    
  return;
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {
  // Early return, no elements in data collection
  if(elementCount == 0) { return; }
  if(elementCount <= capacity / 4 && capacity > INITIAL_CAPACITY) {
    int newSize = capacity / 4 > INITIAL_CAPACITY ? capacity / 4 : INITIAL_CAPACITY;
    int* newArray = getNewSizeArray(newSize);
    delete[] elements;
    elementCount--;
    frontindex = 0;
    backindex = elementCount;
    return;
  }
  elementCount--;
  frontindex = (frontindex + 1) % capacity;
  return;
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
  return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
  return elementCount == 0;
}

// clang-format on
