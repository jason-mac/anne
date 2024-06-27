// clang-format off
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

// Description: returns element count of BST
unsigned int Dictionary::getElementCount() const {
  return keyValuePairs->getElementCount();
}

void Dictionary::put(WordPair& newElement) {
  if(keyValuePairs == nullptr) {
    keyValuePairs = new BST();
  }
  keyValuePairs->insert(newElement);
}

WordPair & Dictionary::get(WordPair & targetElement) const {
  return keyValuePairs->retrieve(targetElement);
}


void Dictionary::displayContent() const {
  keyValuePairs->traverseInOrder(display);
}

// clang-format on
