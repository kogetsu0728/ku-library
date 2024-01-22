---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: template/template_base.hpp
    title: template/template_base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template_base.hpp\"\n#ifdef LOCAL\n#define _GLIBCXX_DEBUG\n\
    #endif\n#include <bits/stdc++.h>\n#include <atcoder/all>\nusing namespace std;\n\
    using namespace atcoder;\nusing ll=long long;\nusing ld=long double;\ntemplate<class\
    \ T> using graph=vector<vector<T>>;\ntemplate<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;\n\
    constexpr int INF32=INT_MAX/2;\nconstexpr ll INF64=1LL<<60;\nconstexpr array<int,8>\
    \ DX={0,0,-1,1,-1,-1,1,1};\nconstexpr array<int,8> DY={-1,1,0,0,-1,1,-1,1};\n\
    template<class T> inline bool chmax(T &a,T b){return a<b?a=b,true:false;}\ntemplate<class\
    \ T> inline bool chmin(T &a,T b){return a>b?a=b,true:false;}\n#define rep(i,s,n)\
    \ for(ll i=(ll)(s);i<(ll)(n);i++)\n#define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)\n\
    #line 2 \"template/template_codeforces.hpp\"\nvoid _main();\nint main(){\n   \
    \ cin.tie(0)->sync_with_stdio(0);\n    cout<<fixed<<setprecision(16);\n    int\
    \ t; cin >> t;\n    for(;t--;) _main();\n}\n"
  code: "#include \"template/template_base.hpp\"\nvoid _main();\nint main(){\n   \
    \ cin.tie(0)->sync_with_stdio(0);\n    cout<<fixed<<setprecision(16);\n    int\
    \ t; cin >> t;\n    for(;t--;) _main();\n}"
  dependsOn:
  - template/template_base.hpp
  isVerificationFile: false
  path: template/template_codeforces.hpp
  requiredBy: []
  timestamp: '2024-01-22 18:10:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/template_codeforces.hpp
layout: document
redirect_from:
- /library/template/template_codeforces.hpp
- /library/template/template_codeforces.hpp.html
title: template/template_codeforces.hpp
---
