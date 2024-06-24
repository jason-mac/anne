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
getElementCount()
put(WordPair& newElement);
get(WordPair& targetElement)
displayContent(visit(WordPair&))
throw ElementDoesNotExistException("Element does not exist");
throw EmptyDataCollectionException("BST is empty.");

//algorithm
// sort in alphaebtical order
// go middle, +-1, +-2, .... +- n /2

while(!EOF) {
  string userInput; 
  cout << "INput word";
  cint >> userInput;
  string translation;
  try {
   translation = get(userInput);
    cout << "translation of " << userInput << " is: " << translation << endl;
  }
  catch (const ElementDoesNotExistException& exception)  {
    cout << "***Not Found!***"  << endl;
  } 
  catch (const EmptyDataCollectionException& exception) {
    cout << "***Not Found!***"  << endl;
  }
}  



// As you discover what main() does, record your understanding of the code by commenting it.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[]) {
   
  Dictionary * translation = nullptr;
  try {
    translation = new Dictionary();
  }
  catch(...) {
    cout << "Filed memory allocation" << endl;
  }
  if (translation != nullptr) {
      
    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string filename = "";
    string delimiter = ":";
    size_t pos = 0;
    WordPair translated;

	 
    // Expecting at least a filename on the command line.
    if ( ( argc > 1 ) ) {
      filename = argv[1];

      ifstream myfile(filename);
      if (myfile.is_open()) {

        //Get rid of after done testing
        cout << "Reading from a file:" << endl;  // For debugging purposes
        
        while ( getline (myfile,aLine) ) {
          pos = aLine.find(delimiter);    
          englishW = aLine.substr(0, pos);
          aLine.erase(0, pos + delimiter.length());
          translationW = aLine;
          WordPair aWordPair(englishW, translationW);
          
		  // insert aWordPair into "translation" using a try/catch block
      try {
              translation->put(aWordPair);
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
      myfile.close();
        // More BST translation happening here!
	      cout << "ElementCount: " << translation->getElementCount() << endl;
        cout << "------TRAVERSING-START--" << endl;
        translation->displayContent(display);
        cout << "------TRAVERSING END----" << endl;
        cout << "Geting words in english to french" << endl;
        cout << "English->French" << endl;
        //cout << "Nurse: " << translation->get(WordPair("Nurse"));
      } else { 
        cout << "Unable to open file" << endl;
      }
    } else {
      cout << "Missing the data filename!" << endl;
    }
  } else { 
    cout << "new failed!" << endl;	
  }
  while
  delete translation; 

  return 0;
}

// clang-format on
