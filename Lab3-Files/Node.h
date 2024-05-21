/*
 * Node.h
 *
 * Class Definition: Node of a singly linked (SL) list 
 *                   in which the data is of "int" data type.
 *                   Designed and implemented as a non-ADT.
 *
 * Created on: 
 * Author: 
 */
 

class Node {
	
public:

	// Public data members - Why are the data members public?
	int data = 0;           // The data in the node
	Node * next = nullptr;  // Pointer to next node
	
	// Constructors
	Node();
	Node(int theData);
	Node(int theData, Node * theNextNode);

}; // end Node