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
    void deepCopy(const Queue& rhs) {
      elementCount = rhs.elementCount;
      capacity = rhs.capacity;
      frontindex = rhs.frontindex;
      backindex = rhs.backindex;
      elements = new int[capacity];
      for(int i = 0; i < elementCount; i++) {
        elements[(frontindex + i) % capacity] = rhs.elements[(frontindex + i) % capacity]; 
      }
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
    // Time Efficiency: O(1)
    bool isEmpty() const;
};
#endif

// clang-format on
