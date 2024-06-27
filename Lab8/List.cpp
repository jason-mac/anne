// clang-format off
/*
 * List.cpp
 * 
 * Description: This is a linked list-based implementation of a List ADT class.
 *              Its underlying data structure is an unsorted singly-headed singly-linked list (SHSL).
 *
 * Author: AL
 * Date: Last modified: June 2024
 */ 

#include "UnableToInsertException.h"
#include "EmptyListException.h"
#include "ElementDoesNotExistException.h"
#include <iostream>
#include "List.h"

using std::cout;
using std::endl;

// Constructors and Destructors

/* Generally, every class that makes use of dynamically allocated memory
 * should have at least two constructors:
 *   - a default constructor and 
 *   - a copy constructor that creates a distinct copy of the given object
 * (even if the client code does not make use of all of these constructors).
 */
 
// Description: Default constructor
template<class ElementType>
List<ElementType>::List() {	
   // cout << "List Default constructor" << endl; // For testing purposes!
}

/* Note the parameter to this copy constructor. C++ functions use pass-by-value by
 * default. This means that the functions make copies of the given arguments. 
 * This is inefficient (particularly for large objects).
 * Therefore it is normal to pass a reference, (using &) of the parameter, called an "alias".
 * Furthermore, if the parameter cannot be changed, it is good programming practice 
 * to indicate so by using the keyword "const". This keyword prevents it from being changed,
 * i.e., the compiler will complaint if the code tries to change the value of the parameter.
 */
 
// Description: Copy constructor creates a new List object as a copy of the existing 
//              "rhs" List object such that both objects are a exact, yet independent
//              copy of each other.
template <class ElementType>
List<ElementType>::List(const List & rhs) {
   //cout << "List Copy constructor called!" << endl; // For testing purposes!

   // Check to see if list rhs is empty
   if (rhs.head != nullptr) {
      Node<ElementType> * current = rhs.head;
      // Traverse the list
      while (current != nullptr) {
         this->append(current->data); // Append data into new List
         current = current->next; // Go to next node
      }
   }
}

// Overloaded Operator
// Description: Assignment (=) operator: copy (assign) "rhs" List object to "this" List object
//              such that both objects are a exact, yet independent copy of each other.
template <class ElementType>
void List<ElementType>::operator=(const List & rhs) {

   // First, destroy "this" ...
   removeAll();
   
   // ... then build it with as a copy of "rhs"
   copy( rhs );
	
   return;
}

// Helper method
// Description: Copy "rhs" List object to "this" List object such that both
//              objects are a exact, yet independent copy of each other.
template <class ElementType>
void List<ElementType>::copy(const List & rhs) {

   // Check to see if list rhs is empty
   if (rhs.head != nullptr) {
      Node<ElementType> * current = rhs.head;
      // Traverse the list
      while (current != nullptr) {
         this->append(current->data); // Append data into new List
         current = current->next; // Go to next node
      }
   }
   return;
}
   
/* The destructor is responsible for deleting any memory that was dynamically
 * allocated by an object. If there is no such memory, no destructor needs to
 * be created (the compiler automatically creates one). 
 * Because this class makes use of dynamically allocated memory
 * i.e., uses pointers when new Node objects are instantiated, it is necessary to write 
 * a destructor. Destructors are identified by the "~" preceding the class name.
 * There can be only one destructor for a class, and it cannot have parameters. 
 */
// Description: Destructor.
template <class ElementType>
List<ElementType>::~List() {
   // cout << "List destructor" << endl; // For testing purposes!
   removeAll();
}


/**************************************************************************/
// List Public Interface 

// Description: Returns the total element count currently stored in List.
template <class ElementType>
unsigned int List<ElementType>::getElementCount() const {

   return elementCount;
}

// Description: Append "newElement" to the list.
// Exception Handling: Throws UnableToInsertException.
template <class ElementType>
void List<ElementType>::append(ElementType& newElement) {

   Node<ElementType> * newNode = new Node<ElementType>(newElement); 
   if (newNode == nullptr)
      throw UnableToInsertException(" in append(): new failed, newNode cannot be allocated heap memory.");

   // Check to see if List is empty
   if (head == nullptr) {
      // Make new Node the new head
      head = newNode;
   } else {
      // Move to the end of the List
      Node<ElementType> * current = head;
      while (current->next != nullptr) {
         current = current->next;
      }
      current->next = newNode;
   }
   elementCount++;
   return;
}

// Description: Removes the first instance of "toBeRemoved" from the List.
// PreCondition: List is not empty.
// Exception Handling: Throws EmptyListException.
// Exception Handling: Throws ElementDoesNotExistException.
template <class ElementType>
void List<ElementType>::remove(ElementType& toBeRemoved) {

   // Is the List empty?
   if (head == nullptr)
       throw EmptyListException(" in remove(): the List is empty.");
   
   Node<ElementType> * current = head;
   Node<ElementType> * toBeDeleted =  nullptr;
   unsigned int previousEC = elementCount;

   // Check to see if toBeRemoved is at the head of the list
   if (head->data == toBeRemoved) {
      head = head->next;
      delete current; //currently assigned head
      elementCount--;
   } else {
       // Otherwise iterate through list
       for (unsigned int i = 0; i < elementCount-1; i++) {
         // Is the next node toBeRemoved
         if (current->next->data == toBeRemoved) {
            toBeDeleted = current->next;
            current->next = current->next->next;
            delete toBeDeleted;
            elementCount--;
         }
         current = current->next;
      }
   }
   if (previousEC == elementCount)
      throw ElementDoesNotExistException(" in remove(): element to be removed is not in the List.");
   return;
}

// Description: Empties the List, freeing up dynamically allocated memory.
template <class ElementType>
void List<ElementType>::removeAll() {
   
   Node<ElementType> * temp = nullptr;
   
   // Traverse the list deleting nodes
   for (Node<ElementType> * toBeDeleted = head; toBeDeleted != nullptr;) {
      temp = toBeDeleted->next; // Mustn't "lose" the next node
      delete toBeDeleted;     // Deallocate memory
      toBeDeleted = temp;  // Go to next node
   }
   // Reset the List to initial state
   head = nullptr;
   elementCount = 0;
   return;
}

/* 
 * Note that there is some debate about whether or not this type of
 * method belongs in a class. The argument (briefly) is that a class
 * shouldn't be responsible for I/O by "displaying" itself as it cannot 
 * foresee how it is to be displayed (in a TUI or GUI environment?).
 * However, such method eases testing.
 * For testing purpose, unless required by client in problem statement.
 * Could also overload operator<<. 
 */
// Description: Prints the contents of the List from the first to the last element.
template <class ElementType>
void List<ElementType>::printList() const {

   Node<ElementType> * current = head;
   
   cout << "{"; //Nice format!
   // Traverse the list
   while (current != nullptr) {
      cout << current->data; // Print data
      current = current->next; // Go to next Node
      if (current != nullptr) {
         cout << ", "; // Print a comma unless at the end of the list
      }
   }
   cout << "}"; // Don't print a newline - it might not be wanted
}
// clang-format on
