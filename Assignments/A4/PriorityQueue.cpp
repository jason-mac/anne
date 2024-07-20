/*
 * PriorityQueue.cpp
 * Description: Class modelling a Priority Queue using a Minimum Binary Heap
 *              as its implementation
 *
 *
 *
 *
 * Authors: Jason Mac, Jagyjot Parmar
 * Last Modified: July 2024
 * 
 * */
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"

using std::nothrow;


// Constructor
template<class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){}

//Destructor
template<class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
  delete this->heap;
}

// Copy Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(const PriorityQueue& other){
  // Check if other has a heap instantiated
  if(other.heap != nullptr) {
    // Deep Copy the BinaryHeap using the copy constructor from BinaryHeap class
    this->heap = new(nothrow) BinaryHeap<ElementType>(*(other.heap));
  } else {
    this->heap = nullptr;
  } 
}


// Overlaoded Assignment Operator
template <class ElementType>
void PriorityQueue<ElementType>::operator=(const PriorityQueue& rhs) {
  // Check for self assignment
  if(this == &rhs) {
    return;
  }

  // Variable for storing pointer to copy of rhs heap, assume that rhs does not have heap initially
  BinaryHeap<ElementType> * rhsHeapCopy = nullptr;

  // Get rhs copy if it exists
  if(rhs.heap != nullptr) {
    rhsHeapCopy = new(nothrow) BinaryHeap<ElementType>(*(rhs.heap));
  }

  // Memory allocation failure
  if(rhsHeapCopy == nullptr && rhs.heap != nullptr) {
    return;
  }

  // delete this->heap to avoid memory leak before assigning new array
  delete this->heap;
  this->heap = nullptr;
  this->heap = rhsHeapCopy;
  return;
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
  // No heap, must be empty
  if(this->heap == nullptr) {
    return true;
  }
  return heap->getElementCount() == 0; 
}

// Description: Inserts "newElement" in this Priority Queue and
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType &newElement) {
  if(this->heap == nullptr) {
    this->heap = new(nothrow) BinaryHeap<ElementType>();
    if(heap == nullptr) {
      return false;
    }
  }
  return this->heap->insert(newElement);
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void PriorityQueue<ElementType>::dequeue() {
  // No heap instantiated
  if(this->heap == nullptr) {
    throw EmptyDataCollectionException("dequeue() called on Empty Data Collection.");
  }
  // Remove element using remove function from binaryHeap
  this->heap->remove();
}

// Description: Returns (but does not remove) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is
// empty. Time Efficiency: O(1)
template<class ElementType>
ElementType& PriorityQueue<ElementType>::peek() const{
  // No heap instantiated
  if(this->heap == nullptr) {
    throw EmptyDataCollectionException("peek() called on Empty Data Collection.");
  }
  // Remove element using remove function from binaryHeap
  return this->heap->retrieve();
}
