#include "Circle.h"
#include <iostream>

using std::cin;
using std::cout;

// Description: Prints out all circles in array
//
void print(Circle **arr, unsigned int size) {
  for (unsigned int i = 0; i < size; i++) {
    arr[i]->displayCircle();
  }
}

// Description: Main function for testing the class.h cnad cliss.cpp files
// Precondition: attempting to break the program
// Precondition: No errors ideally!
int main() {
  Circle **circleArray = nullptr;
  unsigned int size;
  int x;
  int y;
  double radius;
  cout << " insert size ";
  cin >> size;
  while (size < 0) {
    cout << " insert positive size ";
    cin >> size;
  }
  circleArray = new Circle *[size];
  for (int i = 0; i < size; i++) {
    cin >> x;
    cin >> y;
    cin >> radius;
    circleArray[i] = new Circle(x, y, radius);
  }
  print(circleArray, size);
  return 0;
}
