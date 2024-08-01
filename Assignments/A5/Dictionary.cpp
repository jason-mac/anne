// clang-format off
/*
 * Dictionary.cpp
 * 
 * Class Description: Dictionary data collection ADT class.
 *                    The implementation of this class is based on 
 *                    the hashing strategy and the open addressing 
 *                    collision resolution strategy called linear probing hashing. 
 *            
 * Class Invariant: Each element stored in this Dictionary is unique (no duplications allowed).
 *
 * Author: AL
 * Date: Last modified: July 2024
 */

// You can add more #include statements if you wish.

#include <iostream>
#include <cstring>
#include "Dictionary.h"  
#include "Profile.h"
#include "UnableToInsertException.h"
#include "ElementAlreadyExistsException.h"
#include "EmptyDataCollectionException.h"
#include "ElementDoesNotExistException.h"

using std::cout;
using std::endl;
using std::__cxx11::stoul;

// Constructor
Dictionary::Dictionary() {}

// Destructor
// Description: Destruct a Dictionary object, releasing heap-allocated memory.
Dictionary::~Dictionary() {
  // Release all heap memory
  if ( hashTable != nullptr ) { 
    for ( unsigned int i = 0; i < CAPACITY; i++ ) 
      if ( hashTable[i] != nullptr ) {      
        delete hashTable[i]; // Delete object of Profile class on heap
        hashTable[i] = nullptr;
      }
    delete [] hashTable;
    hashTable = nullptr;	
  }
}

// Description: Returns the total element count currently stored in Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getElementCount() const {
  return elementCount;
}

// Description: Returns the CAPACITY (size) of the Dictionary.
// Postcondition: Dictionary remains unchanged.
unsigned int Dictionary::getCapacity() const{
  return CAPACITY;
}

// Hash Function <- For you to complete!
// Description: Hashes the given indexingKey producing a "hash table index".
// Time Efficiency is dependent on two functions, indexingKeyInt, and murmurHash3
// Time Efficiency = max {O(stoul(indexingKey)), murmurHash3(indexingKey)}
// Time Efficiency = max {O(1), O(1)}
// Time Efficiency: O(1)
//
// Space Efficiency is dependent on storing uint64_t, whose value is dependent on 
// on the size of the string indexingKey, but we know this is always going to be 16 characters
// thus its O(1) space efficiency
// Space Efficiency: O(1), all of the usernames have fixed size of 16 characters
// 
unsigned int Dictionary::hashFunction( string indexingKey ) {

  // Put your code here
  uint64_t indexingKeyInt = stoul(indexingKey);
  uint64_t intermediate = 0;
  int power = indexingKey.size();
  for(int i = 1; i < power - 1; i++) {
    intermediate += indexingKeyInt % 10;
    intermediate = intermediate >> i;
    indexingKeyInt /= 10;
    cout << intermediate<< endl;
  }
  unsigned int hashCode = intermediate;
  return hashCode % CAPACITY;
}

// Description: Inserts an element into the Dictionary and increments "elementCount".
//              For this Assignment 5, you do not have to expand the hashTable when it is full. 
// Precondition: newElement must not already be in in the Dictionary.  
// Exception: Throws UnableToInsertException if we cannot insert newElement in the Dictionary.
//            For example, if the operator "new" fails, or Dictionary is full (temporary solution).
// Exception: Throws ElementAlreadyExistsException if newElement is already in the Dictionary.
// *** Warning: This method may not be correct and needs to be tested! ***
void Dictionary::insert( Profile * newElement )  {

  // Have we allocated memory for the hashTable yet?
  if ( elementCount == 0 ) {
    hashTable = new Profile*[CAPACITY];
    if (hashTable == nullptr) throw UnableToInsertException("In insert(): new failed.");
    for ( unsigned int i = 0; i < CAPACITY; i++ ) 
      hashTable[i] = nullptr; // Initialize each cell of hashTable, i.e., each pointer to nullptr.
  }

  // If Dictionary is full, it would make send to expand the Dictionary.
  // However, for this Assignment 5, you do not have to expand the Dictionary when it is full. 
  // We shall simply throw an exception.
  // TO DO FIX IT 
  if ( elementCount == CAPACITY ) 
    throw UnableToInsertException("In insert(): Dictionary is full.");
   
  // Call hash function using indexing key to get hash index

  // Keep hashing and probing until no more collisions using 
  // Linear Probing Hashing Collision Resolution Strategy
  /*unsigned int i = 0;
  unsigned int count = 0;
  while ( hashTable[(hashIndex + i)%CAPACITY] != nullptr ) {   
    // If newElement not already in Dictionary
    if ( *(hashTable[(hashIndex + i)%CAPACITY]) == *newElement ) {
      // newElement was found -> already exists in Dictionary.
      throw ElementAlreadyExistsException("In insert(): newElement already in Dictionary.");
	  }
    count++;
    i++;
    if ( count == CAPACITY ) {
	    throw UnableToInsertException("In insertHelper(): Dictionary is full.");
    } 
  }
  */
  unsigned int hashIndex = hashFunction(newElement->getUserName());

    unsigned int i = 0;
    unsigned int count = 0;
    unsigned int probeIndex = hashIndex;

    while (count < CAPACITY) {
        // Alternating positive and negative quadratic steps
        int step = (i % 2 == 0) ? (i / 2) * (i / 2) : -((i + 1) / 2) * ((i + 1) / 2);
        probeIndex = (hashIndex + step + CAPACITY) % CAPACITY;

        if (hashTable[probeIndex] == nullptr) {
            // Insert newElement here
            hashTable[probeIndex] = newElement;
            elementCount++; // Increment element count
            return;
        }

        if (*(hashTable[probeIndex]) == *newElement) {
            throw ElementAlreadyExistsException("In insert(): newElement already in Dictionary.");
        }

        count++;
        i++;
    }

    // If we exit the loop, it means we could not find an empty slot and the dictionary is full
    throw UnableToInsertException("In insert(): Dictionary is full.");
    
  return;
}

// Description: Returns a pointer to the target element if found.
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
// Exception: Throws ElementDoesNotExistException if target is not found in the Dictionary.
// *** You are not asked to implement this method in this Assignment 5. ***
// Profile * Dictionary::get( Profile & target )  { }
 
// Description: Prints all elements stored in the Dictionary (unsorted).
// Postcondition: Dictionary remains unchanged.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
void Dictionary::printDictionary()  const {
  if ( elementCount == 0 ) 
     throw EmptyDataCollectionException("In printDictionary(): hashTable is empty.");

  cout << endl << "Printing the Dictionary with " << this->elementCount << " elements: " << endl;
  for (unsigned int index = 0; index < CAPACITY; index++) {
    if ( hashTable[index] != nullptr ) 
		cout << "HashTable[" << index << "] = " << *(hashTable[index]) << endl; 
  }   
  return;
}

//clang-format on
