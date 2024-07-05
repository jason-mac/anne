// clang-format off
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
using std::cerr;

// Display Method
void display(WordPair& anElement) {
  cout << anElement;
}

int main() {
      // Test default constructor
      Dictionary *dict1 = new Dictionary();

      // Test inserting elements
      WordPair wp1("key1", "value1");
      WordPair wp2("key2", "value2");
      WordPair wp3("key3", "value3");

      dict1->put(wp1);
      dict1->put(wp2);

      // Test display content
      cout << "Dictionary 1:" << endl;
      dict1->displayContent(display);
      cout << endl;

      // Test copy constructor
      Dictionary *dict2 = new Dictionary(*dict1);

      // Test assignment operator
      Dictionary *dict3 = new Dictionary();
      *dict3 = *dict1;

      // Test getElementCount
      cout << "Number of elements in dict1: " << dict1->getElementCount() << endl;
      cout << "Number of elements in dict2: " << dict2->getElementCount() << endl;
      cout << "Number of elements in dict3: " << dict3->getElementCount() << endl;
      cout << endl;

      // Test get function
      WordPair target("key2", ""); // Testing retrieval by key
      WordPair &result = dict1->get(target);
      cout << "Value for key 'key2' in dict1: " << result << endl;
      cout << endl;

      // Test exception handling (trying to get from empty dictionary)
      Dictionary *emptyDict = new Dictionary();
      try {
          WordPair targetEmpty("key1", "");
          WordPair &resultEmpty = emptyDict->get(targetEmpty);
          cout << "Value for key 'key1' in emptyDict: " << resultEmpty << endl;
      } catch (const EmptyDataCollectionException &e) {
          cout << "Exception caught (emptyDict): " << e.what() << endl;
      }
      cout << endl;

      // Test inserting duplicate element (exception handling)
      try {
          dict1->put(wp2); // wp2 is already in dict1
      } catch (const UnableToInsertException &e) {
          cout << "Exception caught (inserting duplicate): " << e.what() << endl;
      }
      cout << endl;

      // Test display content of empty dictionary
      cout << "Empty Dictionary:" << endl;
      emptyDict->displayContent(display);

      // Clean up: delete allocated dictionaries


    delete dict1;
    delete dict2;
    delete dict3;
    delete emptyDict;
    return 0;
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

/*
int main(int argc, char* argv[]) {
  // Allocate a dictionary onto the heap
  Dictionary * dictionary = new(nothrow) Dictionary();
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
        WordPair aWordPair(englishW, translationW);

        // Try to insert the given wordpair into the dictionary
        try {
          dictionary->put(aWordPair);
        }
        catch (ElementAlreadyExistsException& anException) {
        }
        catch (UnableToInsertException& anException) {
        }
      }

      // Close the file after inserting all of them into the dictionary
      myfile.close();

      // Display the dictionary if desired by the user
      if(argc > 2 && argv[2] == displayString) {
        if(dictionary->getElementCount() != 0) {
          dictionary->displayContent(display);
        } else {
          cout << "Dictionary is empty" << endl;
        }
      } else if ( argc == 2) {
        // Get user input for translation
        while(getline(cin, englishW)) {
          WordPair target(englishW);
          try {
            translated = dictionary->get(target);
            cout << translated;
          }
          catch(ElementDoesNotExistException& anException) {
            cout << "***Not Found!***" << endl;
          }
          catch(EmptyDataCollectionException& anException) {
          }
        }
      }
    } else { // File could not be open case 
      cout << "Could not open file" << endl;
    }
  } else { // File name not given
    cout << "No file name given" << endl;
  }
  delete dictionary;
  dictionary = nullptr;
  return 0;
}
*/

// clang-format on
