#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#include "../../graph/topological_sort.hpp"

int main(){
	int N, M;
	cin >> N >> M;
	TopologicalSort ts(N);
	for(int i=0; i<M; i++){
		int u, v;
		cin >> u >> v;
		ts.add_edge(u, v);
	}

	cout << (ts.build()?0:1) << endl;
}
