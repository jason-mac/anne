#include "BinaryHeap.h"
#include "Queue.h"
#include <iostream>

int main() {
  Queue<int> q;
  int a = 1;
  int b = 2;
  int c = 3;
  q.enqueue(a);
  q.enqueue(b);
  q.enqueue(c);
  BinaryHeap<int> heap;
  heap.insert(a);
  heap.insert(b);
  heap.insert(c);
  cout << q.peek() << " peek q" << endl;
  cout << " heap retrive " << heap.retrieve();
  return 0;
}
