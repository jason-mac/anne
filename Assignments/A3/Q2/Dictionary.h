// clang-format off
/*
 * Dictionary.h
 * 
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 * 
 * Class invariant: Duplicated elements are not allowed.
 *              
 * Author: Jason Mac, Jagyjot Parmar 
 * Date of last modification: June 2024
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "BST.h"
#include <iostream>

using std::cout;

class Dictionary {
   
private:

/* You cannot change the following data member of this class. */
   BST * keyValuePairs = nullptr;                  

/* Feel free to add private methods to this class. */
void static display(WordPair& anElement) {
  cout << anElement;
} 

public:

   // You cannot change the prototype of the public methods of this class.
   // Why? Because we shall use these prototypes when creating our "marking"
   // test driver. So, if our test driver cannot call the methods of you BST 
   // class because the prototype of these public methods don't match, 
   // we won't be able to successfully mark your assignment.

   // Constructor and destructor:
   Dictionary();                               // Default constructor
   Dictionary(const Dictionary & Dictionary);  // Copy constructor
   void operator=(const Dictionary & rhs);     // Overloaded assignment (=) operator   
   ~Dictionary();                              // Destructor 
 
 
/* Dictionary Public Interface */   

   // Description: Returns the number of elements currently stored in the Dictionary.
   // Postcondition: This method does not change the Dictionary.
   unsigned int getElementCount() const;
    
   // Description: Puts "newElement" (association of key-value) into the Dictionary.
   // Precondition: "newElement" does not already exist in the Dictionary.
   //               This is to say: no duplication allowed.
   // Exception: Throws the exception "UnableToInsertException" 
   //            when newElement cannot be inserted in the Dictionary.  
   // Exception: Throws the exception "ElementAlreadyExistsException" 
   //            if "newElement" already exists in the Dictionary.  
   void put(WordPair & newElement);
 
   // Description: Gets "newElement" (i.e., the associated value of a given key) 
   //              from the Dictionary.
   // Precondition: Dictionary is not empty.
   // Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
   // Exception: Throws the exception ElementDoesNotExistException
   //            if the key is not found in the Dictionary.
   // Postcondition: This method does not change the Dictionary.
   WordPair & get(WordPair & targetElement) const;

   // Description: Prints the content of the Dictionary.
   // Precondition: Dictionary is not empty.
   // Exception: Throws the exception EmptyDataCollectionException if the Dictionary is empty.
   // Postcondition: This method does not change the Dictionary.
   void displayContent() const;
   
}; // end Dictionary
#endif

// clang-format on
