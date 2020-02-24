#ifndef INTERPOLATION_HPP
#define INTERPOLATION_HPP

#include <vector>
#include <iostream>

class LagrangeInterpolation{
protected:
  std::vector <std::pair<double, double> > points;
  int nb_points;
public:
  LagrangeInterpolation(): points(0), nb_points(0){};
  void add_point(const std::pair<double, double> &);
  double operator() (const double &);

  friend std::ostream & operator<<(std::ostream &, const LagrangeInterpolation &);
  friend std::istream & operator>>(std::istream &, LagrangeInterpolation &);
};


#endif
