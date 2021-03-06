#include "permutation.hpp"
#include "arithm.hpp"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <vector>
#include <random>

using namespace std;

int main(){
  // première partie
  // test empty constructor
  cout << endl;
  cout << "Première partie:" << endl;
  vector <unsigned int> v = {2,4,5,3,1,0};
  Permutation a(v);
  Permutation b(6);

  // test print permutation
  // cout << a << endl;
  // cout << b << endl;

  for(unsigned i = 0; i <=  6; i++){
    cout << "a^" << i << endl << b << '\n';
    b = b*a;
  }

  list <unsigned> fp = a.fixed_points_list();
  vector <unsigned> fp_v = a.fixed_points_vector();
  auto affiche = [](unsigned x) {cout << x << "\t";};
  for_each(fp.begin(), fp.end(), affiche);
  cout << endl;
  //for_each(fp_v.begin(), fp_v.end(), affiche);
  //cout << endl;

  // test inverse
  //Permutation inv_c = c.inverse();
  // cout << a.inverse() << endl;

  // deuxième partie
  ifstream fichier_s("file_s.dat");
  ifstream fichier_t("file_t.dat");
  Permutation s(fichier_s);
  Permutation t(fichier_t);
  fichier_s.close();
  fichier_t.close();

  Cycle c(list <unsigned> {1,2,3});
  cout << "order of c is: " <<c.order() << endl;

  cout << "test gcd of 2 unsigned: " << gcd(30, 6) << endl;

  cout << "test gcd of a list: " << gcd(list <unsigned> {3,6,9}) << endl;

  cout << "test lcm of 2 unsigned: " << lcm(5, 6) << endl;

  cout << "test lcm of a list: " << lcm(list <unsigned> {3,6,9}) << endl;

  cout << "test cycles of permutaion: " << v.cycles() << endl;
  // cout << s << endl;
/*
  Permutation u = s*t.inverse();
  cout << "L'ordre de la permutaion s*t^-1 est égal à " << u.order() << endl;


  list<Cycle> l = u.cycles();
  cout << "Cette permutaion a " << l.size() << "cycles, dont le plus grand a pour longeur "
       << (max_element(l.begin(), l.end())).size() << endl;
*/
  /*
  // Troisième partie
  mt19937 g;
  unsigned n = 100;
  unsigned nb_echant = 10000;
  unsigned nb_derang = 0;
  for(unsigned i = 0; i < nb_echant; ++i){
    nb_derang += Permutation(n,g).is_derangement();
  }
  cout << "La proportion de dérangement est environ " << nb_derang/double(nb_echant) << endl;
  */
  return 0;
}
