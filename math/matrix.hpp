#pragma once

template<class T> class Matrix{
	private:
		int ro, co;
		vector<vector<T>> vec;
	public:
		Matrix(int _ro, int _co, T _e=0):
			ro(_ro), co(_co), vec(_ro,vector<T>(_co,_e)){}

		int row() const { return ro; }
		int col() const { return co; }

		vector<T> operator[](int i) const {
			return vec[i];
		}
		vector<T> &operator[](int i){
			return vec[i];
		}

		Matrix<T> &operator*=(const Matrix<T> &rhs){
			assert(ro==co && rhs.row()==rhs.col() && co==rhs.col());
			return *this = (*this)*rhs;
		}
		Matrix<T> operator*(const Matrix<T> &rhs) const {
			assert(co==rhs.row());
			Matrix<T> res(ro, rhs.col());
			for(int i=0; i<ro; i++){
				for(int j=0; j<rhs.col(); j++){
					for(int k=0; k<co; k++){
						res[i][j] += vec[i][k]*rhs[k][j];
					}
				}
			}
			return res;
		}

		Matrix<T> pow(long long n) const {
			assert(ro==co);
			Matrix<T> res(ro, co);
			for(int i=0; i<ro; i++){
				res[i][i] = 1;
			}
			Matrix<T> x = *this;
			while(n){
				if(n&1) res *= x;
				x *= x;
				n >>= 1;
			}
			return res;
		}
};
