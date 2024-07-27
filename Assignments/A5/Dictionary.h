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
 * Author: AL
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
uint32_t murmurHash3(uint64_t key) {
    const uint32_t seed = 1; // Seed value can be adjusted as needed
    const uint32_t c1 = 0xcc9e2d51;
    const uint32_t c2 = 0x1b873593;
    const uint32_t r1 = 15;
    const uint32_t r2 = 13;
    const uint32_t m = 5;
    const uint32_t n = 0x561ccd1b;

    uint32_t h1 = seed;
    uint32_t k1 = static_cast<uint32_t>(key);

    k1 *= c1;
    k1 = (k1 << r1) | (k1 >> (32 - r1));
    k1 *= c2;
    h1 ^= k1;
    h1 = (h1 << r2) | (h1 >> (32 - r2));
    h1 = h1 * m + n;

    h1 ^= 8; // Length of the key
    h1 ^= (h1 >> 16);
    h1 *= 0x85ebca6b;
    h1 ^= (h1 >> 13);
    h1 *= 0xc2b2ae35;
    h1 ^= (h1 >> 16);

    return h1;
}
uint64_t xxHash64(const void* input, size_t length, uint64_t seed = 1) {
    const uint64_t PRIME64_1 = 11400714785074694791ULL;
    const uint64_t PRIME64_2 = 14029467366897019727ULL;
    const uint64_t PRIME64_3 =  1609587929392839161ULL;
    const uint64_t PRIME64_4 =  9650029242287828579ULL;
    const uint64_t PRIME64_5 =  2870177450012600261ULL;

    const uint8_t* p = (const uint8_t*)input;
    const uint8_t* const bEnd = p + length;
    uint64_t h64;

    if (length >= 32) {
        const uint8_t* const limit = bEnd - 32;
        uint64_t v1 = seed + PRIME64_1 + PRIME64_2;
        uint64_t v2 = seed + PRIME64_2;
        uint64_t v3 = seed + 0;
        uint64_t v4 = seed - PRIME64_1;

        do {
            v1 += *((uint64_t*)p) * PRIME64_2;
            v1 = (v1 << 31) | (v1 >> 33);
            v1 *= PRIME64_1;
            p += 8;
            v2 += *((uint64_t*)p) * PRIME64_2;
            v2 = (v2 << 31) | (v2 >> 33);
            v2 *= PRIME64_1;
            p += 8;
            v3 += *((uint64_t*)p) * PRIME64_2;
            v3 = (v3 << 31) | (v3 >> 33);
            v3 *= PRIME64_1;
            p += 8;
            v4 += *((uint64_t*)p) * PRIME64_2;
            v4 = (v4 << 31) | (v4 >> 33);
            v4 *= PRIME64_1;
            p += 8;
        } while (p <= limit);

        h64 = ((v1 << 1) | (v1 >> 63)) + ((v2 << 7) | (v2 >> 57)) + ((v3 << 12) | (v3 >> 52)) + ((v4 << 18) | (v4 >> 46));
    } else {
        h64 = seed + PRIME64_5;
    }

    h64 += length;

    while (p + 8 <= bEnd) {
        uint64_t k1 = *((uint64_t*)p);
        k1 *= PRIME64_2;
        k1 = (k1 << 31) | (k1 >> 33);
        k1 *= PRIME64_1;
        h64 ^= k1;
        h64 = ((h64 << 27) | (h64 >> 37)) * PRIME64_1 + PRIME64_4;
        p += 8;
    }

    while (p + 4 <= bEnd) {
        h64 ^= *((uint32_t*)p) * PRIME64_1;
        h64 = ((h64 << 23) | (h64 >> 41)) * PRIME64_2 + PRIME64_3;
        p += 4;
    }

    while (p < bEnd) {
        h64 ^= (*p) * PRIME64_5;
        h64 = ((h64 << 11) | (h64 >> 53)) * PRIME64_1;
        p++;
    }

    h64 ^= h64 >> 33;
    h64 *= PRIME64_2;
    h64 ^= h64 >> 29;
    h64 *= PRIME64_3;
    h64 ^= h64 >> 32;

    return h64;
}

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
  // Time Efficiency: <- For you to complete! 
  // Space Efficiency: <- For you to complete!
  unsigned int hashFunction( string indexingKey );

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
