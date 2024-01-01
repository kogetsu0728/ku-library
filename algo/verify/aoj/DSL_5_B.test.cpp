#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B"

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "../../data_structure/cumulative_sum_2d.hpp"

int main(){
	int N;
	cin >> N;
	vector<long long> x1(N), y1(N), x2(N), y2(N);
	for(int i=0; i<N; i++){
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}

	CumulativeSum2d<long long> cs(1001, 1001);
	for(int i=0; i<N; i++){
		cs.add(y1[i], x1[i], y2[i], x2[i], 1LL);
	}

	cs.build();

	long long ans = 0;
	for(int i=0; i<1000; i++){
		for(int j=0; j<1000; j++){
			ans = max(ans, cs.get(i, j));
		}
	}
	cout << ans << endl;
}
