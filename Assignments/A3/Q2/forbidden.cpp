
ifstream translationFile("myDataFile.txt");
Dictionary *dictionary = new (nothrow) Dictionary();
if (dictionary == nullptr) {
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
if (translationFile.is_open()) {

  cout << "Reading from a file:" << endl; // For debugging purposes

  while (getline(translationFile, aLine)) {
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
delete dictionary;

if (dictionary == nullptr) {
  cout << "Memory allocation for dictionary failed. Terminating program...";
  return EXIT_FAILURE;
}
if (argc < 2) {
  cout << "File name not found. Terminating program...";
  return EXIT_FAILURE;
}
fileName = argv[1];

ifstream file(fileName);
if (!file.is_open()) {
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
while (getline(file, aLine)) {
  // Read the english and translation pair line by line
  pos = aLine.find(delimiter);
  englishW = aLine.substr(0, pos);
  aLine.erase(0, pos + delimiter.length());
  translationW = aLine;
  WordPair aWordPair(englishW, translationW);

  // Insert WordPair into the dictionary Data Collection
  try {
    dictionary->put(aWordPair);
  } catch (const UnableToInsertException &e) {
    cout << e.what() << endl;
  } catch (const ElementAlreadyExistsException &e) {
    cout << e.what() << endl;
  }
}
string displayStr = "display";
if (argc == 3 && argv[2] == displayStr) {
  cout << "here" << endl;
  dictionary->displayContent(display);
  cout << "done display" << endl;
  return EXIT_SUCCESS;
}
if (argc == 3 && argv[2] != displayStr) {
  return EXIT_FAILURE;
}
string userInput = "";
while (getline(cin, userInput)) {
  cin >> userInput;
  WordPair find(userInput);
  WordPair translation;
  try {
    translation = dictionary->get(find);
    cerr << translation.getEnglish() << ":" << translation.getTranslation()
         << endl;
  } catch (const ElementDoesNotExistException &e) {
    cerr << "***Not Found***" << endl;
  }
}
file.close();
delete dictionary;
return EXIT_SUCCESS;

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
  *dict3 = *dict4;
  *dict4 = *dict4;
  *dict3 = *dict4;
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
