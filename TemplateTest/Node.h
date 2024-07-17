#ifndef NODE_H
#define NODE_H
template <class T> class Node {
public:
  Node(T &theData);
  T &data;
  Node<T> *next = nullptr;
  T &getData() const;
};
#include "Node.cpp"

#endif
