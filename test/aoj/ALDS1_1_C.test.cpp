#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/sieve_of_eratosthenes.hpp"

int main(){
	int N;
	cin >> N;

	SieveOfEratosthenes pr(100000000);

	int ans = 0;
	for(;N--;){
		int a;
		cin >> a;

		if(pr.is_prime(a)) ans++;
	}

	cout << ans << endl;

	return 0;
}
