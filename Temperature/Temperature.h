/*
 * Temperature.h
 *
 * Class Description: Class modeling a valid temperature and offering converters.
 *
 * Class Invariant: myScale == 'C' && myDegrees >= ABSOLUTE_ZERO_CELSIUS ||
 *                  myScale == 'F' && myDegrees >= ABSOLUTE_ZERO_FAHRENHEIT
 * 
 * Author: AL
 * Modified on: Sept. 2023
 */
 
#ifndef Temperature_H 
#define Temperature_H

/* Class Definition */

class Temperature {

private:
    double myDegrees = 0.0;  // >= ABSOLUTE_ZERO for myScale
    char   myScale = 'C';    // 'F' or 'C'

    //--- Helpers ---
	
    bool isValidTemperature( const double degrees, const char scale );

public:
    constexpr static double ABSOLUTE_ZERO_FAHRENHEIT = -459.67;
    constexpr static double ABSOLUTE_ZERO_CELSIUS = -273.15;

    //--- Constructors ---

    // Default constructor
    // Description: Constructs an object of Temperature class
    //              with data members initialized to
    //              double myDegrees = 0.0;  // >= ABSOLUTE_ZERO for myScale
    //              char   myScale = 'C';    // 'F' or 'C'
    //              See private section of Tempature.h 
    // Postcondition: 'myDegrees == 0.0 && myScale == 'C''.
    Temperature();

    // Precondition: 'scale' is one of 'f', 'F', 'c', 'C'
    //               and 'degrees' is a valid number of degrees for 'scale'.
    // Postcondition: 'myDegrees == degrees && myScale == (uppercase) scale', if Temperature valid,
    //                otherwise 'myDegrees == 0.0 && myScale == 'C''.
    Temperature(double degrees, char scale );

    //--- Getters ---
	
    double getDegrees( ) const;
    char getScale( ) const;

    //--- Setters ---
	
    // void setDegrees( const double degrees );
	
    // Description: Raise 'this' Temperature by amount in degrees (in 'myScale').
    // Precondition: 'myDegrees + amount' produces a valid magnitude
    //               for a Temperature whose scale is 'myScale'.
    // Postcondition: If raising 'this' Temperature by amount in degrees (in 'myScale')
    //                invalidates 'this' Temperature, 'this' Temperature is unmutated.
    void raise( const double amount );
	    
    // Offering this setter may not make a lot of sense!
    // void Temperature::setScale( const char scale );
	
    //--- Converters ---
	
    // Description: Fahrenheit converter
    // Postcondition: A valid Fahrenheit Temperature, equivalent to 'this', is returned.
    Temperature inFahrenheit( ) const;

    // Description: Celsius converter
    // Postcondition: A valid Celsius Temperature, equivalent to 'this', is returned.
    Temperature inCelsius( ) const;

};
#endif
