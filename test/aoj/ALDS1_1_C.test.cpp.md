---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/sieve_of_eratosthenes.hpp
    title: "Sieve of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
      \u7BE9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_1_C.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"math/sieve_of_eratosthenes.hpp\"\
    \n\n/**\n * @brief Sieve of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\
    \u30B9\u306E\u7BE9)\n */\nclass SieveOfEratosthenes {\n  private:\n    vector<int>\
    \ div, pr;\n\n  public:\n    SieveOfEratosthenes() {}\n    SieveOfEratosthenes(int\
    \ n) : div(n + 1), pr() {\n        div[1] = 1;\n\n        for (long long i = 2;\
    \ i <= n; i++) {\n            if (div[i] != 0) continue;\n\n            div[i]\
    \ = i;\n            pr.emplace_back(i);\n\n            for (long long j = i *\
    \ i; j <= n; j += i) {\n                if (div[j] != 0) continue;\n\n       \
    \         div[j] = i;\n            }\n        }\n    }\n\n    bool is_prime(int\
    \ n) const { return (n < 2 ? false : div[n] == n); }\n\n    vector<int> get_primes()\
    \ const { return pr; }\n\n    vector<pair<int, int>> prime_factors(int n) const\
    \ {\n        vector<pair<int, int>> res;\n        int x = n;\n\n        while\
    \ (2 <= x) {\n            if (res.empty() || res.back().first != div[x]) {\n \
    \               res.push_back({div[x], 1});\n            } else {\n          \
    \      res.back().second++;\n            }\n\n            x /= div[x];\n     \
    \   }\n\n        return res;\n    }\n\n    vector<int> divisors(int n) const {\n\
    \        vector<int> res({1});\n        auto pf = prime_factors(n);\n\n      \
    \  for (const auto& p : pf) {\n            int s = int(res.size());\n\n      \
    \      for (int i = 0; i < s; i++) {\n                int m = 1;\n\n         \
    \       for (int j = 0; j < int(p.second); j++) {\n                    m *= p.first;\n\
    \                    res.push_back(res[i] * m);\n                }\n         \
    \   }\n        }\n\n        sort(res.begin(), res.end());\n\n        return res;\n\
    \    }\n};\n#line 7 \"test/aoj/ALDS1_1_C.test.cpp\"\n\nint main(){\n\tint N;\n\
    \tcin >> N;\n\n\tSieveOfEratosthenes pr(100000000);\n\n\tint ans = 0;\n\tfor(;N--;){\n\
    \t\tint a;\n\t\tcin >> a;\n\n\t\tif(pr.is_prime(a)) ans++;\n\t}\n\n\tcout << ans\
    \ << endl;\n\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../math/sieve_of_eratosthenes.hpp\"\
    \n\nint main(){\n\tint N;\n\tcin >> N;\n\n\tSieveOfEratosthenes pr(100000000);\n\
    \n\tint ans = 0;\n\tfor(;N--;){\n\t\tint a;\n\t\tcin >> a;\n\n\t\tif(pr.is_prime(a))\
    \ ans++;\n\t}\n\n\tcout << ans << endl;\n\n\treturn 0;\n}\n"
  dependsOn:
  - math/sieve_of_eratosthenes.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2024-09-11 23:01:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_1_C.test.cpp
- /verify/test/aoj/ALDS1_1_C.test.cpp.html
title: test/aoj/ALDS1_1_C.test.cpp
---
