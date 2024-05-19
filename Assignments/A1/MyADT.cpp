/*
 * MyADT.cpp
 *
 * Class Description: A linear data collection ADT.
 *                    Its concrete data structure (CDT) is not expandable.
 *                    This signifies that when this data collection becomes
 * full, you do not have to resize its data structure (not in this Assignment
 * 1).
 *
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and
 *                    the elements are kept in ascending sort order of search
 * key.
 *                  - Each element is unique (no duplicates).
 *
 * Author: AL and <Jason Mac>
 * Last modified on: May 2024
 */

#include "MyADT.h"   // Header file of MyADT file
#include "Profile.h" // Header file of Profile class
#include <cctype>
#include <iostream>

using std::cout;
using std::endl;

// Default constructor.
MyADT::MyADT() {
  // cout << "MyADT::default constructor executed!" << endl;   // For testing
  // purposes ... You can also use the above cout to figure out when this
  // constructor is executed. If you do uncomment it, make sure to comment it
  // out again before you submit your Assignment 1.

  /* Put your code here */

  // Initialize each pointer in elements to nullptr and set its corresponding
  // elementCount array to 0
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    elementCount[i] = 0;
    elements[i] = nullptr;
  }
}

// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT &rhs) {
  // cout << "MyADT::copy constructor executed!" << endl; // For testing
  // purposes ... You can also use the above cout to figure out when this
  // constructor is executed. If you do uncomment it, make sure to comment it
  // out again before you submit your Assignment 1.

  /* Put your code here */

  // Loop through each Profile array of rhs to copy
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {

    // Copy the elementCount and set each pointer in elements to nullptr
    elementCount[i] = rhs.elementCount[i];
    elements[i] = nullptr;

    // Retrieve Profile array from rhs to copy
    Profile *rhsProfiles = rhs.elements[i];

    // Checks if rhsProfiles has elements, if so, deep copy the elements
    if (rhsProfiles) {
      Profile *newProfiles = new Profile[MAX_ELEMENTS];
      // Copy each element from rhsCopy into newProfiles
      for (unsigned int j = 0; j < elementCount[i]; j++) {
        newProfiles[j] = rhsProfiles[j];
      }
      // Store deep copied profiles array into appropiate index
      elements[i] = newProfiles;
    }
  }
}

// Overloaded assignment operator - Covered in Lab 4
// Therefore, we shall not be overloading this operator in our Assignment 1
// MyADT & MyADT::operator=(const MyADT& rhs) { stuff and more stuff }
// Destructor - Covered in Lab 3
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
  // cout << "MyADT::destructor" << endl;  // For testing purposes ...
  // You can also use the above cout to figure out when this destructor is
  // executed. If you do uncomment it, make sure to comment it out again before
  // you submit your Assignment 1.

  /* Put your code here */

  // Deallocates all memory in elements array
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    if (elements[i]) {
      delete[] elements[i];
    }
  }
}

