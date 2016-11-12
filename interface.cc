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
      std::cout << ")" << std::endl << "Enter "; 
      if (!hasEnteredPressure) { std::cout << "p for Pressure, "; }
      if (!hasEnteredVolume) {
        if (hasEnteredTemperature && hasEnteredMoles) { std::cout << "v for Volume: "; }
        else { std::cout << "v for Volume, "; }
      }
      if (!hasEnteredTemperature) {
        if (hasEnteredMoles) { std::cout << "t for Temperature: "; }
        else { std::cout << "t for Temperature, "; }
      }
      if (!hasEnteredMoles) { std::cout << "m for Moles: "; }
      std::cin >> type;
      std::cout << std::endl;
    }
    std::string unit = " ";
    float numInput = 0;
    int typeInput = 0;
    if (type == 'v') {
      while ((typeInput < 1) || (typeInput > 6)) {
        std::cout << "Please choose the unit of volume (enter the number of your choice):" << std::endl;
        std::cout << "1. Litres" << std::endl;
        std::cout << "2. Mililitres" << std::endl;
        std::cout << "3. Ounces" << std::endl;
        std::cout << "4. Gallons" << std::endl;
        std::cout << "5. Cubic Inches" << std::endl;
        std::cout << "6. Cubic feet" << std::endl;
        std::cin >> typeInput;
      }
      while (numInput <= 0) {
        std::cout << "Please enter the amount of ";
        if (typeInput == 1) { std::cout << "litres"; }
        else if (typeInput == 2) { std::cout << "mililitres"; }
        else if (typeInput == 3) { std::cout << "ounces"; }
        else if (typeInput == 4) { std::cout << "gallons"; }
        else if (typeInput == 5) { std::cout << "cubic inches"; }
        else if (typeInput == 6) { std::cout << "cubic feet"; }
        std::cout << " of the gas: ";
        std::cin >> numInput;
        }
      processVolume(numInput, typeInput);
      hasEnteredVolume = true;
    }
    else if (type == 't') {
      while (typeInput < 1 || typeInput > 3) {
        std::cout << "Please choose the unit of temperature (enter the number of your choice):" << std::endl;
        std::cout << "1. Degrees Kelvin" << std::endl;
        std::cout << "2. Degrees Celsius" << std::endl;
        std::cout << "3. Degrees Fahrenheit" << std::endl;
        std::cin >> typeInput;
      }
      if (typeInput == 1) { std::cout << "degrees Kelvin"; }
      else if (typeInput == 2) { std::cout << "degrees Celsius"; }
      else if (typeInput == 3) { std::cout << "degrees Fahrenheit"; }
      std::cout << "of the gas: ";
      std::cin >> numInput;
      processTemperature(numInput, typeInput);
      hasEnteredTemperature = true;
    }
    else if (type == 'p') {
      while (typeInput < 1 || typeInput > 5) {
        std::cout << "Please enter the unit of pressure (enter the number of your choice):" << std::endl;
        std::cout << "1. Atmospheres" << std::endl;
        std::cout << "2. Milimetres of Mercury" << std::endl;
        std::cout << "3. Torr" << std::endl;
        std::cout << "4. Kilopascals" << std::endl;
        std::cout << "5. Pounds Per Square Inch" << std::endl;
        std::cin >> typeInput;
      }
      while (numInput <= 0) {
        std::cout << "Please enter the amount of ";
        if (typeInput == 1) { std::cout << "atmospheres"; }
        if (typeInput == 2) { std::cout << "milimetres of mercury"; }
        if (typeInput == 3) { std::cout << "torr"; }
        if (typeInput == 4) { std::cout << "kilopascals"; }
        if (typeInput == 5) { std::cout << "pounds per square inch"; }
        std::cout << " the gas is at: " << std::endl;
        std::cin >> numInput;
      }
      processPressure(numInput, typeInput);
      hasEnteredPressure = true;
    }
    else {
      while (numInput <= 0) {
        std::cout << "Please enter the amount of moles of gas: ";
        std::cin >> numInput;
      }
      processMoles(numInput);
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

void Interface::processVolume(float value, int type) {
  if (type == 1) { //litres
    volume_ = value;
  }
  else if (type == 2) { //mililitres
    volume_ = 0.001 * value;
  }
  else if (type == 3) { //ounces
    volume_ = 33.814 * value;
  }
  else if (type == 4) { //gallons
    volume_ = 0.264172 * value;
  }
  else if (type == 5) { //cubic inches
    volume_ = value * 61.0237;
  }
  else if (type == 5) { //cubic feet
    volume_ = value * 0.0353147;
  }
}

void Interface::processTemperature(float value, int type) {
  if (type == 1) { //kelvin
    temperature_ = value;
  }
  else if (type == 2) { //celsius
    temperature_ = value + 273.15;
  }
  else if (type == 3) { //fahrenheit
    temperature_ = ((value - 32.0) / 1.8) + 273.15;
  }

}

void Interface::processPressure(float value, int type) {
  if (type == 1) { //atm
    pressure_ = value; 
  }
  else if (type == 2) { //mmHg
    pressure_ = value / 760.0;
  }
  else if (type == 3) { //torr
      pressure_ = value / 760.0;
  }
  else if (type == 4) { //kilopascals
    pressure_ = value * 101.325;
  }
  else if (type == 5) { //psi
    pressure_ = value * 14.6959;
  }

}

void Interface::processMoles(float value) {
  moles_ = value;
}

}
