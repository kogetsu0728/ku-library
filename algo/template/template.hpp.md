---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "template/template.hpp"

    #ifdef LOCAL

    #define _GLIBCXX_DEBUG

    #else

    #pragma GCC target("avx2")

    #pragma GCC optimize("O3")

    #pragma GCC optimize("unroll-loops")

    #endif

    #include <bits/stdc++.h>

    #include <atcoder/all>

    using namespace std;

    using namespace atcoder;

    using ll=long long;

    using ull=unsigned long long;

    using ld=long double;

    template<class T=int> using graph=vector<vector<T>>;

    template<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;

    constexpr int INF32=INT_MAX/2;

    constexpr ll INF64=1LL<<60;

    constexpr ld PI=numbers::pi_v<ld>;

    constexpr int DX[]={0,0,-1,1,-1,-1,1,1};

    constexpr int DY[]={-1,1,0,0,-1,1,-1,1};

    template<class T> inline bool chmax(T &a,T b){return a<b?a=b,true:false;}

    template<class T> inline bool chmin(T &a,T b){return a>b?a=b,true:false;}

    #define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)

    #define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)

    void _main();

    int main(){cin.tie(0)->sync_with_stdio(0);cout<<fixed<<setprecision(16);_main();}

    '
  code: '#ifdef LOCAL

    #define _GLIBCXX_DEBUG

    #else

    #pragma GCC target("avx2")

    #pragma GCC optimize("O3")

    #pragma GCC optimize("unroll-loops")

    #endif

    #include <bits/stdc++.h>

    #include <atcoder/all>

    using namespace std;

    using namespace atcoder;

    using ll=long long;

    using ull=unsigned long long;

    using ld=long double;

    template<class T=int> using graph=vector<vector<T>>;

    template<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;

    constexpr int INF32=INT_MAX/2;

    constexpr ll INF64=1LL<<60;

    constexpr ld PI=numbers::pi_v<ld>;

    constexpr int DX[]={0,0,-1,1,-1,-1,1,1};

    constexpr int DY[]={-1,1,0,0,-1,1,-1,1};

    template<class T> inline bool chmax(T &a,T b){return a<b?a=b,true:false;}

    template<class T> inline bool chmin(T &a,T b){return a>b?a=b,true:false;}

    #define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)

    #define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)

    void _main();

    int main(){cin.tie(0)->sync_with_stdio(0);cout<<fixed<<setprecision(16);_main();}

    '
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-01-01 22:33:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
