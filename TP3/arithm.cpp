#include "arithm.hpp"

unsigned gcd(unsigned a, unsigned b){
  if(b == 0){
    return a;
  }
  unsigned r = a%b;
  return gcd(b, r);
}

unsigned gcd(std::list<unsigned> l){
  if (l.size() == 0){
    return 0;
  }
  else if(l.size() == 1){
    return l.front();
  }
  else if (l.size() == 2){
    unsigned a = l.front();
    l.pop_front();
    unsigned b = l.front();
    l.pop_front();
    return gcd(a, b);
  }
  else{
    unsigned a_0 = l.front();
    l.pop_front();
    unsigned a_1 = l.front();
    l.pop_front();
    unsigned b = gcd(a_0, a_1);
    l.push_front(b);
    return gcd(l);
  }
}

unsigned lcm(unsigned a, unsigned b){
  return (a*b)/gcd(a,b);
}

unsigned lcm(std::list<unsigned> l){
  if (l.size() == 0){
    return 0;
  }
  else if(l.size() == 1){
    return l.front();
  }
  else if (l.size() == 2){
    unsigned a = l.front();
    l.pop_front();
    unsigned b = l.front();
    l.pop_front();
    return lcm(a, b);
  }
  else{
    unsigned a_0 = l.front();
    l.pop_front();
    unsigned a_1 = l.front();
    l.pop_front();
    unsigned b = lcm(a_0, a_1);
    l.push_front(b);
    return lcm(l);
  }
}
