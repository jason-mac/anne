// clang-format off
/*
 * List.h
 * 
 * Description: This is a linked list-based implementation of a List ADT class.
 *              Its underlying data structure is an unsorted singly-headed singly-linked list (SHSL).
 *
 * Author: AL
 * Date: Last modified: June 2024
 */ 

#ifndef LIST_H
#define LIST_H

#include "Node.h"

template <class ElementType>
class List  {

private:

   Node<ElementType> * head = nullptr;          // Pointer to the first node in the List.
   unsigned int elementCount = 0;  // Number of elements in the List.
        
public:
   // Constructors and Destructors

   /* Generally, every class that makes use of dynamically allocated memory
    * should have at least two constructors:
    *   - a default constructor and 
    *   - a copy constructor that creates a distinct copy of the given object
    * (even if the client code does not make use of all of these constructors).
    */
   // Description: Default constructor
   List(); 
   
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
   List(const List & rhs);

   // Overloaded Operator
   // Description: Assignment (=) operator: copy (assign) "rhs" List object to "this" List object
   //              such that both objects are a exact, yet independent copy of each other.
   void operator=(const List & rhs);
   
   // Helper method
   // Description: Copy "rhs" List object to "this" List object such that both
   //              objects are a exact, yet independent copy of each other.
   void copy(const List & rhs);
   
   /* The destructor is responsible for deleting any memory that was dynamically
    * allocated by an object. If there is no such memory, no destructor needs to
    * be created (the compiler automatically creates one). 
    * Because this class makes use of dynamically allocated memory
    * i.e., uses pointers when new Node objects are instantiated, it is necessary to write 
    * a destructor. Destructors are identified by the "~" preceding the class name.
    * There can be only one destructor for a class, and it cannot have parameters. 
    */
   // Description: Destructor.
   ~List();


   /**************************************************************************/
   // List Public Interface 
   
   // Description: Returns the total element count currently stored in List.
   unsigned int getElementCount() const;

   // Description: Append "newElement" to the list.
   // Exception Handling: Throws UnableToInsertException.
   void append(ElementType& newElement);
   
   // Description: Removes the first instance of "toBeRemoved" from the List.
   // PreCondition: List is not empty.
   // Exception Handling: Throws EmptyListException.
   // Exception Handling: Throws ElementDoesNotExistException.
   void remove(ElementType& toBeRemoved);
   
   // Description: Empties the List, freeing up dynamically allocated memory.
   void removeAll();

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
   void printList() const;

}; 

#include "List.cpp"

#endif

// clang-format on
