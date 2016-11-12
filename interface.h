#ifndef INTERFACE_H_
#define INTERFACE_H_ 
#include <iostream>
#include <string>

namespace gascalculator {

class Interface {

  public:

    Interface();
    void getInput();
    void printAnswer(float answer);
    float getPressure();
    float getMoles();
    float getTemperature();
    float getVolume();

  private:
    void processPressure(float value, std::string unit);
    void processMoles(float value);
    void processTemperature(float value, std::string unit);
    void processVolume(float value, std::string unit);

    float pressure_;
    float moles_;
    float temperature_;
    float volume_;
    float numOfInputs_;
};

}
#endif // INTERFACE_H_
