// clang-format off
/* 
 * Queue.h - This current version of Queue class does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class.
 *
 * Class Invariant: Queue maintained in FIFO order.
 *
 * Author: Jason Mac
 * Date: May 2024
 */
 
#ifndef QUEUE_H
#define QUEUE_H
 
class Queue {

/* You cannot remove/modify the data members below, 
   except for the "int elements[INITIAL_CAPACITY];". 
   However, you can add more data members.           */
	
  private:
    constexpr static unsigned int INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
    int *elements = nullptr;                     // To do: replace this array with a pointer to an array - see Question 4
    unsigned int elementCount = 0;             // Number of elements in the Queue - if you need it!
    unsigned int capacity = INITIAL_CAPACITY;  // Initial capacity of the data structure (number of cells in the array)
    unsigned int frontindex = 0;               // Index of front element (next dequeued/peeked element)
    unsigned int backindex = 0;                // Index of where the next element will be enqueued                     

/* You can add private methods. */

    // Description: Makes a deep copy of input object rhs and stores it into this instance 
    // Precondition: this->elements is not pointing to heap allocated memory
    // Postcondition: All of rhs data memebers are copied into this object
    //                and rhs elements array has been deep copied into this object
    // Time Efficiency: O(n)
    void deepCopy(const Queue& rhs) {
      // If elements are already allocated, delete exisiting array to avoid memory leaks
      if(elements) {
        delete[] elements;
        elements = nullptr;
      }

      // Copy basic data members from rhs to this instance
      elementCount = rhs.elementCount;
      capacity = rhs.capacity;
      frontindex = rhs.frontindex;
      backindex = rhs.backindex;

      // Allocate new memory for elements
      elements = new int[capacity];

      // Copy elements from rhs to this instance
      for(int i = 0; i < elementCount; i++) {
        elements[(frontindex + i) % capacity] = rhs.elements[(frontindex + i) % capacity]; 
      }
    }

    // Description: Copies elements array into a new specified sized Dynamically allocated array
    //              maintaining the relative order of the elements between each other
    // Postcondition: elements array is copied into a new array and returned 
    // Time Efficiency: O(n)
    int* getNewSizeArray(unsigned int newSize) {
      // Dynamically allocate new array with specified sizes
      int *newArray = new int[newSize];

      // Copy elements from old array into new array maintaining relative order of the elements
      for(int i = 0; i < elementCount; i++) {
        newArray[i] = elements[(frontindex + i) % capacity];
      } 

      // Return the newly dynamically allocated array
      return newArray;
    }  
  

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
    Queue(const Queue&);

    // Description: Destructor 
    // Postconidtion: Dynamically allocated memory is freed
    ~Queue();

    // Overloaded assignment operator 
    Queue& operator = (const Queue&);

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
    bool isEmpty() const;
};
#endif

// clang-format on
