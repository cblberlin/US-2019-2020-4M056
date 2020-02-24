#ifndef FONCTIONS_HPP
#define FONCTIONS_HPP

#include <string>
#include <iostream>

class Fonction{
private:
  std::string fct;
  std::string drv;
public:
  Fonction(std::string);//: fct(nom + "(.)"), drv(nom + "'(.)") {}

  Fonction(std::string nom, std::string derivee);//: fct(nom+"(.)"), drv(derivee+"(.)") {}

  Fonction(unsigned n);

  std::string derivee() const {return drv;}

  friend std::ostream & operator << (std::ostream &, const Fonction &);

  friend Fonction operator + (const Fonction &, const Fonction &);

  friend Fonction operator * (const Fonction &, const Fonction &);

  Fonction operator - () const;

  friend Fonction operator - (const Fonction &, const Fonction &);

  friend Fonction operator * (double, const Fonction &);

  Fonction rond(const Fonction &) const;
};

std::string subst (const std::string & fct, const std::string & new_var);

std::string subst2 (const std::string & fct, const std::string & new_var);



#endif
