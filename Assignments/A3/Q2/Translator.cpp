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

// Display Method
void display(WordPair& anElement) {
  cout << anElement;
}

/*void readData(Dictionary* dictionary, ifstream& file) {
  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
  while(getline(file, aLine)) {
    // Read the english and translation pair line by line
    pos = aLine.find(delimiter);
    englishW = aLine.substr(0, pos);
    aLine.erase(0, pos + delimiter.length());
    translationW = aLine;
    WordPair aWordPair(englishW, translationW);

    // Insert WordPair into the dictionary Data Collection
    try {
      dictionary->put(aWordPair);
    } catch (const UnableToInsertException& e) {
      cout << e.what() << endl;
    } catch (const ElementAlreadyExistsException& e) {
      cout << e.what() << endl;
    }
  }
}
*/


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
  Dictionary * dictionary = new(nothrow) Dictionary();
  string fileName = "";
  if(dictionary == nullptr) {
    cout << "Memory allocation for dictionary failed. Terminating program...";
    return EXIT_FAILURE;
  }
  if(argc < 2) {
    cout << "File name not found. Terminating program...";
    return EXIT_FAILURE;
  } 
  fileName = argv[1];
  
  ifstream file(fileName);
  if(!file.is_open()) {
    cout << "Unable to open file. Terminating program...";
    return EXIT_FAILURE;
  }

  string aLine = "";
  string aWord = "";
  string englishW = "";
  string translationW = "";
  string delimiter = ":";
  size_t pos = 0;
  WordPair translated;
  while(getline(file, aLine)) {
    // Read the english and translation pair line by line
    pos = aLine.find(delimiter);
    englishW = aLine.substr(0, pos);
    aLine.erase(0, pos + delimiter.length());
    translationW = aLine;
    WordPair aWordPair(englishW, translationW);

    // Insert WordPair into the dictionary Data Collection
    try {
      dictionary->put(aWordPair);
    } catch (const UnableToInsertException& e) {
      cout << e.what() << endl;
    } catch (const ElementAlreadyExistsException& e) {
      cout << e.what() << endl;
    }
  }
  string displayStr = "display";
  if(argc == 3 && argv[2] == displayStr) {
    cout << "here" << endl;
    dictionary->displayContent(display);
    cout << "done display" << endl;
    return EXIT_SUCCESS;
  }
  if(argc == 3 && argv[2] != displayStr) {
    return EXIT_FAILURE;
  }
  string userInput = "";
  while (getline(cin, userInput)) {
    cin >> userInput;
    WordPair find(userInput);
    WordPair translation;
    try { 
      translation = dictionary->get(find);
      cerr << translation.getEnglish() << ":" << translation.getTranslation() << endl;
    } catch(const ElementDoesNotExistException& e) {
      cerr << "***Not Found***" << endl;
    }
  }
  file.close();
  delete dictionary;
  return EXIT_SUCCESS; 
}

// clang-format on
