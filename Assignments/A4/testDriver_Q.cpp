#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "Queue.h"
#include <cstdlib>
#include <iostream>

int main() {
  BinaryHeap<int> *heap = new BinaryHeap<int>();
  Queue<int> *q = new Queue<int>();
  int arr[10] = {4, 12, 43, 51, 56, 743, 56, 14, 100, 3333};
  for (int i = 0; i < 10; i++) {
    heap->insert(arr[i]);
    q->enqueue(arr[i]);
  }
  cout << "PRINTING Q" << endl;
  q->print();
  cout << "ENDING PRINT" << endl;

  cout << "PRINTING HEAP" << endl;
  heap->print();
  cout << "ENDING PRINT" << endl;

  cout << "deque" << endl;
  while (!q->isEmpty()) {
    q->dequeue();
    q->print();
  }
  return EXIT_SUCCESS;
}
