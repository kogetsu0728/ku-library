---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: "Extended Euclidean algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
      \u30C9\u306E\u4E92\u9664\u6CD5)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E
  bundledCode: "#line 1 \"verify/aoj/NTL_1_E.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"math/ext_gcd.hpp\"\n\n/**\n\
    \ * @brief Extended Euclidean algorithm (\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\
    \u30C9\u306E\u4E92\u9664\u6CD5)\n */\nlong long ext_gcd(long long a, long long\
    \ b, long long &x, long long &y) {\n  if (b == 0) {\n    x = 1;\n    y = 0;\n\
    \    return a;\n  }\n  long long res = ext_gcd(b, a % b, y, x);\n  y -= (a / b)\
    \ * x;\n  return res;\n}\n#line 8 \"verify/aoj/NTL_1_E.test.cpp\"\n\nint main()\
    \ {\n  long long a, b;\n  cin >> a >> b;\n\n  long long x, y;\n  ext_gcd(a, b,\
    \ x, y);\n  cout << x << ' ' << y << endl;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/ext_gcd.hpp\"\
    \n\nint main() {\n  long long a, b;\n  cin >> a >> b;\n\n  long long x, y;\n \
    \ ext_gcd(a, b, x, y);\n  cout << x << ' ' << y << endl;\n}\n"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: verify/aoj/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2024-09-06 18:44:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/NTL_1_E.test.cpp
- /verify/verify/aoj/NTL_1_E.test.cpp.html
title: verify/aoj/NTL_1_E.test.cpp
---
