#ifdef LOCAL
#define _GLIBCXX_DEBUG
#else
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#define debug(...)
#endif
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using ull=unsigned long long;
using ld=long double;
using graph=vector<vector<int>>;
template<class T> using wgraph=vector<vector<pair<int,T>>>;
template<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;
constexpr int INF32=INT_MAX/2;
constexpr ll INF64=1LL<<60;
constexpr ld PI=numbers::pi_v<ld>;
constexpr int DX[]={0,0,-1,1,-1,-1,1,1}, DY[]={-1,1,0,0,-1,1,-1,1};
template<class T> inline bool chmax(T &a,T b){return a<b?a=b,true:false;}
template<class T> inline bool chmin(T &a,T b){return a>b?a=b,true:false;}
#define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)
#define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)
void _main();
int main(){cin.tie(0)->sync_with_stdio(0);cout<<fixed<<setprecision(16);_main();}

void _main(){
}
