// clang-format off
/*
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL
 * list Class Invariant: LIFO order Top of Stack located at the back of SHSL
 * list.
 *
 * Author: Jason Mac, and Jagyjot Parmar
 * Date: May 2024
 */
#include "Stack.h"

// Description: Constructor
// Postcondition: Stack has no elements
Stack::Stack() {}

// Description: Destructor
// Postcondition: All nodes are deallocated from heap
Stack::~Stack() {
  // popAll() method will free memory in linked list
  this->popAll();
}

// Description: Adds a new element to the top of this Stack. Returns true
//              if element is pushed, false otherwise
// Postcondition: newElement is inserted at top of the stack
// Time Efficiency: O(n)
bool Stack::push(int newElement) {
  // Allocate StackNode onto heap for insert
  StackNode *nodeToPush = new StackNode();

  nodeToPush->data = newElement;
  nodeToPush->next = nullptr;

  // If stack is empty, set head to nodeToPush
  if (isEmpty()) {
    head = nodeToPush;
    // newElement pushed, return true
    return true;
  }

  // Pointer for traversal of linked list
  StackNode *currentNode = head;

  // Get last node in linked list to insert at top of stack
  while (currentNode->next) {
    currentNode = currentNode->next;
  }

  // Insert nodeToPush into linked list, top of the stack
  currentNode->next = nodeToPush;

  // newElement pushed, return true
  return true;
}

// Description: Removes the top element of this Stack. Returns true
//              if element is popped, false otherwise
// Precondition: The Stack is not empty.
// Postconditon: Element at top of the stack is removed
// Time Efficiency: O(n)
bool Stack::pop() {

  // Return false for empty linked list, cannot remove any elements
  if (isEmpty()) {
    return false;
  }

  // Special case: if stack contains only one element
  if (head->next == nullptr) {

    // Delete only element in the stack
    delete head;

    // Indicate that stack is now empty by setting head to nullptr
    head = nullptr;

    // Successful pop, return true
    return true;
  }

  // General case (At least two elements): Traverse to last node in linked list
  // (top of stack)
  StackNode *previousNode = nullptr; // Pointer to previous node
  StackNode *currentNode = head;     // Pointer to current node

  // Traverse to last node, keeping track of the previous node
  while (currentNode->next) {
    previousNode = currentNode;
    currentNode = currentNode->next;
  }

  // Set second last node's next pointer to nullptr
  previousNode->next = nullptr;

  // Delete the last node (top element of the stack)
  delete currentNode;
  currentNode = nullptr;

  // Successful pop, return true
  return true;
}

// Description: Removes all elements from this Stack.
// Postcondition: Stack is in same state as when constructed with default
// constructor
// Time Efficiency: O(n)
void Stack::popAll() {
  // Early return if linked list is empty
  if (isEmpty()) {
    return;
  }

  // Keep track of current working node and its previous node
  StackNode *previousNode = nullptr;
  StackNode *currentNode = head;

  // Visit each node in linked list and deleting the previous node that was
  // visited
  while (currentNode) {
    previousNode = currentNode;
    currentNode = currentNode->next;
    delete previousNode;
  }

  // Set head to nullptr to indicate stack is empty
  head = nullptr;
}

// Description: Returns the top of this Stack.
// Precondition: The Stack is not empty.
// Postcondition: This Stack is unchanged.
// Time Efficiency: O(n)
int Stack::peek() const {
  if (isEmpty()) {
    // TA said to return random number like 99 if stack is empty
    return 99;
  }

  // Pointer to traverse linked list
  StackNode *currentNode = head;

  // Traverse through linked list until reaching the last node (top of the
  // stack)
  while (currentNode->next) {
    currentNode = currentNode->next;
  }

  // Return data of node at top of stack
  return currentNode->data;
}

// Description: Returns true if this Stack is empty otherwise false.
// Postcondition: This Stack is unchanged.
// Time Efficiency: O(1)
bool Stack::isEmpty() const {
  // Stack is empty if head is null
  return head == nullptr;
}
// clang-format on
