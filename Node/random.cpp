#include <iostream>

struct Node {
  int data;
  Node *next;
};

class List {
private:
  Node *head;

public:
  List() : head(nullptr) {}
  void removeMiddle() { Node *return; }

  void insert(int value) {
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
  }

  int removeLast() {
    int result = 0;
    if (!head) {
      return result;
    }

    Node *previous = nullptr;
    Node *current = head;

    while (current->next) {
      result++;
      previous = current;
      current = current->next;
    }

    if (previous) {
      previous->next = nullptr;
      delete current;
      current = nullptr;
    } else {
      delete head;
      head = nullptr;
    }

    return result;
  }

  void display() {
    Node *temp = head;
    while (temp) {
      std::cout << temp->data << " ";
      temp = temp->next;
    }
    std::cout << std::endl;
  }
};

int main() {
  List myList;
  myList.insert(5);
  myList.insert(4);
  myList.insert(3);
  myList.insert(2);
  myList.insert(1);

  myList.display();
  int nodesRemoved = myList.removeLast();
  std::cout << "Nodes Removed: " << nodesRemoved << std::endl;
  myList.display();

  return 0;
}
