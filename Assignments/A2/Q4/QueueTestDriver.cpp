/*
 * main.cpp
 *
 * Description: Queue test driver.
 *
 * Author:
 * Date:
 */

/*
  Feel free to modify this test driver to match
  the design of your Queue class.
*/

#include "Queue.h"
#include <iostream>

using std::cout;
using std::endl;

int main() {
  Queue a;
  Queue b;
  Queue c;
  a.enqueue(5);
  a.print();
  a = b;
  Queue d = b;
  cout << "abcd" << endl;
  a.print();
  b.print();
  c.print();
  d.print();

  // Let's get ourselves a queue!
  Queue *Q = new Queue();

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
  Q->enqueue(69);
  Queue *copy = new Queue(*Q);
  cout << "copy ";
  cout << " q ";
  copy->enqueue(20);
  cout << " copy ";

  Queue *nextCopy = new Queue();
  *nextCopy = *copy;
  cout << "nextopy ";
  cout << "copy ";
  nextCopy->enqueue(344);
  cout << "nextcopy ";
  nextCopy->print();
  cout << "copy ";

  cout << "final print no confusion" << endl;
  cout << "q";
  cout << "copy ";
  Q->print();
  cout << "nextcopy ";

  // Release heap memory
  delete Q;
  delete copy;
  delete nextCopy;
  Q = nullptr;

  return 0;
}
