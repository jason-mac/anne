// clang-format off
/*
 * DataCollection.cpp
 *
 * Description: Implementation of a SHSL list-based DataCollection ADT class.
 * There are no class invariant!
 *
 * Author: AL
 * Date: June 2024
 */

#include "DataCollection.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

// Description: Default constructor. Constructs a DataCollection object.
DataCollection::DataCollection() {}

// Description: Copy constructor creates a new DataCollection object as a
//              copy of an existing DataCollection object.
DataCollection::DataCollection(const DataCollection &DC) {
  Node* dummy = new Node(0);
  deepCopy(dummy, DC.head);
  head = dummy->next;
  delete dummy;
}

// To do: If you have not yet implemented (overloaded) the assignment (=)
// operator
//        in Lab 3, I invite you to overload this operator for this class.
DataCollection &DataCollection::operator=(const DataCollection &DC) {
  deleteAll();
  if (!(DC.head)) {
    return *this;
  }
  Node *dummy = new Node(0);
  deepCopy(dummy, DC.head);
  head = dummy->next;
  delete dummy;
  return *this;
}

// Description: Destroys a DataCollection object, releasing heap memory.
DataCollection::~DataCollection() {

  Node *temp = nullptr;
  for (Node *toBeDeleted = head; toBeDeleted != nullptr;) {
    temp = toBeDeleted->next;
    delete toBeDeleted;
    toBeDeleted = temp;
  }
  head = nullptr;
}

// Description: Appends "newElement" to the DataCollection.
//              Returns true if "newElement" has been
//              successful appended, otherwise, false.
bool DataCollection::append(int newElement) {
  // Put your code here!
  Node* nodeToInsert = new Node(newElement);
  if(!head) {
    head = nodeToInsert;
    return true;
  }

  Node* current = head;
  while(current->next) {
    current = current->next;
  }
  current->next = nodeToInsert;
  return true;
}

// Description: Prepends "newElement" to the DataCollection.
//              Returns true if "newElement" has been
//              successful appended, otherwise, false.
bool DataCollection::prepend(int newElement) {
  
  // Put your code here!
  Node* nodeToInsert = new Node(newElement);
  nodeToInsert->next = head;
  head = nodeToInsert;
  return true;
}

// Description: Prints the content of this DataCollection "thisDC"
//              using this format: {element1, element2, ..., elementn}.
ostream &operator<<(ostream &os, const DataCollection &thisDC) {

  DataCollection::Node *current = thisDC.head;
  cout << "{";
  while (current != nullptr) {
    cout << current->data;
    current = current->next;
    if (current != nullptr) {
      cout << ",";
    }
  }
  cout << "}";

  return os;
}
// clang-format on
