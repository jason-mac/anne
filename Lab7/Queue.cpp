// clang-format off
/* 
 * Queue.cpp
 *
 * Description: Array-based implementation of data collection Queue ADT.
 * Class invariants: FIFO or LILO
 * 
 * Inspired from the code in our textbook (Frank M. Carrano and Tim Henry)
 *
 * Last modified date: June 2024
 */

#include <iostream>
#include "Queue.h"  // Header file

using std::cout;
using std::endl;


// Constructor
Queue::Queue() : front(0), back(-1), elementCount(0) {
} // end default constructor


// Copy constructor, assignment operator and destructor are supplied by compiler.


// Description: Returns "true" is this Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool Queue::isEmpty() const {
   return elementCount == 0;
} // end isEmpty

// Description: Adds newElement to the "back" of this Queue and 
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
bool Queue::enqueue(Profile& newElement) {
   bool queuedOK = false;
   if (elementCount < CAPACITY)
   {
      // Queue has room for another item
      back = (back + 1) % CAPACITY;
      elements[back] = newElement;
      elementCount++;
      queuedOK = true;
   } // end if
   
   return queuedOK;
} // end enqueue


// Description: Removes the element at the "front" of this Queue and 
//              returns "true" if successful, otherwise "false".
// Precondition: This Queue is not empty.
// Time Efficiency: O(1)
bool Queue::dequeue() {
   // Some code
   
   return true;
} // end dequeue


// Description: Returns a copy of the element at the "front" of this Queue, 
//              but does not remove it.
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged.
// Exceptions: Throws EmptyQueueException if this Queue is empty.
// Time Efficiency: O(1)
Profile Queue::peek() const {
   // Enforce precondition
   if (isEmpty())
      throw EmptyQueueException("peek() called with empty Queue.");

   // Queue is not empty; return a copy of "front"
   return elements[front];
} // end peek

// For Testing Purposes
// Description: Prints the content of "this". 
void Queue::print() const { 
   cout << "Printing the Queue from front = " << front << " to back = " << back << endl;
   for ( int i = front; i <= back; i++)
      cout << elements[i];
   cout << endl;
} // end of print

// End of implementation file.
// clang-format on
