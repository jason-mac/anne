// clang-format off
/*
 * Translator.cpp
 * 
 * Description: Drives the translation of the BST ADT class. 
 *
 * Author: AL
 * Last Modification Date: June 2024
 */

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


void display(WordPair& anElement) {
  cout << anElement;
}

int main(int argc, char* arcv[]) {
  ifstream translationFile("myDataFile.txt");
  Dictionary* dictionary = new(nothrow) Dictionary();
  if(dictionary == nullptr) {
    cout << "Memory allocation of new dictionary failed, program terminating...";
    return EXIT_FAILURE;
  }
  
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string filename = "";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
  if(translationFile.is_open()) {
    
      cout << "Reading from a file:" << endl;  // For debugging purposes
      
      while ( getline (translationFile,aLine) ) {
        pos = aLine.find(delimiter);    
        englishW = aLine.substr(0, pos);
        aLine.erase(0, pos + delimiter.length());
        translationW = aLine;
        WordPair aWordPair(englishW, translationW);
        
    // insert aWordPair into "translation" using a try/catch block
    try {
            dictionary->put(aWordPair);
        } catch (const ElementAlreadyExistsException &e) {
            cerr << "Element already exists: " << e.what() << endl;
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
    translationFile.close();
  } else {
    cout << "Unable to open file" << endl;
  } 
  translationFile.close();
  delete dictionary;
}

// clang-format on
