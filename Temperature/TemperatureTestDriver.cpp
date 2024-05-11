/*
 * TemperatureTestDriver.cpp
 *
 * Description: Test Driver for Temperature class (non-ADT).
 * 
 * Author: AL
 * Modified on: Sept. 2023 
 */

#include <iostream>
#include <iomanip>         // setprecision
#include "Temperature.h"

using std::cout;
using std::endl;
using std::setprecision;
using std::fixed;

int main() {

    cout << setprecision(1) << fixed;
	
    // Create a valid Celsius temperature
    cout << endl << "Create a valid default Celsius temperature -> testing constructor Temperature()." << endl;
    cout << "Expected Result: temperature = 0.0 C" << endl;
    Temperature tempCelsius;
    cout << "Actual Result: temperature = " << tempCelsius.getDegrees( ) << " " << tempCelsius.getScale() << endl;

    // Create an invalid Celsius temperature
    cout << endl << "Creating an invalid Celsius temperature -> testing constructor Temperature( -500.0, 'C' )." << endl;
    cout << "Expected Result: temperature = 0.0 C" << endl;
    cout << "Expecting to revert to the default temperature of 0.0 C since this erroneous Temperature object is breaking the class invariant." << endl;    
    Temperature tempCelsiusError( -500.0, 'C' );
    cout << "Actual Result: temperature = " << tempCelsiusError.getDegrees( ) << " " << tempCelsiusError.getScale() << endl;

    // Create a valid Fahrenheit temperature
    cout << endl << "Create a valid Fahrenheit temperature -> testing constructor Temperature( 32.0, 'F' )." << endl;
    cout << "Expected Result: temperature = 32.0 F" << endl;
    Temperature tempFahr( 32.0, 'F' );
    cout << "Actual Result: temperature = " << tempFahr.getDegrees( ) << " " << tempFahr.getScale() << endl;

    // Create an invalid Fahrenheit temperature
    cout << endl << "Create an invalid Fahrenheit temperature -> testing constructor Temperature( -500.0, 'F' )." << endl;
    cout << "Expected Result: temperature = 0.0 C" << endl;
    cout << "Expecting to revert to the default 0.0 C since this erroneous Temperature object is breaking the class invariant." << endl;
    Temperature tempFahrError( -500.0, 'F' );
    cout << "Actual Result: temperature = " << tempFahrError.getDegrees( ) << " " << tempFahrError.getScale() << endl;

    // Try to change a valid Fahrenheit temperature to an invalid amount of degrees
    cout << endl << "Changing the amount of degrees of the valid Fahrenheit temperature we created (32.0 F) by raising it by -492.0 F" << endl;
    cout << "-> testing raise( -492.0 )." << endl;
    cout << "Expected Result: temperature = 32.0 F" << endl;
    cout << "Expecting the temperature to remain unchanged since this would transform a valid Temperature object" << endl;
    cout << "into an erroneous Temperature object hence breaking the class invariant." << endl;
    tempFahr.raise( -492.0 );
    cout << "Actual Result: temperature = " << tempFahr.getDegrees( ) << " " << tempFahr.getScale() << endl;
 
    // More testing ...

    return 0;
}