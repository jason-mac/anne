// clang-format off
/* 
 * testDriver.cpp
 *
 * Description: Test drive the Data Collection ADT class.
 *
 * Author: AL
 * Date: June 2024
 */
 
#include <iostream>

using std::cout;
using std::endl;
using std::nothrow;
#include "DataCollection.h"


int main () {
	
  DataCollection * aDC1 = new(nothrow) DataCollection( );
  DataCollection * aDC2 = new(nothrow) DataCollection( );
  DataCollection * aDC3 = new(nothrow) DataCollection( );
  
  if ( (aDC1 != nullptr) && (aDC2 != nullptr) && (aDC3 != nullptr) ) {
    
    // Test case 1 - Empty DataCollection 1
    cout << "Test Case 1 - Just constructed a DataCollection 1:" << endl;
    cout << "Empty DataCollection 1: " << *aDC1 << endl;

    // Test case 2 - Prepending a few elements: 1 2 3 4 5 6 to DataCollection 1
    cout << "Test Case 2 - Prepending a few elements: 1 2 3 4 5 6 to DataCollection 1:" << endl;
    cout << "              expecting: 6 5 4 3 2 1 in DataCollection 1:" << endl;


    for (unsigned int i = 1; i <= 6; i++) {
   	    cout << "Prepending " << i << " to DataCollection 1" << endl;
        aDC1->prepend( i );
    }
    cout << "Content of DataCollection 1: " << *aDC1 << endl;


    // Test case 3 - Appending a few elements: 1 2 3 4 5 6 to DataCollection 2
    cout << "Test Case 3 - Appending a few elements: 1 2 3 4 5 6 to DataCollection 2:" << endl;
    cout << "              expecting: 1 2 3 4 5 6  in DataCollection 2:" << endl;


    for (unsigned int i = 1; i <= 6; i++) {
   	  cout << "Appending " << i << " to DataCollection 2" << endl;
   	  aDC2->append( i );
    }
    cout << "Content of DataCollection 2: " << *aDC2 << endl;


    // Test case 4 - Prepending and Appending a few elements to DataCollection 3
    cout << "Test Case 3 - Prepending and Appending a few elements to DataCollection 3:" << endl;
    cout << "              expecting: 3 4 1 2 5 6  in DataCollection 3:" << endl;

    cout << "Appending 1 to DataCollection 3" << endl;
    aDC3->append( 1 );

    cout << "Appending 2 to DataCollection 3" << endl;
    aDC3->append( 2 );

    cout << "Prepending 4 to DataCollection 3" << endl;
    aDC3->prepend( 4 );
  
    cout << "Prepending 3 to DataCollection 3" << endl;
    aDC3->prepend( 3 );

    cout << "Appending 5 to DataCollection 3" << endl;
    aDC3->append( 5 );

    cout << "Appending 6 to DataCollection 3" << endl;
    aDC3->append( 6 );

    cout << "Content of DataCollection 3: " << *aDC3 << endl;
    aDC1 = aDC2;
    cout << aDC2;
    cout << aDC1;
    aDC2->append(123);
    cout << aDC2;
    cout << aDC1;

	
    delete aDC1;
    aDC1 = nullptr;

    delete aDC2;
    aDC2 = nullptr;

    delete aDC3;
    aDC3 = nullptr;
  }
   
  return 0;
}
// clang-format on
