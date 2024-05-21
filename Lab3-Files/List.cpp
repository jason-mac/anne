/*
 * List.cpp - Implementation of the List class
 *
 * Class Description: A data collection List ADT class:
 *                    linked list-based implementation.
 *                    Its underlying data structure is a
 *                    singly-headed singly-linked list (SHSL).
 *
 * List Characteristics: Not kept in sorted order.
 *                       Duplication allowed.
 *
 * Creation Date:
 * Author:
 */

#include "List.h"
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

// Constructors and Destructors

// Description: Default constructor
List::List() {}

// Description: Copy constructor creates a new List object as a copy
//              of an existing List object, passed as parameter.
List::List(const List &lst) {
  elementCount = lst.elementCount;
  if (lst.head) {
    Node *current = lst.head;
    Node *newNode = new Node(current->data);
    Node *previous = nullptr;
    head = newNode;
    current = current->next;
    while (current) {
      previous = newNode;
      newNode = new Node(current->data);
      previous->next = newNode;
      current = current->next;
    }
    previous->next = nullptr;
  } else {
    head = nullptr;
  }
}

// Description: Destruct a List object, releasing all heap-allocated memory.
List::~List() {
  // You need to write this!
  if (head) {
    Node *previous = nullptr;
    Node *current = head;
    while (current) {
      previous = current;
      current = current->next;
      delete previous;
    }
  }
}

/**************************************************************************/
// List Operations
//
// Description: Append an element (newElement) to the list.
// Postcondition: newElement is inserted at the end of the list
//                and elementCount is incremented.
void List::append(int newElement) {

  Node *newNode = new Node(newElement); // new Node with x
  // We will be able to report when new fails by catching and throwing an
  // exception.

  // Check to see if list is empty
  if (head == nullptr) {
    // Make new Node the new head
    head = newNode;
  } else {
    // Move to the end of the list
    Node *current = head;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = newNode;
  }
  elementCount++;
  return;
}

/*
 * Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot
 * foresee how it is to be displayed (in a TUI or GUI environment).
 * However, such method eases testing.
 * For testing purpose, unless required by client in problem statement.
 * Could also overload operator<<.
 */
// Description: Prints the contents of the List from the first to the
//              last element.
void List::printList() {
  Node *current = head;

  cout << "{"; // Nice format!
  // Traverse the list
  while (current != nullptr) {
    cout << current->data;   // Print data
    current = current->next; // Go to next Node
    if (current != nullptr) {
      cout << ","; // Print a comma unless at the end of the list
    }
  }
  cout << "}"; // Don't print a newline - it might not be needed.
  return;
}
// end of implementation file of List class
