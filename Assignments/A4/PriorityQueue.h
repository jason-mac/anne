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
*/
#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
template <class ElementType> class PriorityQueue {
private:
  BinaryHeap<ElementType> *heap = nullptr;

public:
  // Constructor
  PriorityQueue();
  ~PriorityQueue();
  PriorityQueue(const PriorityQueue& other); 
  void operator= (const PriorityQueue& rhs);
  // Description: Returns true if this Priority Queue is empty, otherwise false.
  // Postcondition: This Priority Queue is unchanged by this operation.
  // Time Efficiency: O(1)
  bool isEmpty() const;

  // Description: Inserts "newElement" in this Priority Queue and
  //              returns true if successful, otherwise false.
  // Time Efficiency: O(log2 n)
  bool enqueue(ElementType &newElement);

  // Description: Removes (but does not return) the element with the next
  //              "highest" priority value from the Priority Queue.
  // Precondition: This Priority Queue is not empty.
  // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
  // Time Efficiency: O(log2 n)
  void dequeue();

  // Description: Returns (but does not remove) the element with the next
  //              "highest" priority value from the Priority Queue.
  // Precondition: This Priority Queue is not empty.
  // Postcondition: This Priority Queue is unchanged by this operation.
  // Exception: Throws EmptyDataCollectionException if this Priority Queue is
  // empty. Time Efficiency: O(1)
  ElementType &peek() const;
};

#include "PriorityQueue.cpp"

#endif

// clang-format off
