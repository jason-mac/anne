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
  WordPair wp4("key4", "value4");
  WordPair wp5("key5", "value5");
  WordPair wp6("key6", "value6");
  WordPair wp7("key7", "value7");
  WordPair wp8("key8", "value8");
  try {
    dict1->get(wp1);
  }
  catch(EmptyDataCollectionException& exception) {
    cout << exception.what() << endl;
  }
  catch(ElementDoesNotExistException& exception) {
    cout << exception.what() << endl;
  }
  dict1->put(wp1);
  dict1->put(wp2);

  // Test display content
  cout << "Dictionary 1:" << endl;
  cout << "Dict1 elementCount -> " << dict1->getElementCount() << endl;
  dict1->displayContent(display);
  cout << endl;

  // Test copy constructor
  Dictionary *dict2 = new Dictionary(*dict1);

  // Test assignment operator
  Dictionary *dict3 = new Dictionary();
  cout << "Dict3   elementCount -> " << dict3->getElementCount() << endl;
  *dict3 = *dict1;
  cout << "Dict1 elementCount -> " << dict1->getElementCount() << endl;
  dict1->put(wp4);
  dict2->put(wp5);
  dict3->put(wp6);
  // Test getElementCount
  cout << "Number of elements in dict1: " << dict1->getElementCount() << endl;
  cout << "Number of elements in dict2: " << dict2->getElementCount() << endl;
  cout << "Number of elements in dict3: " << dict3->getElementCount() << endl;
  cout << endl;
  cout << "DISPALY START" << endl;
  dict1->displayContent(display);
  cout << "DISPLAY END" << endl;
  cout << endl;
  cout << "DISPALY START" << endl;
  dict2->displayContent(display);
  cout << "DISPLAY END" << endl;
  cout << endl;
  cout << "DISPALY START" << endl;
  dict3->displayContent(display);
  cout << "DISPLAY END" << endl;
  Dictionary *dict4 = new Dictionary();
  cout << "Dict4 elementCount -> " << dict4->getElementCount() << endl;
  *dict3 = *dict4;
  cout << "Dict3 elementCount -> " << dict3->getElementCount() << endl;
  *dict4 = *dict4;
  cout << "Dict4 elementCount -> " << dict4->getElementCount() << endl;
  *dict3 = *dict4;
  cout << "Dict3 elementCount -> " << dict3->getElementCount() << endl;
    
  Dictionary *dict5 = new (nothrow) Dictionary(*(dict4));
    
  try {
    dict3->displayContent(display);
  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
  }
  try {
    dict5->displayContent(display);
  } catch (EmptyDataCollectionException &e) {
    cout << e.what() << endl;
  }
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
  } catch (const ElementAlreadyExistsException &e) {
    cout << "Exception caught (inserting duplicate): " << e.what() << endl;
  } catch(const UnableToInsertException& ex) {
    cout << ex.what() << endl;
  }

  cout << endl;

  // Test display content of empty dictionary
  cout << "Empty Dictionary:" << endl;
  try {

    emptyDict->displayContent(display);
  } catch (EmptyDataCollectionException &e) {
    cout << e.what();
  }
  // Clean up: delete allocated dictionaries

  delete dict1;
  delete dict2;
  delete dict3;
  delete emptyDict;
  delete dict4;
  delete dict5;
  return 0;
}
// clang-format on
