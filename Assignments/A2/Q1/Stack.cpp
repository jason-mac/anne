// clang-format off
/*
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Jason Mac  
 * Date: May 2024
 */
// TODO
// 1) proper comments for function actions
#include "Stack.h"

// Description: Default Constructor
// Postcondition: Stack has no elements
Stack::Stack() {
  head = nullptr;
}


// Description: Destructor 
// Postcondition: All nodes are deallocated from heap
Stack::~Stack() {
  // popAll() method will free memory in linked list 
  this->popAll();
}

// Description: Adds a new element to the top of this Stack.
// Postcondition: newElement is inserted at top of the stack
// Time Efficiency: O(n)
bool Stack::push(int element) {
  // Create a new head if one has not been established

  StackNode* nodeToInsert = new StackNode();                  
  nodeToInsert->data = element;
  nodeToInsert->next = nullptr;
  if(!head) {
    head = nodeToInsert;
    return true;
  }
  StackNode* currentNode = head;
  while(currentNode->next) {
    currentNode = currentNode->next;
  }
  currentNode->next = nodeToInsert;
  return true;
}


// Description: Removes the top element of this Stack.
// Precondition: The Stack is not empty.
// Postconditon: Element at top to the stack is removed
// Time Efficiency: O(n)
bool Stack::pop(){
  // Unsuccessful pop, no elements were popped, return false
  if(isEmpty()) { return false; }

  // Special case when linked list contains only one element
  if(head->next == nullptr) {
    // head points to the only element in the linked list, delete it
    delete head;

    // Avoid dangling pointers
    head = nullptr;

    // Successful pop, return true;
    return true;
  }

  // Keep track of current working node and the previous node
  StackNode* previousNode = nullptr;
  StackNode* currentNode = head;

  // Retrieve last node in linked list to delete and its previous to reset the next pointer data member
  while(currentNode->next) {
    previousNode = currentNode;
    currentNode = currentNode->next;
  }

  // Set second last node's next pointer to nullptr before deleting the last node
  previousNode->next = nullptr;

  // Free memory
  delete currentNode;
  currentNode = nullptr;

  // Successful pop, return true
  return true;
}

// Description: Removes all elements from this Stack.
// Postcondition: Stack is in same state as when constructed.
void Stack::popAll() {
  // Early return on empty linked list, no elements to pop in empty linked list
  if(isEmpty()) { return; } 

  // Keep tracking of current working node and its previous node
  StackNode* previousNode = nullptr;
  StackNode* currentNode = head;

  // Visit each node in linked list and deleting the previous node that was visited
  while(currentNode) {
    previousNode = currentNode;
    currentNode = currentNode->next;
    delete previousNode;
  }

  // Avoid dangling pointers
  head = nullptr;
}

// Description: Returns the top of this Stack.
// Precondition: The Stack is not empty.
// Postcondition: This Stack is unchanged.
// Time Efficiency: O(n)
int Stack::peek() const {
  // Pointer to traverse linked list
  StackNode* currentNode = head;

  // Traverse through linked list until reaching the last node
  while(currentNode->next) {
    currentNode = currentNode->next;
  }

  // return the data as desired
  return currentNode->data;
}

// Description: Returns true if this Stack is empty otherwise false.
// Postcondition: This Stack is unchanged.
// Time Efficiency: O(1)
bool Stack::isEmpty() const {
  return head == nullptr;
}
// clang-format on
