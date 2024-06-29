/*
 * BSTTestDriver.cpp
 *
 * Description: Drives the testing of the BST ADT class.
 *
 * Author: AL
 * Last Modification Date: June 2024
 */

#include "BST.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"
#include "UnableToInsertException.h"
#include "WordPair.h"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::ifstream;
using std::nothrow;

void display(WordPair &anElement) { cout << anElement; }

// As you discover what main() does, record your understanding of the code by
// commenting it. If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[]) {
  BST *testOne = new BST();
  BST *testTwo = nullptr;
  WordPair one("apple", "theapple");
  WordPair two("banana", "thebanana");
  WordPair three("pear", "thepear");

  cout << "elementcount: " << testOne->getElementCount() << endl << endl;
  testOne->insert(one);
  testOne->insert(two);
  testOne->insert(three);

  testTwo = new BST(*testOne);
  BST *testThree = new BST(*testOne);

  cout << "TEST ONE" << endl;
  cout << "ElementCount: " << testOne->getElementCount() << endl;
  cout << "------TRAVERSING-START--" << endl;
  testOne->traverseInOrder(display);
  cout << "------TRAVERSING END----" << endl;
  cout << endl;

  cout << "TEST TWO" << endl;
  cout << "ElementCount: " << testTwo->getElementCount() << endl;
  cout << "------TRAVERSING-START--" << endl;
  testTwo->traverseInOrder(display);
  cout << "------TRAVERSING END----" << endl;
  cout << endl;

  cout << "TEST THREE" << endl;
  cout << "ElementCount: " << testThree->getElementCount() << endl;
  cout << "------TRAVERSING-START--" << endl;
  testThree->traverseInOrder(display);
  cout << "------TRAVERSING END----" << endl;
  cout << endl;

  WordPair newOne("shirt", "theshirt");
  WordPair newTwo("zebra", "thezebra");
  testTwo->insert(newOne);
  testThree->insert(newTwo);

  cout << "TEST ONE" << endl;
  cout << "ElementCount: " << testOne->getElementCount() << endl;
  cout << "------TRAVERSING-START--" << endl;
  testOne->traverseInOrder(display);
  cout << "------TRAVERSING END----" << endl;
  cout << endl;

  cout << "TEST TWO" << endl;
  cout << "ElementCount: " << testTwo->getElementCount() << endl;
  cout << "------TRAVERSING-START--" << endl;
  testTwo->traverseInOrder(display);
  cout << "------TRAVERSING END----" << endl;
  cout << endl;

  cout << "TEST THREE" << endl;
  cout << "ElementCount: " << testThree->getElementCount() << endl;
  cout << "------TRAVERSING-START--" << endl;
  testThree->traverseInOrder(display);
  cout << "------TRAVERSING END----" << endl;
  cout << endl;

  // retrive
  cout << "testing retrive" << endl << endl;
  try {
    WordPair fail("apple", "newtranslation");
    testOne->insert(fail);
  } catch (ElementAlreadyExistsException &exception) {
    cout << exception.what() << endl;
  }
  try {
    WordPair find("apple");
    WordPair &translation = testOne->retrieve(find);
    cout << "Translation of " << find.getEnglish()
         << " is: " << translation.getTranslation() << endl;
  } catch (ElementDoesNotExistException &exception) {
    cout << exception.what() << endl;
  } catch (...) {
    cout << "?????????????" << endl;
  }
  try {
    WordPair find("what");
    WordPair &translation = testOne->retrieve(find);
    cout << "Translation of " << find.getEnglish()
         << " is: " << translation.getTranslation() << endl;
  } catch (ElementDoesNotExistException &exception) {
    cout << exception.what() << endl;
  } catch (...) {
    cout << "?????????????" << endl;
  }
  BST *testFour = new BST();
  try {
    WordPair find("what");
    WordPair &translation = testFour->retrieve(find);
    cout << "Translation of " << find.getEnglish()
         << " is: " << translation.getTranslation() << endl;
  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
  }
  try {
    testFour->traverseInOrder(display);

  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
  }

  delete testOne;
  delete testTwo;
  delete testThree;
  delete testFour;
  BST *testing = new (nothrow) BST();
  if (testing != nullptr) {

    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string filename = "";
    string delimiter = ":";
    size_t pos = 0;
    WordPair translated;

    // Expecting at least a filename on the command line.
    if ((argc > 1)) {
      filename = argv[1];

      ifstream myfile(filename);
      if (myfile.is_open()) {
        cout << "Reading from a file:" << endl; // For debugging purposes
        while (getline(myfile, aLine)) {
          pos = aLine.find(delimiter);
          englishW = aLine.substr(0, pos);
          aLine.erase(0, pos + delimiter.length());
          translationW = aLine;
          WordPair aWordPair(englishW, translationW);

          // insert aWordPair into "testing" using a try/catch block
          try {
            testing->insert(aWordPair);
          } catch (const ElementAlreadyExistsException &e) {
            cerr << e.what();
            cout << aWordPair << " already exists" << endl;
          } catch (const ElementDoesNotExistException &e) {
            cerr << "Element does not exist: " << e.what() << endl;
          } catch (const EmptyDataCollectionException &e) {
            cerr << "Data collection is empty: " << e.what() << endl;
          } catch (const UnableToInsertException &e) {
            cerr << "Unable to insert element: " << e.what() << endl;
          } catch (...) {
            cerr << "Unknown exception during insertion" << endl;
          }
        }
        myfile.close();

        // More BST testing happening here!
        cout << "ElementCount: " << testing->getElementCount() << endl;
        cout << "------TRAVERSING-START--" << endl;
        testing->traverseInOrder(display);
        cout << "------TRAVERSING END----" << endl;
      } else {
        cout << "Unable to open file" << endl;
      }
    } else {
      cout << "Missing the data filename!" << endl;
    }
  } else {
    cout << "new failed!" << endl;
  }
  WordPair targetElement("hello", "bonjour"); // Example target element
  testing->insert(targetElement);
  try {
    WordPair &retrievedElement = testing->retrieve(targetElement);
    cout << "Retrieved element: " << retrievedElement << " - "
         << retrievedElement << endl;
  } catch (const ElementDoesNotExistException &e) {
    cerr << "Element does not exist: " << e.what() << endl;
  } catch (...) {
    cerr << "Unknown exception during retrieval" << endl;
  }
  try {
    WordPair find("black");
    WordPair &word = testing->retrieve(find);
    cout << "translation of " << find.getEnglish()
         << " is: " << word.getTranslation() << endl;
  } catch (ElementDoesNotExistException &e) {
    cout << e.what() << endl;
  }
  try {
    WordPair find("fire");
    WordPair &word = testing->retrieve(find);
    cout << "translation of " << find.getEnglish()
         << " is: " << word.getTranslation() << endl;
  } catch (ElementDoesNotExistException &e) {
    cout << e.what() << endl;
  }
  delete testing;

  return 0;
}
