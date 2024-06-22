// clang-format off
/*
 * BST.cpp
 * 
 * Description: Binary Search Tree (BST) data collection ADT class.
 *              Link-based implementation.
 *
 * Class invariant: Duplicated elements are not allowed.
 *                  It is always a BST.
 * 
 * Author: Inspired from our textbook
 * Date of last modification: June 2024
 */
 
#include "BST.h"
#include "BSTNode.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "UnableToInsertException.h"
#include "WordPair.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;


// You cannot change the prototype of the public methods of this BST class.
// Why? Because we shall use these prototypes when creating our "marking"
// test driver. So, if our test driver cannot call the methods of you BST 
// class because the prototype of these public methods don't match, 
// we won't be able to successfully mark your assignment.

/* Helper Functions */

// Description: Recursively copies all nodes from the given source BST to the current BST.
// Precondition: 'rhsCurrent' is the root of a non-empty BST to be copied. 
// Postcondition: 'thisCurrent' and its subtree are a deep copy of 'rhsCurrent' and its subtree.
// Exception: Throws an exception if memory allocation fails.
// Time efficiency: O(n), where n is the number of nodes in the BST.
void BST::deepCopyR(BSTNode* thisCurrent, BSTNode* rhsCurrent) {
  BSTNode* insertLeft = nullptr;
  BSTNode* insertRight = nullptr;
  if(rhsCurrent->hasLeft()) {
    insertLeft = new(nothrow) BSTNode(rhsCurrent->left->element);
  }
  if(rhsCurrent->hasRight()) {
    insertRight = new(nothrow) BSTNode(rhsCurrent->right->element);
  }
  thisCurrent->left = insertLeft;
  thisCurrent->right = insertRight;
  if(thisCurrent->hasLeft()) {
    deepCopyR(thisCurrent->left, rhsCurrent->left);
  }
  if(thisCurrent->hasRight()) {
    deepCopyR(thisCurrent->right, rhsCurrent->right);
  }
}

void BST::destroyBST(BSTNode* current) {  
  if(current == nullptr) {
    return;
  }
  destroyBST(current->left);
  destroyBST(current->right);
  delete current; 
}

/* Constructors and destructor */

// Default constructor
BST::BST() { }            

// Copy constructor
BST::BST(const BST & aBST) {
  // to do
  if(aBST.root != nullptr) {
    BSTNode* newBSTNode = new BSTNode(aBST.root->element);
    deepCopyR(newBSTNode, aBST.root);
    elementCount = aBST.elementCount;
    root = newBSTNode;
  }   
}

// Overloaded oeprator
// Description: Assignment (=) operator: copy (assign) "rhs" BST 
//              object to "this" BST object such that both objects
//              are an exact, yet independent, copy of each other.
void BST::operator=(const BST & rhs) { 
  // to do
  if(rhs.root != nullptr) {
    BSTNode* newBSTNode = new BSTNode(rhs.root->element);
    deepCopyR(newBSTNode, rhs.root);
    root = newBSTNode;
    elementCount = rhs.elementCount;
  }
  return;
}                


// Destructor 
BST::~BST() {

  // to do
  destroyBST(root);
}                


 
 
/* BST Public Interface */
 
// Description: Returns the number of elements currently stored in the BST.   
// Postcondition: This method does not change the BST.
// Time efficiency: O(1)
unsigned int BST::getElementCount() const {     
  // to do
  return elementCount;
}

// Description: Inserts an element into the BST.
//              This is a wrapper method which calls the recursive insertR( ).
// Precondition: "newElement" does not already exist in the BST.
// Exception: Throws the exception "ElementAlreadyExistsException" 
//            if "newElement" already exists in the BST.
// Exception: Throws the exception "UnableToInsertException" when "newElement" 
//            cannot be inserted into the BST. 
// Time efficiency: O(log2 n)   
void BST::insert(WordPair & newElement) {

  // to do
  BSTNode *newBSTNode = new(nothrow) BSTNode(newElement);
  if(newBSTNode == nullptr) {
    throw UnableToInsertException("Memory could not be allocated for new node");
  }
  if(root == nullptr) {
    root = newBSTNode;
    elementCount++;
    return;
  }
  bool result = insertR(newBSTNode, root);
  if(!result) {
    delete newBSTNode;
    throw ElementAlreadyExistsException("Element Already Exists");
  } else {
    elementCount++;
  }
  return; 
} 

// Description: Recursive insertion into a BST.
//              Returns true when "anElement" has been successfully inserted into the 
//              BST. Otherwise, returns false.
bool BST::insertR(BSTNode * newBSTNode, BSTNode * current) {  
// to do
  BSTNode* next = nullptr;
  if(newBSTNode->element == current->element) {
    return false;
  }
  if(newBSTNode->element < current->element) {
    if(current->left == nullptr) {
      current->left = newBSTNode;
      return true;
    } else {
      next = current->left;
    }
  }
  if(newBSTNode->element > current->element) {
    if(current->right == nullptr) {
      current->right = newBSTNode;
      return true;
    } else { 
      next = current->right;
    }
  }
  return insertR(newBSTNode, next);
}


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
/* Feel free to use the provided code below.
  You can add to it, if you find it necessary to do so,
or you can replace it using your own implementation. */ 
WordPair& BST::retrieve(WordPair & targetElement) const {
  
 if (elementCount == 0)  
    throw EmptyDataCollectionException("BST is empty.");

 WordPair& translated = retrieveR(targetElement, root);

 return translated;
}

// Description: Recursive retrieval from a BST.
// Exception: Throws the exception "ElementDoesNotExistException" 
//            if "targetElement" is not found in the BST.
// Postcondition: This method does not change the BST.
WordPair& BST::retrieveR(WordPair & targetElement, BSTNode * current) const {

// to do
  if(current != nullptr) {
    if(current->element == targetElement) {
      return current->element;
    }	
    if(current->element < targetElement) {
      return retrieveR(targetElement, current->right);
    }
    if(current->element > targetElement) {
      return retrieveR(targetElement, current->left);
    }
  }
  throw ElementDoesNotExistException("Element does not exist");
}  

// Description: Traverses the BST in order.
//              This is a wrapper method which calls the recursive traverseInOrderR( ).
//              The action to be done on each element during the traverse is the function "visit".
// Precondition: BST is not empty.
// Exception: Throws the exception "EmptyDataCollectionException" 
//            if the BST is empty.
// Postcondition: This method does not change the BST.
// Time efficiency: O(n) 
/* Feel free to use the provided code below.
  You can add to it, if you find it necessary to do so,
or you can replace it using your own implementation. */   
void BST::traverseInOrder(void visit(WordPair &)) const {
 
 if (elementCount == 0)  
   throw EmptyDataCollectionException("BST is empty.");

 traverseInOrderR(visit, root);
 
 return;
}

// Description: Recursive "in order" traversal of a BST.   
// Postcondition: This method does not change the BST. 
void BST::traverseInOrderR(void visit(WordPair &), BSTNode* current) const { 

  // to do
  if(current == nullptr) {
    return;
  }
  if(current->hasRight()) {
    traverseInOrderR(visit, current->right);
  }  
  visit(current->element);
  if(current->hasLeft()) {
    traverseInOrderR(visit, current->left);
  } 
}

// clang-format on
