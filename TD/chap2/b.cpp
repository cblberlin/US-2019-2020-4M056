#include "b.hpp"
#include <ctime>
std::mt19937 G(time(NULL));
int g(){
  return std::binomial_distribution <int> (10,0.5) (G);
}

double h(double x, int i) {
  return add(i) * x;
}
