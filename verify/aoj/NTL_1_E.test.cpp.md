---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/ext_gcd.hpp
    title: math/ext_gcd.hpp
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
  bundledCode: "#line 1 \"verify/aoj/NTL_1_E.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"math/ext_gcd.hpp\"\
    \nlong long ext_gcd(long long a, long long b, long long &x, long long &y){\n\t\
    if(b==0){\n\t\tx = 1;\n\t\ty = 0;\n\t\treturn a;\n\t}\n\tlong long res = ext_gcd(b,\
    \ a%b, y, x);\n\ty -= (a/b)*x;\n\treturn res;\n}\n#line 7 \"verify/aoj/NTL_1_E.test.cpp\"\
    \n\nint main(){\n\tlong long a, b; cin >> a >> b;\n\n\tlong long x, y;\n\text_gcd(a,\
    \ b, x, y);\n\tcout << x << ' ' << y << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/ext_gcd.hpp\"\
    \n\nint main(){\n\tlong long a, b; cin >> a >> b;\n\n\tlong long x, y;\n\text_gcd(a,\
    \ b, x, y);\n\tcout << x << ' ' << y << endl;\n}\n"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: verify/aoj/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2024-03-15 14:05:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/NTL_1_E.test.cpp
- /verify/verify/aoj/NTL_1_E.test.cpp.html
title: verify/aoj/NTL_1_E.test.cpp
---
