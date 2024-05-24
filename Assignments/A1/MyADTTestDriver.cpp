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
  cout << "Creating MyADT first object, and 5 profiles objects with username "
          "starting with character 'j'"
       << endl;
  MyADT first;
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
  cout << "Testing insert on MyADT first" << endl;
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
    cout << "Inserted past MAX_ELEMENTS capacity for character j" << endl;
  } else {
    cout << "Failed to insert past MAX_ELEMENTS capacity for character j"
         << endl;
  }
  cout << "Testing copy constructor by making MyADT second = first" << endl;
  MyADT second = first;
  cout << "Printing out first object" << endl;
  first.print();
  cout << endl;
  cout << "Printing out second object (should be same since using copy "
          "constructor)"
       << endl;
  second.print();
  cout << "Inserting a new profile into second" << endl;
  if (second.insert(Profile("zebra"))) {
    cout << "Profile('zebra') has been inserted into second!" << endl;
  } else {
    cout << "Could not insert Profile('zebra') into second" << endl;
  }
  cout << "Printing out first after inserting a new profile into second"
       << endl;
  first.print();
  cout << "Printing out second after inserting new profile into second, "
          "include all same profiles but with addition of zebra profile "
          "Testing copy constructor"
       << endl;
  second.print();
  cout << "Testing out remove function" << endl;

  return EXIT_SUCCESS;
}
