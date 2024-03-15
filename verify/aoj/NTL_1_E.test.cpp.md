---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/ext_gcd.hpp
    title: math/ext_gcd.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"verify/aoj/NTL_1_E.test.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 1 \"math/ext_gcd.hpp\"\nlong long ext_gcd(long long\
    \ a, long long b, long long &x, long long &y){\n\tif(b==0){\n\t\tx = 1;\n\t\t\
    y = 0;\n\t\treturn a;\n\t}\n\tlong long res = ext_gcd(b, a%b, y, x);\n\ty -= (a/b)*x;\n\
    \treturn res;\n}\n#line 5 \"verify/aoj/NTL_1_E.test.cpp\"\n\nint main(){\n\tlong\
    \ long a, b; cin >> a >> b;\n\n\tlong long x, y;\n\text_gcd(a, b, x, y);\n\tcout\
    \ << x << ' ' << y << endl;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/ext_gcd.hpp\"\
    \n\nint main(){\n\tlong long a, b; cin >> a >> b;\n\n\tlong long x, y;\n\text_gcd(a,\
    \ b, x, y);\n\tcout << x << ' ' << y << endl;\n}\n"
  dependsOn:
  - math/ext_gcd.hpp
  isVerificationFile: true
  path: verify/aoj/NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2024-03-15 14:04:34+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/NTL_1_E.test.cpp
- /verify/verify/aoj/NTL_1_E.test.cpp.html
title: verify/aoj/NTL_1_E.test.cpp
---
