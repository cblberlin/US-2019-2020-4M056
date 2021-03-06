#ifndef PERMUTATIONS_CYCLES
#define PERMUTATIONS_CYCLES

#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <algorithm>

using namespace std;

class Permutation;
class Cycle;

class Permutation{
private:
  // Constructeurs prenant en argument
  // taille de la permutation
  unsigned n;
  vector<unsigned> images;
  // 3.4 mutate the element of images
  unsigned & operator[](unsigned i);
  // extend n to m (m is greater than n)
  Permutation extend(unsigned m) const;

public:
  // constructor empty
  Permutation() = default;
  // return identity permutation
  Permutation(unsigned);
  // return permutation from a vector defined
  Permutation(const vector <unsigned> &);
  // 3.17 from a file
  Permutation(istream &);
  // return size of permutation
  /*unsigned size() const{
    return n;
  }*/
  // up there works as well
  // 3.4 return size of permutation
  unsigned size() const;

  // acces by index i
  unsigned operator[](unsigned) const;

  // 3.6 operator multiplication of 2 permutaions
  friend Permutation operator*(const Permutation &, const Permutation &);

  // 3.7 print the permutation at terminal
  friend ostream & operator<<(ostream &, const Permutation &);

  // 3.8 list of fixed points
  list<unsigned> fixed_points_list() const;
  // vector of fixed points
  vector<unsigned> fixed_points_vector() const;
  // 3.9 inverse of permutaion
  Permutation inverse() const;
  // 3.12 cycles
  list <Cycle> cycles() const;

  template <typename T> 
};
// 3.10 constructor of cycle with elem as private member and public constructor
// and order

class Cycle{
private:
  list <unsigned> elem;
public:
  Cycle(list <unsigned>);
  unsigned order() const;
};


#endif
