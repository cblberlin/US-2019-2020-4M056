#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <cmath>

using namespace std;

struct Fiche{
	string prenom;
	string ville;
	int age;
	double temps;
};

int main(){
	const int N = 2500;
	// ouvrir le fichier
	ifstream fichier("smalldata.txt");

	// stocker les fiches
	vector<Fiche> vdata(N);

	for(int i=0; i< N; ++i) {
        fichier
            >> vdata[i].prenom
            >> vdata[i].ville
            >> vdata[i].age
            >> vdata[i].temps;
    }

	fichier.close();

	//3.a
	int nb_lyon = 0;
	for (int i = 0; i < N; ++i){
		if(vdata[i].ville == "Lyon") {
			++nb_lyon;
		}
	}
	cout << "(a) "<< nb_lyon << " personnes habitent à Lyon.\n\n";

	//3.B
	int nb_lyon_30 = 0;
	for (int i = 0; i < N; ++i){
		if((vdata[i].ville == "Lyon") && (vdata[i].age < 30))
			++nb_lyon_30;
	}
	cout << "(b) "<< nb_lyon_30 << " personnes habitent à Lyon et moins de 30 ans.\n\n";

	//3.c
	bool existe = false;
	for (int i = 0; i < N; ++i){
		if ((vdata[i].ville == "Toulouse") && (vdata[i].age > 70)){
			existe = true;
		}
	}

	if (existe){
		cout << "(c) Il existe un toulousain qui a plus de 70 ans.\n\n";
	}
	else{
		cout << "(c) Il n'existe pas un toulousain qui a plus de 70 ans.\n\n";
	}

	//3.d
	int indice_min = 0;
	int indice_max = 0;
	for(int i = 0; i < N; ++i){
		if(vdata[i].age > vdata[indice_max].age){
			indice_max = i;
		}
		if(vdata[i].age < vdata[indice_min].age){
			indice_min = i;
		}
	}
	cout << "(d) Le plus âgé a " << vdata[indice_max].age <<" ans, "<< "son prenom est " << vdata[indice_max].prenom 
		 << " le plus jeune a " << vdata[indice_min].age << "ans, " << "son prenom est " << vdata[indice_min].prenom << ".\n\n";


	//3.e
	double moyenne = 0;
	double variance = 0;
	for (int i = 0; i < N; ++i){
		moyenne += vdata[i].age;
		variance += vdata[i].age*vdata[i].age;
	}

	moyenne /= double(N);
	variance /= double(N);
	variance -= moyenne*moyenne;
	cout << "(e) L'age moyen est " << moyenne << " ans.\n\n";
	cout << "(e) La variance est " << sqrt(variance) << " ans.\n\n";

	//3.f
	double moyenne_paris = 0;
	int nb_paris = 0;
	double moyenne_marseille = 0;
	int nb_marseille = 0;
	for (int i = 0; i < N; ++i) {
		if (vdata[i].ville == "Paris"){
			moyenne_paris += vdata[i].temps;
			++nb_paris;
		}
		else if (vdata[i].ville == "Marseille") {
			moyenne_marseille += vdata[i].temps;
			++nb_marseille;
		}
	}
	moyenne_paris /= double(nb_paris);
	moyenne_marseille /= double(nb_marseille);
	if(moyenne_paris > moyenne_marseille){
		cout << "(f) Parisien ("<< moyenne_paris <<") sont plus rapide que mareillais " << moyenne_marseille <<" .\n\n";
	}
	else {
		cout << "(f) Parisien ("<< moyenne_paris <<") sont plus lent que mareillais " << moyenne_marseille <<" .\n\n";
	}

	//3.g h
	ofstream file2("toulousains.txt");
	double age_moyenne_toulousain = 0;
	double temps_moyenne_toulousain = 0;
	double covariance = 0;
	int nb_toulousain = 0;

	for (int i = 0; i < N; ++i){
		if(vdata[i].ville == "Toulouse"){
			file2 << vdata[i].prenom <<"\t"
				  << vdata[i].ville <<"\t" 
				  << 2018 - vdata[i].age <<"\t"
				  << vdata[i].temps
				  << endl;
			++nb_toulousain;
            temps_moyenne_toulousain += vdata[i].temps;
            age_moyenne_toulousain += vdata[i].age;
            covariance += vdata[i].age * vdata[i].temps;
		}
	}
	file2.close();
	covariance = covariance/nb_toulousain - (temps_moyenne_toulousain/nb_toulousain)*(age_moyenne_toulousain/nb_toulousain);

	cout << "(g) le fichier est généré.\n\n" 
		 << "(h) la covariance est " << covariance << " .\n\n";


	//3.i
	set<string> Villes;
	for(int i = 0; i < N; ++i) {
		Villes.insert(vdata[i].ville);
	}
	cout << "(i) les villes sont: " << endl;
	for (set<string>::iterator i = Villes.begin(); i != Villes.end(); i++) {
    cout << *i << endl;
}
	return 0;
}





