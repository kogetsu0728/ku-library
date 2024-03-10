---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: template/template_atcoder.hpp
    title: template/template_atcoder.hpp
  - icon: ':warning:'
    path: template/template_codeforces.hpp
    title: template/template_codeforces.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "template/template_base.hpp"

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

    constexpr array<int,8> DX={0,0,-1,1,-1,-1,1,1};

    constexpr array<int,8> DY={-1,1,0,0,-1,1,-1,1};

    template<class T> inline bool chmax(T &a,T b){return a<b?a=b,true:false;}

    template<class T> inline bool chmin(T &a,T b){return a>b?a=b,true:false;}

    #define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)

    #define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)

    '
  code: '#include <bits/stdc++.h>

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

    constexpr array<int,8> DX={0,0,-1,1,-1,-1,1,1};

    constexpr array<int,8> DY={-1,1,0,0,-1,1,-1,1};

    template<class T> inline bool chmax(T &a,T b){return a<b?a=b,true:false;}

    template<class T> inline bool chmin(T &a,T b){return a>b?a=b,true:false;}

    #define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)

    #define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)

    '
  dependsOn: []
  isVerificationFile: false
  path: template/template_base.hpp
  requiredBy:
  - template/template_codeforces.hpp
  - template/template_atcoder.hpp
  timestamp: '2024-03-10 11:21:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template_base.hpp
layout: document
redirect_from:
- /library/template/template_base.hpp
- /library/template/template_base.hpp.html
title: template/template_base.hpp
---
