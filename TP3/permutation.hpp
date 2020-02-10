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
  vector<unsigned int> im;

public:
  // renvoie le taille d'une permutaion
  unsigned size() const{
    return n;
  }


};
