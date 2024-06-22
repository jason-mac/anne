/* 
 * Queue.h
 *
 * Description: Array-based implementation of data collection Queue ADT.
 * Class invariants: FIFO or LILO
 * 
 * Inspired from the code in our textbook (Frank M. Carrano and Tim Henry)
 *
 * Last modified date: June 2024
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "Profile.h"
#include "EmptyQueueException.h"


class Queue {

private:
   constexpr static int CAPACITY = 5; 
   
   Profile elements[CAPACITY]; // Array of Queue items
   int front;                 // Index to front of Queue
   int back;                  // Index to back of Queue
   unsigned int elementCount; // Number of elements currently in the Queue
   
public:
   // Constructor
   Queue();
   
   // Copy constructor and destructor supplied by compiler
        
   // Description: Returns "true" is this Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;
   
   // Description: Adds newElement to the "back" of this Queue and 
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(Profile& newElement);
   
   // Description: Removes the element at the "front" of this Queue and 
   //              returns "true" if successful, otherwise "false".
   // Precondition: This Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns a copy of the element at the "front" of this Queue, 
   //              but does not remove it.
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged.
   // Exceptions: Throws EmptyQueueException if this Queue is empty.
   // Time Efficiency: O(1)
   Profile peek() const;
  
   // For Testing Purposes
   // Description: Prints the content of "this". 
   void print() const;
      
}; // end Queue
#endif
