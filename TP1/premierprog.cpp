#include <iostream>
#include <cmath>

double aire_du_cercle(double x) {return M_PI*x*x;}

double aire_du_carre(double x) {return x*x;}

int main() {
    double r;
    double a; 

    std::cout << "Entrez le rayon du cercle: " << std::endl;
    std::cin >> r;
    std::cout << "Son aire est " << aire_du_cercle(r) << std::endl;

    std::cout << "Entrez la longeur du carre: " << std::endl;
    std::cin >> a;
    std::cout << "Son aire est " << aire_du_carre(a) << std::endl;

    return 0;
}


