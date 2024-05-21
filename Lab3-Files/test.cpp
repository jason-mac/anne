/*
 * test.cpp
 *
 * Description: Driver program for testing our List ADT class.
 *              More specifically, for testing its copy constructor
 *              and destructor.
 *
 * Creation Date:
 * Author:
 */

#include "List.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void listTest() {

  List *ls1 = new List();

  /* Test Case */
  cout << "Appending 1,2,3 to the first List object." << endl;
  ls1->append(1);
  ls1->append(2);
  ls1->append(3);
  cout << endl << "Printing the first List object." << endl;
  ls1->printList();
  cout << endl << "Does it contain {1,2,3}?" << endl;

  cout << endl << "Make a copy of the List object." << endl;
  List *ls2 = new List(*ls1);
  cout << endl << "Print second List object." << endl;
  ls2->printList();
  cout << endl << "Does it contain {1,2,3}?" << endl;

  cout << endl << "Append 4,5,6 to the first List object." << endl;
  ls1->append(4);
  ls1->append(5);
  ls1->append(6);
  cout << endl << "Print first List object." << endl;
  ls1->printList();
  cout << endl << "Does it contain {1,2,3,4,5,6}?" << endl;

  cout << endl << "Print second List object: (what does it contain?)." << endl;
  ls2->printList();

  cout << endl << "If it was shallow copied, it should contain: {1,2,3,4,5,6}.";
  cout << endl << "If it was deep copied, it should contain: {1,2,3}." << endl;
  cout << endl;

  return;
}
int main() {
  listTest();
  return 0;
}
