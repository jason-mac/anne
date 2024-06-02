/* 
 * StackTestDriver.cpp
 *
 * Description: Test Driver for Stack class.
 *
 * Author:
 * Date:
 */

/* 
  Feel free to modify this test driver to match 
  the design of your Stack class.
  For example, if I design my push(...) and pop() 
  methods such that they both return a bool value, 
  then I would change this test driver such that
  it captures this returned bool value, etc.  
*/ 

#include <iostream> 
#include "Stack.h"

using std::cout;
using std::endl;


int main () {
  
  // Let's get ourselves a stack!
  Stack * stk = new Stack( );
  

  // Test Case 1: push 1, 2, 3, 4, 5
  // Expected result: 
  for (int i = 1; i <= 5; i++) {
    stk->push(i);
    cout << "push " << i << endl;
  }


  // Test Case 2: pop top twice
  // Expected result:
  int x = stk->peek();
  stk->pop();
  int y = stk->peek();
  stk->pop();
  cout << "top 1: " << x << ", top 2: " << y << endl;


  // Test Case 3: push 6, 7, 8, 9, 10
  // Expected result:
  for (int i = 6; i <= 10; i++) {
    stk->push(i);
    cout << "push " << i << endl;
  }


  // Test Case 4: pop all elements
  // Expected result:
  while (!stk->isEmpty()) {
    int x = stk->peek();
    stk->pop();
    cout << "pop " << x << endl;
  }

  // Release heap memory
  delete stk;
  stk = nullptr;
  
  return 0;
}

