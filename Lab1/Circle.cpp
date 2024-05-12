#include "Circle.h"
#include <iostream>
using std::cout;
using std::endl;
// Default Constructor
//  Description: Constructs an object of the Circle class
//              with data members initialized to
//              xCoordinate = 0;
//              yCoordinate = 0;
//              radius = 0.0; // >= 0.0
//  Postcondition: 'xCoordinate = 0 && yCoordinate = 0 && radius = 0.0'
Circle::Circle() {
  xCoordinate = 0;
  yCoordinate = 0;
  radius = 10.0;
}

// Precondition: radius >= 0.0
// Postcondition: 'xCoordinate = x && yCoordinate = y && radius = r'
Circle::Circle(int x, int y, double r) {
  xCoordinate = x;
  yCoordinate = y;
  radius = r;
}

//--- Getters ---

int Circle::getYCoordinate() const { return yCoordinate; }
int Circle::getXCoordinate() const { return xCoordinate; }
double Circle::getRadius() const { return radius; }

//--- Setters ---
//
// Description: Change x coordinate of the center of the circle
// Postcondition: 'xCoordinate  = x'
void Circle::setXCoordainte(int x) { xCoordinate = x; }

// Description: Change y coordinate of the center of the circle
// Postcondition: 'yCoordinate  = y'
void Circle::setYCoordinate(int y) { yCoordinate = y; }

// Description: Change radius of the circle
// Precondition: r >= 0.0
// Postcondition: 'radius = r or radius = 10.0 if r is invalid'
void Circle::setRadius(double r) {
  if (r < 0) {
    radius = 10;
  } else {
    radius = r;
  }
}

// Description: 'this' x and y coordinates are shifted by integer amount
// Postcondition: 'xCoordinate = xCoordinate + horiz && yCoordinate =
// yCoordinate + vert'
void Circle::move(int horiz, int vert) {
  xCoordinate = xCoordinate + horiz;
  yCoordinate = yCoordinate + vert;
}
// Displays content of 'this'
// Postcondition: Contents of 'this' are displayed as "x = 'xCoordinate', y =
// 'yCoordinate', radius = 'radius'"
void Circle::displayCircle() const {
  cout << "x = " << xCoordinate << " y = " << yCoordinate
       << " radius = " << radius << endl;
}

// Description: Checks if 'this' and given circle are intersecting
// Postcondition: returns true if 'this' and c are intersecting, returns false
// otherwise
bool Circle::intersect(Circle c) const {
  if (this->xCoordinate == c.xCoordinate &&
      this->yCoordinate == c.yCoordinate && this->radius == c.radius) {
    return true;
  }
  int deltaX = abs(this->xCoordinate - c.xCoordinate);
  int deltaY = abs(this->yCoordinate - c.yCoordinate);
  double delta = std::sqrt(deltaX * deltaX + deltaY * deltaX);
  double radiusSum = this->radius + c.radius;
  if (delta > radiusSum) {
    return false;
  }
  if (delta < abs(this->radius - c.radius)) {
    return false;
  }
  return true;
}

// Desciption: Returns area of circle
double Circle::computeArea() const { return PI * radius * radius; }
