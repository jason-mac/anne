// clang-format off
/*
 * DataCollection.cpp
 *
 * Description: Implementation of a SHSL list-based DataCollection ADT class.
 * Class invariatnt:t here are no class invariant!
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
  head = nullptr;
  Node* currentDC = DC.head;
  while(currentDC) {
    this->append(currentDC->data);
    currentDC = currentDC->next;
  }
}

// To do: If you have not yet implemented (overloaded) the assignment (=)
// operator
//        in Lab 3, I invite you to overload this operator for this class.
DataCollection &DataCollection::operator=(const DataCollection &DC) {
  if(this == &DC) {
    return *this;
  }
  Node* currentThis = head;
  Node* currentDC = DC.head;
  while(currentThis && currentDC) {
    currentThis->data = currentDC->data;
    currentThis = currentThis->next;
    currentDC = currentDC->next;
  }
  while(currentDC != nullptr) {
    this->append(currentDC->data);
    currentDC = currentDC->next;
  }
  while(currentThis != nullptr){
    Node* previous = currentThis;
    currentThis = currentThis->next;
    delete previous;
  }

  return *this;
}

// Description: Destroys a DataCollection object, releasing heap memory.
DataCollection::~DataCollection() {
  Node* previous = nullptr;
  Node* current = head;
  while(current) {
    previous = current;
    current = current->next;
    delete previous;
  }
  head = nullptr;
}

// Description: Appends "newElement" to the DataCollection.
//              Returns true if "newElement" has been
//              successful appended, otherwise, false.
bool DataCollection::append(int newElement) {
  Node* insertNode = new Node(newElement);
  if(!insertNode) {
    return false;
  }
  if(!head) {
    head = insertNode;
    return true;
  }
  Node* current = head;
  while(current->next) {
    current = current->next;
  }
  current->next = insertNode;
  return true;
}

// Description: Prepends "newElement" to the DataCollection.
//              Returns true if "newElement" has been
//              successful appended, otherwise, false.
bool DataCollection::prepend(int newElement) {
  Node* insertNode = new Node(newElement);
  if(!insertNode) {
    return false;
  }
  if(!head) {
    head = insertNode;
    return true;
  }
  insertNode->next = head;
  head = insertNode;
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
