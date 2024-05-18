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
 * Author: AL and <put your name here>
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
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {

    // initially each character 'a - z' has 0 elements corresponding to it
    elementCount[i] = 0;

    // only insert elements when needed, otherwise we keep it as nullptr
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
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    elementCount[i] = rhs.elementCount[i];
    Profile *rhsCopy = rhs.elements[i];
    if (!rhsCopy) {
      elements[i] = nullptr;
      continue;
    }
    Profile *thisCopy = new Profile[elementCount[i]];
    for (unsigned int j = 0; j < elementCount[i]; j++) {
      thisCopy[j] = rhsCopy[j];
    }
    elements[i] = thisCopy;
  }
}

// Overloaded assignment operator - Covered in Lab 4
// Therefore, we shall not be overloading this operator in our Assignment 1
// MyADT & MyADT::operator=(const MyADT& rhs) { }

// Destructor - Covered in Lab 3
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
  // cout << "MyADT::destructor" << endl;  // For testing purposes ...
  // You can also use the above cout to figure out when this destructor is
  // executed. If you do uncomment it, make sure to comment it out again before
  // you submit your Assignment 1.

  /* Put your code here */
  this->removeAll();
}

// Description: Returns the total number of elements currently stored in the
// data collection MyADT.
unsigned int MyADT::getElementCount() const { /* Put your code here */
  int count = 0;
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    count += elementCount[i];
  }
  return count;
}

// Description: Inserts an element in the data collection MyADT.
//              Returns "true" when the insertion is successfull, otherwise
//              "false".
// Precondition: newElement must not already be in the data collection MyADT.
// Postcondition: newElement inserted, MyADT's class invariants are still true
//                and the appropriate elementCount has been incremented.
// Time Efficiency:
bool MyADT::insert(const Profile &newElement) { /* Put your code here */
  char searchKey = newElement.getSearchKey();
  unsigned int profileIndexKey = int(searchKey) - int('a');
  unsigned int elementCountAtSearchKey = elementCount[profileIndexKey];

  // insert failed, cannot insert more elements
  if (elementCountAtSearchKey == MAX_ELEMENTS) {
    return false;
  }
  // create new array on heap if there is no array
  if (elementCountAtSearchKey == 0) {
    Profile *profile = new Profile[MAX_ELEMENTS];
    profile[0] = newElement;
    elements[profileIndexKey] = profile;
    elementCount[profileIndexKey] += 1;
    return true;
  }

  Profile *profile = elements[int(searchKey) - int('a')];
  unsigned int left = 0;
  unsigned int right = elementCountAtSearchKey - 1;

  // Binary search to determine existence of newElement
  // Also detemines index of insertion if element does not exist
  while (left <= right) {
    unsigned int middle = (left + right) / 2;
    if (profile[middle] == newElement) {
      return false;
    }
    if (profile[middle] < newElement) {
      left = middle + 1;
    }
    if (profile[middle] > newElement) {
      right = middle - 1;
    }
  }

  // if binary search fails to find element then we are able to insert at left
  // shift each element by one index before inserting newElement
  for (unsigned int i = elementCountAtSearchKey - 1; i > left; i--) {
    profile[i] = profile[i - 1];
  }
  profile[left] = newElement;
  elementCount[profileIndexKey] += 1;
  return true;
}

// Description: Removes an element from the data collection MyADT.
//              Returns "true" when the removal is successfull, otherwise
//              "false".
// Precondition: The data collection MyADT is not empty.
// Postcondition: toBeRemoved (if found) is removed, MyADT's class invariants
// are still true
//                and the appropriate elementCount is decremented.
// Time Efficiency:
bool MyADT::remove(const Profile &toBeRemoved) { /* Put your code here */
  char searchKey = toBeRemoved.getSearchKey();
  unsigned int profileIndexKey = int(searchKey) - int('a');
  unsigned int elementCountAtSearchKey = elementCount[profileIndexKey];
  // check for empty list, if empty then the toBeRemoved does not exists and
  // return false
  if (elementCountAtSearchKey == 0) {
    return false;
  }
  Profile *profile = elements[profileIndexKey];
  unsigned int left = 0;
  unsigned int right = elementCountAtSearchKey;
  unsigned int middle = (left + right) / 2;
  while (left <= right) {
    middle = (left + right) / 2;
    if (profile[middle] == toBeRemoved) {
      break;
    }
    if (profile[middle] < toBeRemoved) {
      left = middle + 1;
    }
    if (profile[middle] > toBeRemoved) {
      right = middle - 1;
    }
  }
  if (profile[middle] == toBeRemoved) {
    for (unsigned int i = middle; i < elementCountAtSearchKey - 1; i++) {
      profile[i] = profile[i + 1];
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
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    if (!elements[i])
      continue;
    delete[] elements[i];
  }
}

// Description: Searches for target element in the data collection MyADT.
//              Returns a pointer to the element if found, otherwise, returns
//              nullptr.
// Precondition: The data collection MyADT is not empty.
// Time Efficiency:
Profile *MyADT::search(const Profile &target) { /* Put your code here */
  char searchKey = target.getSearchKey();
  unsigned int profileIndexKey = int(searchKey) - int('a');
  unsigned int elementCountAtSearchKey = elementCount[profileIndexKey];
  Profile *profile = elements[profileIndexKey];
  if (!profile) {
    return nullptr;
  }
  unsigned int left = 0;
  unsigned int right = elementCountAtSearchKey - 1;
  unsigned int middle = (right + left) / 2;
  while (left <= right) {
    if (profile[middle] == target) {
      return &profile[middle];
    }
    if (profile[middle] < target) {
      left = middle + 1;
    }
    if (profile[middle] > target) {
      right = middle - 1;
    }
  }
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
