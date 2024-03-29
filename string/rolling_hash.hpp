#pragma once

class RollingHash{
	private:
		static const long long mod1=888888901, mod2=987654323;
		long long base1, base2;
		int n;
		vector<long long> hash1, hash2, pow1, pow2;

	public:
		RollingHash(const string &s, const long long _base1=2525, const long long _base2=4649):
			base1(_base1), base2(_base2) {
				n = s.length();
				hash1.assign(n+1, 0);
				hash2.assign(n+1, 0);
				pow1.assign(n+1, 1);
				pow2.assign(n+1, 1);
				for (int i=0; i<n; i++){
					hash1[i+1] = (hash1[i]*base1+s[i]) % mod1;
					hash2[i+1] = (hash2[i]*base2+s[i]) % mod2;
					pow1[i+1] = (pow1[i]*base1) % mod1;
					pow2[i+1] = (pow2[i]*base2) % mod2;
				}
			}

		pair<long long, long long> get(const int l, const int r) const {
			long long fi = hash1[r]-(hash1[l]*pow1[r-l]%mod1);
			if(fi<0) fi += mod1;
			long long se = hash2[r]-(hash2[l]*pow2[r-l]%mod2);
			if(se<0) se += mod2;
			return make_pair(fi,se);
		}

		pair<long long, long long> merge( \
				const pair<long long, long long> a, const pair<long long, long long> b, const int b_len) const {
			long long fi = ((a.first*pow1[b_len])%mod1 + b.first) % mod1;
			long long se = ((a.second*pow2[b_len])%mod2 + b.second) % mod2;
			return make_pair(fi, se);
		}

		int lcp(const int a, const int b) const {
			int ok = 0, ng = min(n+1-a,n+1-b);
			while(1<ng-ok){
				int mid = (ok+ng)/2;
				if(get(a,a+mid)==get(b,b+mid)) ok = mid;
				else ng = mid;
			}
			return ok;
		}
};
