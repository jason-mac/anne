#include <iostream>

class Node {
public:
  int val;
  Node *next;
  Node(int val) : val(val), next(nullptr) {}
  Node(int val, Node *next) : val(val), next(next) {}
};
