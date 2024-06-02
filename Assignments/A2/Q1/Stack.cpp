// clang-format off
#include "Stack.h"

Stack::Stack() {
  head = nullptr;
  elementCount = 0;
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

void Stack::push(int element) {
  // Create a new head if one has not been established

  StackNode* nodeToInsert = new StackNode();                  
  nodeToInsert->data = element;
  nodeToInsert->next = nullptr;
  if(!head) {
    elementCount += 1;
    head = nodeToInsert;
    return;
  }
  StackNode* current = head;
  while(current->next) {
    current = current->next;
  }
  elementCount += 1;
  current->next = nodeToInsert;
}

void Stack::pop(){
  if(isEmpty()) { return; }
  if(head->next == nullptr) {
    delete head;
    head = nullptr;
    return;
  }
  StackNode* trail = nullptr;
  StackNode* current = head;
  while(current->next) {
    trail = current;
    current = current->next;
  }
  trail->next = nullptr;
  elementCount -= 1;
  delete current;
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
  elementCount = 0;
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
  return elementCount == 0;
}
// clang-format on
