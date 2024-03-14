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
  bundledCode: "#line 1 \"template/template.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#if __has_include(<atcoder/all>)\n#include <atcoder/all>\nusing\
    \ namespace atcoder;\n#endif\nusing ll=long long;\nusing ld=long double;\ntemplate<class\
    \ T> using graph=vector<vector<T>>;\ntemplate<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;\n\
    constexpr int INF32=INT_MAX/2;\nconstexpr ll INF64=1LL<<60;\nconstexpr array<int,4>\
    \ DX4={0,1,0,-1};\nconstexpr array<int,4> DY4={-1,0,1,0};\nconstexpr array<int,8>\
    \ DX8={0,1,1,1,0,-1,-1,-1};\nconstexpr array<int,8> DY8={-1,-1,0,1,1,1,0,-1};\n\
    template<class T> inline bool chmax(T &a,T b){return a<b?a=b,true:false;}\ntemplate<class\
    \ T> inline bool chmin(T &a,T b){return a>b?a=b,true:false;}\n#define rep(i,s,n)\
    \ for(ll i=(ll)(s);i<(ll)(n);i++)\n#define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)\n\
    void _main();\nint main(){\n\tcin.tie(0)->sync_with_stdio(0);\n\tcout<<fixed<<setprecision(16);\n\
    \t_main();\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n#if __has_include(<atcoder/all>)\n\
    #include <atcoder/all>\nusing namespace atcoder;\n#endif\nusing ll=long long;\n\
    using ld=long double;\ntemplate<class T> using graph=vector<vector<T>>;\ntemplate<class\
    \ T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;\nconstexpr\
    \ int INF32=INT_MAX/2;\nconstexpr ll INF64=1LL<<60;\nconstexpr array<int,4> DX4={0,1,0,-1};\n\
    constexpr array<int,4> DY4={-1,0,1,0};\nconstexpr array<int,8> DX8={0,1,1,1,0,-1,-1,-1};\n\
    constexpr array<int,8> DY8={-1,-1,0,1,1,1,0,-1};\ntemplate<class T> inline bool\
    \ chmax(T &a,T b){return a<b?a=b,true:false;}\ntemplate<class T> inline bool chmin(T\
    \ &a,T b){return a>b?a=b,true:false;}\n#define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)\n\
    #define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)\nvoid _main();\nint main(){\n\
    \tcin.tie(0)->sync_with_stdio(0);\n\tcout<<fixed<<setprecision(16);\n\t_main();\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: template/template.hpp
  requiredBy: []
  timestamp: '2024-03-14 15:44:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template.hpp
layout: document
redirect_from:
- /library/template/template.hpp
- /library/template/template.hpp.html
title: template/template.hpp
---
