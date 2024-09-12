---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/binomial.hpp
    title: "Binomial (\u4E8C\u9805\u4FC2\u6570)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
    links:
    - https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod
  bundledCode: "#line 1 \"test/yosupo/binomial_coefficient_prime_mod.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include <atcoder/modint>\n\
    using namespace atcoder;\n\n#line 2 \"math/binomial.hpp\"\n\n/**\n * @brief Binomial\
    \ (\u4E8C\u9805\u4FC2\u6570)\n */\ntemplate <class T> class Binomial {\n  private:\n\
    \    vector<T> fac, ifac;\n\n  public:\n    Binomial() {}\n    Binomial(int _n)\
    \ : fac(_n + 1, 1), ifac(_n + 1, 1) {\n        for (int i = 0; i < _n; i++) {\n\
    \            fac[i + 1] = fac[i] * (i + 1);\n        }\n        ifac[_n] = 1 /\
    \ fac[_n];\n        for (int i = _n; i > 0; i--) {\n            ifac[i - 1] =\
    \ ifac[i] * i;\n        }\n    }\n\n    T p(int a, int b) {\n        if (b < 0\
    \ || a < b) return 0;\n        return fac[a] * ifac[a - b];\n    }\n\n    T c(int\
    \ a, int b) {\n        if (b < 0 || a < b) return 0;\n        return p(a, b) *\
    \ ifac[b];\n    }\n\n    T h(int a, int b) {\n        if (a == 0 && b == 0) return\
    \ 1;\n        if (a <= 0 || b < 0) return 0;\n        return c(a + b - 1, b);\n\
    \    }\n};\n#line 10 \"test/yosupo/binomial_coefficient_prime_mod.test.cpp\"\n\
    \nint main(){\n\tint T, M;\n\tcin >> T >> M;\n\n\tmodint::set_mod(M);\n\n\tBinomial<modint>\
    \ bin(M-1);\n\n\tfor(;T--;){\n\t\tint n, k;\n\t\tcin >> n >> k;\n\n\t\tcout <<\
    \ bin.c(n, k).val() << '\\n';\n\t}\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include <atcoder/modint>\n\
    using namespace atcoder;\n\n#include \"../../math/binomial.hpp\"\n\nint main(){\n\
    \tint T, M;\n\tcin >> T >> M;\n\n\tmodint::set_mod(M);\n\n\tBinomial<modint> bin(M-1);\n\
    \n\tfor(;T--;){\n\t\tint n, k;\n\t\tcin >> n >> k;\n\n\t\tcout << bin.c(n, k).val()\
    \ << '\\n';\n\t}\n\n\treturn 0;\n}\n"
  dependsOn:
  - math/binomial.hpp
  isVerificationFile: true
  path: test/yosupo/binomial_coefficient_prime_mod.test.cpp
  requiredBy: []
  timestamp: '2024-09-12 11:52:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/binomial_coefficient_prime_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/binomial_coefficient_prime_mod.test.cpp
- /verify/test/yosupo/binomial_coefficient_prime_mod.test.cpp.html
title: test/yosupo/binomial_coefficient_prime_mod.test.cpp
---
