#include "a.hpp"
#include "b.hpp"
#include "c.hpp"
#include <iostream>
#include <Eigen/Dense>
int main(){
  std::cout << h(4., 2.) << std::endl;
  Eigen::Matrix <int, 4, 4> A;
  for (int i = 0; i < 4; i++){
    for (int j = 0; j < 4; j++){
      A(i,j) = g();
    }
  }
  //std::cout << A << std::endl;
  f(r(A));
}
