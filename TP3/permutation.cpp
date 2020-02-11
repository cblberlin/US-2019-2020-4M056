#include "permutation.hpp"
#include <iostream>
#include <algorithm>
#include <set>
#include <list>

using namespace std;

// 3.3 create a identity permutaion and a permutation from a vector and from a flux
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

Permutation::Permutation(istream & flux){
	flux >> n;
	images.resize(n);
	for(unsigned i = 0; i < n; ++i){
		flux >> images[i];
	}
}


// 3.4 access size and access and modifier of i-th element of permutaion
unsigned Permutation::size() const {
	return n;
}
// accessor of i-th element of images
unsigned Permutation::operator[](unsigned i) const {
	return images[i];
}
// modifier of i-th element of images
unsigned & Permutation::operator[](unsigned i) {
	return images[i];
}

// 3.5 private method of extend
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
		return p;
	}
}

// 3.6 operator multiplication of 2 PERMUTATIONS_CYCLES
Permutation operator*(const Permutation & p1, const Permutation & p2){
	if(p1.size() != p2.size()){
		unsigned m = max(p1.size(), p2.size());
		return p1.extend(m) * p2.extend(m);
	}

	Permutation p(p1.size());
	for(unsigned i = 0; i < p1.size(); ++i){
		p[i] = p1[p2[i]];
	}
	return p;
}

// 3.7 read the permutation and print it in terminal
ostream & operator<<(ostream & out, const Permutation &p){
	out << p.n << endl;
	for (unsigned i = 0; i < p.n; i++){
		out << p.images[i] << " ";
	}
	out << endl;
	return out;
}

// 3.8 fixed points list
list<unsigned> Permutation::fixed_points_list() const{
	list<unsigned> l_fixed_points;
	for(unsigned i = 0; i < n; i++){
		if(i == images[i]){
			l_fixed_points.push_back(i);
		}
	}
	return l_fixed_points;
}
// fixed points vector
vector<unsigned> Permutation::fixed_points_vector() const{
	vector<unsigned> v_fixed_points;
	for(unsigned i = 0; i < n; i++){
		if(i == images[i]){
			v_fixed_points.push_back(i);
		}
	}
	return v_fixed_points;
}

// 3.9 inverse of Permutation
Permutation Permutation::inverse() const{
	Permutation inv(n);
	for(unsigned i = 0; i < size(); ++i){
		inv[images[i]] = i;
	}
	return inv;
}

// 3.10 constructor of cycle from a list copied from elem
Cycle::Cycle(list <unsigned> l):
	elem(l)
{

}

unsigned Cycle::order() const{
	return elem.size();
}
