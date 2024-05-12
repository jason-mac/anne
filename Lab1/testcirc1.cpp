/* 
 * testcirc1.cpp
 *
 * Description: Driver program 1 for testing the circle class. 
 *
 * Author: Many people
 * Last Modification Date: May 2024
 */

#include <iostream> // As we need to print data
#include <iomanip>  // As we need to set the precision of output
#include "Circle.h"

using std::cout;
using std::endl;
using std::setprecision;

int main() {

  Circle c1 = Circle(0,0,3);
  Circle c2 = Circle(5,20,10);

  // Apply the setters.
  c1.move(5,2);
  c2.setRadius(5);
	
  // Print the output of the getters
  // Should produce 5
  cout << "c1.getX() = " << c1.getX() << endl;
  // Should produce 2
  cout << "c1.getY() = " << c1.getY() << endl;
  // Should produce 5
  cout << "c2.getRadius() = " << c2.getRadius() << endl;
  // Should produce 25*PI = 78.5
  // Setting precision of 1 significant figure
  cout << "c2.computeArea() = " << setprecision(3) << c2.computeArea() << endl; 
	
  return 0;
}
