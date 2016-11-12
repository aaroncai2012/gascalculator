#include "interface.h"

#include <iostream>
#include <string>

namespace gascalculator {

Interface::Interface() {

  pressure_ = 0;
  volume_ = 0;
  temperature_ = 0;
  moles_ = 0;

}
void Interface::getInput() {
  bool hasEnteredPressure = false;
  bool hasEnteredVolume = false;
  bool hasEnteredTemperature = false;
  bool hasEnteredMoles = false;
  for (int i = 0; i < 3; ++i) {
    char type  = ' ';
    while ( type != 'v' && type != 't' && type != 'p' && type != 'm') {
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
      std::cout << "Enter p for Pressure, v for Volume, t for Temperature, m for Moles: ";
      std::cin >> type;
      std::cout << std::endl;
    }
    std::string unit = " ";
    float input = 0;
    if (type == 'v') {
      while (input <= 0) {
        std::cout << "Please enter the amount of litres of gas: ";
        std::cin >> input;
      }
      processVolume(input, "l");
      hasEnteredVolume = true;
    }
    else if (type == 't') {
      while (input <= 0) {
        std::cout << "Please enter the temperature in Kelvin: ";
        std::cin >> input;
      }
      processTemperature(input, "k");
      hasEnteredTemperature = true;
    }
    else if (type == 'p') {
      while (input <= 0) {
        std::cout << "Please enter the pressure in atm: ";
        std::cin >> input;
      }
      processPressure(input, "atm");
      hasEnteredPressure = true;
    }
    else {
      while (input <= 0) {
        std::cout << "Please enter the amount of moles of gas: ";
        std::cin >> input;
      }
      processMoles(input);
      hasEnteredMoles = true;
    }
    std::cout << std::endl;
  }
}

void Interface::printAnswer(float answer) {

  std::cout << "A gas sample with ";
  if (pressure_) {
    std::cout << pressure_ << " atm, ";
  }
  if (volume_) {
    std::cout << volume_ << " L, ";
  }
  if (temperature_ && !moles_) {
    std::cout << temperature_ << " K ";
  }
  else {
    std::cout << temperature_ << " K, ";
  }
  if (moles_) {
    std::cout << moles_ << " moles ";
  }

  std::cout << "will have " << answer;
  if (!pressure_) { std::cout << " atm."; }
  else if (!volume_) { std::cout << " L."; }
  else if (!temperature_) { std::cout << " K."; }
  else { std::cout << " moles."; }
  std::cout << std::endl;

}

float Interface::getPressure() { return pressure_; }
float Interface::getTemperature() { return temperature_; }
float Interface::getVolume() { return volume_; }
float Interface::getMoles() { return moles_; }

void Interface::processVolume(float value, std::string type) {
  if (type == "l") {
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
