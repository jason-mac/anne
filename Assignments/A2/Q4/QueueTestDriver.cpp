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

  // Test dequeuing
  cout << "Dequeuing elements until empty..." << endl;
  while (!q.isEmpty()) {
    cout << "Dequeue: " << q.peek() << endl;
    q.dequeue();
  }

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

  // Test chaining of assignment operators
  cout << "==================================" << endl;
  cout << "Testing Chaining of Assignment Operators" << endl;
  cout << "==================================" << endl;

  q1 = q2 = q3;

  cout << "Peek Front of q1 after chaining assignment: " << q1.peek() << endl;
  cout << "Peek Front of q2 after chaining assignment: " << q2.peek() << endl;
  cout << "Peek Front of q3 after chaining assignment: " << q3.peek() << endl;

  // Insert elements into q1, q2, and q3
  for (int i = 1; i <= 5; i++) {
    q1.enqueue(i);
    q2.enqueue(i * 2);
    q3.enqueue(i * 3);
  }

  // Remove elements from q1, q2, and q3
  for (int i = 1; i <= 3; i++) {
    q1.dequeue();
    q2.dequeue();
    q3.dequeue();
  }

  cout << "Peek Front of q1 after operations: " << q1.peek() << endl;
  cout << "Peek Front of q2 after operations: " << q2.peek() << endl;
  cout << "Peek Front of q3 after operations: " << q3.peek() << endl;

  return 0;
}
