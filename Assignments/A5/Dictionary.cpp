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
 * Author: Jason Mac, Jagyjot Parmar
 * Date: Last modified: July 2024
 */

// You can add more #include statements if you wish.

#include <iostream>
#include <cmath>
#include <cstring>
#include <sys/types.h>
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

// Description: Secondary hash function for probing 
// Time Efficiency = max {O(1), O(1), O(1)} = O(1)
// Space Efficiency = O(1), fixed by size of indexingKey
unsigned int Dictionary::hashFunctionTwo( string indexingKey ) {

  // Put your code here
  // Convert string to integral value
  uint64_t indexingKeyInt = stoul(indexingKey);  // O(1)
  const uint64_t PRIME = 191;
  uint64_t hashCode = 0;
  // Try to mix up the numbers using Prime and the value of indexingKeyInt at its end
  while (indexingKeyInt > 0) { // O(1)
      hashCode = hashCode * PRIME + (indexingKeyInt % 10);
      indexingKeyInt /= 10;
  }
  // Ensure we do not return 0
  return (hashCode == 0) ? hashCode % PRIME : 1; // O(1)
}

// ASSUMPTION: That the userNames of each inserting object is going to be fixed by 16 characters as 
//             given by our dataFile_100_16.txt
//             However, if we assume that that the indexingKey can be n characters long then
//             Time Efficiency becomes O(n)
// Description: Hashes the given indexingKey producing a "hash table index".
// Time Efficiency = max {O(1), O(1), O(1), O(1), O(1)} = O(1)
//
// Space Efficiency: O(1), all of the usernames have fixed size of 16 characters
//                         so space needed to store keyInt is fixed
unsigned int Dictionary::hashFunction(string indexingKey) {
// Convert the string to an unsigned long integer using stoul
    uint64_t keyInt = stoul(indexingKey); // O(1) Time
    // Get Prime number for shifting
    const uint64_t PRIME = 61;
    // hash alogrithm using bit manipulation and modulo operation
    // Inspired by MIT video (Original idea came from Dr. Erik Demaine) and many prime number testing 
    uint64_t hash = keyInt ^ (keyInt >> PRIME);  // XOR and shift, O(1)
    hash = hash * 997525853ULL;        // Multiply by a large prime number O(1)
    hash = hash ^ (hash >> PRIME);              // XOR and shift again O(1)

    return static_cast<unsigned int>(hash % CAPACITY); // Ensure hash fits in table size O(1)
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

  // Double Hashing probing strategy
  unsigned int hashIndex = hashFunction(newElement->getUserName());
  unsigned int secondaryHashIndex = hashFunctionTwo(newElement->getUserName());
  unsigned int i = 0;
  unsigned int count = 0;
  unsigned int probeIndex = hashIndex;
  while(count < CAPACITY) {
    // get step amount for probing
    unsigned int step = (secondaryHashIndex * i);
    probeIndex = (hashIndex + step) % CAPACITY;
    // Insert if nullptr
    if(hashTable[probeIndex] == nullptr) {
      hashTable[probeIndex] = newElement;
      elementCount++;
      // return as element has been inserted
      return;
    }
    // If already exists, throw exception
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
