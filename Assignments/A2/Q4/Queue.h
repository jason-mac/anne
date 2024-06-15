/*
 * Queue.h - This current version of Queue class does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class.
 *
 * Class Invariant: Queue maintained in FIFO order.
 *
 * Author: Jason Mac and Jagyjot Parmar
 * Date: June 2024
 */
 
#ifndef QUEUE_H
#define QUEUE_H
 
class Queue {

/* You cannot remove/modify the data members below, 
   except for the "int elements[INITIAL_CAPACITY];". 
   However, you can add more data members.           */
	
  private:
    constexpr static unsigned int INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
    int* elements = nullptr;                     // To do: replace this array with a pointer to an array - see Question 4
    unsigned int elementCount = 0;             // Number of elements in the Queue - if you need it!
    unsigned int capacity = INITIAL_CAPACITY;  // Initial capacity of the data structure (number of cells in the array)
    unsigned int frontindex = 0;               // Index of front element (next dequeued/peeked element)
    unsigned int backindex = 0;                // Index of where the next element will be enqueued                     

/* You can add private methods. */

    // Utility Methods

    // Description: Makes a deep copy of input object rhs and stores it into this instance 
    // Precondition: this->elements is not pointing to heap allocated memory
    // Postcondition: All of rhs data memebers (except elements) are copied into this object
    //                and rhs elements array has been deep copied into this object
    // Time Efficiency: O(n)
    void deepCopy(const Queue& rhs);

    // Description: Copies elements array into a new specified sized Dynamically allocated array
    //              maintaining the relative order of the elements between each other
    // Postcondition: elements array is copied into a new array and returned 
    // Time Efficiency: O(n)
    int* getNewSizeArray(unsigned int newSize);
  

  public:
 
/* You cannot remove/modify the public methods below.  
   This also applies to their documentation. 
   However, you can add public methods if you need them 
   like "printQueue()", etc.      

   However, you will need to add a destructor, a copy constructor 
   as well as an overloaded assignment = operator - see Question 4
*/

    // Description: Constructor
    Queue();
    
    // Description: Copy Constructor
    // Postcondition: rhs.elements is deep copied into this->elements and its basic data members
    //                are copied into this instance data members
    Queue(const Queue&);

    // Description: Destructor 
    // Postconidtion: Dynamically allocated memory is freed
    ~Queue();

    // Description: Overloaded assignment operator. Deletes all dyamically memory in this instance
    //              then makes a deep copy of rhs storing it into this instance. Allows for chaining of 
    //              assignment operator.
    // Postcondition: rhs.elements is deep copied into this->elements and its basic data members
    //                are copied into this instance data members, returns *this for chaining
    //                assignmnet operator.
    Queue& operator= (const Queue&);

    // Description: Inserts newElement at the back of Queue
    // Time Efficiency: O(1)
    void enqueue(int newElement);

    // Description: Removes the frontmost element
    // Precondition: Queue not empty
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns a copy of the frontmost element
    // Precondition: Queue not empty
    // Time Efficiency: O(1)
    int peek() const;

    // Description: Returns true if and only if Queue empty
    // Postconidtion: Queue remains unchanged
    // Time Efficiency: O(1)
    bool isEmpty()  const;
    
};
#endif
