// clang-format off
/* 
 * BinaryHeap.cpp
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant: Always maintains a Minimum Binary Heap property.
 * 
 * Author: Jason Mac, Jagyjot Parmar 
 * Last Modification: July 2024
 *
 */  


#include <iostream>
#include "BinaryHeap.h"  // Header file

using std::cout;
using std::endl;
using std::nothrow;
  
// Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap() {}

// Copy Constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap(const BinaryHeap& other) {
  // Get a deep copy of other.elements
  ElementType* otherElementsCopy = nullptr;
  if(other.elements != nullptr) {
    otherElementsCopy = new(nothrow) ElementType[other.capacity];
    for(unsigned int i = 0; i < other.elementCount; i++) {
      otherElementsCopy[i] = other.elements[i];
    }
  }
  this->elements = otherElementsCopy;
  this->capacity = other.capacity;
  this->elementCount = other.elementCount;
}

// Destructor
template <class ElementType>
BinaryHeap<ElementType>::~BinaryHeap() {
  delete[] elements;
  this->elements = nullptr;
}

// Assignment Operator
template <class ElementType>
void BinaryHeap<ElementType>::operator= (const BinaryHeap& rhs) {
 // Self-assignment check
  if (this == &rhs) {
    return;
  }

  // Perform deep copy of elements array from `rhs`
  ElementType* rhsCopyElements = nullptr;
  if(rhs.elements != nullptr) {
    rhsCopyElements = new(nothrow) ElementType[rhs.capacity];
    for(unsigned int i = 0; i < rhs.elementCount; i++) {
      rhsCopyElements[i] = rhs.elements[i];
    }
  }
  // Delete current elements array and assign new one from `rhs`
  if(this->elements != nullptr) {
    delete[] this->elements;
  }
  this->elements = rhsCopyElements;

  // Copy other basic data members
  this->elementCount = rhs.elementCount;
  this->capacity = rhs.capacity;
}


/* UTILITY METHODS */

// Description: Copies elements array into a new specified sized dynamically allocated array
//              maintaining the relative order of the elements and the array is returned
// Postcondition: The Binary Heap remains unchaged
template<class ElementType>
ElementType* BinaryHeap<ElementType>::getNewSizeArray(unsigned int newCapacity) const {
  // Allocate a new array with the specified new capacity
  ElementType* newElements = new(nothrow) ElementType[newCapacity];
  
  // Check if memory allocation was successful
  if(newElements == nullptr) {
    return nullptr; // Return nullptr if allocation failed
  }
  
  // Copy existing elements from the old elements array to the new elements array
  for(unsigned int i = 0; i < elementCount; i++) {
    newElements[i] = elements[i];
  }
  
  // Return the pointer to the new array containing copied elements
  return newElements;
}

// Description: Recursively put the array back into a Min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot) {

   unsigned int indexOfMinChild = indexOfRoot;
   
   // Find indices of children.
   unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
   unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

   // Base case: elements[indexOfRoot] is a leaf as it has no children
   if (indexOfLeftChild > elementCount - 1) return;

   // If we need to swap, select the smallest child
   // If (elements[indexOfRoot] > elements[indexOfLeftChild])
   if ( ! (elements[indexOfRoot] <= elements[indexOfLeftChild]) )
      indexOfMinChild = indexOfLeftChild;

   // Check if there is a right child, is it the smallest?
   if (indexOfRightChild < elementCount) {
      // if (elements[indexOfMinChild] > elements[indexOfRightChild])
      if ( ! (elements[indexOfMinChild] <= elements[indexOfRightChild]) )
         indexOfMinChild = indexOfRightChild;
   }

   // Swap parent with smallest of children.
   if (indexOfMinChild != indexOfRoot) {
      
      ElementType temp = elements[indexOfRoot];
      elements[indexOfRoot] = elements[indexOfMinChild];
      elements[indexOfMinChild] = temp;
      
      // Recursively put the array back into a heap
      reHeapDown(indexOfMinChild);
   }
   return;
}

