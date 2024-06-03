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

#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;


int main () {

  // Let's get ourselves a queue!
  Queue * Q = new Queue();


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

  // Release heap memory
  delete Q;
  Q = nullptr;
  
  return 0;
}

