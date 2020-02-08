#include "c.hpp"
int r(const Eigen::Matrix <int, 4,4> & A){
  return 2*A.trace();
}
