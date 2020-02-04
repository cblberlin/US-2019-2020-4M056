#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <chrono>
#include <Eigen/Eigenvalues>
#include </usr/include/eigen3/unsupported/Eigen/MatrixFunctions>

using namespace Eigen;
using namespace std;

typedef Matrix<double, Dynamic, Dynamic> MatrixDouble;
typedef SparseMatrix<double> SparseDouble;

// 2.1
MatrixDouble puissance(const MatrixDouble & M, int n){
		if(n==0){
			return MatrixDouble::Identity(M.rows(),M.cols());
		}
		else if (n==1){
			return M;
		}
		else{
			MatrixDouble N = puissance(M, n-1);
			return M*N;
		}
	}
// 2.3
MatrixDouble puissanceB(const MatrixDouble M, int n){
		if(n==0){
			return MatrixDouble::Identity(M.rows(),M.cols());
		}
		else if (n==1){
			return M;
		}
		else{
			MatrixDouble N = puissance(M, n-1);
			return M*N;
		}
	}
// 2.4
MatrixDouble puissance2(const MatrixDouble & M, int n){
	if(n == 0){
		return MatrixDouble::Identity(M.rows(), M.cols());
	}
	else if (n%2 == 0){
		MatrixDouble N = puissance2(M, n/2);
		return N*N;
	}
	else{
		MatrixDouble N = puissance2(M, (n-1)/2);
		return M*N*N;
	}
}

// 2.6
SparseDouble puissance_sparse(const SparseDouble & M, int n){
	if(n == 0){
		SparseDouble identity(M.rows(), M.cols());
		identity.setIdentity();
		return identity;
	}
	else if(n == 1){
		return M;
	}
	else if(n % 2 == 0){
		SparseDouble N(M.rows(), M.cols());
		N = puissance_sparse(M, n/2);
		return N*N;
	}
	else{
		SparseDouble N(M.rows(), M.cols());
		N = puissance_sparse(M, (n-1)/2);
		return M*N*N;
	}
}

// 2.8
MatrixDouble crochet_lie(const MatrixDouble & A, const MatrixDouble & B){
	return A*B - B*A;
}

// 2.9
pair<double, double> f(const MatrixDouble & X, const MatrixDouble & Y){
	MatrixDouble M_A(X.rows(), X.cols());
	MatrixDouble M_B(X.rows(), X.cols());
	MatrixDouble somme(X.rows(), X.cols());
	MatrixDouble produit(X.rows(), X.cols());
	somme = X + Y;
	produit = X.exp()*Y.exp();
	M_A = produit - somme.exp();
	M_B = produit - (somme + 0.5*crochet_lie(X,Y)).exp();
	pair<double, double> result;
	result.first = M_A.norm();
	result.second = M_B.norm();
	return result;
}



int main(){
	int n = 10000;
	// 2.2
	Matrix <double, 3, 3> A;
	A << 0.4, 0.6, 0.,
		 0.75, 0.25, 0.,
		 0., 0., 1.;
	cout << "A = \n\n" << A << ".\n\n";
	cout << "A^10000 = \n\n" << puissance(A, n) << ".\n\n";

	// 2.3
	chrono::time_point<chrono::system_clock> start, end;
	start = chrono::system_clock::now();
	puissance(A,n);
	end = chrono::system_clock::now();

	chrono::time_point<chrono::system_clock> start2, end2;
	start2 = chrono::system_clock::now();
	puissanceB(A,n);
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

	// 2.5
	auto t1 = chrono::system_clock::now();
	puissance2(M,n);
	auto t2 = chrono::system_clock::now();
	chrono::duration<double> diff = t2 - t1;
	cout << "Pour calculer M puissance 10000 en utilisant puissance2 ça prend: \n" << endl << diff.count() << "s."<<endl;

	//2.6
	SparseDouble M2(M.rows(),M.cols());
	double c;
	for (int i = 0; i < M.rows(); ++i){
		for (int j = 0; j < M.cols();++j){
			c = M(i,j);
			if(c != 0){
			M2.coeffRef(i,j) = c;
			}
		}
	}

	auto t3 = chrono::system_clock::now();
	puissance(M,n);
	auto t4 = chrono::system_clock::now();
	chrono::duration<double> diff2 = t4 - t3;
	cout << "Pour calculer M puissance 10000 en utilisant puissance ça prend: \n" << endl << diff2.count() << "s."<<endl;

	auto t5 = chrono::system_clock::now();
	puissance_sparse(M2, n);
	auto t6 = chrono::system_clock::now();
	chrono::duration<double> diff3 = t6 - t5;
	cout << "Pour calculer M puissance 10000 en utilisant puissance_sparse ça prend: \n" << endl << diff3.count() << "s."<<endl;

	//2.10
	//Initialisation

	mt19937 G(time(NULL));
	uniform_real_distribution<double> Loi(-100,100);
	int nb_simulation = 1000;
	double s_x = 0.0;
	double s_y = 0.0;
	pair<double, double> result;
	MatrixDouble X = MatrixDouble::Zero(3,3);
	MatrixDouble Y = MatrixDouble::Zero(3,3);
	//cout << Loi(G) << endl;
	//Simulation
	for(int i = 0; i < nb_simulation; ++i){
		X(0,1) = Loi(G);
		X(0,2) = Loi(G);
		X(1,2) = Loi(G);
		Y(0,1) = Loi(G);
		Y(0,2) = Loi(G);
		Y(1,2) = Loi(G);
		result = f(X,Y);
		s_x += result.first;
		s_y += result.second;
	}
	//cout << result.first << endl;
	//cout << result.second << endl;
	cout << "moyenne de M_A est: " << s_x/double(nb_simulation) <<endl;
	cout << "moyenne de M_B est: " << s_y/double(nb_simulation) <<endl;

	//2.11
	//créer une histogramme
	const int M = 20;
	vector<double> hist(M,0);
	//loi sur le diag et hor diag
	normal_distribution<double> Loi1(0,1);
	normal_distribution<double> Loi2(0,2);
	//GOE, calculer les valeurs propres
	MatrixDouble GOE(150, 150);
	for(int i = 0, i < 150; ++i){
		GOE(i,i) = Loi1(G);
		for(int j = i + 1, j < 150; ++j){
			GOE(i,j) = Loi2(G);
			GOE(j,i) = GOE(i,j);
		}
	}
	EigenSolver<MatrixDouble> Solver(M);

	


	return 0;
}
