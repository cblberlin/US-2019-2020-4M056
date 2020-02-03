#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <chrono>
#include <Eigen/Eigenvalues>

using namespace Eigen;
using namespace std;

typedef Matrix<double, Dynamic, Dynamic> MatrixDouble;

// 2.1
MatrixDouble puissance(const MatrixDouble & M, int n){
		if(n==0){
			return MatrixDouble::Identity(M.rows(),M.cols());
		}
		else if (n==1){
			return M;
		}
		else{
			MatrixDouble N(M.rows(), M.cols());
			N = puissance(M, n-1);
			return M*N;
		}
	}
	
MatrixDouble puissanceB(const MatrixDouble M, int n){
		if(n==0){
			return MatrixDouble::Identity(M.rows(),M.cols());
		}
		else if (n==1){
			return M;
		}
		else{
			MatrixDouble N(M.rows(), M.cols());
			N = puissance(M, n-1);
			return M*N;
		}
	}

MatrixDouble puissance2(const MatrixDouble & M, int n){
	if(n == 0){
		return MatrixDouble::Identity(M.rows(), M.cols());
	}
	else if (n%2 == 0){
		return puissance2(M, n/2)*puissance2(M,n/2);
	}
	else{
		return M*puissance2(M,(n-1)/2)*puissance2(M,(n-1)/2);
	}
}

int main(){
	// 2.2
	Matrix <double, 3, 3> A;
	A << 0.4, 0.6, 0.,
		 0.75, 0.25, 0.,
		 0., 0., 1.;
	cout << "A = \n\n" << A << ".\n\n";
	cout << "A^100 = \n\n" << puissance(A, 100) << ".\n\n";
	
	// 2.3
	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();
	puissance(A,100);
	end = chrono::system_clock::now();
	
	chrono::time_point<chrono::system_clock> start2, end2;
	start2 = chrono::system_clock::now();
	puissanceB(A,100);
	end2 = chrono::system_clock::now();
	
	auto executed_time1 = chrono::duration<double>(end - start).count();
	auto executed_time2 = chrono::duration<double>(end2 - start2).count();
	
	cout << "Avec & on a utilisé " << executed_time1 << " secondes" << "\n\n";
	cout << "Sans & on a utilisé " << executed_time2 << " secondes" << "\n\n";
	
	ifstream o("matrice.dat");
	MatrixDouble M(30,30);
	for (int i = 0; i < 30; ++i){
		for (int j = 0; j < 30; ++j){
			o >> M(i,j);
		}		
	}
	cout << "M est: \n" << M << "\n\n";
	
	puissance2(M,1000);
	cout << "M puissance 1000 " << endl << M <<endl;
	
	return 0;
}












