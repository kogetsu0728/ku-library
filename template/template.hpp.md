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
  bundledCode: "#line 1 \"template/template.hpp\"\n#ifdef ATCODER\n#pragma GCC target(\"\
    avx2\")\n#pragma GCC optimize(\"O3\")\n#pragma GCC optimize(\"unroll-loops\")\n\
    #else\n#define _GLIBCXX_DEBUG\n#endif\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing uint = unsigned int;\nusing ll = long long;\nusing ull = unsigned\
    \ long long;\nusing ld = long double;\ntemplate<class T> using graph = vector<vector<T>>;\n\
    template<class T> using min_priority_queue = priority_queue<T,vector<T>,greater<T>>;\n\
    #define rep(i,s,n) for(ll i=(ll)(s); i<(ll)(n); i++)\n#define rrep(i,s,n) for(ll\
    \ i=(ll)(s); i>=(ll)(n); i--)\n#define all(a) (a).begin(),(a).end()\n#define rall(a)\
    \ (a).rbegin(),(a).rend()\nconstexpr int INF32 = INT_MAX/2;\nconstexpr ll INF64\
    \ = 1LL<<60;\nconstexpr ld PI = 3.14159265358979323846;\nconstexpr array<int,4>\
    \ DX4 = {0,1,0,-1}, DY4 = {-1,0,1,0};\nconstexpr array<int,8> DX8 = {0,1,1,1,0,-1,-1,-1},\
    \ DY8 = {-1,-1,0,1,1,1,0,-1};\ntemplate<class T> inline bool chmax(T& a,const\
    \ T& b){ return a<b?a=b,true:false; }\ntemplate<class T> inline bool chmin(T&\
    \ a,const T& b){ return b<a?a=b,true:false; }\nstruct SETUP{\n\tSETUP(){\n\t\t\
    cin.tie(nullptr);\n\t\tios_base::sync_with_stdio(false);\n\t\tcout << fixed <<\
    \ setprecision(16);\n\t}\n} SETUP;\n"
  code: "#ifdef ATCODER\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\n#else\n#define _GLIBCXX_DEBUG\n#endif\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing uint = unsigned int;\nusing\
    \ ll = long long;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    template<class T> using graph = vector<vector<T>>;\ntemplate<class T> using min_priority_queue\
    \ = priority_queue<T,vector<T>,greater<T>>;\n#define rep(i,s,n) for(ll i=(ll)(s);\
    \ i<(ll)(n); i++)\n#define rrep(i,s,n) for(ll i=(ll)(s); i>=(ll)(n); i--)\n#define\
    \ all(a) (a).begin(),(a).end()\n#define rall(a) (a).rbegin(),(a).rend()\nconstexpr\
    \ int INF32 = INT_MAX/2;\nconstexpr ll INF64 = 1LL<<60;\nconstexpr ld PI = 3.14159265358979323846;\n\
    constexpr array<int,4> DX4 = {0,1,0,-1}, DY4 = {-1,0,1,0};\nconstexpr array<int,8>\
    \ DX8 = {0,1,1,1,0,-1,-1,-1}, DY8 = {-1,-1,0,1,1,1,0,-1};\ntemplate<class T> inline\
    \ bool chmax(T& a,const T& b){ return a<b?a=b,true:false; }\ntemplate<class T>\
    \ inline bool chmin(T& a,const T& b){ return b<a?a=b,true:false; }\nstruct SETUP{\n\
    \tSETUP(){\n\t\tcin.tie(nullptr);\n\t\tios_base::sync_with_stdio(false);\n\t\t\
    cout << fixed << setprecision(16);\n\t}\n} SETUP;\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-05-11 13:53:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
