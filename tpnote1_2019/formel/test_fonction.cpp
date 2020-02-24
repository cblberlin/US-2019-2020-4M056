#include "fonction.hpp"

#include <string>
#include <iostream>

int main(){
  Fonction f("f");
  std::cout << f;
  //std::cout << f.derivee() << std::endl;
  //Fonction pow_5(5);

  Fonction cos("cos", "-sin");
  std::cout << cos;

  Fonction pow_5(5);
  std::cout << pow_5;

  std::cout << pow_5 * cos;
  std::cout << pow_5 + cos;

  std::cout << -pow_5;

  std::cout << pow_5 - cos;

  std::cout << 4.6*pow_5;

  std::cout << (f.rond(cos*pow_5)).derivee() << std::endl;

  
  return 0;
}
