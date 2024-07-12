#ifndef NODELIST_H
#define NODELIST_H
#include "node.h"
class NodeList {
public:
  Node *head = nullptr;
  int removeMiddle();
};

#endif
