#ifndef NODE_H
#define NODE_H
#include <iostream>

class Node {
public:
  int data;
  Node *next;
  Node(int val) : val(val), next(nullptr) {}
  Node(int val, Node *next) : val(val), next(next) {}
};

#endif
