/*
 * Queue.h
 *
 * Description: Array-based implementation of Queue as an ADT class.
 *
 * Class Invariant: Queue maintained in FIFO order.
 *
 * Author: Jason Mac and Jagyjot Parmar
 * Date: July 2024
 */
#ifndef QUEUE_H
#define QUEUE_H

#include "EmptyDataCollectionException.h"

template<class ElementType>
class Queue {
private:
    /* HELPER FUNCTIONS*/

    // Description: Copies elements array into a new specified sized dynamically allocated array
    //              maintaining the relative order of the elements.
    // Postcondition: elements array is copied into a new array and returned.
    ElementType* getNewSizeArray(unsigned int newSize);

    // Private Members
    constexpr static unsigned int INITIAL_CAPACITY = 8; // Constant INITIAL_CAPACITY
    unsigned int capacity = INITIAL_CAPACITY;
    unsigned int frontindex = 0;
    unsigned int backindex = 0;
    unsigned int elementCount = 0;
    ElementType* elements = nullptr;

public:		
    Queue();
    ~Queue();
    Queue(const Queue& other);

    // Description: Overloaded assignment operator. Deletes all dyamically memory in this instance
    //              then makes a deep copy of rhs storing it into this instance. Allows for chaining of 
    //              assignment operator.
    // Postcondition: rhs.elements is deep copied into this->elements and its basic data members
    //                are copied into this instance data members, returns *this for chaining
    //                assignmnet operator.
    Queue& operator= (const Queue& rhs);

    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement at the "back" of this Queue 
    //              (not necessarily the "back" of this Queue's data structure) 
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType & newElement);

    // Description: Removes (but does not return) the element at the "front" of this Queue 
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.   
    // Time Efficiency: O(1)
    void dequeue(); 

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType & peek() const;
};

#include "Queue.cpp"
#endif
