#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
template<class T> using graph=vector<vector<T>>;
template<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;
constexpr int INF32=INT_MAX/2;
constexpr ll INF64=1LL<<60;
constexpr int DX[]={0,0,-1,1,-1,-1,1,1};
constexpr int DY[]={-1,1,0,0,-1,1,-1,1};
template<class T> inline bool chmax(T &a,T b){return a<b?a=b,true:false;}
template<class T> inline bool chmin(T &a,T b){return a>b?a=b,true:false;}
#define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)
#define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)
void _main();
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout<<fixed<<setprecision(16);
    int codeforces;
    cin >> codeforces;
    for(;codeforces--;) _main();
}
