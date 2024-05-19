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
  int insertIndex = 0;

  // Retrieve appropiate Profile array for insertion of newElement
  Profile *profiles = elements[profilesIndexKey];

  // Check for full profiles array, cannot insert into full array
  if (elementCountAtSearchKey == MAX_ELEMENTS) {

    // Unsuccessful insert, return false to indicate as such
    return false;
  }

  // Dynamically allocate memory if there is no array for particular searchKey
  if (!profiles) {
    profiles = new Profile[MAX_ELEMENTS];

    // Insert element into the profiles array
    profiles[0] = newElement;

    // Store new profiles array into elements at appropiate index
    elements[profilesIndexKey] = profiles;

    // Increment elementCount for appropiate character
    elementCount[profilesIndexKey] += 1;

    // Successful insert, return true
    return true;
  }

  // Check if newElement exists in array and find insertion index
  // Due to sorted order, the first element that is greater than
  // newElement is the insetion index, thus whenever
  // newElement > profiles[insertIndex], the insert index has been found
  while (insertIndex < elementCountAtSearchKey &&
         newElement < profiles[insertIndex]) {

    // Check if newElement already exists in the array
    if (profiles[i] == newElement) {

      // Unsuccessful insert, return false to indicate as such
      return false;
    }

    insertIndex++;
  }

  // Shift each element to the right by one index before inserting newElement
  for (unsigned int i = elementCountAtSearchKey; i > insertIndex; i--) {
    profiles[i] = profiles[i - 1];
  }

  // Insert newElement into array
  profiles[insertIndex] = newElement;

  // Increment elementCount for appropiate character
  elementCount[profilesIndexKey] += 1;

  // Successful insert, return true to indicate as such
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
  bool found = false;
  bool hasBeenRemoved = false;
  // Checks for empty array, and returns false as toBeRemoved cannot exist in
  // empty array
  if (elementCountAtSearchKey == 0) {
    return false;
  }

  // Retrieve appropiate profiles array from elements
  Profile *profiles = elements[profilesIndexKey];

  // Searches for toBeRemoved in profiles array and shifts elements by one index
  // if found while overwrting toBeRemoved
  for (unsigned int i = 0; i < elementCountAtSearchKey; i++) {
    if (profiles[i] == toBeRemoved) {
      elementCount[profilesIndexKey] -= 1;
      found = true;
      hasBeenRemoved = true;
    }

    // If toBeRemoved was found, shift elements to the left and overwrites
    // toBeRemoved
    if (found && i < elementCountAtSearchKey - 1) {
      profiles[i] = profiles[i + 1];
    }
  }

  // Decrement elemntCount for appropiate character if an element is removed
  // from profiles array
  // Note: there is a special case where toBeRemoved is at
  // profiles[elementCountAtSearchKey] not covered by the previous for loop,
  // but this is covered by decrementing elementCount
  if (hasBeenRemoved) {
    elementCount[profilesIndexKey] -= 1;
  }

  // For memory efficiency, if after removal there are no elements,
  // delete the dyamically allocated array
  if (elementCount[profilesIndexKey] == 0) {
    delete[] profiles;

    // Avoid dangling pointers
    profiles = nullptr;
    elements[profilesIndexKey] = profiles;
  }

  return hasBeenRemoved;
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
  bool found = false;
  char searchKey = target.getSearchKey();
  unsigned int profilesIndexKey = int(searchKey) - int('a');
  cout << profilesIndexKey << " profilesIndexKey " << endl;
  unsigned int elementCountAtSearchKey = elementCount[profilesIndexKey];
  Profile *toReturn = nullptr;
  cout << elementCountAtSearchKey << "elementCountAtSearchKey" << endl;
  Profile *profiles = elements[profilesIndexKey];
  if (!profiles) {
    return nullptr;
  }
  unsigned int i = 0;
  while (i < elementCountAtSearchKey && !found) {
    if (profiles[i] == target) {
      toReturn = &profiles[i];
      found = true;
    }
    i++;
  }
  cout << " not found" << endl;
  return toReturn;
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
