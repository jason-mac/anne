// clang-format off
/*
 * BST.h
 * 
 * Description: Binary Search Tree (BST) data collection ADT class.
 *              Link-based implementation.
 *
 * Class invariant: Duplicated elements are not allowed.
 *                  It is always a BST.
 * 
 * Authors: Inspired from our textbook, refined by Jason Mac, and Jagyjot Parmar
 * Date of last modification: June 2024
 */

#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "WordPair.h"


class BST {
   
private:

  // You cannot change the following data members of this class.
  BSTNode * root = nullptr; 
  unsigned int elementCount = 0;        

  /* Helper Functions */

  // Feel free to add private methods to this class.
   
  // Description: Recursively copies all nodes from the given source BST to the current BST
  //              using a preorder traversal
  // Precondition: 'rhsCurrent' is the root of a non-empty BST to be copied. 
  // Postcondition: 'thisCurrent' and its subtree are a deep copy of 'rhsCurrent' and its subtree.
  // Time Efficiency: O(n), where n is the number of nodes in the BST.
  void deepCopyR(BSTNode* current);

  // Description: Recursively destroys a BST starting from the given node using
  //              a post order traversal
  // Postcondition: The BST starting from "current" is destroyed, and memory is freed.
  // Time Efficiency: O(n)
  void destroyBSTr(BSTNode* current);

  // description: recursive insertion into a bst.
  //              returns true when "anelement" has been successfully inserted into the 
  //              bst. otherwise, returns false.
  bool insertR(BSTNode * newBSTNode, BSTNode * current);

  // Description: Recursive retrieval from a BST.
  // Exception: Throws the exception "ElementDoesNotExistException" 
  //            if "targetElement" is not found in the BST.
  // Postcondition: This method does not change the BST.
  WordPair & retrieveR(WordPair & targetElement, BSTNode * current) const;

  // Description: Recursive "in order" traversal of a BST.   
  // Postcondition: This method does not change the BST.
  void traverseInOrderR(void visit(WordPair &), BSTNode * current) const;


public:

   // You cannot change the prototype of the public methods of this BST class.
   // Why? Because we shall use these prototypes when creating our "marking"
   // test driver. So, if our test driver cannot call the methods of you BST 
   // class because the prototype of these public methods don't match, 
   // we won't be able to successfully mark your assignment.

  int isBalancedR(BSTNode* current);
  bool isBalanced();

   /* Constructors and destructor */
   BST();                            // Default constructor
   BST(const BST & aBST);            // Copy constructor
   void operator=(const BST & rhs);  // Overloaded assignment (=) operator
   ~BST();                           // Destructor 
 
/* Getters and Setters */

/* The getter "getElementCount()" is considered part of the BST Public Interface. */

/* getRoot() and setRoot(...) are not acceptable getter/setter in this situation. 
   Can you see why?
   setElementCount(...) is not an acceptable setterin this situation. 
   Can you also see why?                                                          */

 
/* BST Public Interface */
   
   // Description: Returns the number of elements currently stored in the BST.   
   // Postcondition: This method does not change the BST.
   // Time efficiency: O(1)
   unsigned int getElementCount() const;

   // Description: Inserts an element into the BST.
   //              This is a wrapper method which calls the recursive insertR( ).
   // Precondition: "newElement" does not already exist in the BST.
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the BST.
   // Exception: Throws the exception "UnableToInsertException" when "newElement" 
   //            cannot be inserted into the BST. 
   // Time efficiency: O(log2 n)   
   void insert(WordPair & newElement);   
   
   // Description: Retrieves "targetElement" from the BST.
   //              This is a wrapper method which calls the recursive retrieveR( ).
   // Precondition: BST is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the BST is empty.
   // Exception: Propagates the exception "ElementDoesNotExistException" 
   //            thrown from the retrieveR(...)
   //            if "targetElement" is not found in the BST.
   // Postcondition: This method does not change the BST.
   // Time efficiency: O(log2 n)
   WordPair & retrieve(WordPair & targetElement) const;
   
   // Description: Traverses the BST in order.
   //              This is a wrapper method which calls the recursive traverseInOrderR( ).
   //              The action to be done on each element during the traverse is the function "visit".
   // Precondition: BST is not empty.
   // Exception: Throws the exception "EmptyDataCollectionException" 
   //            if the BST is empty.
   // Postcondition: This method does not change the BST.
   // Time efficiency: O(n)   
   void traverseInOrder(void visit(WordPair &)) const;

}; // end BST
#endif

// clang-format on
