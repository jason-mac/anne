#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "Queue.h"
#include <cstdlib>
#include <iostream>

void myTest() {
  BinaryHeap<int> *heap = new BinaryHeap<int>();
  Queue<int> *q = new Queue<int>();
  int arr[10] = {4, 12, 43, 51, 56, 743, 89, 14, 100, 3333};
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
    cout << "PEEK" << q->peek() << endl;
    q->print();
    q->dequeue();
  }
  try {
    q->dequeue();
  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
  }
  try {
    q->peek();
  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
  }
  cout << "HEAP MIN TEST" << endl;
  while (heap->getElementCount() != 0) {
    cout << "Min: " << heap->retrieve() << endl;
    heap->remove();
  }
  delete heap;
  delete q;
}
void sort(int array[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

void intTest() {
  int testInts[15];
  cout << "[ UNSORTED ]\n";
  for (unsigned int i = 0; i < 15; i++) {
    testInts[i] = rand() % 50;
    cout << testInts[i] << " ";
  }
  cout << endl;
  cout << "[ SORTED ]\n";
  sort(testInts, 15);
  for (unsigned int i = 0; i < 15; i++) {
    cout << testInts[i] << " ";
  }
  cout << endl << endl;
  Queue<int> QUEUE;
  BinaryHeap<int> BINARYHEAP;
  for (int i = 0; i < 15; i++) {
    int &buf = testInts[i];
    QUEUE.enqueue(buf);
    BINARYHEAP.insert(buf);
  }
  cout << "[ QUEUE ]\n";
  QUEUE.print();
  cout << "\n[ BINARY HEAP ]\n";
  BINARYHEAP.print();
  cout << "\n[ PRIORITY QUEUE ]\n";
  // PRIORITYQUEUE.print();
}

int main(int argc, char *argv[]) {
  time_t t;
  srand(time(&t));
  cout << "OTHER GUY" << endl;
  intTest();
  return EXIT_SUCCESS;
}
