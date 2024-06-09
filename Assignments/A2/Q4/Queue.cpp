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
// Postcondition: rhs.elements is deep copied into this->elements and its basic data members
//                are copied into this instance data members
Queue::Queue(const Queue& rhs) {
  this->deepCopy(rhs);
}

// Description: Destructor
// Postcondition: Dynamically allocated memory is freed 
Queue::~Queue() { 
  delete[] elements;
}

// Description: Overloaded assignment operator=. Deletes all dyamically memory in this instance
//              then makes a deep copy of rhs storing it into this instance. Allows for chaining of 
//              assignment operator.
// Postcondition: rhs.elements is deep copied into this->elements and its basic data members
//                are copied into this instance data members, returns *this for chaining
//                assignmnet operator.
Queue& Queue::operator=(const Queue& rhs) {
  delete[] elements;
  elements = nullptr;
  this->deepCopy(rhs);
  return *this;
}

// Description: Inserts newElement at the back of Queue
// Time Efficiency: Amortized O(1)
void Queue::enqueue(int newElement) {
  if(elementCount == capacity) {

    // Retrieve a new array of double the old capacity with elements in same relative order
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
// Time Efficiency: Amortized O(1)
void Queue::dequeue() {

  // Return early, no elements to dequeue
  if(elementCount == 0) {
    return;
  }

  // Update frontindex to remove frontmost element
  elementCount--;
  frontindex = (frontindex + 1) % capacity;

  // Resize array if necessary
  if(elementCount <= capacity / 4 && capacity > INITIAL_CAPACITY) {
    // Calculate new capacity, ensuring it does not drop below INITIAL_CAPACITY
    int newSize = std::max(capacity / 2, INITIAL_CAPACITY);

    // Retrieve a new array of newSize with same elements in its respective relative order
    int* newArray = getNewSizeArray(newSize);

    // Delete old elements array and update appropiate data members 
    delete[] elements;
    elements = newArray;
    capacity = newSize;
    
    // Reset frontindex and backindex 
    frontindex = 0;
    backindex = elementCount;
  }
} 

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const {
  return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Postconidtion: Queue remains unchanged
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
  return elementCount == 0;
}

// clang-format on