// Description: Recursively put the array back into a Min Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfChild) {
  unsigned int indexOfRoot = 0;

  // Calculate the parent's index
  unsigned int indexOfParent = (indexOfChild - 1) / 2;

  // Base case: if the child is the root node, stop the recursion
  if(indexOfChild <= indexOfRoot) {
    return;
  }

  // If the parent's element is greater than the child's element, swap them
  if(!(elements[indexOfParent] <= elements[indexOfChild])) {

    // Swap elements at indexOfChild and indexOfParent
    ElementType temp = elements[indexOfChild];
    elements[indexOfChild] = elements[indexOfParent];
    elements[indexOfParent] = temp;
    
    // Recursively call reHeapUp on the parent index and fix potential violation of Min Binary Heap
    reHeapUp(indexOfParent);
    
    // Return after the recursive call
    return;
  }
}

/* PUBLIC INTERFACE */
// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove() {  
  // Throw an exception if the heap is empty
  if (elementCount == 0) 
    throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");
  
  // Replace the root element with the last element
  elements[0] = elements[elementCount - 1];
  elementCount--;

  // If more than one element remains, re-heapify starting from the root
  if (elementCount > 0) 
    reHeapDown(0);

  // Resize if elementCount is less than capacity / 4 to maintain efficient use of memory
  if (elementCount <= capacity / 4 && capacity > BASE_CAPACITY) {
    // Always maintain a capacity >= 8 == BASE_CAPACITY, otherwise take half the capacity as new size
    unsigned int newSize = std::max(BASE_CAPACITY, capacity / 2);
    ElementType* newSizeArray = getNewSizeArray(newSize);
    if (newSizeArray == nullptr) {
      // Memory allocation failed 
      return;
    }
    delete[] elements;
    elements = newSizeArray;
    capacity = newSize;
  }

  return;   
}

// Description: Inserts a new element into the heap.
// Time Efficiency: O(log2 n) amortized
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType& newElement) {
  // Check if elements array is initialized
  if(elements == nullptr) {
    elements = new(nothrow) ElementType[BASE_CAPACITY];
    if(elements == nullptr) {
      // Memory allocation failed
      return false;
    }
    capacity = BASE_CAPACITY;
  }

  // Check if capacity is full 
  if(elementCount == capacity) {
    unsigned int newCapacity = capacity * 2;                  // Double Current Capacity
    ElementType* newElements = getNewSizeArray(newCapacity);  // Get resized Array
    if(newElements == nullptr) {
      return false;                                           // Return false if resizing fails
    }
    delete[] elements;                                        // Delete old array
    capacity = newCapacity;
    elements = newElements;                                   // Update elements to point to resized array
  }

  // Insert at the end of the heap
  unsigned int insertionIndex = elementCount;

  // Insert newElement at end of the heap 
  elements[insertionIndex] = newElement;
  elementCount++;

  // Fix possible violation of invariant of the min heap 
  reHeapUp(insertionIndex);


  // Successful insertion, return true
  return true;
}

// Description: Returns the root element of the heap.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType& BinaryHeap<ElementType>::retrieve() const {
    // Check if the heap is empty
    if (elementCount == 0) {
        // Throw an exception if trying to retrieve from an empty heap
        throw EmptyDataCollectionException("Empty Data Collection, no element to retrieve.");
    }
    
    // Return a reference to the root element of the heap
    return elements[0];
}


// Description: Returns the number of elements currently stored in the Binary Heap.
// Postcondition: The Binary Heap remains unchanged.
// Time Efficiency: O(1)
template<class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const {
  return elementCount;
}

// PERSONAL PRINT METHOD FOR TESTING
template<class ElementType>
void BinaryHeap<ElementType>::print() const {
  if(elements == nullptr) {
    cout << "empty" << endl;
    return;
  }
  cout << "[";
  for(unsigned int i = 0; i < elementCount - 1; i++) {
    cout << elements[i] << ", ";
  }
  cout << elements[elementCount - 1] << "]" << endl;
}
// clang-format on
