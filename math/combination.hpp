#pragma once

template<class T>
class Combination{
	private:
		vector<T> fac, ifac;

	public:
		Combination():Combination(0){}
		Combination(int _n):
			fac(_n+1,1),ifac(_n+1,1){
				for(int i=0; i<=_n; i++) fac[i+1] = fac[i]*(i+1);
				ifac[_n] = 1/fac[_n];
				for(int i=_n+1; i>0; i--) ifac[i-1] = ifac[i]*i;
			}

		T p(int a, int b){ 
			if(b<0 || a<b) return 0;
			return fac[a]*ifac[a-b];
		}

		T c(int a, int b){
			if(b<0 || a<b) return 0;
			return p(a,b)*ifac[b];
		}

		T h(int a, int b){
			if(a==0 && b==0) return 1;
			if(a<=0 || b<0) return 0;
			return c(a+b-1, b);
		}
};
