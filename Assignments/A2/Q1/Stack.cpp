// clang-format off
// TODO 
// 1) comments
// 2) time complexity
#include "Stack.h"

// Description: Default Constructor
// Postcondition: Stack has no elements
Stack::Stack() {
  head = nullptr;
}


// Description: Desctructor
// Postcondition: All nodes are deallocated from heap
Stack::~Stack() {
  if (head) {
    StackNode *trail = nullptr;
    StackNode *current = head;
    while (current) {
      trail = current;
      current = current->next;
      delete trail;
    }
  }
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
  StackNode* current = head;
  while(current->next) {
    current = current->next;
  }
  current->next = nodeToInsert;
  return true;
}


// Description: Removes the top element of this Stack.
// Precondition: The Stack is not empty.
// Postconditon: Element at top to the stack is removed
// Time Efficiency: O(n)
bool Stack::pop(){
  if(isEmpty()) { return false; }
  if(head->next == nullptr) {
    delete head;
    head = nullptr;
    return true;
  }
  StackNode* trail = nullptr;
  StackNode* current = head;
  while(current->next) {
    trail = current;
    current = current->next;
  }
  trail->next = nullptr;
  delete current;
  return true;
}

// Description: Removes all elements from this Stack.
// Postcondition: Stack is in same state as when constructed.
void Stack::popAll() {
  if(isEmpty()) { return; } 
  StackNode* trail = nullptr;
  StackNode* current = head;
  while(current) {
    trail = current;
    current = current->next;
    delete trail;
  }
  head = nullptr;
}

// Description: Returns the top of this Stack.
// Precondition: The Stack is not empty.
// Postcondition: This Stack is unchanged.
// Exceptions: Throws EmptyStackException if this Stack is empty. ???????
// Time Efficiency: O(n)
int Stack::peek() const {
  StackNode* current = head;
  while(current->next) {
    current = current->next;
  }
  return current->data;
}

// Description: Returns true if this Stack is empty otherwise false.
// Postcondition: This Stack is unchanged.
// Time Efficiency: O(1)
bool Stack::isEmpty() const {
  return head == nullptr;
}
// clang-format on
