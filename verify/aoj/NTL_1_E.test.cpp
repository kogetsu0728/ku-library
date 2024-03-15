#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include <bits/stdc++.h>
using namespace std;

#include "../../math/ext_gcd.hpp"

int main(){
	long long a, b; cin >> a >> b;

	long long x, y;
	ext_gcd(a, b, x, y);
	cout << x << ' ' << y << endl;
}
