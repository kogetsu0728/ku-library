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
  bundledCode: "#line 1 \"template/codeforces_template.hpp\"\n#ifdef LOCAL\n#define\
    \ _GLIBCXX_DEBUG\n#endif\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll=long long;\nusing ld=long double;\ntemplate<class T> using graph=vector<vector<T>>;\n\
    template<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;\n\
    constexpr int INF32=INT_MAX/2;\nconstexpr ll INF64=1LL<<60;\nconstexpr int DX[]={0,0,-1,1,-1,-1,1,1};\n\
    constexpr int DY[]={-1,1,0,0,-1,1,-1,1};\ntemplate<class T> inline bool chmax(T\
    \ &a,T b){return a<b?a=b,true:false;}\ntemplate<class T> inline bool chmin(T &a,T\
    \ b){return a>b?a=b,true:false;}\n#define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)\n\
    #define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)\nvoid _main();\nint main(){\n\
    \    cin.tie(0)->sync_with_stdio(0);\n    cout<<fixed<<setprecision(16);\n   \
    \ int codeforces;\n    cin >> codeforces;\n    for(;codeforces--;) _main();\n\
    }\n"
  code: "#ifdef LOCAL\n#define _GLIBCXX_DEBUG\n#endif\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll=long long;\nusing ld=long double;\ntemplate<class\
    \ T> using graph=vector<vector<T>>;\ntemplate<class T> using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;\n\
    constexpr int INF32=INT_MAX/2;\nconstexpr ll INF64=1LL<<60;\nconstexpr int DX[]={0,0,-1,1,-1,-1,1,1};\n\
    constexpr int DY[]={-1,1,0,0,-1,1,-1,1};\ntemplate<class T> inline bool chmax(T\
    \ &a,T b){return a<b?a=b,true:false;}\ntemplate<class T> inline bool chmin(T &a,T\
    \ b){return a>b?a=b,true:false;}\n#define rep(i,s,n) for(ll i=(ll)(s);i<(ll)(n);i++)\n\
    #define rrep(i,s,n) for(ll i=(ll)(s);i>=(ll)(n);i--)\nvoid _main();\nint main(){\n\
    \    cin.tie(0)->sync_with_stdio(0);\n    cout<<fixed<<setprecision(16);\n   \
    \ int codeforces;\n    cin >> codeforces;\n    for(;codeforces--;) _main();\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: template/codeforces_template.hpp
  requiredBy: []
  timestamp: '2024-01-20 11:06:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template/codeforces_template.hpp
layout: document
redirect_from:
- /library/template/codeforces_template.hpp
- /library/template/codeforces_template.hpp.html
title: template/codeforces_template.hpp
---
