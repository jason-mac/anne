#include "MyADT.h"
#include <cstdlib>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

//
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
  cout << "Checking elementCount of first object after instantiation" << endl;
  cout << "elemenctCount of first object is : " << first.getElementCount()
       << endl;
  Profile p1("jason");
  Profile p2("jordan");
  Profile p3("jayz");
  Profile p4("jiggle");
  Profile p5("johncena");

  Profile p1copy = p1;
  cout << "Testing insert on MyADT first" << endl;
  if (first.insert(p1)) {
    cout << p1.getUserName() << " has been inserted! (Expected behaviour)"
         << endl;
    cout << "current elementCount for object first is: "
         << first.getElementCount() << endl;
  } else {
    cout << p1.getUserName() << " could not be inserted (Unexpected behaviour)"
         << endl;
  }
  cout << endl;

  first.insert(p2);
  first.insert(p3);
  first.insert(p4);
  cout << "Testing if profile duplicates can be inserted by inserting "
          "Profile('jason'), into data collection again"
       << endl;
  if (first.insert(p1copy)) {
    cout << "Inserted profile copy (Unexpected behaviour)" << endl;
  } else {
    cout << "Attmempt of insertion of same profile failed (Expected behaviour)"
         << endl;
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
  cout << endl;
  cout << "Testing copy constructor by making a new object MyADT second = first"
       << endl;
  MyADT second = first;
  cout << "Printing out first object" << endl;
  first.print();
  cout << endl;
  cout << "Printing out second object (should be same since using copy "
          "constructor)"
       << endl;
  second.print();
  cout << endl;
  cout << "Inserting a new profile into second" << endl;
  if (second.insert(Profile("zebra"))) {
    cout << "Profile('zebra') has been inserted into second!" << endl;
  } else {
    cout << "Could not insert Profile('zebra') into second" << endl;
  }
  cout << endl;
  cout << "Printing out first after inserting a new profile into second"
       << endl;
  first.print();
  cout << endl;
  cout << "Printing out second after inserting new profile into second, "
          "should include all same profiles but with addition of zebra profile "
       << endl;
  second.print();
  cout << endl;
  cout << "Testing out remove function" << endl;

  cout << "Testing remove function" << endl;
  cout << "Removing existing profile (jason) from first (should be successful)"
       << endl;
  if (first.remove(Profile("jason"))) {
    cout << "jason has been removed!" << endl;
  } else {
    cout << "jason has failed to be removed" << endl;
  }
  cout << endl;
  cout << "Removing non-existent profile (aaaa) from first (should fail)"
       << endl;
  if (first.remove(Profile("aaaa"))) {
    cout << "aaaa has been removed" << endl;
  } else {
    cout << "aaaa has failed to be removed" << endl;
  }
  cout << endl;

  cout << "Testing out removeAll() on first" << endl;
  cout << first.getElementCount()
       << " elemenctCount of first before calling first.removeAll()" << endl;
  first.removeAll();
  cout << first.getElementCount()
       << " elemenctCount of first after calliong first.removeAll() (should be "
          "zero!)"
       << endl;
  cout << "Calling first.print() after removing all elements, should print "
          "nothing"
       << endl;
  first.print();
  cout << endl;

  cout << "Testing out search function on second object" << endl;
  cout << "Searching for existig profile (jordan) in second ADT" << endl;
  if (second.search(p2)) {
    cout << p2.getUserName()
         << " has been found in second ADT! (Expected behaviour)" << endl;
  } else {
    cout << p2.getUserName()
         << " has not been found in second ADT! (Unexpected behaviour)" << endl;
  }
  cout << endl;
  const Profile fake("fake");
  cout << "Searching for non-existent profile (fake) in second ADT" << endl;
  if (second.search(fake) != nullptr) {
    cout << fake.getUserName()
         << " has been found in second ADT (Unexpected behaviour)" << endl;
  } else
    cout << fake.getUserName()
         << " has not been found in second ADT (Expected behaviour)" << endl;

  return EXIT_SUCCESS;
}
