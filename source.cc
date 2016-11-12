#include <cstdlib>
#include <iostream>

#include "interface.h"
#include "calculator.h"

int main() {

  gascalculator::Interface io;
  io.getInput();
  gascalculator::Calculator calc(io.getPressure(), io.getMoles(), io.getTemperature(), io.getVolume());
  io.printAnswer(calc.calculate());
  return 0;

}
