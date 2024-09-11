---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_1_C.test.cpp
    title: test/aoj/ALDS1_1_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: "Sieve of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
      \u306E\u7BE9)"
    links: []
  bundledCode: "#line 2 \"math/sieve_of_eratosthenes.hpp\"\n\n/**\n * @brief Sieve\
    \ of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n */\n\
    template <class T> class SieveOfEratosthenes {\n  private:\n    vector<T> div,\
    \ pr;\n\n  public:\n    SieveOfEratosthenes() {}\n    SieveOfEratosthenes(int\
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
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Sieve of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9)\n */\ntemplate <class T> class SieveOfEratosthenes\
    \ {\n  private:\n    vector<T> div, pr;\n\n  public:\n    SieveOfEratosthenes()\
    \ {}\n    SieveOfEratosthenes(int n) : div(n + 1), pr() {\n        div[1] = 1;\n\
    \n        for (long long i = 2; i <= n; i++) {\n            if (div[i] != 0) continue;\n\
    \n            div[i] = i;\n            pr.emplace_back(i);\n\n            for\
    \ (long long j = i * i; j <= n; j += i) {\n                if (div[j] != 0) continue;\n\
    \n                div[j] = i;\n            }\n        }\n    }\n\n    bool is_prime(int\
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
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sieve_of_eratosthenes.hpp
  requiredBy: []
  timestamp: '2024-09-11 22:59:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_1_C.test.cpp
documentation_of: math/sieve_of_eratosthenes.hpp
layout: document
redirect_from:
- /library/math/sieve_of_eratosthenes.hpp
- /library/math/sieve_of_eratosthenes.hpp.html
title: "Sieve of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
  )"
---
