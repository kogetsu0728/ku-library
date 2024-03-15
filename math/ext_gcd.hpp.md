---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/NTL_1_E.test.cpp
    title: verify/aoj/NTL_1_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/ext_gcd.hpp\"\nlong long ext_gcd(long long a, long\
    \ long b, long long &x, long long &y){\n\tif(b==0){\n\t\tx = 1;\n\t\ty = 0;\n\t\
    \treturn a;\n\t}\n\tlong long res = ext_gcd(b, a%b, y, x);\n\ty -= (a/b)*x;\n\t\
    return res;\n}\n"
  code: "long long ext_gcd(long long a, long long b, long long &x, long long &y){\n\
    \tif(b==0){\n\t\tx = 1;\n\t\ty = 0;\n\t\treturn a;\n\t}\n\tlong long res = ext_gcd(b,\
    \ a%b, y, x);\n\ty -= (a/b)*x;\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ext_gcd.hpp
  requiredBy: []
  timestamp: '2024-03-15 14:01:55+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/NTL_1_E.test.cpp
documentation_of: math/ext_gcd.hpp
layout: document
redirect_from:
- /library/math/ext_gcd.hpp
- /library/math/ext_gcd.hpp.html
title: math/ext_gcd.hpp
---
