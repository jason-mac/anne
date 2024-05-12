/* 
 * testcirc2.cpp
 *
 * Description: Driver program 2 for testing the circle class. 
 *
 * Author: Many people
 * Last Modification Date: May 2024
 */

#include <iostream> // As we need to print data
#include "Circle.h"

using std::cout;
using std::endl;

int main() {
  Circle c1 = Circle();
  Circle c2 = Circle(0,4,10);
  Circle c3 = Circle(0,4,14.1);
  Circle c4 = Circle(0,11,0.2);
  
  cout << "c1 : ";
  c1.displayCircle();
  cout << "c2 : ";
  c2.displayCircle();
  cout << "c3 : ";
  c3.displayCircle();
  cout << "c4 : ";
  c4.displayCircle();
  
  // Tests intersection method.
  if (c1.intersect(c2))
    cout << "c1 intersects c2" << endl;
  else
    cout << "c1 does not intersect c2" << endl;

  if (c1.intersect(c3))
    cout << "c1 intersects c3" << endl;
  else
    cout << "c1 does not intersect c3" << endl;

  if (c1.intersect(c4))
    cout << "c1 intersects c4" << endl;
  else
    cout << "c1 does not intersect c4" << endl;	

  return 0;
}
