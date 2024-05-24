#include <iostream>

template <class T> class Queue {
private:
  const unsigned int INITIAL_SIZE = 8;
  unsigned int capacity = INITIAL_SIZE;
  T *elements = nullptr;
  unsigned int front = 0;
  unsigned int back = 0;
  unsigned int elementCount = 0;

public:
  bool enqueue(const T &element);
  bool dequeue();
  bool dequeueAll();
  T &peek() const;
  bool isEmpty();
};
