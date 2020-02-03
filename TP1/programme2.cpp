#include <iostream>
#include <fstream>

int main() {
    int n;
    std::cout << "Entrez un nombre entier <100:" << std::endl;
    std::cin >> n;
    //std::vector <int> tableau(n);
    int tableau[100];
    for(int i = 0; i < n; i++) {
        tableau[i] = i*i;
    }

    std::ofstream fichier("donnees_crois.dat");
    fichier << "Voici les carrés des entiers:" << std::endl;
    for(int i = 0; i < n; i++) {
        fichier << i <<": " <<tableau[i] << std::endl;
    }
    fichier.close();

    std::ofstream fichier2("donnees_crois_cube.dat");
    fichier2 << "Voici les carrés et cubes des entiers:" << std::endl;
    for(int i = 0; i < n; i++) {
        fichier2 << i <<": " <<tableau[i] << " "<< tableau[i]*i << std::endl;
    }
    fichier2.close();

    std::ofstream fichier3("donnees_decrois.dat");
    fichier3 << "Voici les carrés des entiers dans l'ordre décroissante:" << std::endl;
    for(int i = n-1; i >= 0; i--) {
        fichier3 << i <<": " <<tableau[i] << std::endl;
    }
    fichier3.close();
    return 0;
}




