/*
 * Circle.h
 *
 * Class Description: Class modelling circle in the cartesian plane and data
 * members xCoordinate and yCoordinate will represent the center of the circle
 * object and radius will represent the circle's radius offerring interstion
 * checker
 *
 * Class invartiant: radius >= 0.0
 *
 *
 * Author: Jason Mac
 * Modified: May 2024
 *
 */

#ifndef CIRCLE_H
#define CIRCLE_H

// Class Defintion

class Circle {
private:
  constexpr static double PI = 3.14159;

  int xCoordinate;
  int yCoordinate;
  double radius; // >= 0.0

public:
  //--- Constructors ---

  // Default Constructor
  //  Description: Constructs an object of the Circle class
  //              with data members initialized to
  //              xCoordinate = 0;
  //              yCoordinate = 0;
  //              radius = 0.0; // >= 0.0
  //  Postcondition: 'xCoordinate = 0 && yCoordinate = 0 && radius = 0.0'
  Circle();

  // Precondition: radius >= 0.0
  // Postcondition: 'xCoordinate = x && yCoordinate = y && radius = r'
  Circle(int, int, double);

  //--- Getters ---

  int getYCoordinate() const;
  int getXCoordinate() const;
  double getRadius() const;

  //--- Setters ---
  // Description: Change x coordinate of the center of the circle
  // Postcondition: 'xCoordinate  = x'
  void setXCoordainte(int);
  // Description: Change y coordinate of the center of the circle
  // Postcondition: 'yCoordinate  = y'
  void setYCoordinate(int);

  void setRadius(double);

  double computeArea() const;
  void move(int, int);
  void displayCircle() const;
  bool intersect(Circle) const;
};

#endif
