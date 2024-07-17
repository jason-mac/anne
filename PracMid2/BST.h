// clang-format off
/*
 * BST.h
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 * 
 * Date of last modification: July 2024
 */

#ifndef BST_H
#define BST_H

#include "UnableToInsertException.h"


class BST {
	
private:

  class BSTNode {

    public:
  
      int element = 0;
      BSTNode * left = nullptr;
      BSTNode * right = nullptr;

      // Constructors
      BSTNode() {}
      BSTNode(int element) { this->element = element; }

      BSTNode(int element, BSTNode * left, BSTNode * right) {
        this->element = element;
        this->left = left;
        this->right = right;
      }



      // Boolean helper functions
      bool isLeaf() const { return (left == nullptr && right == nullptr); }
      bool hasLeft() const { return (left != nullptr); }
      bool hasRight() const { return (right != nullptr); }

  };

/* Data Members */

  // You cannot change the following data members of this class.

  BSTNode * root = nullptr; 
  unsigned int elementCount = 0;          

/* Utility methods */
	
// Feel free to add private methods to this class.
  //
  unsigned int heightR(BSTNode* current) const;
  unsigned int numberOfNodesR(BSTNode* current) const;
	
  // Description: Recursive insertion into a binary search tree.
  void insertR(BSTNode * newElement, BSTNode * current);

  // Description: Recursively traverse the a binary search tree
  //              printing its elements in order.   
  void printInOrderR(BSTNode * current) const;
	
  // Description: Recursive preorder traversal of a binary search tree in order to build its copy.
  void copyR(BSTNode * current);

  // Description: Recursive postorder traversal of a BST in order to release heap memory allocated to BSTNode.
  void destroyR(BSTNode * current);

  int isBalancedR(BSTNode* current) const;


public:

// You cannot change the prototype of the public methods of this class.


/* Constructors and Destructor */

  // Default constructor: Constructs an empty tree.
  
  BST();            

  // Parameterized constructor
  BST(int element);        

  // Copy constructor
  BST(const BST & aBST);
  
  // Overloaded operator
  // Description: Assignment (=) operator: copy (assign) "rhs" BST 
  //              object to "this" BST object such that both objects
  //              are an exact, yet independent, copy of each other.
  void operator=(const BST & rhs);

  // Destructor 
  ~BST();


/* Getters and setters */
   
  // Description: Returns the number of elements currently stored in the binary search tree.  
  unsigned int getElementCount() const;

/* BST Operations */

  // Description: Inserts an element into the binary search tree.
  //              This is a wrapper method which calls the recursive insertR( ).
  // Exception: Throws the exception "UnableToInsertException" when newElement 
  //            cannot be inserted (e.g., "new" operator fails).  
  void insert(int newElement);

  // Description: Returns the height of this binary search tree.
  //              Feel free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.
  unsigned int height() const;

  bool isBalanced() const;

  // Description: Returns the number of nodes in this binary search tree.
  //              You cannot return "elementCount".
  //              Feel free to implement this method as an iterative method or
  //              as a wrapper method calling a recursive method.		
  unsigned int numberOfNodes( ) const;
  
  // Description: Prints the content of the binary search tree in order.
  //              This is a wrapper method which calls the recursive printsInOrderR( ).
  void printInOrder() const;

};

#endif

// clang-format on
