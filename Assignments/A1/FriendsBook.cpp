/*
 * FriendsBook.cpp - Assignment 1
 *
 * Class Description: Social network application.
 *
 * In this version, we use our MyADT class.
 *
 * Author: Software developer A
 * Modified on: May 2024
 */
// clang-format off
#include <iostream>
#include <string>
#include <cctype>
#include "Profile.h"
#include "MyADT.h"

using std::cout;
using std::ws;
using std::cin;
using std::endl;

/* NOTE:
Using "getline(cin >> ws, theUserName);"
removes all leading whitespace -> ws     
*/

void join(MyADT & theMembers) {
    string theUserName = "";
    string theName = "";
    string theEmail = "";
    string theBirthday = "";

    // Create a new member profile
    cout << "Please, enter a userName (first character must be a lower case letter) : ";  
    getline(cin >> ws, theUserName);
    Profile testMember(theUserName);

    // Ensure the userName is a valid username and not the default value defined in Profile class.
    if ( testMember.getUserName() == Profile::getDefaultStrValue( ) )
        cout << "'" << theUserName << "'" << " is not a valid userName. A userName must have a lower case letter as its first character. Please, try again!." << endl;
    else {
        Profile * target = theMembers.search(testMember);
        if ( target == nullptr ) {
            cout << "Please, enter your name : ";
            getline(cin >> ws, theName);
            cout << "Please, enter your email : ";  
            getline(cin >> ws, theEmail);
            cout << "Please, enter your birthday : "; 
            getline(cin >> ws, theBirthday);      
            Profile theMember(theUserName, theName, theEmail, theBirthday);
            // Add new member profile to list
            if ( theMembers.insert(theMember) )
                // Report to user
                cout << "Member: " << "'" << theMember.getUserName() << "'" << " has successfully joined FriendsBook." << endl;
            else
                cout << "Member: " << "'" << theMember.getUserName() << "'" << " was unable to joined FriendsBook (she/he may already be a member?)" << endl;
        }
        else
            cout << "Member: " << "'" << testMember.getUserName() << "'" << " was unable to joined FriendsBook (she/he may already be a member?)" << endl;
    }

    return;
}


void leave(MyADT & theMembers) {
    string theUserName = "";

    cout << "Please, enter the username of the member that is leaving: ";
    getline(cin >> ws, theUserName);
    Profile toBeRemoved(theUserName);

    // Ensure the userName is a valid username and not the default value defined in Profile class.
    if ( toBeRemoved.getUserName() == Profile::getDefaultStrValue( ) )
        cout << "'" << theUserName << "'" << " is not a valid userName. A userName must have a lower case letter as its first character. Please, try again!." << endl;
    else {
        // Remove friend from FriendsBook
        if ( theMembers.remove(toBeRemoved) )
            cout << "Friend : " << "'" << toBeRemoved.getUserName() << "'" << " has now left this social network." << endl;
        else
            cout << "Friend : " << "'" << toBeRemoved.getUserName() << "'" << " is not a member of this social network!" << endl;
    }
    return;
}

 
void search(MyADT & theMembers) {
    string theUserName = "";
    
    // Create a new member profile
    cout << "Please, enter the username of the member you are looking for: ";   
    getline(cin >> ws, theUserName);
    Profile theMember(theUserName);

    // Ensure the userName is a valid username and not the default value defined in Profile class.
    if ( theMember.getUserName() == Profile::getDefaultStrValue( ) )
         cout << "'" << theUserName << "'" << " is not a valid userName. A userName must have a lower case letter as its first character. Please, try again!." << endl;
   else {
        // Search
        Profile * target = theMembers.search(theMember);

        if ( target != nullptr )
            // Report to user
            cout << "Member: " << "'" << target->getUserName() << "'" << " has been successfully found in FriendsBook." << endl;
        else
            cout << "'" << theUserName << "'" << " is not a member of FriendsBook." << endl;
    }

    return;
} 


void modify(MyADT & theMembers) {    
    string newString = "";
    string theUserName = "";
 
    cout << "Please, enter the username of the profile to be modified: ";  
    cin >> theUserName;
    cin.ignore(256, '\n');
    Profile theMember(theUserName);
    
    // Ensure the userName is a valid username and not the default value defined in Profile class.
    if ( theMember.getUserName() == Profile::getDefaultStrValue( ) )
        cout << "'" << theUserName << "'" << " is not a valid userName. A userName must have a lower case letter as its first character. Please, try again!." << endl;
    else {
        // Search
        Profile * target = theMembers.search(theMember);
        if ( target != nullptr ) {
            // Modify
            cout << "Modifying member's name " << "'" << target->getName() << "'" << endl;
            cout << "Please enter new name for this profile (press ENTER to skip): ";
            getline(cin, newString);
            if ( !newString.empty() ) target->setName(newString);
    
            cout << "Modifying member's email " << "'" << target->getEmail() << "'" << endl;
            cout << "Please, enter the new email of this member (press ENTER to skip): ";   
            getline(cin, newString);
            if ( !newString.empty() ) target->setEmail(newString);
            
            cout << "Modifying member's birthday " << "'" << target->getBirthday() << "'" << endl;
            cout << "Please, enter the new birthday of this member(press ENTER to skip): ";  
            getline(cin, newString);
            if ( !newString.empty() ) target->setBirthday(newString);        
        
        } else
            cout << "Member : " << "'" << theMember.getUserName() << "'" << " is not a member of FriendsBook." << endl;
    }
  
    return;
}

