#include "interface.h"

#include <iostream>
#include <string>

namespace gascalculator {

void Interface::getInput() {
  bool hasEnteredPressure = false;
  bool hasEnteredVolume = false;
  bool hasEnteredTemperature = false;
  bool hasEnteredMoles = false;
  for (int i = 0; i < 3; ++i) {
    char type  = ' ';
    while ( type != 'v' && type != 't' && type != 'p' && type != 'm') {
//    std::cout << "Please chose a variable to enter (Volume, Temperature, Pressure, Moles)" << std::endl;
      std::cout << "Please choose a variable to enter (";
      if (!hasEnteredPressure) { std::cout << "Presssure, "; }
      if (!hasEnteredVolume) {
        if (hasEnteredTemperature && hasEnteredMoles) { std::cout << "Volume"; }
        else { std::cout << "Volume, "; }
      }
      if (!hasEnteredTemperature) {
        if (hasEnteredMoles) { std::cout << "Temperature"; }
        else { std::cout << "Temperature, "; }
      }
      if (!hasEnteredMoles) {
        std::cout << "Moles";
      }
      std::cout << ")" << std::endl;
      std::cout << "Enter v for Volume, t for Temperature, p for Pressure, or m for Moles: ";
      std::cin >> type;
    }
    std::string unit = " ";
    int input;
    if (type = 'v') {
      std::cout << "Please enter the amount of ml of gas: ";
      std::cin >> input;
      processVolume(input, "ml");
      hasEnteredVolume = true;
    }
    else if (type = 't') {
      std::cout << "Please enter the temperature in Kelvin: ";
      std::cin >> input;
      processTemperature(input, "k");
      hasEnteredTemperature = true;
    }
    else if (type = 'p') {
      std::cout << "Please enter the pressure in atm: ";
      std::cin >> input;
      processPressure(input, "atm");
      hasEnteredPressure = true;
    }
    else {
      std::cout << "Please enter the amount of moles of gas: ";
      std::cin >> input;
      processMoles(input);
      hasEnteredMoles = true;
    }
  }
}

float Interface::getPressure() { return pressure_; }
float Interface::getTemperature() { return temperature_; }
float Interface::getVolume() { return volume_; }
float Interface::getMoles() { return moles_; }

void Interface::processVolume(float value, std::string type) {
  if (type == "ml") {
    volume_ = value;
  }
}

void Interface::processTemperature(float value, std::string type) {
  if (type == "k") {
    temperature_ = value;
  }
}

void Interface::processPressure(float value, std::string type) {
  if (type == "atm") {
    pressure_ = value; 
  }
}

void Interface::processMoles(float value) {
  moles_ = value;
}

}
