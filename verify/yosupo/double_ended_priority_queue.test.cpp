#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include <iostream>
#include <set>
using namespace std;

#include "../../data_structure/double_ended_priority_queue.hpp"

int main(){
	int N, Q;
	cin >> N >> Q;
	DoubleEndedPriorityQueue<long long> que;
	for(int i=0; i<N; i++){
		long long s;
		cin >> s;
		que.push(s);
	}

	for(;Q--;){
		int t;
		cin >> t;
		if(t==0){
			long long x;
			cin >> x;
			que.push(x);
		}else if(t==1){
			cout << que.min() << endl;
			que.pop_min();
		}else{
			cout << que.max() << endl;
			que.pop_max();
		}
	}
}