// Description: Returns index of found element returns -1 if not found
int MyADT::getIndex(Profile *profiles, unsigned int size,
                    const Profile &target) {

  // Using binary search since profiles array is sorted
  int left = 0;
  int right = size - 1;
  int middle;
  while (left <= right) {
    middle = (right + left) / 2;
    if (profiles[middle] == target) {
      return middle;
    }
    if (profiles[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  return left;
}

// Description: Returns the total number of elements currently stored in the
// data collection MyADT.
unsigned int MyADT::getElementCount() const {
  /* Put your code here */
  unsigned int totalElementCount = 0;

  // Iterate through elementCount array and sum value
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    totalElementCount += elementCount[i];
  }
  return totalElementCount;
}

// Description: Inserts an element in the data collection MyADT.
//              Returns "true" when the insertion is successfull, otherwise
//              "false".
// Precondition: newElement must not already be in the data collection MyADT.
// Postcondition: newElement inserted, MyADT's class invariants are still true
//                and the appropriate elementCount has been incremented.
// Time Efficiency: O(n)
bool MyADT::insert(const Profile &newElement) { /* Put your code here */
  char searchKey = newElement.getSearchKey();
  unsigned int profilesIndexKey = int(searchKey) - int('a');
  unsigned int elementCountAtSearchKey = elementCount[profilesIndexKey];

  // Check for full Profile array, return false if so
  if (elementCountAtSearchKey == MAX_ELEMENTS) {
    return false;
  }
  // Dynamically allocate memory for new array if there is no array
  if (!elements[profilesIndexKey]) {
    Profile *profiles = new Profile[MAX_ELEMENTS];

    // Check if new operator failed, return false if so
    if (!profiles) {
      return false;
    }

    // Insert element into the profiles array
    profiles[0] = newElement;

    // Store new profiles array into elements at appropiate index
    elements[profilesIndexKey] = profiles;

    // Increment elementCount at appropiate index
    elementCount[profilesIndexKey] += 1;
    return true;
  }

  // Retrieve appropiate Profile array for insertion of newElement
  Profile *profiles = elements[profilesIndexKey];

  // Binary search to determine existence of newElement
  // Also detemines index of insertion if element does not exist
  unsigned int left = 0;
  unsigned int right = elementCountAtSearchKey - 1;
  while (left <= right) {
    unsigned int middle = (left + right) / 2;

    if (profiles[middle] == newElement) {

      // At this point, newElement exists in profiles array, return false to
      // indicate insertion failure
      return false;
    }
    if (profiles[middle] < newElement) {
      left = middle + 1;
    }
    if (profiles[middle] > newElement) {
      right = middle - 1;
    }
  }

  // Binary search has failed to find newElement, able to insert newElement at
  // index left Shift each element by one index before inserting newElement
  cout << left << " left " << endl;
  for (unsigned int i = elementCountAtSearchKey - 1; i > left; i--) {
    profiles[i] = profiles[i - 1];
  }

  // Insert newElement into array
  profiles[left] = newElement;

  // Increment elementCount for appropiate index
  elementCount[profilesIndexKey] += 1;
  return true;
}

// Description: Removes an element from the data collection MyADT.
//              Returns "true" when the removal is successfull, otherwise
//              "false".
// Precondition: The data collection MyADT is not empty.
// Postcondition: toBeRemoved (if found) is removed, MyADT's class invariants
// are still true
//                and the appropriate elementCount is decremented.
// Time Efficiency: O(n)
bool MyADT::remove(const Profile &toBeRemoved) { /* Put your code here */
  char searchKey = toBeRemoved.getSearchKey();
  unsigned int profilesIndexKey = int(searchKey) - int('a');
  unsigned int elementCountAtSearchKey = elementCount[profilesIndexKey];
  // check for empty list, if empty then the toBeRemoved does not exists and

  // Checks for empty array, and returns false as toBeRemoved cannot exist in
  // empty array
  if (elementCountAtSearchKey == 0) {
    return false;
  }

  // Retrieve appropiate profiles array from elements
  Profile *profiles = elements[profilesIndexKey];

  // Binary Search algorithm to find existence of toBeRemoved in profiles array
  unsigned int left = 0;
  unsigned int right = elementCountAtSearchKey;
  unsigned int middle = (left + right) / 2;
  while (left <= right) {
    middle = (left + right) / 2;
    if (profiles[middle] == toBeRemoved) {
      break;
    }
    if (profiles[middle] < toBeRemoved) {
      left = middle + 1;
    }
    if (profiles[middle] > toBeRemoved) {
      right = middle - 1;
    }
  }
  if (profiles[middle] == toBeRemoved) {
    for (unsigned int i = middle; i < elementCountAtSearchKey - 1; i++) {
      profiles[i] = profiles[i + 1];
    }
    return true;
  }
  return false;
}

// Description: Removes all elements from the data collection MyADT.
// Precondition: The data collection MyADT is not empty.
// Postcondition: MyADT reverts back to its initialization state, i.e.,
//                the state it is in once it has been constructed (once
//                the default constructor has executed).
// Time Efficiency:
void MyADT::removeAll() {
  /* Put your code here */

  // Loop through each Profile array in elements
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    // Check if the element at index i is not nullptr
    if (elements[i]) {
      // Delete the dynamically allocated memory
      delete[] elements[i];
      // Set the pointer to nullptr to avoid dangling pointer issues
      elements[i] = nullptr;
    }
    // Reset the element count for this index
    elementCount[i] = 0;
  }
}

// Description: Searches for target element in the data collection MyADT.
//              Returns a pointer to the element if found, otherwise, returns
//              nullptr.
// Precondition: The data collection MyADT is not empty.
// Time Efficiency:
Profile *MyADT::search(const Profile &target) { /* Put your code here */
  char searchKey = target.getSearchKey();
  unsigned int profilesIndexKey = int(searchKey) - int('a');
  cout << profilesIndexKey << " profilesIndexKey " << endl;
  unsigned int elementCountAtSearchKey = elementCount[profilesIndexKey];
  cout << elementCountAtSearchKey << "elementCountAtSearchKey" << endl;
  Profile *profiles = elements[profilesIndexKey];
  if (!profiles) {
    return nullptr;
  }
  unsigned left = 0;
  unsigned right = elementCountAtSearchKey - 1;
  while (left <= right) {
    unsigned middle = (left + right) / 2;
    if (profiles[middle] == target) {
      return &profiles[middle];
    }
    if (profiles[middle] < target) {
      left = middle + 1;
    } else {
      right = middle - 1;
    }
  }
  cout << " not found" << endl;
  return nullptr;
}

// Description: Prints all elements stored in the data collection MyADT in
// ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
// Time Efficiency: O(m)
void MyADT::print() { /* Put your code here */
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    if (!elements[i])
      continue;
    for (unsigned int j = 0; j < elementCount[i]; j++) {
      cout << elements[i][j];
    }
  }
}

//  End of implementation file
