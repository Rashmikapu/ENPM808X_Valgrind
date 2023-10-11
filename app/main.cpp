#include <AnalogSensor.hpp>
#include <iostream>

int main() {
  AnalogSensor lightSensor(5);
  std::cout << "Averaged sensor reading: " << lightSensor.Read() << std::endl;
  bool terminator = false;
  if (terminator) {
    std::cout << "DONE" << std::endl;
  }
  return 0;
}
