// clang-format off
/*
 * MyADTTestDriver.cpp - Assignment 1
 * 
 * Class Description: Testing our MyADT Data Collection
 *
 * Author: Ehsan Omar Marouf
 * Modified on: Jan. 2024
 */

#include <iostream>
#include "MyADT.h"
#include "Profile.h"

using std::cout;
using std::endl;

int main(){

    //testing default constructor. Expected result: MyADT object is created
    MyADT testADT;
    cout << "MyADT object succesfully created." << endl;

    //testing getElementCount function. Expected result: Returns 0 as no elements are in the data collection
    cout << "\nTesting getElementCount function. Expected Result: Returns 0 as no elements are in the data collection." << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;

    //creating profile objects with usernames starting with "a" for testing purposes
    Profile profile1("aRen", "Tyson", "tysonren@live.ca", "January 5 1995");
    Profile profile2("aTefdv", "Alex", "aLexter@gmail.com", "February 2 1996");
    Profile profile3("aBurgers", "Chris", "chrisburgers@hotmail.com", "March 23 1998");
    Profile profile4("aAnders", "Mark", "markAnders5@gmail.com", "August 10 2000");
    Profile profile5("aYellow", "Zack", "zackYello2@live.ca", "July 15 1997");
    cout << "\n5 profile objects with usernames starting with 'a' have been created." << endl;

    //adding all profile objects to MyADT. Expected result: all of them are succesfully added
    testADT.insert(profile1);
    testADT.insert(profile2);
    testADT.insert(profile3);
    testADT.insert(profile4);
    testADT.insert(profile5);
    cout << "\nInserting all 5 profiles into data collection." << endl;
    //checking number of elements now. Expected result: returns 5
    cout << "\nChecking to see how many elements are now in data collection. Expected result: 5" << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;
    
    //profile to add starting with username starting with "a" to check if full
    Profile profileWithA("aFE");
    cout << "\nAnother profile object created with username starting with 'a'." << endl;
    //testing adding a profile when list of profiles starting with username "a" is full. Expected result: returns false(0) 
    cout << "Attempting to add recently created profile to data collection when list of usernames starting with 'a' is full. Expected result: false(0)" << endl;
    cout << testADT.insert(profileWithA) << endl;
    //checking number of elements now. Expected result: returns 5 since the recently added profile should not have been added 
    cout << "\nChecking number of elements in the data collection to see if object was not added because of capacity. Expected result: 5" << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;

    //creating profile objects with different usernames
    Profile profile6("bTqwe");
    Profile profile7("dERF");
    cout << "\nTwo profile object created wth different first characters in username." << endl;
    //adding these profile objects to MyADT. Expected result: all of them are succesfully added
    testADT.insert(profile6);
    testADT.insert(profile7);
    cout << "Inserting both of these objects in data collection." << endl;
    //checking number of elements now. Expected result: returns 7 since the recently added profile should not have been added 
    cout << "\nChecking number of elements in the data collection. Expected result: 7" << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;

    //printing elements in data collection so far. Expected result: displaying in ascending order
    cout << "\nProfiles in data collection currently: " << endl;
    testADT.print();
    
    //trying to add the same profile again. Expected result: returns false(0) since data collection is full
    cout << "\nTrying to insert a profile that's already been added again. Expected result: false (0)" << endl;
    cout << "The result is: " << testADT.insert(profile1) << endl;

    //printing elements in data collection so far. Expected result: displaying in ascending order with recent profile not added because its duplicated
    cout << "\nPrinting objects again to show that duplicate object was not added:" << endl;
    testADT.print();
    //checking number of elements now. Expected result: returns 7 since the recently added profile should not have been added 
    cout << "\nChecking number of elements in the data collection. Expected result: 7" << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;

    //removing 4 profiles that have username "a"
    testADT.remove(profile1);
    testADT.remove(profile2);
    testADT.remove(profile3);
    testADT.remove(profile4);
    cout << "\n4 profile objects with usernames starting with 'a' have been removed." << endl;
    //printing elements after removing. Expected result: displaying 3 profiles
    cout << "\nNow printing the objects in the data collection:" << endl;
    testADT.print();
    //checking number of elements now. Expected result: returns 3 since the recently added profile should not have been added 
    cout << "\nChecking number of elements in the data collection after removing 4 profiles. Expected result: 3" << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;

    //trying to remove a profile that has already been removed. Expected result: returns false(0) as profile has already been removed 
    cout << "\nAttempting to remove a profile from the data collection that has already been removed. Expected result: false(0)" << endl;
    cout << testADT.remove(profile1) << endl;
    //checking number of elements now. Expected result: returns 3 since the recently added profile should not have been added 
    cout << "\nChecking number of elements in the data collection. Expected result: 3" << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;

    //removing the final profile that has a username that starts with "a". Expected result: profile is removed
    cout << "\nRemoving the final profile that starts with username 'a'." << endl;
    testADT.remove(profile5);
    //checking number of elements now. Expected result: returns 2 since the recently added profile should have been removed
    cout << "\nChecking number of elements in the data collection after removing final 'a' profile. Expected result: 2" << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;
    //removing the same profile again while the list of profiles with usernames starting with "a" is empty. Expected result: returns false (0) as list of username starting with "a" is empty
    cout << "\nAttempting to remove the recently removed profile again from data colection. Expected result: false(0)" << endl;
    cout << testADT.remove(profile5) << endl;
    //checking number of elements now. Expected result: returns 2 since the recently added profile should not have been added 
    cout << "\nChecking number of elements in the data collection after attempting to remove the same profile. Expected result: 2" << endl;
    cout << "Number of elements in data collection is: " << testADT.getElementCount() << endl;

    //testing copy constructor. Expected result: copies object on rhs to new object being created
    cout << "\nCreating a new MyADT object by using a copy constructor and copying contents from the original data collection." << endl;
    MyADT copyADT(testADT);

    //printing recently constructed copy constructor. Expected result: prints the same objects that were in testADT
    cout << "\nPrinting the contents of the copied data collection:" << endl;
    copyADT.print();
    //testADT objects
    cout << "\nPrinting the contents of the original data collecion:" << endl;
    testADT.print();

    //testing if copyADT has the same numbers of elements as testADT. Expected result: has 2 elements as that was how many testADT had before copying
    cout << "\nTesting if both data collections have the same number of elements. Expected result: Both have 2 elements in the collection" << endl;
    cout << "Number of elements in original data collection is: " << testADT.getElementCount() << endl;
    cout << "Number of elements in copied data collection is: " << copyADT.getElementCount() << endl;

    //testing search function when profile is in the data collection. Expected result: returns address of profile 
    cout << "\nTesting if searching for a profile returns an address of a profile object. Expected result: Address is returned" << endl;
    cout << "Address of profile is " << copyADT.search(profile6) << endl;
    //testing search function when profile is not in the data collection. Expected result: returns nullptr (0)
    cout << "\nTesting if searching for a profile that doesn't exist returns nullptr(0). Expected result: nullptr is returned" << endl;
    cout << "Address of profile is " << copyADT.search(profile4) << endl;

    //testing remove all function on test adt. Expected result: returns to it's initialized state with no elements and nothing in the data collection.
    cout << "\nRemoving all objects in original data collection. Expected result: returns to it's original initialized state" << endl;
    testADT.removeAll();
    cout << "\nChecking if all the objects have been removed. Expected result: 0" << endl;
    cout << "Number of elements in original data collection is: " << testADT.getElementCount() << endl;
    cout << "\nPrinting the contents of the original data collection. Expected result: Nothing prints as data collection is empty." << endl;
    testADT.print();

    //print the copied data collection to show. Expected result: prints the 2 elements copied from testADT
    cout << "\nChecking to see if the copied data collection is not affected. Expected result: Prints the original 2 objects that were copied." << endl;
    copyADT.print();
    cout << "\nChecking the number of elements in copied data collection. Expected result: 2" << endl;
    cout << "Number of elements in copied data collection is: " << copyADT.getElementCount() << endl;


    return 0;

}
// clang-format on
