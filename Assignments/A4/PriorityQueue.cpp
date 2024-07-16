// clang-format off
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
  delete heap;
}

// Copy Constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(const PriorityQueue& other){
  if(other.heap != nullptr) {
    this->heap = new(nothrow) BinaryHeap<ElementType>(*(other.heap));
  } else {
    this->heap = nullptr;
  } 
}


// Overlaoded Assignment Operator
template <class ElementType>
void PriorityQueue<ElementType>::operator=(const PriorityQueue& rhs) {
  if(this == &rhs) {
    return;
  }
  delete this->heap;
  BinaryHeap rhsHeapCopy = (rhs == nullptr) ? nullptr : new(nothrow) BinaryHeap<ElementType>(*(rhs.heap));
  this->heap = rhsHeapCopy;
  return;
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const {
  if(heap == nullptr) {
    return true;
  }
  return heap->getElementCount() == 0; 
}

// Description: Inserts "newElement" in this Priority Queue and
//              returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template<class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType &newElement) {
  if(heap == nullptr) {
    heap = new(nothrow) BinaryHeap<ElementType>();
    return heap->insert(newElement);
  }
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template<class ElementType>
void PriorityQueue<ElementType>::dequeue() {
  if(this->heap == nullptr) {
    throw EmptyDataCollectionException("dequeue() called on Empty Data Collection.");
  }
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
  if(heap == nullptr) {
    throw EmptyDataCollectionException("peek() called on Empty Data Collection.");
  }
  return this->heap->retrieve();
}
// clang-format on
