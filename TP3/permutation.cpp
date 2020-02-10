#include "permutation.hpp"
#include <iostream>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

Permutation Permutation::extend(unsigned m) const{
	if(m < size()){
		cout << "m must be greater than n" << endl;
		return Permutation(images);
	}
	else{
		Permutation p(m);
		for(unsigned i = 0; i < size(); ++i){
			p[i] = images[i];
		}
	}
	return p;
}

unsigned & Permutation::operator[] (unsigned i){return images[i];}

unsigned Permutation::size() const {
	return n;
}

vector<unsigned> Permutation::image(){
	return images;
}

Permutation::Permutation(unsigned _n):
	n(_n), images(_n)
{
	for(unsigned i = 0; i < _n; ++i){
		images[i] = i;
	}
}


Permutation::Permutation(const vector <unsigned> &v):
	n(v.size()), images(v)
{
	for(unsigned i = 0; i < v.size(); i++){
		images[i] = v[i];
	}
}

unsigned Permutation::operator[](unsigned i) const {
	return images[i];
}

//Permutation::Permutation()
ostream & operator<<(ostream & o, const Permutation &p){
	o << p.n << endl;
	for (unsigned i = 0; i < p.n; i++){
		o << p.images[i] << " ";
	}
	o << endl;
	return o;
}