void print(MyADT & theMembers) {
    
    cout << "Printing FriendsBook" << endl;
    cout << "\nThere are now " << theMembers.getElementCount() << " friends in FriendsBook." << endl;
    theMembers.print();
    
    return;
}
void testMyADT() {
    // Create MyADT instances
    MyADT adt1;
    MyADT adt2;
    
    // Create Profile instances
    Profile p1("alice");
    Profile p2("bob");
    Profile p3("carol");
    Profile p4("dave");
    Profile p5("eve");
    Profile p6("alice");  // Duplicate

    // Insert profiles into adt1
    std::cout << "Inserting profiles into adt1:" << std::endl;
    std::cout << "Insert alice: " << adt1.insert(p1) << std::endl;
    std::cout << "Insert bob: " << adt1.insert(p2) << std::endl;
    std::cout << "Insert carol: " << adt1.insert(p3) << std::endl;
    std::cout << "Insert dave: " << adt1.insert(p4) << std::endl;
    std::cout << "Insert eve: " << adt1.insert(p5) << std::endl;
    std::cout << "Insert duplicate alice: " << adt1.insert(p6) << std::endl;

    // Print adt1
    std::cout << "ADT1 contents after insertion:" << std::endl;
    adt1.print();
    std::cout << std::endl;

    // Copy adt1 to adt3 using copy constructor
    MyADT adt3(adt1);
    std::cout << "ADT3 (copy of ADT1) contents:" << std::endl;
    adt3.print();
    std::cout << std::endl;

    // Insert profiles into adt2
    std::cout << "Inserting profiles into adt2:" << std::endl;
    std::cout << "Insert eve: " << adt2.insert(p5) << std::endl;
    std::cout << "Insert dave: " << adt2.insert(p4) << std::endl;
    std::cout << "Insert carol: " << adt2.insert(p3) << std::endl;
    std::cout << "Insert bob: " << adt2.insert(p2) << std::endl;
    std::cout << "Insert alice: " << adt2.insert(p1) << std::endl;

    // Print adt2
    std::cout << "ADT2 contents after insertion:" << std::endl;
    adt2.print();
    std::cout << std::endl;

    // Remove elements from adt1
    std::cout << "Removing elements from adt1:" << std::endl;
    std::cout << "Remove alice: " << adt1.remove(p1) << std::endl;
    std::cout << "Remove non-existent element 'z': " << adt1.remove(Profile("zoe")) << std::endl;
    std::cout << "Remove dave: " << adt1.remove(p4) << std::endl;

    // Print adt1 after removals
    std::cout << "ADT1 contents after removal:" << std::endl;
    adt1.print();
    std::cout << std::endl;

    // Search for elements in adt2
    std::cout << "Searching elements in adt2:" << std::endl;
    Profile* searchResult = adt2.search(p3);
    if (searchResult) {
        std::cout << "Found carol: " << *searchResult << std::endl;
    } else {
        std::cout << "Carol not found" << std::endl;
    }

    searchResult = adt2.search(Profile("zoe"));
    if (searchResult) {
        std::cout << "Found zoe: " << *searchResult << std::endl;
    } else {
        std::cout << "Zoe not found" << std::endl;
    }

    // Remove all elements from adt2
    std::cout << "Removing all elements from adt2:" << std::endl;
    adt2.removeAll();
    std::cout << "ADT2 contents after removeAll:" << std::endl;
    adt2.print();
    std::cout << std::endl;
}
int main() {

    // Variables declaration
    MyADT members = MyADT(); 
    bool done = false;
    char input = 0;
    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << "\n----Welcome to FriendsBook!" << endl << endl;
        cout << endl << "Enter ..." << endl;
        cout << "j -> to join FriendsBook by creating a profile." << endl;
        cout << "l -> to leave FriendsBook." << endl;
        cout << "s -> to search for a friend on FriendsBook." << endl;
        cout << "m -> to modify your profile on FriendsBook." << endl;
        cout << "p -> to print all members on FriendsBook." << endl;
        cout << "x -> to exit FriendsBook." << endl << endl;


        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch(input) {
            case 'j': join(members); break;
            case 'l': leave(members); break;
            case 's': search(members); break;
            case 'm': modify(members); break;
            case 'p': print(members); break;
            case 'x': cout << "\n----Bye!\n" << endl; 
                      done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    MyADT adtcopy = members;
  cout << "hello" << endl;
    cout << &adtcopy << " address for adtcopy " << endl;
    adtcopy.insert(Profile());
    members.removeAll(); 
    members.insert(Profile("john"));
    cout << "print out copy after everything we've done to members" << endl;
    print(adtcopy);

    cout << " printing members after remove all and add john" << endl;
    print(members);
   MyADT myCollection;

    // Creating some Profile objects to test
    Profile p1("alice123", "Alice", "alice@example.com", "1995-01-01");
    Profile p2("alex456", "Alex", "alex@example.com", "1990-02-02");
    Profile p3("amanda789", "Amanda", "amanda@example.com", "1985-03-03");
    Profile p4("anthony012", "Anthony", "anthony@example.com", "1980-04-04");
    Profile p5("avery345", "Avery", "avery@example.com", "1975-05-05");
    Profile p6("adam678", "Adam", "adam@example.com", "1970-06-06"); // To test the limit of MAX_ELEMENTS
    Profile p7("hank123", "Hank", "hank@example.com", "1990-07-07");
    Profile p8("henry456", "Henry", "henry@example.com", "1985-08-08");
    Profile p9("harry789", "Harry", "harry@example.com", "1980-09-09");
    Profile p10("helen012", "Helen", "helen@example.com", "1975-10-10");
    Profile p11("holly345", "Holly", "holly@example.com", "1970-11-11");
    Profile p12("harriet678", "Harriet", "harriet@example.com", "1965-12-12"); // To test the limit of MAX_ELEMENTS

    // Initial tests on myCollection
    std::cout << "Inserting profiles into myCollection...\n";
    myCollection.insert(p1);
    myCollection.insert(p2);
    myCollection.insert(p3);
    myCollection.insert(p4);
    myCollection.insert(p5);
    myCollection.insert(p7);
    myCollection.insert(p8);
    myCollection.insert(p9);
    myCollection.insert(p10);
    myCollection.insert(p11);

    // Create a second MyADT instance
    MyADT newName;

    // Perform a variety of operations on newName
    std::cout << "Performing operations on newName...\n";

    // Insertions
    std::cout << "Inserting profiles into newName...\n";
    std::cout << "Insert Alice: " << (newName.insert(p1) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Amanda: " << (newName.insert(p3) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Anthony: " << (newName.insert(p4) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Avery: " << (newName.insert(p5) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Adam (should fail): " << (newName.insert(p6) ? "Success" : "Failure") << std::endl;

    std::cout << "Insert Hank: " << (newName.insert(p7) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Henry: " << (newName.insert(p8) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Harry: " << (newName.insert(p9) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Helen: " << (newName.insert(p10) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Holly: " << (newName.insert(p11) ? "Success" : "Failure") << std::endl;
    std::cout << "Insert Harriet (should fail): " << (newName.insert(p12) ? "Success" : "Failure") << std::endl;

    // Element count
    std::cout << "Total elements in newName: " << newName.getElementCount() << std::endl;

    // Searches
    std::cout << "Searching for Amanda in newName: " << (newName.search(p3) != nullptr ? "Found" : "Not Found") << std::endl;
    std::cout << "Searching for Harriet in newName: " << (newName.search(p12) != nullptr ? "Found" : "Not Found") << std::endl;

    // Removals
    std::cout << "Removing Amanda from newName: " << (newName.remove(p3) ? "Success" : "Failure") << std::endl;
    std::cout << "Removing Harriet from newName (should fail): " << (newName.remove(p12) ? "Success" : "Failure") << std::endl;

    // Total elements after removals
    std::cout << "Total elements in newName after removals: " << newName.getElementCount() << std::endl;

    // Remove all elements
    std::cout << "Removing all elements from newName...\n";
    newName.removeAll();
    std::cout << "Total elements in newName after removeAll: " << newName.getElementCount() << std::endl;

    // Additional random operations
    std::cout << "Inserting some profiles back into newName...\n";
    newName.insert(p1);
    newName.insert(p7);
    newName.insert(p8);
    newName.insert(p10);

    // Print current elements in newName
    std::cout << "Printing all elements in newName:\n";
    newName.print();

    // Copy constructor test
    std::cout << "Testing copy constructor...\n";
    MyADT copiedCollection(newName);
    std::cout << "Printing elements of copiedCollection:\n";
    copiedCollection.print();

    // Create a third MyADT instance
    std::cout << "Creating a third MyADT instance using the copy constructor...\n";
    MyADT thirdCollection(copiedCollection);

    // Perform a variety of operations on thirdCollection
    std::cout << "Performing operations on thirdCollection...\n";
    thirdCollection.insert(p2);
    thirdCollection.insert(p4);
    thirdCollection.insert(p6);
    std::cout << "Total elements in thirdCollection: " << thirdCollection.getElementCount() << std::endl;

    std::cout << "Removing elements from thirdCollection...\n";
    thirdCollection.remove(p1);
    thirdCollection.remove(p7);
    thirdCollection.remove(p10);

    std::cout << "Total elements in thirdCollection after removals: " << thirdCollection.getElementCount() << std::endl;

    std::cout << "Printing all elements in thirdCollection:\n";
    thirdCollection.print();

    // Destructor test will automatically be invoked at the end of main
    std::cout << "Destructor test will occur at the end of the program.\n";

    testMyADT();
    return 0;
}
// clang-format on 
