#include "Circle.h"
#include <iostream>
using std::cout;

Circle::Circle() {
  xCoordinate = 0;
  yCoordinate = 0;
  radius = 10;
}

Circle::Circle(int x, int y, double r) {
  xCoordinate = x;
  yCoordinate = y;
  this->radius = r;
}

int Circle::getXCoordinate() const { return xCoordinate; }

int Circle::getYCoordinate() const { return yCoordinate; }

double Circle::getRadius() const { return radius; }

void Circle::setYCoordinate(int y) { yCoordinate = y; }

void Circle::setXCoordainte(int x) { xCoordinate = x; }

void Circle::setRadius(double r) {
  if (r < 0) {
    radius = 10;
    return;
  }
  radius = r;
}

void Circle::move(int dx, int dy) {
  xCoordinate = xCoordinate + dx;
  yCoordinate = yCoordinate + dy;
}

bool Circle::intersect(Circle c) const {
  int radiusSum = this->radius + c.getRadius();
  int deltaX = abs(this->getXCoordinate() - c.getXCoordinate());
  int deltaY = abs(this->getYCoordinate() - c.getYCoordinate());
  int deltaRsquared = deltaX * deltaX + deltaY * deltaY;
  if (deltaRsquared <= radiusSum) {
    return true;
  }
  return false;
}

void Circle::displayCircle() const {
  cout << "x coordinate: " << xCoordinate << " "
       << "y coordinate: " << yCoordinate << " "
       << "radius: " << radius;
}
