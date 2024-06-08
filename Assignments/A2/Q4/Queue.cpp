// clang-format off
/* 
 * Queue.cpp - This current version of Queue class does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class.
 *
 * Class Invariant: Queue maintained in FIFO order.
 *
 * Author: Jason Mac, Jagyjot Parmar
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
void Queue::enqueue(int newElement) {
  if(elementCount == capacity) {

    // Create new array with double of old capacity
    int newSize = capacity * 2;
    int* newArray = getNewSizeArray(newSize);

    // Delete old elements array and update appropiate data members 
    delete[] elements;
    elements = newArray;
    capacity = newSize;

    // Add new element
    elements[elementCount] = newElement;
    backindex = elementCount;
    elementCount++;
    frontindex = 0;
    return;
  }
  elementCount++;
  elements[backindex] = newElement;
  backindex = (backindex + 1) % capacity;    
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
void Queue::dequeue() {
  if(elementCount == 0) {
    return;
  }

  // Update frontindex to remove frontmost element
  elementCount--;
  frontindex = (frontindex + 1) % capacity;

  // Resize array if necessary
  if(elementCount <= capacity / 4 && capacity > INITIAL_CAPACITY) {
    int newSize = capacity / 4 > INITIAL_CAPACITY ? capacity / 4 : INITIAL_CAPACITY;
    int* newArray = getNewSizeArray(newSize);

    // Delete old elements array and update appropiate data members 
    delete[] elements;
    elements = newArray;
    capacity = newSize;
    
    // Reset frontindex and backindex 
    frontindex = 0;
    backindex = elementCount;
    return;
  }
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
int Queue::peek() const {
  return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
bool Queue::isEmpty() const {
  return elementCount == 0;
}

// clang-format on
