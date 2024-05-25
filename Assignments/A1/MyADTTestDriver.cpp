// clang-format off
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
void makeFullADT(MyADT& adt) {
    const int MAX_REPEATS = adt.MAX_ELEMENTS;
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        for (int repeats = 1; repeats <= MAX_REPEATS; ++repeats) {
            //fill constructor
            string username(repeats, ch);
            Profile temp(username); 
            adt.insert(temp); 
        }
    }
}

// Test Driver function for MyADT class
int main() {
  MyADT fullADT;

  // Test: Full MyADT
  makeFullADT(fullADT);
  cout << "Printing full MyADT object. Expecting 5 usernames per character 'a' -> 'z'" << endl;
  fullADT.print();
  cout << "Expecting 26 * 5 = 130 element count (MAX_ELEMENTS * MAX_ALPHA). fullADT.getElementCount() = " << fullADT.getElementCount() << endl;
  cout << endl;

  // For formatting
  string dash = "----------------------------------------------------";

  // Creating test object using default constructor. 
  MyADT test;
  cout << "Creating test MyADT object...." << endl;

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

  // Test: Insert function
  cout << "Testing insert function..." << endl;
  cout << dash << endl;
  cout << "Attempting to insert " << p1.getUserName() << " into test object..." << endl;
  if (test.insert(p1)) {
    cout << "\t" << p1.getUserName() << " has been inserted! (Expected Result)" << endl;
    cout << "\tChecking element count after insertion, expecting 1 : test.getElementCount() = " << test.getElementCount() << endl;
  } else {
    cout << "\t" << p1.getUserName() << " could not be inserted (Unexpected Result)" << endl;
  }
  cout << endl;

  // Test: Duplicate insertion
  cout << "Testing if duplicate profile can be inserted by inserting " << p1copy.getUserName() << " again" << endl;
  cout << dash << dash << endl;
  cout << "Inserting " << p1copy.getUserName() << " into test object again... " << endl;
  if (test.insert(p1copy)) {
    cout << "\tDuplicate profile inserted (Unexpected Result)" << endl;
  } else {
    cout << "\tAttmempt of insertion of duplicate profile failed (Expected Result)" << endl;
  }
  cout << endl;

  // Insert remainder profiles
  cout << "Inserting four more profiles with 'j' usernames..." << endl;
  test.insert(p2);
  test.insert(p3);
  test.insert(p4);
  test.insert(p5);
  cout << endl;

  // Test: Print function and element count
  cout << "Printing out test ADT instance (Expecting 5 profiles with username starting with j)" << endl;
  cout << dash << endl;
  test.print();
  cout << dash << endl;
  cout << endl;
  cout << "Printing element count. Expected Result: 5, test.getElementCount() = " << test.getElementCount() << endl;
  cout << endl;
  
  // Test: Insert beyond MAX_ELEMENTS
  Profile extraJ("jupitr");
  cout << "Attempting to add profiles past MAX_ELEMENTS with character j..." << endl;
  if (test.insert(extraJ)) {
    cout << "\t" << "Inserted past MAX_ELEMENTS capacity for character j (Unexpected Result)" << endl;
  } else {
    cout << "\t" << "Failed to insert past MAX_ELEMENTS capacity for character j (Expected Result)" << endl;
  }
  cout << endl;

  // Insert variety of Profiles
  cout << "Inserting a variety of profiles into test..." << endl;
  Profile p6("random");
  Profile p7("unicorn");
  test.insert(p6);
  test.insert(p7);
  cout << endl;

  // Test: Copy constructor (deep copy)
  cout << "Testing copy constructor by making a new object with MyADT copy = test" << endl;
  cout << dash << endl;
  MyADT copy = test;
  cout << "Calling MyADT copy = test..." << endl;
  cout << "A deep copy of test has been instantiated" << endl;
  cout << endl;

  cout << "Printing out test object" << endl;
  cout << dash << endl;
  test.print();
  cout << dash << endl;
  cout << endl;

  cout << "Printing out copy object. Expected Result: Exact same print as test" << endl;
  cout << dash << endl;
  copy.print();
  cout << dash << endl;
  cout << endl;

  // Test: Deep copy implementation 
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

  // Print both test and copy after modifications
  cout << "Printing out both test and copy after inserting another profile into copy and removal of a profile from test" << endl; 
  cout << "Expected Result: copy should have the same profiles but should have zebra and random as well" << endl;
  cout << endl;

  cout << "Printing out test after inserting a new profile into copy and removing random from test" << endl;
  cout << dash << endl;
  test.print();
  cout << dash << endl;
  cout << endl;

  cout << "Printing out copy after inserting new profile into copy and removing random from test" << endl;
  cout << dash << endl;
  copy.print();
  cout << dash << endl;
  cout << endl;


  // Test: Remove function
  cout << "Testing remove function" << endl;
  cout << dash << endl;


  // Removing existing profile
  cout << "Attemping to remove " << p1.getUserName() << " from test object (should succeed)..." << endl;
  if (test.remove(p1)) {
    cout << "\t" << p1.getUserName() << " has been removed! (Expected Result)" << endl;
  } else {
    cout << "\t" << p1.getUserName() << " has failed to be removed (Unexpected Result)" << endl;
  }
  cout << endl;


  // Removing non-existent profile
  Profile doesNotExist("doesNotExist");
  cout << "Attempting to remove non-existent profile from test (should fail)..." << endl;
  if (test.remove(doesNotExist)) {
    cout << "\t" << doesNotExist.getUserName() << " has been removed (Unexpected Result)" << endl;
  } else {
    cout << "\t" << doesNotExist.getUserName() << " has failed to be removed (Expected Result)" << endl;
  }
  cout << endl;

  // Test: Removing and then re-adding the same profile
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

  // Searching for existing profile
  cout << "Searching for " << p2.getUserName() << " in test object..." << endl;
  if (test.search(p2)) {
    cout << "\t" << p2.getUserName() << " has been found in test ADT! (Expected Result)" << endl;
  } else {
    cout << "\t" << p2.getUserName() << " has not been found in test ADT! (Unexpected Result)" << endl;
  }
  cout << endl;
  
  // Searching for non-existent profile
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
  cout << "Calling test.removeAll()... " << endl;
  test.removeAll();
  cout << "After calling test.removeAll() (Expecting 0), test.getElementCount() = " << test.getElementCount() << endl;
  cout << endl;


  // Check for empty array
  cout << "Printing after calling test.removeAll() should print no elements" << endl;
  cout << "Calling test.print()..." << endl;
  test.print();
  cout << endl;
  cout << "See nothing?? good!" << endl;

  // Test: Printing final state of test and copy objects
  cout << "Final state of test and copy objects" << endl;
  cout << dash << endl;
  
  cout << "Printing out test object" << endl;
  cout << dash << endl;
  test.print();
  cout << dash << endl;
  cout << endl;

  cout << "Printing out copy object" << endl;
  cout << dash << endl;
  copy.print();
  cout << dash << endl;
  cout << endl;

  // End of test driver
  cout << "End of MyADT test driver" << endl;
  return 0;
}

// clang-format on
