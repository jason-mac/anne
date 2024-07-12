/*
 * EmptyDataCollectionException.h
 *
 * Class Description: Defines the exception that is thrown when the data
 * collection is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */

#ifndef EMPTY_DATA_COLLECTION_EXCEPTION_H
#define EMPTY_DATA_COLLECTION_EXCEPTION_H

#include <stdexcept>

using std::logic_error;
using std::string;

class EmptyDataCollectionException : public logic_error {

public:
  static constexpr const char *const msg = "Hello, World!";
  // Constructor
  EmptyDataCollectionException(const string &message);
};
#endif
