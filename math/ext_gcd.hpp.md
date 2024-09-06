---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/NTL_1_E.test.cpp
    title: verify/aoj/NTL_1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/ext_gcd.hpp\"\n\nlong long ext_gcd(long long a, long\
    \ long b, long long &x, long long &y) {\n  if (b == 0) {\n    x = 1;\n    y =\
    \ 0;\n    return a;\n  }\n  long long res = ext_gcd(b, a % b, y, x);\n  y -= (a\
    \ / b) * x;\n  return res;\n}\n"
  code: "#pragma once\n\nlong long ext_gcd(long long a, long long b, long long &x,\
    \ long long &y) {\n  if (b == 0) {\n    x = 1;\n    y = 0;\n    return a;\n  }\n\
    \  long long res = ext_gcd(b, a % b, y, x);\n  y -= (a / b) * x;\n  return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ext_gcd.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:27:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/NTL_1_E.test.cpp
documentation_of: math/ext_gcd.hpp
layout: document
redirect_from:
- /library/math/ext_gcd.hpp
- /library/math/ext_gcd.hpp.html
title: math/ext_gcd.hpp
---
