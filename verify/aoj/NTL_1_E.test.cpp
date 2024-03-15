#include <bits/stdc++.h>
using namespace std;

#include "../../math/ext_gcd.hpp"

int main(){
	long long a, b; cin >> a >> b;

	long long x, y;
	ext_gcd(a, b, x, y);
	cout << x << ' ' << y << endl;
}
