#pragma once

class LowLink{
	private:
		int n, comp;
		vector<vector<int>> g;
		vector<bool> seen;
		vector<int> ord, low, art;
		set<pair<int,int>> bri;

		void dfs(int v, int p, int &i){
			seen[v] = true;
			ord[v] = low[v] = i++;
			for(const int &nv:g[v]){
				if(seen[nv]){
					if(nv!=p){
						low[v] = min(low[v], ord[nv]);
					}
				}else{
					dfs(nv, v, i);
					low[v] = min(low[v], low[nv]);
					if(ord[v]<=low[nv]) art[v]++;
					if(ord[v]<low[nv]) bri.insert(make_pair(min(v,nv),max(v,nv)));
				}
			}
			if(p==-1) art[v]--;
		}

	public:
		LowLink(const int _n=0):
			n(_n), comp(0), g(_n), seen(_n), ord(_n), low(_n), art(_n){}

		void add_edge(int u, int v){
			g[u].push_back(v);
			g[v].push_back(u);
		}

		void build(){
			for(int v=0; v<n; v++) if(!seen[v]){
				comp++;
				int i{};
				dfs(v, -1, i);
			}
		}

		int component() const {
			return comp;
		}

		int get_art(int v) const {
			return art[v];
		}

		bool is_art(int v) const {
			return 0<get_art(v);
		}

		bool is_bridge(int u, int v) const {
			return bri.count(make_pair(min(u,v),max(u,v)));
		}
};
