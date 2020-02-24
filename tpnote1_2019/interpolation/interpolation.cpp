#include "interpolation.hpp"

void LagrangeInterpolation::add_point(const std::pair<double, double> & p){
  bool test_doublon=false;
  //Test de présence du point
  for(int i=0; i<nb_points; i++){
      if(points[i].first == p.first){
          points[i].second = p.second;
          test_doublon=true;
      }
  }
  //Ajout du point
  if(!test_doublon){
      points.push_back(p);
      nb_points++;
  }
}

double LagrangeInterpolation::operator()(const double & x){
    double res=0;
    for(int j=0; j<nb_points;j++){
        double prod=1;
        for(int i=0; i<nb_points;i++){
            if(i!=j){
                prod*=(x-points[i].first);
                prod/=(points[j].first-points[i].first);
            }
        }
        prod*=points[j].second;
        res+=prod;
    }
    return res;
}

std::ostream & operator<<(std::ostream & o, const LagrangeInterpolation & P){
    for(int i=0; i<P.nb_points; i++){
        o << P.points[i].first << '\t' << P.points[i].second << std::endl;
    }
    return o;
}

std::istream & operator>>(std::istream & F, LagrangeInterpolation & P){
    double x;
    double y;
    while(F >> x >> y){
        std::pair<double,double> p(x,y);
        P.add_point(p);
    }
    return F;
}
