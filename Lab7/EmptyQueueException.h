/*
 * EmptyQueueException.h
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    Queue is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */
 
#ifndef EmptyQueueException_H
#define EmptyQueueException_H

#include <stdexcept>
#include <string>

using std::string;
using std::logic_error;

class EmptyQueueException : public logic_error
{
public:
   EmptyQueueException(const string& message = "");
   
}; // end EmptyQueueException
#endif 
