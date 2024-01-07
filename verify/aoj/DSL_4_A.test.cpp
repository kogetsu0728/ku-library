#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"

#include <bits/stdc++.h>
using namespace std;

#include "../../misc/compress.hpp"
#include "../../data_structure/cumulative_sum_2d.hpp"

int main(){
	int N;
	cin >> N;
	vector<long long> x1(N), y1(N), x2(N), y2(N);
	for(int i=0; i<N; i++){
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
	}

	Compress<long long> cmp_x, cmp_y;
	for(int i=0; i<N; i++){
		cmp_x.push(x1[i]), cmp_x.push(x2[i]);
		cmp_y.push(y1[i]), cmp_y.push(y2[i]);
	}

	cmp_x.build(), cmp_y.build();

	CumulativeSum2d<int> cnt(int(cmp_y.size()), int(cmp_x.size()));
	for(int i=0; i<N; i++){
		cnt.add(cmp_y.get(y1[i]), cmp_x.get(x1[i]),
		cmp_y.get(y2[i]), cmp_x.get(x2[i]), 1);
	}

	cnt.build();

	long long ans{};
	for(int i=0; i<int(cmp_y.size())-1; i++){
		for(int j=0; j<int(cmp_x.size())-1; j++){
			if(cnt.get(i,j)){
				ans += (cmp_y.nth(i+1)-cmp_y.nth(i))*(cmp_x.nth(j+1)-cmp_x.nth(j));
			}
		}
	}

	cout << ans << endl;
}
