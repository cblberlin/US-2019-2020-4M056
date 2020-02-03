#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <numeric>


using namespace std;

struct Fiche{
	string prenom;
	string ville;
	int age;
	double temps;
};


int main() {
	ifstream file("smalldata.txt");
	int n = 0;
	vector<Fiche> vdata;
	Fiche individu;
	while (file >> individu.prenom 
		        >> individu.ville 
		        >> individu.age 
		        >> individu.temps){
		++n;
		vdata.push_back(individu);
	}
	file.close();
	//1.3.2.a

	auto is_from_Lyon = [] (Fiche f) {
		return (f.ville == "Lyon");
	};
	int nb_Lyon = count_if(vdata.begin(), vdata.end(),is_from_Lyon);

	cout << "(a) Il y a " << nb_Lyon << " lyonnais.\n\n";

	//1.3.2.b
	int is_from_lyon_30=count_if(vdata.begin(), vdata.end(), [](Fiche f) { return ((f.ville=="Lyon")&&(f.age<30));});
    cout << "(b) Il y a " << is_from_lyon_30 << " lyonnais. moins de 30 ans.\n\n";


	//1.3.2.c
	bool existe = any_of(vdata.begin(), vdata.end(), [](Fiche f) {return ((f.ville == "Toulouse") && (f.age > 70));});
	if (existe) {
	cout << "(c) Il y a un toulousain plus de 70 ans.\n\n";
	}
	else {
	cout << "(c) Il n'y a pas un toulousain plus de 70 ans.\n\n";
	}

	//1.3.2.d
	auto result = minmax_element(vdata.begin(),vdata.end(), [](Fiche f1,Fiche f2) { return f1.age < f2.age; });

	cout << "(d) le plus âgé a " << result.second->age << " ans.\n\n"
		 << "son nom est " << result.second->prenom << ".\n\n"
		 << "le plus jeune a " << result.first->age << "ans.\n\n"
		 << "son nom est " << result.first->prenom << ".\n\n";

	//1.3.2.e
	double moyenne = accumulate(vdata.begin(), vdata.end(), 0, [](double s, Fiche f) {return s+f.age;});
	double variance = accumulate(vdata.begin(), vdata.end(), 0, [](double s, Fiche f) {return s+f.age*f.age;});
	moyenne /= double(n);
	variance /= double(n);
	variance -= moyenne*moyenne;
	cout << "(e) L'age moyenne est " << moyenne << " ans.\n\n"
	     << "L'écart-type est " << sqrt(variance) << " ans.\n\n"; 


	//1.3.2.f
	double moyenne_paris = accumulate(vdata.begin(), vdata.end(), 0., [](double s, Fiche f) -> double {return s + ((f.ville=="Paris")?f.temps: 0.);});
	auto is_from_Paris = [] (Fiche f) {
		return (f.ville == "Paris");
	};
	int nb_paris = count_if(vdata.begin(), vdata.end(), is_from_Paris);

	double moyenne_marseille = accumulate(vdata.begin(), vdata.end(), 0., [](double s, Fiche f) -> double {return s + ((f.ville=="Marseille")?f.temps: 0.);});
	auto is_from_marseille = [] (Fiche f) {
		return (f.ville == "Marseille");
	};
	int nb_marseille = count_if(vdata.begin(), vdata.end(), is_from_marseille);

	moyenne_paris /= nb_paris;
	moyenne_marseille /= nb_marseille;
	string adjectif = (moyenne_paris > moyenne_marseille)?"rapides":"lents";


	cout << "(f) Parisien ("<< moyenne_paris <<"s) sont plus " << adjectif << " que mareillais(" << moyenne_marseille <<"s) .\n\n";


	//1.3.2.g
	ofstream file2("toulousains_algo.txt");
	auto is_from_Toulouse = [&file2] (Fiche f) {
		if(f.ville == "Toulouse"){
			file2 << f.prenom <<"\t"
				  << f.ville <<"\t"
				  << 2018 - f.age <<"\t"
		    	  << f.temps
		    	  << endl;
		}
	};
    for_each(vdata.begin(), vdata.end(), is_from_Toulouse);
    file2.close();
	cout << "(g) Le fichier toulousains_algo est bien généré.\n\n";


    //1.3.2.h
    double age_moyenne_toulousain = accumulate(vdata.begin(), vdata.end(), 0., [] (double a, Fiche f) -> double {return a + ((f.ville == "Toulouse")?f.age: 0.);});

	double temps_moyenne_toulousain = accumulate(vdata.begin(), vdata.end(), 0., [] (double t, Fiche f) -> double {return t + ((f.ville == "Toulouse")?f.temps: 0.);});

	auto from_Toulouse = [] (Fiche f) {
		return (f.ville == "Toulouse");
	};
	int nb_toulouse = count_if(vdata.begin(), vdata.end(), from_Toulouse);

	double covariance = accumulate(vdata.begin(), vdata.end(), 0., [] (double c, Fiche f) -> double {return c + ((f.ville == "Toulouse")?(f.age*f.temps): 0.);});

	age_moyenne_toulousain /= nb_toulouse;
	temps_moyenne_toulousain /= nb_toulouse;
	covariance = covariance/nb_toulouse - (age_moyenne_toulousain*temps_moyenne_toulousain);

	cout << "(h) La covariance entre age et temps toulousain est " << covariance << " .\n\n";

	//1.3.2.i
	set<string> Villes;
	for_each(vdata.begin(), vdata.end(),[&Villes](Fiche f) {Villes.insert(f.ville);});

	cout << "(i) Les villes sont: " << endl; 
	for_each(Villes.begin(), Villes.end(), [] (string nom) {cout << nom << endl;});

	//1.3.3
	sort(vdata.begin(), vdata.end(), [](Fiche x, Fiche y) {return (x.temps < y.temps);});

	//sort(vdata.begin(), vdata.begin() + 100, [](Fiche x, Fiche y) {return (x.temps < y.temps);});


	ofstream file_tri("data_tri.txt");
	reverse(vdata.begin(), vdata.begin() + 100);
	for_each(vdata.begin(), vdata.begin() + 100, [&file_tri](Fiche f) {file_tri << f.prenom << "\t" << f.ville << "\t" << f.age << "\t" << f.temps << "\n";});
	file_tri.close();

	map<int, int> Histogramme;
	for_each(vdata.begin(), vdata.end(), [&Histogramme](Fiche f) {Histogramme[f.age]++;});
	cout << "Histoframme de age est : \n\n";
	for_each(Histogramme.begin(), Histogramme.end(), [](pair<int, int> v) {cout << "Age:  " << v.first << "\tnombre: " << v.second << "\n\n";});

	return 0;
}


