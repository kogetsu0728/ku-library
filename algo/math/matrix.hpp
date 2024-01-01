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

		Matrix<T> &operator+=(const Matrix<T> &rhs){
			assert(ro==rhs.row() && co==rhs.col());
			for(int i=0; i<ro; i++){
				for(int j=0; j<co; j++){
					vec[i][j] += rhs[i][j];
				}
			}
			return *this;
		};
		Matrix<T> operator+(const Matrix<T> &rhs) const {
			return Matrix(*this) += rhs;
		}
		Matrix<T> operator+() const {
			return Matrix(*this);
		}
		Matrix<T> &operator+=(T rhs){
			for(int i=0; i<ro; i++){
				for(int j=0; j<co; j++){
					vec[i][j] += rhs;
				}
			}
			return *this;
		}
		Matrix<T> operator+(T rhs) const {
			return Matrix(*this) += rhs;
		}

		Matrix<T> &operator-=(const Matrix<T> &rhs){
			assert(ro==rhs.row() && co==rhs.col());
			for(int i=0; i<ro; i++){
				for(int j=0; j<co; j++){
					vec[i][j] -= rhs[i][j];
				}
			}
			return *this;
		}
		Matrix<T> operator-(const Matrix<T> &rhs) const {
			return Matrix(*this) -= rhs;
		}
		Matrix<T> operator-() const {
			return Matrix(ro, co)-Matrix(*this);
		}

		Matrix<T> &operator-=(T rhs){
			return *this += -rhs;
		}
		Matrix<T> operator-(T rhs) const {
			return Matrix(*this) -= rhs;
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

		Matrix<T> &operator*=(T rhs){
			for(int i=0; i<ro; i++){
				for(int j=0; j<co; j++){
					vec[i][j] *= rhs;
				}
			}
			return *this;
		}
		Matrix<T> operator*(T rhs) const {
			return Matrix(*this) *= rhs;
		}

		Matrix<T> &operator/=(T rhs){
			for(int i=0; i<ro; i++){
				for(int j=0; j<co; j++){
					vec[i][j] /= rhs;
				}
			}
			return *this;
		}
		Matrix<T> operator/(T rhs) const {
			return Matrix(*this) /= rhs;
		}

		bool operator==(const Matrix<T> &rhs) const {
			if(ro!=rhs.row() || co!=rhs.col()){
				return false;
			}
			bool res = true;
			for(int i=0; i<ro; i++){
				for(int j=0; j<co; j++){
					if(vec[i][j]!=rhs[i][j]) res = false;
				}
			}
			return res;
		}

		Matrix<T> pow(long long rhs) const {
			assert(ro==co);
			Matrix<T> res(ro, co);
			for(int i=0; i<ro; i++){
				res[i][i] = 1;
			}
			Matrix<T> x = *this;
			long long n = rhs;
			while(n){
				if(n&1) res *= x;
				x *= x;
				n >>= 1;
			}
			return res;
		}

		Matrix<T> rot(const long long rhs) const {
			int n = 0;
			if(0<=rhs) n = rhs%4;
			else n = (4-abs(rhs)%4)%4;
			Matrix<T> res = *this;
			for(int i=0; i<n; i++){
				Matrix<T> tmp(res.col(), res.row());
				for(int i=0; i<res.row(); i++){
					for(int j=0; j<res.col(); j++){
						tmp[j][res.row()-1-i] = res[i][j];
					}
				}
				swap(res,tmp);
			}
			return res;
		}
};
