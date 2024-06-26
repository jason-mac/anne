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


/* Constructors and destructor */

// Default constructor
BST::BST() { }            

// Copy constructor
BST::BST(const BST & aBST) {
  // Check if aBST's BST is not empty
  if(aBST.root != nullptr) {
    // Perform a deep copy of rhs BST's nodes starting from newBSTNode and root of aBST's BST   
    this->deepCopyR(aBST.root);
  }
}                

// Overloaded oeprator
// Description: Assignment (=) operator: copy (assign) "rhs" BST 
//              object to "this" BST object such that both objects
//              are an exact, yet independent, copy of each other.
void BST::operator=(const BST & rhs) { 
  // Check if rhs BST is not empty
  if(rhs.root != nullptr) {
    // Perform a deep copy of rhs BST's nodes starting from newBSTNode and root of rhs BST 
    this->deepCopyR(rhs.root);
  }
}                


// Destructor 
BST::~BST() {

  // Deallocate heap memory in BST
  destroyBSTr(root);
}                

/* Helper Functions */

// Description: Recursively copies all nodes from the given source BST to the current BST.
// Precondition: 'rhsCurrent' is the root of a non-empty BST to be copied. 
// Postcondition: 'thisCurrent' and its subtree are a deep copy of 'rhsCurrent' and its subtree.
//                elementCount of this object is equal to element count of "rhs" BST
// Time Efficiency: O(n)
void BST::deepCopyR(BSTNode* rhsCurrent) {
  // Insert the current right hand side BSTNode's element into the current BST
  this->insert(rhsCurrent->element);

  // Recursively copy the left subtree, if it exists
  if(rhsCurrent->hasLeft()) {
    deepCopyR(rhsCurrent->left);
  }

  // Recursively copy the right subtree, if it exists
  if(rhsCurrent->hasRight()) {
    deepCopyR(rhsCurrent->right);
  }
}

// Description: Recursively destroys a BST starting from the given node using
//              a post order traversal
// Postcondition: The BST starting from "current" is destroyed, and memory is freed.
// Time Efficiency: O(n)
void BST::destroyBSTr(BSTNode* current) {  
  // Base case: If current BSTNode is nullptr, return
  if(current == nullptr) {
    return;
  }

  // Recursively destroy left subtree
  destroyBSTr(current->left);

  // Recursively destroy right subtree
  destroyBSTr(current->right);

  // delete current BSTNode
  delete current; 
}
 
 
/* BST Public Interface */
 
// Description: Returns the number of elements currently stored in the BST.   
// Postcondition: This method does not change the BST.
// Time efficiency: O(1)
unsigned int BST::getElementCount() const {     
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

  // Create a new BSTNode for the new element
  BSTNode *newBSTNode = new(nothrow) BSTNode(newElement);
  if(newBSTNode == nullptr) {
    throw UnableToInsertException("Memory could not be allocated for newElement");
  }

  // If the tree is empty, set the new BSTNode as the root
  if(root == nullptr) {
    root = newBSTNode;
    elementCount++;
    return;
  }

  // Call the recursive insertR method to insert the new BSTNode into BST and retrive result
  bool hasBeenInserted = insertR(newBSTNode, root);

  if(!hasBeenInserted) {
    // If insertion was unsuccessful, delete the allocated node and throw exception
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
  
  // Initialize the next BSTNode for recursion
  BSTNode* nextBSTNode = nullptr;

  // If new BSTNode's value is equal to current BSTNode's value
  if(newBSTNode->element == current->element) {
    return false; // Element already exists, insertion failed
  }

  // If new node's value is less than current node's value
  if(newBSTNode->element < current->element) {
    // If left child of current BSTNode is empty
    if(current->hasLeft()) {
      current->left = newBSTNode;               // Insert new node as left child
      return true;                              // Successful insertion
    } else {
      nextBSTNode = current->left;              // For recursive call to traverse to left child
    }
  }

  // If new BSTNode's value is greater than the current BSTNode's value
  if(newBSTNode->element > current->element) {
    // If the right child of the current BSTNode is empty
    if(current->hasRight()) {
      current->right = newBSTNode;              // Insert newBSTNode as right child
      return true;                              // Successful insertion
    } else { 
      nextBSTNode = current->right;             // For recursive call to traverse to right child
    }
  }

  // Recursively call insertR with the new BSTNode and appropiate child BSTNode
  return insertR(newBSTNode, nextBSTNode);
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

  //If the current BSTNode contains the targetElement, return its element
  if(current->element == targetElement) {
    return current->element;
  }

  //If targetElement is less than current BSTNode's element, search left subtree if it exists
  if(targetElement < current->element && current->hasLeft()) {
    return retrieveR(targetElement, current->left);
  }

  //If targetElement is greater than current BSTNode's element, search right subtree if it exists
  if(targetElement > current->element && current->hasRight()) {
    return retrieveR(targetElement, current->right);
  }

  //If none of the previous conditions hold true, it must be the case that targetElement does not exist
  throw ElementDoesNotExistException("Element Does Not Exist");

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

  // Order: Left, Visit, Right
  
  // Traverse left subtree, if it exists
  if(current->hasLeft()) {
    traverseInOrderR(visit, current->left);
  } 

  // Call visit function on current BSTNode's element
  visit(current->element);

  // Traverse right subtree first, if it exists
  if(current->hasRight()) {
    traverseInOrderR(visit, current->right);
  }  
}

// clang-format on
