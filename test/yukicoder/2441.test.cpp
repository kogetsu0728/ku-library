#define PROBLEM "https://yukicoder.me/problems/no/2441"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/matrix.hpp"

int main() {
	vector<vector<int>> M(2, vector<int>(2));
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			cin >> M[i][j];
		}
	}

	Matrix<int> mat1(M), mat2(2, 2);
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			mat2.set(i, j, M[i][j]);
		}
	}

	assert(mat1 == mat2);

	mat1 = mat1.pow(3);

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			if(j) cout << ' ';
			cout << mat1.get(i, j);
		}
		cout << endl;
	}

	return 0;
}
