/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 *                    Its concrete data structure (CDT) is not expandable.  
 *                    This signifies that when this data collection becomes full,
 *                    you do not have to resize its data structure (not in this Assignment 1).  
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *
 * Author: AL and <put your name here>
 * Last modified on: May 2024
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;

    
// Default constructor.
MyADT::MyADT() {
   // cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above cout to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
 
   /* Put your code here */
   
}  

// Copy constructor - Covered in Lab 3
MyADT::MyADT(const MyADT& rhs) {
   // cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
   // You can also use the above cout to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   /* Put your code here */
   
}  

// Overloaded assignment operator - Covered in Lab 4
// Therefore, we shall not be overloading this operator in our Assignment 1
// MyADT & MyADT::operator=(const MyADT& rhs) { }
	
// Destructor - Covered in Lab 3
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {
   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above cout to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
  
   /* Put your code here */
   
}  

// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {

   /* Put your code here */

}


// Description: Inserts an element in the data collection MyADT.
//              Returns "true" when the insertion is successfull, otherwise "false".
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted, MyADT's class invariants are still true
//                and the appropriate elementCount has been incremented.
// Time Efficiency: 
bool MyADT::insert(const Profile& newElement) {
 
   /* Put your code here */
   
}  

// Description: Removes an element from the data collection MyADT. 
//              Returns "true" when the removal is successfull, otherwise "false".    
// Precondition: The data collection MyADT is not empty.  
// Postcondition: toBeRemoved (if found) is removed, MyADT's class invariants are still true
//                and the appropriate elementCount is decremented.
// Time Efficiency: 
bool MyADT::remove(const Profile& toBeRemoved) {

   /* Put your code here */
   
}  

// Description: Removes all elements from the data collection MyADT. 
// Precondition: The data collection MyADT is not empty. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
// Time Efficiency: 
void MyADT::removeAll() {
    
    /* Put your code here */

}   

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
// Precondition: The data collection MyADT is not empty.
// Time Efficiency: 
Profile* MyADT::search(const Profile& target) {
    
    /* Put your code here */

}  


// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
// Time Efficiency: 
void MyADT::print() {
  
    /* Put your code here */  

} 

//  End of implementation file
