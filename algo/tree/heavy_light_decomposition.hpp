#pragma once

class HeavyLightDecomposition{
	private:
		int n;
		vector<vector<int>> g;
		vector<int> siz, par, dep, top, in, out;

		void dfs_siz(int v, int p){
			par[v] = p;
			for(int &nv:g[v]){
				if(nv==p){
					if(nv==g[v].back()) break;
					swap(nv, g[v].back());
				}
				dfs_siz(nv, v);
				siz[v] += siz[nv];
				if(siz[nv]>siz[g[v][0]]){
					swap(nv, g[v][0]);
				}
			}
		}

		void dfs_hld(int v, int p, int &i){
			in[v] = i++;
			for(int &nv:g[v]){
				if(nv==p) continue;
				dep[nv] = dep[v]+1;
				if(nv==g[v][0]) top[nv] = top[v];
				else top[nv] = nv;
				dfs_hld(nv, v, i);
			}
			out[v] = i;
		}

	public:
		HeavyLightDecomposition(const int _n=0):
			n(_n), g(_n), siz(_n, 1), par(_n, -1),
			dep(_n), top(_n), in(_n), out(_n){}

		void add_edge(int u, int v){
			g[u].push_back(v);
			g[v].push_back(u);
		}

		void build(){
			dfs_siz(0, -1);
			int i{};
			dfs_hld(0, -1, i);
		}

		int depth(int v) const {
			return dep[v];
		}

		int lca(int u, int v) const {
			while(true){
				if(in[u]>in[v]) swap(u, v);
				if(top[u]==top[v]) return u;
				v = par[top[v]];
			}
		}

		void node_query(int v, const function<void(int)> &func) const {
			func(in[v]);
		}

		void subtree_query(int v, const function<void(int,int)> &func) const {
			func(in[v], out[v]);
		}

		void path_query(int u, int v, const function<void(int,int)> &func) const {
			while(true){
				if(in[u]>in[v]) swap(u, v);
				func(max(in[u], in[top[v]]), in[v]+1);
				if(top[u]==top[v]) break;
				v = par[top[v]];
			}
		}
};
