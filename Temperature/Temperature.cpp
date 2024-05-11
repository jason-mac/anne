/*
 * Temperature.cpp
 *
 * Class Description: Class modeling a valid temperature and offering converters.
 *
 * Class Invariant: myScale == 'C' && myDegrees >= ABSOLUTE_ZERO_CELSIUS ||
 *                  myScale == 'F' && myDegrees >= ABSOLUTE_ZERO_FAHRENHEIT
 *
 * Author: AL
 * Modified on: Sept. 2023
 */

#include <cctype>
#include "Temperature.h"


//--- Constructors ---

// Default constructor
// Description: Constructs an object of Temperature class
//              with data members initialized to
//              double myDegrees = 0.0;  // >= ABSOLUTE_ZERO for myScale
//              char   myScale = 'C';    // 'F' or 'C'
//              See private section of Tempature.h 
// Postcondition: 'myDegrees == 0.0 && myScale == 'C''.
Temperature::Temperature(){ 
	// No need for an "initialization list" because
	// the data members have already been initialized. 
}

// Parameterized constructor
// Precondition: 'scale' is one of 'f', 'F', 'c', 'C'
//               and 'degrees' is a valid number of degrees for 'scale'.
// Postcondition: 'myDegrees == degrees && myScale == (uppercase) scale', if Temperature valid,
//                otherwise 'myDegrees == 0.0 && myScale == 'C''.
Temperature::Temperature( double degrees, char scale ) {
  if ( isValidTemperature( degrees, scale ) ) {
    myDegrees = degrees;
    myScale = toupper( scale ); 
  }
}

//--- Getters ---

double Temperature::getDegrees( ) const {
	return myDegrees;
}

char Temperature::getScale( ) const {
    return myScale;
}

//--- Setters ---

//void Temperature::setDegrees( const double degrees ) {
//  if ( isValidTemperature( degrees, myScale ) ) {
//   myDegrees = degrees;
//  }
//}

// Description: Raise 'this' Temperature by amount in degrees (in 'myScale').
// Precondition: 'myDegrees + amount' produces a valid magnitude
//               for a Temperature whose scale is 'myScale'.
void Temperature::raise( const double amount ) {
  double newDegrees = myDegrees + amount;

  if ( isValidTemperature( newDegrees, myScale ) )
    myDegrees = newDegrees;

  return;
}

// Offering this setter may not make a lot of sense!
// void Temperature::setScale( const char scale ) {
//	 myScale = scale;
// }

//--- Converters ---

// Description: Fahrenheit converter
// Postcondition: A valid Fahrenheit Temperature, equivalent to 'this', is returned.
Temperature Temperature::inFahrenheit( ) const {
  Temperature result;

  if ( myScale == 'F' )
   result = Temperature( myDegrees, 'F' );
  else if ( myScale == 'C' )
   result = Temperature( myDegrees * 1.8 + 32.0, 'F' );

  return result;
}

// Description: Celsius converter
// Postcondition: A valid Celsius Temperature, equivalent to 'this', is returned.
Temperature Temperature::inCelsius( ) const {
  Temperature result;

  if ( myScale == 'C' )
   result = Temperature( myDegrees, 'C' );
  else if ( myScale == 'F' )
   result = Temperature( ( myDegrees - 32.0 ) / 1.8, 'C' );

  return result;
}

// Description: Temperature validation utility.
//              Returns true if Temperature( degrees, scale ) represents a 
//              valid temperature, false otherwise.
bool Temperature::isValidTemperature( const double degrees, const char scale ) {
  bool result = false;

  if ( scale == 'C' || scale == 'c' )
    result = degrees >= ABSOLUTE_ZERO_CELSIUS;
  else if ( scale == 'F' || scale == 'f' )
    result = degrees >= ABSOLUTE_ZERO_FAHRENHEIT;

  return result;
} 
