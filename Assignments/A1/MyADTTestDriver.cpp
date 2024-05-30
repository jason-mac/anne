// clang-format off
/* MyADTTestDriver.cpp - Assignment 1 Part 2 
 * 
 * Class Description: Testing our MyADT Class Data Collection 
 *
 * Author: Jason Mac 
 * Modified on: May 2024
 */
#include "MyADT.h"
#include "Profile.h"
#include <cstdlib>
#include <iostream>


using std::cout;
using std::endl;
using std::string;

// Functions of MyADT class
// Profile * search(const Profile& target);
// void print();
// void removeAll();
// bool remove(const Profile& toBeRemoved);
// bool insert(const Profile& newElement);
// unsigned int getElementCount() const;

//Printing function for easier to read formatting
void printADT(MyADT& adt) { 
  string border = "====================================================";
  cout << border << " PRINT START" << endl;
  adt.print();
  cout << border << " PRINT END" << endl;
  cout << endl;
}
// Test Driver function for MyADT class
int main() {

  // For formatting
  string dash = "----------------------------------------------------";

  // Creating test object using default constructor. 
  cout << "Create a valid default MyADT data collection named 'test' -> testing constructor MyADT()" << endl;
  MyADT test;

  // Test: getElementCount() with default constructor. Expecting 0 elements
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
  Profile p1copy = Profile(p1.getUserName());

  // Test: Insert function. Expected Result: succesful insert
  cout << "Testing insert function" << endl;
  cout << dash << endl;
  cout << "Attempting to insert " << p1.getUserName() << " into test object using test.insert()" << endl;
  if (test.insert(p1)) {
    cout << "\t" << p1.getUserName() << " has been inserted! (Expected Result)" << endl;
    cout << "\tChecking element count after insertion. Expected Result: 1. test.getElementCount() = " << test.getElementCount() << endl;
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
    cout << "\tAttempt of insertion of duplicate profile failed (Expected Result)" << endl;
  }
  cout << endl;
  cout << "Printing current state of test object" << endl;
  cout << "Expected Result: Only have " << p1.getUserName() << " in test data collection, no duplication" << endl;
  printADT(test);
  
  // Insert remainder profiles
  cout << "Inserting four more profiles with 'j' usernames" << endl;
  test.insert(p2);
  test.insert(p3);
  test.insert(p4);
  test.insert(p5);
  cout << endl;

  // Test: Print function. Expecting Created Profiles to be displyaed in ascending order
  cout << "Printing current state of test object" << endl;
  cout << "Printing out test ADT instance. Expecting 5 profiles with username starting with j in ascending order" << endl;
  printADT(test);
  cout << "Printing element count. Expected Result: 5, test.getElementCount() = " << test.getElementCount() << endl;
  cout << endl;
  
  // Test: Insert beyond MAX_ELEMENTS, where MAX_ELEMENTS = 5. Expecting failure insert
  Profile extraJ("jupitr");
  cout << "MAX_ELEMENTS for any character, 'a' to 'z' in the profiles array is: 5" << endl;
  cout << "Attempting to insert " << extraJ.getUserName() << " profile, past MAX_ELEMENTS with character j" << endl;
  cout << "Expected Result: failure" << endl;
  if (test.insert(extraJ)) {
    cout << "\t" << "Inserted past MAX_ELEMENTS capacity for character j (Unexpected Result)" << endl;
  } else {
    cout << "\t" << "Failed to insert " << extraJ.getUserName() << " past MAX_ELEMENTS capacity for character j (Expected Result)" << endl;
  }
  cout << endl;

  // Insert variety of Profiles to test other usernames other than 'j'
  cout << "Inserting a variety of profiles into test" << endl;
  Profile p6("rAndom");
  Profile p7("rANdom");
  Profile p8("b2134");
  Profile p9("b3234");
  Profile p10("batman");
  test.insert(p6);
  test.insert(p7);
  test.insert(p8);
  test.insert(p9);
  test.insert(p10);
  cout << endl;
  cout << "Printing current state of test object. Expecting an inclusion of new profiles in ascending order, but with no profile named " 
       << extraJ.getUserName() << endl;
  printADT(test);

  // Test: Copy constructor (deep copy). Expecting test and copy to not be aliases of each other
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

  cout << "Testing elementCount of test and copy. Expected Result: Same values for both" << endl;
  cout << "test.getElementCount() = " << test.getElementCount() << ". copy.getElementCount() = " << copy.getElementCount() << endl; 
  cout << endl;

  // Test: Deep copy implementation. Expecting different print statements for test and copy objects
  Profile zebra("zebra");
  cout << "Inserting a new profile into copy" << endl;
  if (copy.insert(zebra)) {
    cout << "\tProfile('zebra') has been inserted into copy! (Expected Result)" << endl;
  } else {
    cout << "\tCould not insert Profile('zebra') into copy (Unexpected Result)" << endl;
  }

  cout << "Removing " << p6.getUserName() << " from test object" << endl;
  if(test.remove(p6)) {
    cout << "\t" <<  p6.getUserName() << " has been removed (Expected Result)" << endl;
  } else {
    cout << "\t" << p6.getUserName() << " has not been removed (Unexpected Result)" << endl;
  }
  cout << endl;

  // Print both test and copy after modifications
  cout << "Printing out both test and copy after inserting another profile into copy and removal of a profile from test" << endl; 
  cout << "Expected Result: copy should have the same profiles but should include profiles with usernames, "  
       << zebra.getUserName() << " and " << p6.getUserName() << endl;
  
  cout << endl;

  cout << "Printing out test after inserting a new profile into copy and removing a profile from test" << endl;
  printADT(test);

  cout << "Printing out copy after inserting a new profile into copy and removing a profile from test" << endl;
  printADT(copy);


  // Test: Remove function
  cout << "Testing remove function" << endl;
  cout << dash << endl;

  // Removing existing profile. Expecting exisiting profile to be removed successfully
  cout << "Attemping to remove " << p1.getUserName() << " from test object using test.remove(). Expected Result: success" << endl;
  if (test.remove(p1)) {
    cout << "\t" << p1.getUserName() << " has been removed! (Expected Result)" << endl;
  } else {
    cout << "\t" << p1.getUserName() << " has failed to be removed (Unexpected Result)" << endl;
  }

  cout << endl;
  cout << "Printing current state of test object" << endl;
  cout << "Expected Result: " << p1.getUserName() << " to not be a part of print statement" << endl;
  printADT(test);

  // Removing non-existent profile. Expecting failure of removal of non-existent profile
  Profile doesNotExist("doesNotExist");
  cout << "Attempting to remove " << doesNotExist.getUserName() << " profile from test using test.remove(). Expected Result: failure" << endl;
  if (test.remove(doesNotExist)) {
    cout << "\t" << doesNotExist.getUserName() << " has been removed (Unexpected Result)" << endl;
  } else {
    cout << "\t" << doesNotExist.getUserName() << " has failed to be removed (Expected Result)" << endl;
  }
  cout << endl;
  cout << "Printing current state of test object" << endl;
  printADT(test);
  cout << "Expected Result: same print as previous print as no profiles were removed" << endl;
  cout << endl;

  // Removing profiles from test for easier to read print 
  cout << "Removing some profiles from test object for easier reading" << endl;
  test.remove(p4);
  test.remove(p5);
  test.remove(p6);
  test.remove(p7);
  cout << "Printing current state of test object after removing various profiles" << endl;
  printADT(test);
 
  // Test: search function
  cout << "Testing search function on test object using test.search()" << endl;
  cout << dash << endl;

  // Searching for existing profile. Expecting existing profile to be found
  cout << "Searching for " << p2.getUserName() << " in test object. Expected Result: success" << endl;
  if (test.search(p2) != nullptr) {
    if(*test.search(p2) == p2) {
      cout << "\t" << p2.getUserName() << " has been found in test ADT (Expected Result)" << endl;
    } else {
      cout << "\t" << p2.getUserName() << " has not been found in test ADT (Unexpected Result)" << endl;
    }
  } else {
    cout << "\t" << p2.getUserName() << " has not been found in test ADT (Unexpected Result)" << endl;
  }
  cout << endl;
  
  // Searching for non-existent profile. Expecting non-existent to not be found
  cout << "Searching for non-existent profile in test object. Expected Result: failure" << endl;
  if (test.search(doesNotExist) == nullptr) {
    cout << "\t" << doesNotExist.getUserName() << " has not been found in test ADT (Expected Result)" << endl;
  } else {
    cout << "\t" << "A profile corresponding to " << doesNotExist.getUserName() << " has been found (Unexpected Result)" << endl;
  }
  cout << endl;


  // Test: removeAll function
  cout << "Testing removeAll() on test" << endl;
  cout << "\tBefore calling test.removeAll(), test.getElementCount() = " << test.getElementCount() << endl;
  cout << "\tCalling test.removeAll()" << endl;
  test.removeAll();
  cout << "\tCheck getElementCount() after calling test.removeAll(). Expected Result: 0. test.getElementCount() = " << test.getElementCount() << endl;
  cout << endl;


  // Check for empty print on test after removing all elements
  cout << "Printing after calling test.removeAll(). Expected Result: no elements displayed" << endl;
  printADT(test);
  cout << endl;

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
