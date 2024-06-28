// clang-format off
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
#include "BST.h"
#include "WordPair.h"


// Description: Constructor
Dictionary::Dictionary() {}

// Description: Copy Constructor
Dictionary::Dictionary(const Dictionary & Dictionary) {
  keyValuePairs = Dictionary.keyValuePairs;
}

// Description: Overloaded assingment (=) operator
void Dictionary::operator=(const Dictionary & rhs) {
  keyValuePairs = rhs.keyValuePairs;
}

// Description: Destructor
Dictionary::~Dictionary() {
  delete keyValuePairs;
}

// Description: Returns the number of elements currently stored in the Dictionary.
// Postcondition: This method does not change the Dictionary.
unsigned int Dictionary::getElementCount() const {
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
  if(keyValuePairs == nullptr) {
    keyValuePairs = new BST();
  }
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
  return keyValuePairs->retrieve(targetElement);
}


// Description: Prints the content of the Dictionary.
// Precondition: Dictionary is not empty.
// Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
// Postcondition: This method does not change the Dictionary.
void Dictionary::displayContent(void visit(WordPair &)) const {
  keyValuePairs->traverseInOrder(visit);
}

// clang-format on
