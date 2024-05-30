// clang-format off
/* MyADTTestDriver.cpp - Assignment 1
 * 
 * Class Description: Testing our MyADT Data Collection
 *
 * Author: Jason Mac 
 * Modified on: May 2024
 */
#include "MyADT.h"
#include <cstdlib>
#include <iostream>


using std::cout;
using std::endl;
using std::string;

// Functions
// Profile * search(const Profile& target);
// void print();
// void removeAll();
// bool remove(const Profile& toBeRemoved);
// bool insert(const Profile& newElement);
// unsigned int getElementCount() const;
// friend void makeFullADT(MyADT& adt);

// Fills a MyADT object

void printADT(MyADT& adt) { 
  string dash = "----------------------------------------------------";
  cout << dash << endl;
  adt.print();
  cout << dash << endl;
  cout << endl;
}
// Test Driver function for MyADT class
int main() {

  // For formatting
  string dash = "----------------------------------------------------";

  // Creating test object using default constructor. 
  cout << "Create a valid default MyADT data collection -> testing constructor MyADT()." << endl;
  MyADT test;

  // Test: getElementCount() with default constructor
  cout << "Testing getElementCount() function with default constructor instantiated test object" << endl;
  cout << "Expected result: 0. test.getElementCount() = " << test.getElementCount() << endl;
  cout << endl;

  // Creating test profiles
  cout << "Creating 5 Profile objects with usernames starting with 'j' character" << endl;
  Profile p1("japanLover", "Benjamin Franklin", "getmoney@hotmail.com", "January 29 2004");
  Profile p2("jazzyB", "Gurvinder Grewal", "hockeyfan21@gmail.com", "March 31 1998");
  Profile p3("jayz", "David Goggins", "dontknowmeson@getbig.com", "February 17 1975");
  Profile p4("jiggle", "Nick Cannon", "puffthemagicdragon@live.ca", "April 12 1969");
  Profile p5("johncena", "John Cena", "cantseeme@outlook.com", "April 23 1977");

  // Creating an extra copy of one of the profiles for testing
  Profile p1copy = p1;

  // Test: Insert function. Expecting succesful insert
  cout << "Testing insert function" << endl;
  cout << dash << endl;
  cout << "Attempting to insert " << p1.getUserName() << " into test object" << endl;
  if (test.insert(p1)) {
    cout << "\t" << p1.getUserName() << " has been inserted! (Expected Result)" << endl;
    cout << "\tChecking element count after insertion, expecting 1 : test.getElementCount() = " << test.getElementCount() << endl;
  } else {
    cout << "\t" << p1.getUserName() << " could not be inserted (Unexpected Result)" << endl;
  }
  cout << endl;
  cout << "Printing current state of test object" << endl;
  printADT(test);

  // Test: Duplicate insertion. Expecting failure of duplicate insertion
  cout << "Testing if duplicate profile can be inserted by inserting " << p1copy.getUserName() << " again" << endl;
  cout << dash << dash << endl;
  cout << "Inserting " << p1copy.getUserName() << " into test object again... " << endl;
  if (test.insert(p1copy)) {
    cout << "\tDuplicate profile inserted (Unexpected Result)" << endl;
  } else {
    cout << "\tAttmempt of insertion of duplicate profile failed (Expected Result)" << endl;
  }
  cout << endl;
  cout << "Printing current state of test object" << endl;
  cout << "Expecting to only have " << p1.getUserName() << " in test data collection" << endl;
  printADT(test);
  
  // Insert remainder profiles
  cout << "Inserting four more profiles with 'j' usernames..." << endl;
  test.insert(p2);
  test.insert(p3);
  test.insert(p4);
  test.insert(p5);
  cout << endl;

  // Test: Print function and element count. Expecting Created Profiles to be displyaed in ascending order
  cout << "Printing current state of test object" << endl;
  cout << "Printing out test ADT instance (Expecting 5 profiles with username starting with j)" << endl;
  printADT(test);
  cout << "Printing element count. Expected Result: 5, test.getElementCount() = " << test.getElementCount() << endl;
  cout << endl;
  
  // Test: Insert beyond MAX_ELEMENTS. Expecting failure insert
  Profile extraJ("jupitr");
  cout << "Attempting to add profiles past MAX_ELEMENTS with character j..." << endl;
  if (test.insert(extraJ)) {
    cout << "\t" << "Inserted past MAX_ELEMENTS capacity for character j (Unexpected Result)" << endl;
  } else {
    cout << "\t" << "Failed to insert past MAX_ELEMENTS capacity for character j (Expected Result)" << endl;
  }
  cout << endl;
  cout << "Printing current state of test object" << endl;
  cout << "Expecting to have 5 profiles starting with 'j', but no profile with " << extraJ.getUserName() << endl;

  // Insert variety of Profiles
  cout << "Inserting a variety of profiles into test..." << endl;
  Profile p6("random");
  Profile p7("unicorn");
  test.insert(p6);
  test.insert(p7);
  cout << endl;
  cout << "Printing current state of test object" << endl;
  printADT(test);

  // Test: Copy constructor (deep copy). Expecting test and copy to not be alises of each other
  cout << "Testing copy constructor by making a new object with MyADT copy = test" << endl;
  cout << dash << endl;
  MyADT copy = test;
  cout << "Calling MyADT copy = test" << endl;
  cout << "A deep copy of test has been instantiated" << endl;
  cout << endl;

  cout << "Printing out test object" << endl;
  printADT(test);

  cout << "Printing out copy object. Expected Result: Exact same print as test" << endl;
  printADT(test);

  // Test: Deep copy implementation. Expecting different print statements for test and copy objects
  cout << "Inserting a new profile into copy..." << endl;
  if (copy.insert(Profile("zebra"))) {
    cout << "\tProfile('zebra') has been inserted into copy! (Expected Result)" << endl;
  } else {
    cout << "\tCould not insert Profile('zebra') into copy (Unexpected Result)" << endl;
  }

  cout << "Removing " << p6.getUserName() << " from test object..." << endl;
  if(test.remove(p6)) {
    cout << "\t" <<  p6.getUserName() << " has been removed (Expected Result)" << endl;
  } else {
    cout << "\t" << p6.getUserName() << " has not been removed (Unexpected Result)" << endl;
  }
  cout << endl;
  cout << "Printing current state of test object. Expected Result: p6.getUserName() is not in print statement" << endl;
  printADT(test);

  // Print both test and copy after modifications
  cout << "Printing out both test and copy after inserting another profile into copy and removal of a profile from test" << endl; 
  cout << "Expected Result: copy should have the same profiles but should have zebra and random as well" << endl;
  cout << endl;

  cout << "Printing out test after inserting a new profile into copy and removing random from test" << endl;
  printADT(test);

  cout << "Printing out copy after inserting new profile into copy and removing random from test" << endl;
  printADT(copy);


  // Test: Remove function
  cout << "Testing remove function" << endl;
  cout << dash << endl;


  // Removing existing profile. Expecting exisiting profile to be removed successfully
  cout << "Attemping to remove " << p1.getUserName() << " from test object (should succeed)..." << endl;
  if (test.remove(p1)) {
    cout << "\t" << p1.getUserName() << " has been removed! (Expected Result)" << endl;
  } else {
    cout << "\t" << p1.getUserName() << " has failed to be removed (Unexpected Result)" << endl;
  }
  cout << endl;
  cout << "Printing current state of test object" << endl;
  cout << "Expecting " << p1.getUserName() << " to not be a part of print statement" << endl;
  printADT(test);

  // Removing non-existent profile. Expecting failure of removal of non-existent profile
  Profile doesNotExist("doesNotExist");
  cout << "Attempting to remove non-existent profile from test (should fail)..." << endl;
  if (test.remove(doesNotExist)) {
    cout << "\t" << doesNotExist.getUserName() << " has been removed (Unexpected Result)" << endl;
  } else {
    cout << "\t" << doesNotExist.getUserName() << " has failed to be removed (Expected Result)" << endl;
  }
  cout << endl;
  cout << "Printing current state of test object" << endl;
  cout << "Expecting same print as previous print" << endl;

  // Test: Removing and then re-adding the same profile. Expecting succesful removal and isnert of same profile
  cout << "Testing remove followed by re-insert of the same profile" << endl;
  cout << dash << endl;

  // Removing p2
  cout << "Removing " << p2.getUserName() << " from test object..." << endl;
  if (test.remove(p2)) {
      cout << "\t" << p2.getUserName() << " has been removed! (Expected Result)" << endl;
  } else {
      cout << "\t" << p2.getUserName() << " has failed to be removed (Unexpected Result)" << endl;
  }
  cout << endl;
  cout << ""

  // Re-inserting p2
  cout << "Re-inserting " << p2.getUserName() << " into test object..." << endl;
  if (test.insert(p2)) {
      cout << "\t" << p2.getUserName() << " has been re-inserted! (Expected Result)" << endl;
  } else {
      cout << "\t" << p2.getUserName() << " could not be re-inserted (Unexpected Result)" << endl;
  }
  cout << endl;
  
  // Test: search function
  cout << "Testing out search function on test object" << endl;
  cout << dash << endl;

  // Searching for existing profile. Expecting existing profile to be found
  cout << "Searching for " << p2.getUserName() << " in test object..." << endl;
  if (test.search(p2)) {
    cout << "\t" << p2.getUserName() << " has been found in test ADT! (Expected Result)" << endl;
  } else {
    cout << "\t" << p2.getUserName() << " has not been found in test ADT! (Unexpected Result)" << endl;
  }
  cout << endl;
  
  // Searching for non-existent profile. Expecting non-existent to not be found
  cout << "Searching for non-existent profile in test object..." << endl;
  if (test.search(doesNotExist) != nullptr) {
    cout << "\t" << doesNotExist.getUserName() << " has been found in test ADT (Unexpected Result)" << endl;
  } else {
    cout << "\t" << doesNotExist.getUserName() << " has not been found in copy ADT (Expected Result)" << endl;
  }
  cout << endl;


  // Test: removeAll function
  cout << "Testing out removeAll() on test" << endl;
  cout << "Before calling test.removeAll(), test.getElementCount() = " << test.getElementCount() << endl;
  cout << "Calling test.removeAll()" << endl;
  test.removeAll();
  cout << "Check getElementCount() after calling test.removeAll() (Expecting 0), test.getElementCount() = " << test.getElementCount() << endl;
  cout << endl;


  // Check for empty MyADT. Expecting empty print statement for test object
  cout << "Printing after calling test.removeAll() should print no elements" << endl;
  printADT(test);
  cout << endl;
  cout << "See nothing?? good!" << endl;

  // Test: Printing final state of test and copy objects
  cout << "Final state of test and copy objects" << endl;
  cout << dash << endl;
  
  cout << "Printing out test object" << endl;
  printADT(test);

  cout << "Printing out copy object" << endl;
  printADT(copy);
  // End of test driver
  cout << "End of MyADT test driver" << endl;
  return 0;
}

// clang-format on
