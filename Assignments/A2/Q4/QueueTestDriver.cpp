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

using namespace std;

void testQueue(Queue &q, int testNum) {
  cout << "==================================" << endl;
  cout << "Test " << testNum << ": Queue Operations" << endl;
  cout << "==================================" << endl;

  // Test isEmpty on an empty queue
  cout << "Is queue empty initially? " << (q.isEmpty() ? "Yes" : "No") << endl;

  // Test enqueueing
  cout << "Enqueuing elements 1 to 10..." << endl;
  for (int i = 1; i <= 10; i++) {
    q.enqueue(i * testNum);
  }

  // Test isEmpty after enqueueing
  cout << "Is queue empty after enqueueing? " << (q.isEmpty() ? "Yes" : "No")
       << endl;

  // Test copy constructor
  cout << "Creating a new queue using copy constructor..." << endl;
  Queue copiedQueue(q);
  cout << "Peek Front of copied queue: " << copiedQueue.peek() << endl;

  // Test assignment operator
  cout << "Creating another queue using assignment operator..." << endl;
  Queue assignedQueue;
  assignedQueue = q;
  cout << "Peek Front of assigned queue: " << assignedQueue.peek() << endl;

  // Test peeking with elements
  cout << "Peek Front of original queue: " << q.peek() << endl;

  // Test dequeueing
  cout << "Dequeuing elements until empty..." << endl;
  while (!q.isEmpty()) {
    cout << "Dequeue: " << q.peek() << endl;
    q.dequeue();
  }

  // Test isEmpty after dequeueing
  cout << "Is queue empty after dequeueing? " << (q.isEmpty() ? "Yes" : "No")
       << endl;

  cout << "==================================" << endl;
}

int main() {
  // Test 1
  Queue q1;
  testQueue(q1, 1);

  // Test 2
  Queue q2;
  testQueue(q2, 2);

  // Test 3
  Queue q3;
  testQueue(q3, 3);

  return 0;
}
