// clang-format off
#include "Queue.h"
#include <iostream>
#include "EmptyDataCollectionException.h"
#include <algorithm>
#include <new>
using std::nothrow;
using std::cout;
using std::endl;


/* CONTRUCTORS AND DESTRUCTOR */

// Constructor
template<class ElementType>
Queue<ElementType>::Queue() {}

// Destructor
template<class ElementType>
Queue<ElementType>::~Queue() {
  delete[] elements;
}

// Description: Copy Constructor
// Postcondition: rhs.elements is deep copied into this->elements and its basic data members
//                are copied into this instance data members
template<class ElementType>
Queue<ElementType>::Queue(const Queue& other) {
  this->elements = getDeepCopyArray(other);
  this->elementCount = other.elementCount;
  this->capacity = other.capacity;
  this->frontindex = other.frontindex;
  this->backindex = other.backindex;
}
// Description: Overloaded assignment operator. Deletes all dyamically memory in this instance
//              then makes a deep copy of rhs storing it into this instance. Allows for chaining of 
//              assignment operator.
// Postcondition: rhs.elements is deep copied into this->elements and its basic data members
//                are copied into this instance data members, returns *this for chaining
//                assignmnet operator.
template<class ElementType>
Queue<ElementType>& Queue<ElementType>::operator= (const Queue& rhs) {
  // Handle Self Assingment
  if(this == &rhs) {
    return *this;
  }

  // Create a deep copy of rhs elements
  ElementType* newElements = getDeepCopyArray(rhs);

  // Deallocate old memory
  delete[] this->elements;

  // Assign new elements and copy basic data members
  this->elements = newElements;
  this->capacity = rhs.capacity;
  this->elementCount = rhs.elementCount;
  this->frontindex = rhs.frontindex;
  this->backindex = rhs.backindex;

  return *this;
}


/* HELPER FUNCTIONS */

// Description: Makes a deep copy of the input object rhs and stores it into this instance.
// Precondition: this->elements is not pointing to heap-allocated memory.
// Postcondition: All of rhs's data members (except elements) are copied into this object,
//                and rhs's elements array has been deep copied into this object.
template<class ElementType>
ElementType* Queue<ElementType>::getDeepCopyArray(const Queue& rhs) {
  if(rhs.elements == nullptr) {
    return nullptr;
  }
  ElementType* rhsElementsCopy = new(nothrow) ElementType[rhs.capacity];
  if(rhsElementsCopy == nullptr) {
    return nullptr;
  }
  for(unsigned int i = 0; i < rhs.elementCount; i++) {
    rhsElementsCopy[(rhs.frontindex + i) % rhs.capacity] = rhs.elements[(rhs.frontindex + i) % rhs.capacity];
  }
  return rhsElementsCopy;
}

// Description: Copies elements array into a new specified sized Dynamically allocated array
//              maintaining the relative order of the elements between each other, but not
//              necessarily the position of frontindex and backindex
// Postcondition: elements array is copied into a new array and returned 
// Time Efficiency: O(n)
template<class ElementType>
ElementType* Queue<ElementType>::getNewSizeArray(unsigned int newSize) {
  cout << "RESIZE" << endl;
  ElementType * newSizeArray = new(nothrow) ElementType[newSize];
  if(newSizeArray == nullptr) {
    return nullptr;
  }
  for(unsigned int i = 0; i < elementCount; i++) {
    newSizeArray[i] = elements[(i + frontindex) % capacity];
  }
  return newSizeArray;
}

/* PUBLIC INTERFACE */

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::isEmpty() const {
 return elementCount == 0;
}

// Description: Inserts newElement at the "back" of this Queue 
//              (not necessarily the "back" of this Queue's data structure) 
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template<class ElementType>
bool Queue<ElementType>::enqueue(ElementType & newElement) {
  // If there is no allocated memory for Queue elements array
  if(elements == nullptr) {
    elements = new(nothrow) ElementType[INITIAL_CAPACITY];
    // Failed memory allocation case
    if(elements == nullptr) {
      return false;
    }
    capacity = INITIAL_CAPACITY;
    elements[backindex] = newElement;
    elementCount++;
    backindex++;
    return true;
  }
  if(elementCount == capacity) {
    //resize array
    unsigned int newSize = capacity * 2;
    ElementType * newSizeArray = getNewSizeArray(newSize);
    if(newSizeArray == nullptr) {
      // could not allocate memory for the new array
      return false;
    }
    delete[] elements;
    elements = newSizeArray;
    elements[elementCount] = newElement; // Place newElement at the end 
    elementCount++;
    frontindex = 0;
    backindex = elementCount; // Reset backindex after resizing
    capacity = newSize;
    return true;
  }

  // Enqueuing procedure
  elements[backindex] = newElement;
  backindex = (backindex + 1) % capacity;
  elementCount++;
  return true;
}


// Description: Removes (but does not return) the element at the "front" of this Queue 
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.   
// Time Efficiency: O(1)
template<class ElementType>
void Queue<ElementType>::dequeue() {
  // Return early, no elements to dequeue
  if(elementCount == 0){
    throw EmptyDataCollectionException("dequeue() called on empty Queue.");
  }
  // Update frontindex to remove frontmost element
  elementCount--;
  frontindex = (frontindex + 1) % capacity;

  // Resize array if necessary
  if(elementCount <= capacity / 4 && capacity > INITIAL_CAPACITY) {
    // Calculate new capacity, ensuring it does not drop below INITIAL_CAPACITY
    unsigned int newSize = std::max(capacity / 2, INITIAL_CAPACITY);

    // Retrieve a new array of newSize with same elements in its respective relative order
    ElementType* newSizeArray = getNewSizeArray(newSize);

    // Delete old elements array and update appropiate data members 
    delete[] elements;
    elements = newSizeArray;
    capacity = newSize;
    
    // Reset frontindex and backindex 
    frontindex = 0;
    backindex = elementCount;
  }
}

 // Description: Returns (but does not remove) the element at the "front" of this Queue
 //              (not necessarily the "front" of this Queue's data structure).
 // Precondition: This Queue is not empty.
 // Postcondition: This Queue is unchanged by this operation.
 // Exception: Throws EmptyDataCollectionException if this Queue is empty.
 // Time Efficiency: O(1)
template<class ElementType>
ElementType& Queue<ElementType>::peek() const {
  if(elementCount == 0) {
    throw EmptyDataCollectionException("peek() called on empty Data Collection.");
  }
  return elements[frontindex];
}

template<class ElementType>
void Queue<ElementType>::print() const {
  if(elementCount == 0) {
    cout << "empty" << endl;
    return;
  }
  cout << "[";
  for(unsigned int i = 0; i < elementCount - 1; i++) {
    cout << elements[(i + frontindex) % capacity] << ", ";
  }
  cout << elements[elementCount - 1] << "]" << endl;
}

// clang-format on
