#pragma once

template<class T> class Fraction{
	private:
		T num, den;
		Fraction<T> &reduce(){
			assert(den!=0);
			if(num==0){
				den = 1;
			}else{
				if(den<0){ num *= -1, den *= -1; }
				T div = gcd(abs(num), den);
				num /= div, den /= div;
			}
			return *this;
		}

	public:
		Fraction(const T _num=0, const T _den=1):
			num(_num), den(_den){
				reduce();
			}

		T numer() const { return num; }
		T denom() const { return den; }
		long double val() const { return (long double)num/den; }

		bool operator<(const Fraction<T> &rhs) const {
			return num*rhs.denom() < rhs.numer()*den;
		}
		bool operator>(const Fraction<T> &rhs) const {
			return num*rhs.denom() > rhs.numer()*den;
		}
		bool operator==(const Fraction<T> &rhs) const {
			return num*rhs.denom() == rhs.numer()*den;
		}

		Fraction<T> &operator+=(const Fraction<T> &rhs){
			num = num*rhs.denom() + rhs.numer()*den;
			den = den*rhs.denom();
			return reduce();
		}
		Fraction<T> operator+(const Fraction<T> &rhs) const {
			return Fraction(*this) += rhs;
		}
		Fraction<T> operator+() const {
			return Fraction(*this);
		}

		Fraction<T> &operator-=(const Fraction<T> &rhs){
			num = num*rhs.denom() - rhs.numer()*den;
			den = den*rhs.denom();
			return reduce();
		}
		Fraction<T> operator-(const Fraction<T> &rhs) const {
			return Fraction(*this) -= rhs;
		}
		Fraction<T> operator-() const {
			return Fraction()-Fraction(*this);
		}

		Fraction<T> &operator*=(const Fraction<T> &rhs){
			num = num*rhs.numer();
			den = den*rhs.denom();
			return reduce();
		}
		Fraction<T> operator*(const Fraction<T> &rhs) const {
			return Fraction(*this) *= rhs;
		}

		Fraction<T> &operator/=(const Fraction<T> &rhs){
			num = num*rhs.denom();
			den = den*rhs.numer();
			return reduce();
		}
		Fraction<T> operator/(const Fraction<T> &rhs) const {
			return Fraction(*this) /= rhs;
		}

		friend ostream& operator<<(ostream& os, const Fraction &rhs){
			os << rhs.val();
			return os;
		}
};
