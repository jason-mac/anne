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

  // Test dequeuing
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

  // Test aliasing between copies and original queues after copy construction
  cout << "==================================" << endl;
  cout << "Testing Aliasing between Copies (Copy Constructor)" << endl;
  cout << "==================================" << endl;

  Queue aliasedQueue1(q1);
  Queue aliasedQueue2 = q2;
  aliasedQueue1.enqueue(100);
  aliasedQueue2.enqueue(200);

  cout << "Peek Front of q1: " << q1.peek() << endl;
  cout << "Peek Front of q2: " << q2.peek() << endl;
  cout << "Peek Front of aliasedQueue1: " << aliasedQueue1.peek() << endl;
  cout << "Peek Front of aliasedQueue2: " << aliasedQueue2.peek() << endl;

  // Test aliasing between copies and original queues after assignment
  cout << "==================================" << endl;
  cout << "Testing Aliasing between Copies (Assignment Operator)" << endl;
  cout << "==================================" << endl;

  Queue aliasedQueue3;
  aliasedQueue3 = q3;
  Queue aliasedQueue4 = q1;
  aliasedQueue3.enqueue(300);
  aliasedQueue4.enqueue(400);

  cout << "Peek Front of q3: " << q3.peek() << endl;
  cout << "Peek Front of q1: " << q1.peek() << endl;
  cout << "Peek Front of aliasedQueue3: " << aliasedQueue3.peek() << endl;
  cout << "Peek Front of aliasedQueue4: " << aliasedQueue4.peek() << endl;

  // Test chaining of assignment operators
  cout << "==================================" << endl;
  cout << "Testing Chaining of Assignment Operators" << endl;
  cout << "==================================" << endl;

  Queue chainQueue;
  chainQueue.enqueue(500) = chainQueue.enqueue(600) = chainQueue.enqueue(700);

  cout << "Peek Front of chainQueue: " << chainQueue.peek() << endl;

  return 0;
}
