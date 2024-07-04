
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
