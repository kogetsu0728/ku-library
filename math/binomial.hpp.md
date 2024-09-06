---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Binomial (\u4E8C\u9805\u4FC2\u6570)"
    links: []
  bundledCode: "#line 2 \"math/binomial.hpp\"\n\n/**\n * @brief Binomial (\u4E8C\u9805\
    \u4FC2\u6570)\n */\ntemplate <class T>\nclass Binomial {\n private:\n  vector<T>\
    \ fac, ifac;\n\n public:\n  Binomial() {}\n  Binomial(int _n) : fac(_n + 1, 1),\
    \ ifac(_n + 1, 1) {\n    for (int i = 0; i < _n; i++){\n\t\t\tfac[i + 1] = fac[i]\
    \ * (i + 1);\n\t\t}\n    ifac[_n] = 1 / fac[_n];\n    for (int i = _n; i > 0;\
    \ i--){\n\t\t\tifac[i - 1] = ifac[i] * i;\n\t\t}\n  }\n\n  T p(int a, int b) {\n\
    \    if (b < 0 || a < b) return 0;\n    return fac[a] * ifac[a - b];\n  }\n\n\
    \  T c(int a, int b) {\n    if (b < 0 || a < b) return 0;\n    return p(a, b)\
    \ * ifac[b];\n  }\n\n  T h(int a, int b) {\n    if (a == 0 && b == 0) return 1;\n\
    \    if (a <= 0 || b < 0) return 0;\n    return c(a + b - 1, b);\n  }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Binomial (\u4E8C\u9805\u4FC2\u6570)\n */\n\
    template <class T>\nclass Binomial {\n private:\n  vector<T> fac, ifac;\n\n public:\n\
    \  Binomial() {}\n  Binomial(int _n) : fac(_n + 1, 1), ifac(_n + 1, 1) {\n   \
    \ for (int i = 0; i < _n; i++){\n\t\t\tfac[i + 1] = fac[i] * (i + 1);\n\t\t}\n\
    \    ifac[_n] = 1 / fac[_n];\n    for (int i = _n; i > 0; i--){\n\t\t\tifac[i\
    \ - 1] = ifac[i] * i;\n\t\t}\n  }\n\n  T p(int a, int b) {\n    if (b < 0 || a\
    \ < b) return 0;\n    return fac[a] * ifac[a - b];\n  }\n\n  T c(int a, int b)\
    \ {\n    if (b < 0 || a < b) return 0;\n    return p(a, b) * ifac[b];\n  }\n\n\
    \  T h(int a, int b) {\n    if (a == 0 && b == 0) return 1;\n    if (a <= 0 ||\
    \ b < 0) return 0;\n    return c(a + b - 1, b);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/binomial.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:44:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/binomial.hpp
layout: document
redirect_from:
- /library/math/binomial.hpp
- /library/math/binomial.hpp.html
title: "Binomial (\u4E8C\u9805\u4FC2\u6570)"
---
