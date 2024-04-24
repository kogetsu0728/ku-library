#pragma once

#include "checker/build_checker.hpp"

class TopologicalSort{
	private:
		BuildChecker build_checker;
		int n;
		vector<vector<int>> g;
		vector<int> p;

	public:
		TopologicalSort(): TopologicalSort(0) {}
		TopologicalSort(int _n): build_checker(), init(false), n(_n), g(_n){}

		void add_edge(int u, int v){
			build_checker.before();

			g[u].push_back(v);
		}

		bool build(){
			build_checker.build();

			vector<int> cnt(n);
			for(int v=0; v<n; v++){
				for(int nv:g[v]){
					cnt[nv]++;
				}
			}
			queue<int> que;
			for(int v=0; v<n; v++){
				if(cnt[v]==0){
					que.push(v);
				}
			}
			while(!que.empty()){
				int v = que.front();
				que.pop();
				p.push_back(v);
				for(int nv:g[v]){
					cnt[nv]--;
					if(cnt[nv]==0){
						que.push(nv);
					}
				}
			}
			if(n!=int(p.size())){
				p.clear();
				return false;
			}
			return true;
		}

		int operator[](const int i) const {
			build_checker.after();

			return p[i];
		}
};
