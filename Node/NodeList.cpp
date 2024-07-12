#include "NodeList.h"

int NodeList::removeMiddle() {
  int toReturn = -1;
  if (!head) {
    return toReturn;
  }
  if (head->next == nullptr) {
    toReturn = head->data;
    delete head;
    head = nullptr;
    return toReturn;
  }
  int count = 0;
  Node *current = head;
  while (current) {
    current = current->next;
    count++;
  }
  current = head;
  Node *previous = nullptr;
  for (int i = 1; i < count; i++) {
    previous = current;
    current = current->next;
  }
  if (previous == head) {
    toReturn = current->data;
    previous->next = nullptr;
    delete current;
  } else {
    toReturn = current->data;
    previous->next = current->next;
    delete current;
  }
  return toReturn;
}
