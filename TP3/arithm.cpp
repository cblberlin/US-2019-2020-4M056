#include "arithm.hpp"



unsigned gcd(unsigned a, unsigned b){
  if(b == 0){
    return a;
  }
  unsigned r = a%b;
  return gcd(b, r);
}

/*
unsigned gcd(std::list<unsigned> l){

}
*/
