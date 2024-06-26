// clang-format off
/*
 * MyADT.cpp
 *
 * Class Description: A linear data collection ADT.
 *                    Its concrete data structure (CDT) is not expandable.
 *                    This signifies that when this data collection becomes
 *                    full, you do not have to resize its data structure (not in
 *                    this Assignment 1).
 *
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and
 *                    the elements are kept in ascending sort order of search
 *                    key.
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

void MyADT::deepCopy(const MyADT &rhs) {

  for (unsigned int i = 0; i < MAX_ALPHA; i++) {

    // Copy the elementCount from rhs and set each pointer in elements to
    // nullptr
    this->elementCount[i] = rhs.elementCount[i];
    this->elements[i] = nullptr;

    // Retrieve Profile array for particular character from rhs to copy
    Profile *rhsProfiles = rhs.elements[i];

    // Checks if rhsProfiles has been dynamically allocated, if so, deep copy
    // the elements
    if (rhsProfiles) {

      // Dynamically allocate a new profile array for deep copy
      Profile *newProfiles = new Profile[MAX_ELEMENTS];

      // Copy each element from rhsCopy into newProfiles
      for (unsigned int j = 0; j < elementCount[i]; j++) {
        newProfiles[j] = rhsProfiles[j];
      }

      // Store deep copied profiles array into this elements appropiate index
      this->elements[i] = newProfiles;
    }
  }
}
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
  // Create a deep copy from rhs data collection to this instance
  this->deepCopy(rhs);
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

    // Checks if elements[i] has been dynamically allocated before deleting
    if (elements[i]) {
      delete[] elements[i];
      elements[i] = nullptr;
    }
  }
}

// Description: Returns the total number of elements currently stored in the
//              data collection MyADT.
unsigned int MyADT::getElementCount() const {
  /* Put your code here */
  unsigned int totalElementCount = 0;

  // Iterate through elementCount array and sum up the counts
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
// Time Efficiency: O(m)
bool MyADT::insert(const Profile &newElement) {

  /* Put your code here */

  // Get search key for elements array and element counts for search key
  unsigned int elementsIndexKey = newElement.getSearchKey() - 'a';
  unsigned int elementCountAtIndex = elementCount[elementsIndexKey];

  // Retrieve appropiate Profile array for insertion of newElement
  Profile *profiles = elements[elementsIndexKey];

  // Use to store insertion index of newElement into array
  unsigned int insertIndex = 0;

  // Check for full profiles array, cannot insert into full array
  if (elementCountAtIndex == MAX_ELEMENTS) {
    // Unsuccessful insert, return false
    return false;
  }

  // Dynamically allocate memory if there is no array for particular searchKey
  if (!profiles) {
    profiles = new Profile[MAX_ELEMENTS];

    // Insert element into the profiles array
    profiles[0] = newElement;
    elementCount[elementsIndexKey] += 1;

    // Store new profiles array into elements at appropiate index
    elements[elementsIndexKey] = profiles;

    // Successful insert, return true
    return true;
  }

  // Check if newElement exists in array and find insertion index
  // Due to ascending sorted order, the first element found that is greater than
  // newElement is the insertion index, thus whenever
  // profiles[insertIndex] > newElement, the insertion index has been found
  while (insertIndex < elementCountAtIndex &&
         !(profiles[insertIndex] > newElement)) {

    if (profiles[insertIndex] == newElement) {
      // Unsuccessful insert, element already exists, return false
      return false;
    }
    insertIndex++;
  }
  // Shift each element to the right to make space for newElement
  for (unsigned int i = elementCountAtIndex; i > insertIndex; i--) {
    profiles[i] = profiles[i - 1];
  }

  // Insert newElement into profiles array
  profiles[insertIndex] = newElement;
  elementCount[elementsIndexKey] += 1;

  // Successful insert, return true
  return true;
}

