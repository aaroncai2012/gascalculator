#include "calculator.h"

#include <cstdlib>
#include <string>

namespace gascalculator {

Calculator::Calculator(float pressure, float moles, float temperature, float volume) {

  pressure_ = pressure;
  moles_ = moles;
  temperature_ = temperature;
  volume_ = volume;

  if (!pressure_) { answerType_ = "pressure"; }
  if (!moles_) { answerType_ = "moles"; }
  if (!temperature_) { answerType_ = "temperature"; }
  if (!volume_) { answerType_ = "volume"; }

}

float Calculator::calculate() {

  if (answerType_ == "pressure") {
    return ((r * moles_ * temperature_) / volume_);
  }
  else if (answerType_ == "moles") {
    return ((pressure_ * volume_) / (r * temperature_));
  }
  else if (answerType_ == "temperature") {
    return ((pressure_ * volume_) / (r * moles_));
  }
  else {
    return ((r * moles_ * temperature_) / pressure_);
  }

}

}
