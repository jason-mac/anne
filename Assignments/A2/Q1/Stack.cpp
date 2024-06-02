// clang-format off
#include "Stack.h"

Stack::Stack() {
  head = nullptr;
}

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

int Stack::peek() const {
  StackNode* current = head;
  while(current->next) {
    current = current->next;
  }
  return current->data;
}

bool Stack::isEmpty() const {
  return head == nullptr;
}
// clang-format on
