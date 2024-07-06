/*
 * Translator.cpp
 * 
 * Description: Drives the translation of the BST ADT class. 
 *
 * Author: Jason Mac, Jagyjot Parmar 
 * Last Modification Date: June 2024
 */

#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "Dictionary.h"

using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;

// Display Method
void display(WordPair& anElement) {
  cout << anElement;
}

/*
   Translation Algorithm:
   
  Read in the data filename the user entered at the command line.
  Load its content (all the word pairs) into the Dictionary.
  While not EOF
    Read the English word the user entered at the command line.
    Translate this English word using the Dictionary object.
    Print <English word>:<word in the other language> on the computer monitor screen.
    If the English word was not found, print ***Not Found!*** instead.
 */

int main(int argc, char* argv[]) {
  // Allocate a dictionary onto the heap
  Dictionary * dictionary = new(nothrow) Dictionary();
  if(dictionary == nullptr) {
    cout << "New operator failed. Terminating program...";
    return 0;
  }

  // Variable setup for main algorithm
  string displayString = "display";
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;

  if (argc > 1) {
    filename = argv[1];
    ifstream myfile(filename);

    if(myfile.is_open()) {
      // Read in data from file and insert into the dictionary
      while(getline(myfile, aLine)) {
        pos = aLine.find(delimiter);
        englishW = aLine.substr(0, pos);
        aLine.erase(0, pos + delimiter.length());
        translationW = aLine;

        //Create WordPair for insertion into dictionary
        WordPair aWordPair(englishW, translationW);

        // Try to insert the given WordPair into the dictionary
        try {
          dictionary->put(aWordPair);
        }
        // Catch any errors
        catch (UnableToInsertException& anException) {}
        catch (ElementAlreadyExistsException& anException) {}
      }

      // Close the file after inserting all of them into the dictionary
      myfile.close();

      // Display the dictionary if desired by the user input
      if(argc > 2 && argv[2] == displayString) {
        if(dictionary->getElementCount() != 0) {
          dictionary->displayContent(display);
        } else {
          cout << "***Empty Dictionary!***" << endl;
        }
      } else if ( argc == 2) {
        // Get user input for translation
        while(getline(cin, englishW)) {
          WordPair target(englishW);

          // Try to find translation of given english word
          try {
            translated = dictionary->get(target);
            cout << translated;
          }
          // Catch any errors
          catch(ElementDoesNotExistException& anException) {
            cout << "***Not Found!***" << endl;
          }
          catch(EmptyDataCollectionException& anException) {}
        }
      }
    } else { // File could not be open  
      cout << "Could not open file" << endl;
    }
  } else { // File name not given
    cout << "No file name given" << endl;
  }
  delete dictionary;
  dictionary = nullptr;
  return 0;
}
