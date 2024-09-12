#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
using namespace atcoder;

#include "../../math/binomial.hpp"

int main(){
	int T, M;
	cin >> T >> M;

	modint::set_mod(M);

	Binomial<modint> bin(min(M-1, 10000000));

	for(;T--;){
		int n, k;
		cin >> n >> k;

		cout << bin.c(n, k).val() << '\n';
	}

	return 0;
}
