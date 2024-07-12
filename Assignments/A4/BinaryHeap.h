// clang-format off
#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H
#include "EmptyDataCollectionException.h"
template <class ElementType>
class BinaryHeap {
private:
  constexpr static unsigned int BASE_CAPACITY = 8;
  unsigned int elementCount = 0;
  ElementType* elements = nullptr;
  unsigned int capacity;


  // ***Utiltiy Methods***
  void reHeapDown(unsigned int);
  void reHeapUp(unsigned int);
  ElementType* getNewSizeArray(unsigned int) const;
  ElementType* getDeepCopyArray(const BinaryHeap& rhs);

public:
  

  // Constructor
  BinaryHeap();

  // Destructor
  ~BinaryHeap();

  // Copy Constructor
  BinaryHeap(const BinaryHeap& other);
  
  // Assignmnet Operator
  void operator= (const BinaryHeap& rhs);

  // Description: Returns the number of elements currently stored in the Binary Heap.
  // Postcondition: The Binary Heap remains unchanged.
  // Time Efficiency: O(1)
  unsigned int getElementCount() const;

  // Description: Inserts newElement into the Binary Heap according to its heap properties.
  //              Returns true if successful, otherwise false.
  // Time Efficiency: O(log n)
  bool insert(ElementType& newElement);

  // Description: Removes the root element from the Binary Heap.
  // Precondition: The Binary Heap is not empty.
  // Postcondition: The root element is removed, and the Binary Heap's heap properties are restored.
  // Exceptions: Throws EmptyDataCollectionException if the Binary Heap is empty.
  // Time Efficiency: O(log n)t(ElementType&);
  void remove();

  
  // Description: Retrieves (but does not remove) the necessary element.
  // Precondition: This Binary Heap is not empty.
  // Postcondition: This Binary Heap is unchanged.
  // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
  // Time Efficiency: O(1) 
  ElementType& retrieve() const;

  void print() const;
};

#include "BinaryHeap.cpp"
#endif

// clang-format on
