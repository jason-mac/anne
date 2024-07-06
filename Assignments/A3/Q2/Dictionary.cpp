/*
 * Dictionary.cpp
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 * 
 * Class invariant: Duplicated elements are not allowed.
 *              
 * Author: Jason Mac, Jagyjot Parmar 
 * Date of last modification: June 2024
 */
#include "Dictionary.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
using std::nothrow;

// Description: Constructor
Dictionary::Dictionary() {}

// Description: Copy Constructor
Dictionary::Dictionary(const Dictionary & Dictionary) {
  // Initialize a new pointer for keyValuePairs to nullptr
  BST* newKeyValuePairsCopy = nullptr;

  // If input Dictionary's keyValuePairs is not null, create a deep copy of it
  if(Dictionary.keyValuePairs != nullptr) {
    // Use the BST copy constuctor to create a new BST
    newKeyValuePairsCopy = new(nothrow) BST(*(Dictionary.keyValuePairs));
  }

  // Assign newly created BST (or nullptr) to this Dictionary's keyValuePairs
  this->keyValuePairs = newKeyValuePairsCopy;
}


// Description: Overloaded assingment (=) operator
void Dictionary::operator=(const Dictionary & rhs) {
  // Check for reassignment 
  if(this == &rhs) {
    return;
  }

  // Delete this->keyValuePairs BST structure if it is instantiated
  if(this->keyValuePairs != nullptr) {
    delete this->keyValuePairs;
  }

  // Initialize a new pointer for the new BST
  BST* rhsKeyValuePairsCopy = nullptr;

  // if rhs.keyValuePairs is not null, create a deep copy of it
  if(rhs.keyValuePairs != nullptr) {
    rhsKeyValuePairsCopy = new(nothrow) BST(*(rhs.keyValuePairs));
  }

  // Assign newly created BST (or nullptr) to this Dictionary's keyValuePairs
  this->keyValuePairs = rhsKeyValuePairsCopy;
}

// Description: Destructor
Dictionary::~Dictionary() {
  delete keyValuePairs;
  keyValuePairs = nullptr;
}

// Description: Returns the number of elements currently stored in the Dictionary.
// Postcondition: This method does not change the Dictionary.
unsigned int Dictionary::getElementCount() const {
  // If there is no BST allocated, return 0 elements
  if(keyValuePairs == nullptr) {
    return 0;
  }
  return keyValuePairs->getElementCount();
}

// Description: Puts "newElement" (association of key-value) into the Dictionary.
// Precondition: "newElement" does not already exist in the Dictionary.
//               This is to say: no duplication allowed.
// Exception: Throws the exception "UnableToInsertException" 
//            when newElement cannot be inserted in the Dictionary.  
// Exception: Throws the exception "ElementAlreadyExistsException" 
//            if "newElement" already exists in the Dictionary.  
void Dictionary::put(WordPair& newElement) {
  // If there is no BST, allocate memory for BST
  if(keyValuePairs == nullptr) {
    keyValuePairs = new(nothrow) BST();
    // Throw exception if memory allocation failed
    if(keyValuePairs == nullptr) {
      throw UnableToInsertException("New operator failed, new element could not be inserted into dictonary");
    }
  }
  // Insert newElement 
  keyValuePairs->insert(newElement);
}

// Description: Gets "newElement" (i.e., the associated value of a given key) 
//              from the Dictionary.
// Precondition: Dictionary is not empty.
// Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
// Exception: Throws the exception ElementDoesNotExistException
//            if the key is not found in the Dictionary.
// Postcondition: This method does not change the Dictionary.
WordPair & Dictionary::get(WordPair & targetElement) const {
  // If there is no bst to search, throw exception
  if(keyValuePairs == nullptr) {
    throw EmptyDataCollectionException("Empty dictionary, element cannot be found");
  }
  return keyValuePairs->retrieve(targetElement);
}

// Description: Prints the content of the Dictionary.
// Precondition: Dictionary is not empty.
// Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
// Postcondition: This method does not change the Dictionary.
void Dictionary::displayContent(void visit(WordPair &)) const {
  if(keyValuePairs == nullptr) {
    throw(EmptyDataCollectionException("Empty Data Collection, nothing to display"));
  }
  keyValuePairs->traverseInOrder(visit);
}
