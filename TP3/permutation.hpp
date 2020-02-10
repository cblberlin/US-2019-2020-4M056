#ifndef PERMUTATIONS_CYCLES
#define PERMUTATIONS_CYCLES

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <algorithm>

using namespace std;

class Permutation{
private:
  // Constructeurs prenant en argument
  // taille de la permutation
  unsigned n;
  // un vecteur representant la seconde ligne du tableau
  vector<unsigned> images;
  
  // mutata the element of images
  unsigned & operator[](unsigned i);
  // extend n par m
  Permutation extend(unsigned m) const;
  
public:
  // return size of permutation
  /*unsigned size() const{
    return n;
  }*/
  // return size of permutation
  unsigned size() const;
  
  // mutate the value of images
  unsigned & operator=(unsigned i);
  
  // return identity permutation
  Permutation(unsigned _n);
  
  // return permutation from a vector defined
  Permutation(const vector <unsigned> &v);
  
  // acces by index
  unsigned operator[](unsigned i) const;
  
  // print the permutation at terminal
  friend ostream & operator<<(ostream &, const Permutation &);
  
  
  
};

  





#endif
