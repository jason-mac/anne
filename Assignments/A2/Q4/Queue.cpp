/*
 * Queue.cpp - This current version of Queue class does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class.
 *
 * Class Invariant: Queue maintained in FIFO order.
 *
 * Author: Jason Mac, Jagyjot Parmar
 * Date: June 2024
 */
 
#include <cstdlib>
#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;
using std::max;

// Description: Constructor
Queue::Queue() {}

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
// Postcondition: rhs.elements is deep copied into this->elements and rhs basic data members
//                are copied into this instance data members, returns *this for chaining
//                assignmnet operator.
Queue& Queue::operator=(const Queue& rhs) {
  if(this == &rhs) {
    return *this;
  }
  this->deepCopy(rhs);
  return *this;
}

// Description: Inserts newElement at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int newElement) {
  // Allocate memory if not done already for an array and insert newElement
  if(elements == nullptr) {
    elements = new int[INITIAL_CAPACITY];

    // Case for failed memory allocation, cannot insert, return early
    if(elements == nullptr) {
      return;
    }

    elements[0] = newElement;
    elementCount++;
    backindex++;
    return;
  }

  // Check if resizing array is necessary before enqueuing
  if(elementCount == capacity) {
    // Retrieve a new array of double the old capacity with elements in same relative order
    int newSize = capacity * 2;
    int* newArray = getNewSizeArray(newSize);
    if(newArray == nullptr) {
      // Failed memory allocation, cannot insert, return early
      return;
    }
    // Delete old elements array and update appropiate data members 
    delete[] elements;
    elements = newArray;
    capacity = newSize;

    // Add new element
    elements[elementCount] = newElement;
    elementCount++;
    backindex = elementCount;
    frontindex = 0;
    return;
  }
  elementCount++;
  elements[backindex] = newElement;
  backindex = (backindex + 1) % capacity;    
} 

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue() {

  // Return early, no elements to dequeue
  if(isEmpty()) {
    return;
  }

  // Update frontindex to remove frontmost element
  elementCount--;
  frontindex = (frontindex + 1) % capacity;

  // Resize array if necessary
  if(elementCount <= capacity / 4 && capacity > INITIAL_CAPACITY) {
    // Calculate new capacity, ensuring it does not drop below INITIAL_CAPACITY
    int newSize = max(capacity / 2, INITIAL_CAPACITY);

    // Retrieve a new array of newSize with same elements in its respective relative order
    int* newArray = getNewSizeArray(newSize);
    if(!newArray) {
      // Failed memory allocation, cannot insert, return early
      return;
    }

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
  if(isEmpty()) {
    // Return -1 if Queue is empty
    return -1;
  }
  return elements[frontindex];    
} 

// Description: Returns true if and only if Queue empty
// Postconidtion: Queue remains unchanged
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
  return elementCount == 0;
}

// Description: Clears any heap allocated memory in this instance. 
//              Makes a deep copy of input object rhs and stores it into this instance 
// Postcondition: All of rhs data memebers are copied into this object
//                and rhs elements array has been deep copied into this object
// Time Efficiency: O(n)
void Queue::deepCopy(const Queue& rhs) {
  cout << "you're broke" << endl;
  // delete any heap allocated memory before proceding with deep copy
  if(elements != nullptr) {
    delete[] elements;
    elements = nullptr;
  }

  // Copy basic data members from rhs to this instance
  elementCount = rhs.elementCount;
  capacity = rhs.capacity;
  frontindex = rhs.frontindex;
  backindex = rhs.backindex;

  // Case where rhs is a Queue object with no initiated heap allocated memory
  if(rhs.elements == nullptr) {
    return;
  }

  // Allocate memory for array 
  elements = new int[capacity];

  // Copy elements from rhs to this instance
  for(unsigned int i = 0; i < elementCount; i++) {
    elements[(frontindex + i) % capacity] = rhs.elements[(frontindex + i) % capacity]; 
  }
}

// Description: Copies elements array into a new specified sized Dynamically allocated array
//              maintaining the relative order of the elements between each other
// Postcondition: elements array is copied into a new array and returned 
// Time Efficiency: O(n)
int* Queue::getNewSizeArray(unsigned int newSize) {
  // Dynamically allocate new array with specified sizes
  int *newArray = new int[newSize];

  // If memory allocation fails, return nullptr
  if(!newArray) {
    return nullptr;
  }

  // Copy elements from old array into new array maintaining relative order of the elements
  // The front element in the queue of the newArray will start at index 0
  for(unsigned int i = 0; i < elementCount; i++) {
    newArray[i] = elements[(frontindex + i) % capacity];
  } 

  // Return the newly dynamically allocated array
  return newArray;
}
