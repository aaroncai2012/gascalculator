#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <string>
#include <cstdlib>

namespace gascalculator {

class Calculator {

  public:

    Calculator(float pressure, float volume, float temperature, float moles);
    float calculate();

  private:

    float pressure_;
    float volume_;
    float temperature_;
    float moles_;
    std::string answerType_;
    const float r = 0.082057338;

};

}

#endif // CALCULATOR_H_
