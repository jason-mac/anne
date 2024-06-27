/*
 * templateTestDriver.cpp
 * 
 * Description: Test driver for the List ADT class as we convert it into a template ADT class.
 *
 * Author: AL
 * Date: Last modified: June 2024
 */ 
 
#include <iostream>
#include "UnableToInsertException.h"
#include "EmptyListException.h"
#include "ElementDoesNotExistException.h"
#include "List.h"

using std::cout;
using std::endl;

int main() {

  int anInt = 3;
  List * intList = new List();
  
/* Test Case 1
 * An empty 'int' List has already been instantiated - the default constructor was executed.
 * Confirm this by calling getElementCount() and printing the List.
 */
  cout << "Test Case 1: Creating an empty List of int's." << endl;
  cout << "Expected Result: The List is empty." << endl; 
  cout << "Actual Result: Is the List empty (has 0 elements)? Answer -> elementCount = " << intList->getElementCount() << endl;
  cout << "Actual Result: Is the List empty (has 0 elements)? Answer -> " ;
  intList->printList(); 
  cout << endl << endl;


/* Test Case 2
 * Appending the element 3 to our empty 'int' List.
 * Confirm append(3) was successful by calling getElementCount() which should return 1 
 * and printing the List.
 */
  cout << "Test Case 2: Appending the element " << anInt << " to our empty 'int' List." << endl;
  try {
     intList->append(anInt);     
  }
  catch (UnableToInsertException & anException) {
     cout << "intList->append(" << anInt << ") unsuccessful because " << anException.what() << endl;
  }
  cout << "Expected Result: The List has one element: " << anInt << "." << endl;
  cout << "Actual Result: Does the List contain one element? Answer -> elementCount = " << intList->getElementCount() << endl;
  cout << "Actual Result: Does the List contain the element " << anInt << "? Answer -> " ; 
  intList->printList();
  cout << endl << endl;
  
/* Add more test cases here */



  return 0;
  
}
