#include "MyADT.h"
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// Functions
// Profile * search(const Profile& target);
// void print();
// void removeAll();
// bool remove(const Profile& toBeRemoved);
// bool insert(const Profile& newElement);
// unsigned int getElementCount() const;

// Test Driver function for myadt class
int main() {
  MyADT first;
  MyADT second;
  Profile p1("jason");
  Profile p2("jordan");
  Profile p3("jayz");
  Profile p4("jiggle");
  Profile p5("johncena");
  Profile p1copy = p1;
  first.insert(p1);
  first.insert(p2);
  first.insert(p3);
  first.insert(p4);
  cout << "Testing if profile duplicates can be inserted" << endl;
  if (first.insert(p1copy)) {
    cout << "Inserted profile copy" << endl;
  } else {
    cout << "Attmempt of insertion of same profile failed" << endl;
  }
  first.insert(p5);
  cout << "Printing out first ADT instance (5 profiles with username starting "
          "with j)"
       << endl;
  first.print();
  cout << "Attempting to add profiles past MAX_ELEMENTS with character j"
       << endl;
  if (first.insert(Profile("j"))) {
    cout << "Inserted past MAX_ELEMENTS capacity" << endl;
  } else {
    cout << "Failed to insert past MAX_ELEMENTS capacity" << endl;
  }
  return EXIT_SUCCESS;
}