// Description: Removes an element from the data collection MyADT.
//              Returns "true" when the removal is successfull, otherwise
//              "false".
// Precondition: The data collection MyADT is not empty.
// Postcondition: toBeRemoved (if found) is removed, MyADT's class invariants
// are still true
//                and the appropriate elementCount is decremented.
// Time Efficiency: O(m)
bool MyADT::remove(const Profile &toBeRemoved) {

  /* Put your code here */

  // Get search key for elements array and element counts for search key
  unsigned int elementsIndexKey = toBeRemoved.getSearchKey() - 'a';
  unsigned int elementCountAtIndex = elementCount[elementsIndexKey];

  // Retrieve appropiate profiles array from elements for removal of toBeRemoved
  Profile *profiles = elements[elementsIndexKey];

  // for report of removal and condition variable to shift elements
  bool found = false;

  // Checks if profiles array does not exist, if so, returns false as
  // toBeRemoved cannot exist
  if (!profiles) {
    return found;
  }

  // Searches for toBeRemoved in profiles array and shifts elements by one index
  // to the left if found
  for (unsigned int i = 0; i < elementCountAtIndex; i++) {
    if (profiles[i] == toBeRemoved) {
      // Indicates toBeRemoved has been found to begin shifting of elements
      found = true;
    }

    // If toBeRemoved was found, shift elements to the left and overwrites
    // toBeRemoved
    if (found && i != elementCountAtIndex - 1) {
      profiles[i] = profiles[i + 1];
    }
  }

  // Note: In the loop above if toBeRemoved is found at elementCountAtIndex - 1
  // it is not overwritten but its access is removed by the decrementation of
  // the element count.

  // decrement elementCount as toBeRemoved was found and removed
  if (found) {
    elementCount[elementsIndexKey] -= 1;
  }

  return found;
}

// Description: Removes all elements from the data collection MyADT.
// Precondition: The data collection MyADT is not empty.
// Postcondition: MyADT reverts back to its initialization state, i.e.,
//                the state it is in once it has been constructed (once
//                the default constructor has executed).
// Time Efficiency: O(n)
void MyADT::removeAll() {

  /* Put your code here */

  // Loop through each Profile array in elements
  for (unsigned int i = 0; i < MAX_ALPHA; i++) {

    // Check if the Profile array at index i has been dynamically allocated
    if (elements[i]) {

      // Delete the dynamically allocated array
      delete[] elements[i];

      // Set the pointer to nullptr to avoid dangling pointers
      elements[i] = nullptr;
    }

    // Reset the element count for this character
    elementCount[i] = 0;
  }
}

// Description: Searches for target element in the data collection MyADT.
//              Returns a pointer to the element if found, otherwise, returns
//              nullptr.
// Precondition: The data collection MyADT is not empty.
// Time Efficiency: O(m)
Profile *MyADT::search(const Profile &target) {

  /* Put your code here */

  // Get search key
  unsigned int elementsIndexKey = target.getSearchKey() - 'a';
  unsigned int elementCountAtIndex = elementCount[elementsIndexKey];

  // Retrieve appropiate profiles array for searching target
  Profile *profiles = elements[elementsIndexKey];

  bool found = false;
  Profile *toReturn = nullptr;

  // Check if profiles array does not exist, if so, return nullptr since the
  // target cannot exist
  if (!profiles) {
    return toReturn;
  }

  // For loop to search for target in the profiles array
  for (unsigned int i = 0; i < elementCountAtIndex && !found; i++) {
    if (profiles[i] == target) {

      // Update return variable once target has been found
      toReturn = &profiles[i];
      found = true;
    }
  }

  return toReturn;
}

// Description: Prints all elements stored in the data collection MyADT in
// ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
// Time Efficiency: O(n)
void MyADT::print() {

  /* Put your code here */

  for (unsigned int i = 0; i < MAX_ALPHA; i++) {
    if (elements[i]) {
      for (unsigned int j = 0; j < elementCount[i]; j++) {
        cout << elements[i][j];
      }
    }
  }
}

ostream &operator<<(ostream &os, const MyADT &ADT) {
  for (unsigned int index = 0; index < ADT.MAX_ALPHA; index++) {
    Profile *profiles = ADT.elements[index];
    if (profiles) {
      for (unsigned int element = 0; element < ADT.elementCount[index]; element++) {
        Profile profile = profiles[element];
        os << profile.getUserName() << " " << profile.getName()
           << profile.getEmail() << " " << profile.getBirthday() << endl;
      }
    }
  }
  return os;
}

MyADT &MyADT::operator=(const MyADT &rhs) {
  this->removeAll();
  this->deepCopy(rhs);
  return *this;
}
// clang-format on
//  End of implementation file
