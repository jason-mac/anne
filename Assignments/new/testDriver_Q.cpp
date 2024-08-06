#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
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
  if (heap.insert(a)) {
    cout << a << " has been inserted into heap " << endl;
  }
  cout << q.peek() << " peek q" << endl;
  cout << " heap retrive " << heap.retrieve();
  cout << heap.getElementCount() << endl;
  heap.remove();
  try {
    heap.remove();
  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
  }
  return 0;
}
