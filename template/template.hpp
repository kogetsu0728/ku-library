#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using ll=long long;
using ld=long double;
template<class T> using graph=vector<vector<T>>;
template<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;
constexpr int INF32=INT_MAX/2;
constexpr ll INF64=1LL<<60;
constexpr array<int,4> DX4={0,1,0,-1};
constexpr array<int,4> DY4={-1,0,1,0};
constexpr array<int,8> DX8={0,1,1,1,0,-1,-1,-1};
constexpr array<int,8> DY8={-1,-1,0,1,1,1,0,-1};
template<class T> inline bool chmax(T& a,const T& b){return a<b?a=b,true:false;}
template<class T> inline bool chmin(T& a,const T& b){return b<a?a=b,true:false;}
#define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)
#define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)
void _main();
int main(){
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cout<<fixed<<setprecision(16);
	_main();
}
