// clang-format off
/*
 * Dictionary.h
 * 
 * Class Description: Dictionary data collection ADT class.
 *                    The implementation of this class is based on 
 *                    the hashing strategy and the open addressing 
 *                    collision resolution strategy called linear probing hashing. 
 *            
 * Class Invariant: Each element stored in this Dictionary is unique (no duplications allowed).
 *
 * Author: Jason Mac, Jagyjot Parmar 
 * Date: Last modified: July 2024
 */


#ifndef DICTIONARY_H
#define DICTIONARY_H

// You can add more #include statements if you wish.

#include <string>
#include "Profile.h"


class Dictionary  {

/* 
 * You can add more private methods to this class.
 * You cannot modify the given code unless you are instructed to do so.
 *
 */ 
 
private:

  constexpr static unsigned int CAPACITY = 103;  // Size of hashTable - underlying data structure (array) of Dictionary.
                                                 // Using Radke's equation where g is 25: 4 * 25 + 3 = 103

  Profile * * hashTable = nullptr;               // HashTable - underlying data structure (array) of our Dictionary.
                                                 // HashTable is a pointer to an array of pointers to objects of Profile class.
  unsigned int elementCount = 0;                 // Current number of elements stored in this Dictionary.


public:
                                                
  
  // Constructor
  Dictionary();
  
  // Destructor
  // Description: Destruct a Dictionary object, releasing heap-allocated memory.
  ~Dictionary();

  // Description: Returns the total element count currently stored in Dictionary.
  // Postcondition: Dictionary remains unchanged.
  unsigned int getElementCount() const;
  
  // Description: Returns the CAPACITY (size) of the Dictionary.
  // Postcondition: Dictionary remains unchanged.
  unsigned int getCapacity() const;
  
  // Hash Function <- For you to complete!
  // Description: Hashes the given indexingKey producing a "hash table index".
  // Time Efficiency: This is given in the cpp file! 
  // Space Efficiency: This is given in the cpp file!
  unsigned int hashFunction( string indexingKey );

  // Description: Secondary Hash Function for probing
  //              and dealing with collisions
  // Time Efficiency: O(1) 
  // Space Efficiency: O(1)
  unsigned int hashFunctionTwo(string indexingKey);

  // Description: Inserts an element into the Dictionary and increments "elementCount".
  //              For this Assignment 5, you do not have to expand the Dictionary when it is full. 
  // Precondition: newElement must not already be in in the Dictionary.  
  // Exception: Throws UnableToInsertException if we cannot insert newElement in the Dictionary.
  //            For example, if the operator "new" fails, or Dictionary is full (temporary solution).
  // Exception: Throws ElementAlreadyExistsException if newElement is already in the Dictionary.  
  // *** Warning: This method may not be correct and needs to be tested! ***
  void insert( Profile * newElement );
   
  // Description: Returns a pointer to the target element if found.
  // Postcondition: Dictionary remains unchanged.
  // Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
  // Exception: Throws ElementDoesNotExistException if target is not found in the Dictionary.
  // *** You are not asked to implement this method in this Assignment 5.
  // Profile * Dictionary::get( Profile & target );
  
  // Description: Prints all elements stored in the Dictionary (unsorted).
  // Postcondition: Dictionary remains unchanged.
  void printDictionary() const;
  
}; // end Dictionary.h
#endif

// clang-format on
