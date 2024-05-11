#ifndef CIRCLE_H
#define CIRCLE_H
class Circle {
private:
  int xCoordinate;
  int yCoordinate;
  double radius;

public:
  Circle();
  Circle(int, int, double);
  int getYCoordinate() const;
  int getXCoordinate() const;
  void setXCoordainte(int);
  void setYCoordinate(int);
  double getRadius() const;
  void setRadius(double);
  void move(int, int);
  void displayCircle() const;
  bool intersect(Circle) const;
};

#endif
