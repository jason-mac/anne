// clang-format off
/*
 * Node.h
 *
 * Class Definition: Node of a singly linked list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */
 
#ifndef NODE_H
#define NODE_H

template<class ElementType>
class Node {
public:

   // Public attributes
   ElementType& data;           // The data in the node
   Node * next = nullptr;   // Pointer to next node
	
   // Constructors (why no destructor?)
   Node();
   Node(ElementType& theData);
   Node(ElementType& theData, Node * theNextNode);

}; 
#include "Node.cpp"
#endif

// clang-format on
