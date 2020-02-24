#include "fonction.hpp"
#include <sstream>
#include <string>

std::ostream & operator << (std::ostream & out, const Fonction & f) {
  out << "La fonction " << f.fct << " a pour dérivée " << f.drv <<std::endl;
  return out;
}

Fonction::Fonction(unsigned n){
  if(n == 0){
    fct = "1";
    drv = "0";
  }

  else if (n == 1){
    fct = "(.)";
    drv = "1";
  }
  else{
    fct = "(.)^" + std::to_string(n);
    drv = std::to_string(n) + "*(.)^" + std::to_string(n-1);
  }
}

Fonction operator + (const Fonction & f, const Fonction & g){
  std::string partie_fct = "(" + f.fct + "+" + g.fct + ")";
  std::string partie_drv = "(" + f.drv + "+" + g.drv + ")";
  return Fonction(partie_fct, partie_drv);
}

Fonction operator * (const Fonction & f, const Fonction & g){
  std::string partie_fct = "(" + f.fct + "*" + g.fct + ")";
  std::string partie_drv = "((" + f.drv + "*" + g.fct + "))" + "+" + "((" + g.drv + "*" + f.fct + "))";
  return Fonction(partie_fct, partie_drv);
}

Fonction Fonction::operator - () const{
  return Fonction("-("+fct+")", "-("+drv+")");
}

Fonction operator - (const Fonction & f, const Fonction & g){
  std::string partie_fct = "(" + f.fct + "-" + g.fct + ")";
  std::string partie_drv = "(" + f.drv + "-" + g.drv + ")";
  return Fonction(partie_fct, partie_drv);
}

Fonction operator * (double a, const Fonction & f){
  std::string partie_fct = std::to_string(a)+"*" + f.fct;
  std::string partie_drv = std::to_string(a)+"*" + f.drv;
  return Fonction(partie_fct, partie_drv);
}

std::string subst(const std::string & fct, const std::string & nvar){
  std::string s = "";
  for(int i = 0; i < fct.size(); ++i){
    if(fct[i] == '.'){
      s.push_back(fct[i]);
    }
    else{
      s.append(nvar);
    }
  }
  return s;
}

std::string subst2(const std::string & fct, const std::string & n_var){
  std::stringstream ss;
  auto replace = [&](char c){
    if(c == '.'){
      ss << n_var;
    }
    else{
      ss << c;
    }
  };
  std::for_each(fct.begin(), fct.end(), replace);
  return ss.str();
}

Fonction Fonction::rond(const Fonction & g) const{
  std::string f_rond_g = subst(fct, g.fct);
  std::string f_rond_g_drv = "("+g.drv+")*("+subst(drv,g.fct)+")";
  return Fonction(f_rond_g, f_rond_g_drv);
}
