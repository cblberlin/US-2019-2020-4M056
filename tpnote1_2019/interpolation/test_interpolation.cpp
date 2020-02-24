#include "interpolation.hpp"
#include <fstream>
#include <cmath>

int main(){
  LagrangeInterpolation P1;
  std::ifstream test_input("sample.dat");
  test_input >> P1;
  std::ofstream test_output("sample2.dat");
  test_output << P1;

  test_input.close();
  test_output.close();
  
  return 0;
}
