#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
#include "Event.h"
#include "Queue.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void testQueue() {
  Queue<int> a;
  Queue<int> b;
  Queue<int> c;
  int five = 5;
  a.enqueue(five);
  a = b;
  Queue<int> d = b;
  cout << "abcd" << endl;

  // Let's get ourselves a queue!
  Queue<int> *Q = new Queue<int>();

  // Test Case 1: enqueue 1, 2, 3, 4, 5
  // Expected result:
  for (int i = 1; i <= 5; i++) {
    Q->enqueue(i);
    cout << "enqueue " << i << endl;
  }

  // Test Case 2: dequeue twice
  // Expected result:
  for (int i = 0; i < 2; i++) {
    int y = Q->peek();
    Q->dequeue();
    cout << "peek " << y << endl;
  }

  // Test Case 3: enqueue 6, 7, 8, 9, 10
  // Expected result:
  for (int i = 6; i <= 10; i++) {
    Q->enqueue(i);
    cout << "enqueue " << i << endl;
  }

  // Test Case 4: dequeue all elements
  // Expected result:
  while (!Q->isEmpty()) {
    int y = Q->peek();
    Q->dequeue();
    cout << "peek " << y << endl;
  }
  for (int i = 69; i <= 89; i++) {
    Q->enqueue(i);
    cout << "enqueue " << i << endl;
  }
  while (!Q->isEmpty()) {
    Q->dequeue();
  }
  cout << " done deqing" << endl;
  int sixtynine = 69;
  Q->enqueue(sixtynine);
  Queue<int> *copy = new Queue<int>(*Q);
  cout << "copy ";
  cout << " q ";
  int lol = 20;
  copy->enqueue(lol);
  cout << " copy ";

  Queue<int> *nextCopy = new Queue<int>();
  *nextCopy = *copy;
  cout << "nextopy ";
  cout << "copy ";
  int what = 344;
  nextCopy->enqueue(what);
  cout << "nextcopy ";
  cout << "copy ";

  cout << "final print no confusion" << endl;
  cout << "q";
  cout << "copy ";
  cout << "nextcopy ";

  // Release heap memory
  delete Q;
  delete copy;
  delete nextCopy;
  Q = nullptr;
}

void myTest() {
  BinaryHeap<int> *heap = new BinaryHeap<int>();
  Queue<int> *q = new Queue<int>();
  int arr[10] = {4, 12, 43, 51, 56, 743, 89, 14, 100, 3333};
  for (int i = 0; i < 10; i++) {
    heap->insert(arr[i]);
    q->enqueue(arr[i]);
  }
  cout << "PRINTING Q" << endl;
  cout << "ENDING PRINT" << endl;

  cout << "PRINTING HEAP" << endl;
  cout << "ENDING PRINT" << endl;

  cout << "deque" << endl;
  while (!q->isEmpty()) {
    cout << "PEEK: " << q->peek() << endl;
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
void inHousesort(int array[], int n) {
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
  inHousesort(testInts, 15);
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
  cout << "\n[ BINARY HEAP ]\n";
  cout << "\n[ PRIORITY QUEUE ]\n";
  // PRIORITYQUEUE.print();
}

void printVec(std::vector<int> vec) {
  cout << "{";
  for (unsigned int i = 0; i < vec.size() - 1; i++) {
    cout << vec[i] << ", ";
  }
  cout << vec[vec.size() - 1] << "}" << endl;
}
template <typename T> void vectorSort(std::vector<T> &vec) {
  int n = vec.size();
  bool swapped;
  do {
    swapped = false;
    for (int i = 1; i < n; ++i) {
      if (vec[i - 1] > vec[i]) {
        std::swap(vec[i - 1], vec[i]);
        swapped = true;
      }
    }
    --n;
  } while (swapped);
}
void testBinaryHeap() {
  BinaryHeap<int> *heap = new BinaryHeap<int>();

  std::vector<int> values = {4312, 9,     315,  435, 4356234, 5321,   900,
                             4,    234,   2345, 36,  54,      76578,  69,
                             6765, 8657,  6,    6,   56,      432513, 451,
                             4523, 64537, 3245, 6,   357,     255324};
  std::vector<int> sorted = values;
  vectorSort(sorted);
  printVec(values);
  printVec(sorted);
  for (auto x : values) {
    heap->insert(x);
  }
  cout << "PRINT HEAP" << endl;
  while (!(heap->getElementCount() == 0)) {
    cout << "min->" << heap->retrieve() << " " << endl;
    heap->remove();
  }
  try {
    heap->remove();
  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
  }
  heap->insert(values[0]);
  BinaryHeap<int> *newheap = new BinaryHeap<int>(*heap);
  while (!(heap->getElementCount() == 0)) {
    cout << "min->" << heap->retrieve() << " " << endl;
    heap->remove();
  }
  newheap->insert(values[1]);
  while (!(newheap->getElementCount() == 0)) {
    cout << "min->" << heap->retrieve() << " " << endl;
    heap->remove();
  }
  BinaryHeap<int> *oldheap = new BinaryHeap<int>();
  *oldheap = *heap;
  oldheap->insert(values[7]);
  cout << "old" << endl;
  while (!(oldheap->getElementCount() == 0)) {
    cout << "min->" << heap->retrieve() << " " << endl;
    heap->remove();
  }
  cout << endl;
  delete heap;
}

int main(int argc, char *argv[]) {
  testQueue();
  testBinaryHeap();
  myTest();
  // time_t t;
  // srand(time(&t));
  cout << "OTHER GUY" << endl;
  // intTest();

  return EXIT_SUCCESS;
}
