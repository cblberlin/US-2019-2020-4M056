#include <iostream>

int main(){
  enum Mois {Janvier = 1, Fevrier, Mars, Avril, Mai, Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre};
  Mois vacance_hiver = Janvier;
  Mois vacance_ete = Juin;
  std::cout << vacance_hiver << std::endl;
  std::cout << vacance_ete << std::endl;

  return 0;
}
