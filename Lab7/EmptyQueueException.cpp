/*
 * EmptyQueueException.cpp
 *
 * Class Description: Defines the exception that is thrown when the 
 *                    Queue is empty.
 *
 * Author: Inspired from our textbook's authors Frank M. Carrano and Tim Henry.
 *         Copyright (c) 2013 __Pearson Education__. All rights reserved.
 */

#include "EmptyQueueException.h"  

EmptyQueueException::EmptyQueueException(const string& message): 
logic_error("Empty Queue Exception: " + message)
{
}  // end constructor

// End of implementation file.