#pragma once

class SieveOfEratosthenes{
	private:
		int siz;
		vector<int> div, pr, cnt;
	public:
		SieveOfEratosthenes(int n):
			siz(n),div(n+1),pr(0),cnt(n+1){
				div[1] = 1;
				for(int i=2; i<=n; i++){
					if(div[i]!=0) continue;
					pr.push_back(i);
					for(int j=i; j<=n; j+=i){
						if(div[j]==0) div[j] = i;
						cnt[j]++;
					}
				}
			}

		int nth_prime(int n) const {
			return pr[n];
		}

		int count_prime(int n) const {
			if(n<2) return 0;
			return cnt[n];
		}

		int count_divisors(int n) const {
			auto f = prime_factors(n);
			int res = 1;
			for(auto p:f){
				res *= (1+p.second);
			}
			return res;
		}

		int totient(int n) const {
			auto f = prime_factors(n);
			int res = n;
			for(auto p:f){
				res /= p.first;
			}
			for(auto p:f){
				res *= p.first-1;
			}
			return res;
		}

		int prev_prime(int n) const {
			int l=0, r=pr.size();
			while(r-l>1){
				int m=(l+r)/2;
				if(pr[m]<n) l=m;
				else r=m;
			}
			return pr[l];
		}

		int next_prime(int n) const {
			int l=0, r=pr.size();
			while(r-l>1){
				int m=(l+r)/2;
				if(pr[m]<=n) l=m;
				else r=m;
			}
			return pr[r];
		}

		bool is_prime(int n) const {
			if(n<2) return false;
			return div[n]==n;
		}

		vector<pair<int,int>> prime_factors(int n) const {
			vector<pair<int,int>> res;
			int x = n;
			while(2<=x){
				if(res.empty() || res.back().first!=div[x]){
					res.push_back({div[x], 1});
				}else{
					res.back().second++;
				}
				x /= div[x];
			}
			return res;
		}

		vector<int> get_divisors(int n) const {
			vector<int> res = {1};
			auto pf = prime_factors(n);
			for(auto p:pf){
				int s=(int)res.size();
				for(int i=0; i<s; i++){
					int m = 1;
					for(int j=0; j<(int)p.second; j++){
						m *= p.first;
						res.push_back(res[i]*m);
					}
				}
			}
			sort(res.begin(), res.end());
			return res;
		}
};
