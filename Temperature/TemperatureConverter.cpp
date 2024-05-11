/*
 * TemperatureConverter.cpp
 *
 * Description: Test Driver for Temperature class (ADT).
 *
 * Author: AL
 * Modified on: Sept. 2023 
 */

#include <iostream>
#include <iomanip>         // setprecision
#include "Temperature.h"

using std::cout;
using std::endl;
using std::cin;
using std::setprecision;

int main() {

  cout << "\n*** Temperature Converter ***\n";

  // Variables declaration
  double degrees = 0;
  bool done = false;
  char input = 0;

  // Keep doing what the user selects until the user exits
  while (not done) {
    // Print menu to user 
    cout << "\nEnter 1 to convert from Celsius to Fahrenheit." << endl;
    cout << "Enter 2 to convert from Fahrenheit to Celsius." << endl;
    cout << "Enter 3 to exit." << endl;
    cout << "Your choice: ";
    cin >> input;
    switch(input) {
      case '1': {  // Scope of both Temperature objects aTempC and aTempF
        cout << "Enter the degrees in Celsius: ";   
        cin >> degrees; 
        Temperature aTempC( degrees, 'C' );  
        Temperature aTempF = aTempC.inFahrenheit(); 
        cout << aTempC.getDegrees() << " degrees " << aTempC.getScale() << " -> " <<  aTempF.getDegrees() << " degrees " << aTempF.getScale() << endl;
        break;
      }
      case '2': { // Scope of both Temperature objects aTempC and aTempF
        cout << "Enter the degrees in Fahrenheit: ";   
        cin >> degrees; 
        Temperature aTempF( degrees, 'F' );  
        Temperature aTempC = aTempF.inCelsius(); 
        cout << aTempF.getDegrees() << " degrees " << aTempF.getScale() << " -> " <<  aTempC.getDegrees() << " degrees " << aTempC.getScale() << endl;
        break;
      }
      case '3': cout << "\n----Bye!\n" << endl; done = true; break;
      default: cout << "Not sure what you mean! Please, try again!" << endl;
    }
  }

  return 0;
}
