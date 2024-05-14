#include "Circle.h"
#include <iostream>

using std::cin;
using std::cout;

// Description: Prints out all circles in array
//
void print(Circle **arr, unsigned int size) {
  for (int i = 0; i < size; i++) {
    arr[i]->displayCircle();
  }
}

int main() {
  Circle **circleArray = nullptr;
  unsigned int size;
  int x;
  int y;
  double radius;
  cout << " insert size ";
  cin >> size;
  while (size < 0) {
    cin >> size;
  }
  circleArray = new Circle *[size];
  for (int i = 0; i < size; i++) {
    cin >> x;
    cin >> y;
    cin >> radius;
    circleArray[i] = new Circle(x, y, radius);
  }
  return 0;
}
