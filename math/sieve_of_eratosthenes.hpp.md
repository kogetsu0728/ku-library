---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Sieve of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\
      \u306E\u7BE9)"
    links: []
  bundledCode: "#line 2 \"math/sieve_of_eratosthenes.hpp\"\n\n/**\n * @brief Sieve\
    \ of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9)\n */\n\
    class SieveOfEratosthenes {\n  private:\n    int siz;\n    vector<int> div, pr,\
    \ cnt;\n\n  public:\n    SieveOfEratosthenes(int n) : siz(n), div(n + 1), pr(0),\
    \ cnt(n + 1) {\n        div[1] = 1;\n        for (int i = 2; i <= n; i++) {\n\
    \            if (div[i] != 0) continue;\n            pr.push_back(i);\n      \
    \      for (int j = i; j <= n; j += i) {\n                if (div[j] == 0) div[j]\
    \ = i;\n                cnt[j]++;\n            }\n        }\n    }\n\n    int\
    \ nth_prime(int n) const { return pr[n]; }\n\n    int count_prime(int n) const\
    \ {\n        if (n < 2) return 0;\n        return cnt[n];\n    }\n\n    int count_divisors(int\
    \ n) const {\n        auto f = prime_factors(n);\n        int res = 1;\n     \
    \   for (auto p : f) {\n            res *= (1 + p.second);\n        }\n      \
    \  return res;\n    }\n\n    int totient(int n) const {\n        auto f = prime_factors(n);\n\
    \        int res = n;\n        for (auto p : f) {\n            res /= p.first;\n\
    \        }\n        for (auto p : f) {\n            res *= p.first - 1;\n    \
    \    }\n        return res;\n    }\n\n    int prev_prime(int n) const {\n    \
    \    int l = 0, r = pr.size();\n        while (r - l > 1) {\n            int m\
    \ = (l + r) / 2;\n            if (pr[m] < n)\n                l = m;\n       \
    \     else\n                r = m;\n        }\n        return pr[l];\n    }\n\n\
    \    int next_prime(int n) const {\n        int l = 0, r = pr.size();\n      \
    \  while (r - l > 1) {\n            int m = (l + r) / 2;\n            if (pr[m]\
    \ <= n)\n                l = m;\n            else\n                r = m;\n  \
    \      }\n        return pr[r];\n    }\n\n    bool is_prime(int n) const {\n \
    \       if (n < 2) return false;\n        return div[n] == n;\n    }\n\n    vector<pair<int,\
    \ int>> prime_factors(int n) const {\n        vector<pair<int, int>> res;\n  \
    \      int x = n;\n        while (2 <= x) {\n            if (res.empty() || res.back().first\
    \ != div[x]) {\n                res.push_back({div[x], 1});\n            } else\
    \ {\n                res.back().second++;\n            }\n            x /= div[x];\n\
    \        }\n        return res;\n    }\n\n    vector<int> get_divisors(int n)\
    \ const {\n        vector<int> res = {1};\n        auto pf = prime_factors(n);\n\
    \        for (auto p : pf) {\n            int s = (int)res.size();\n         \
    \   for (int i = 0; i < s; i++) {\n                int m = 1;\n              \
    \  for (int j = 0; j < (int)p.second; j++) {\n                    m *= p.first;\n\
    \                    res.push_back(res[i] * m);\n                }\n         \
    \   }\n        }\n        sort(res.begin(), res.end());\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Sieve of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\
    \u30C6\u30CD\u30B9\u306E\u7BE9)\n */\nclass SieveOfEratosthenes {\n  private:\n\
    \    int siz;\n    vector<int> div, pr, cnt;\n\n  public:\n    SieveOfEratosthenes(int\
    \ n) : siz(n), div(n + 1), pr(0), cnt(n + 1) {\n        div[1] = 1;\n        for\
    \ (int i = 2; i <= n; i++) {\n            if (div[i] != 0) continue;\n       \
    \     pr.push_back(i);\n            for (int j = i; j <= n; j += i) {\n      \
    \          if (div[j] == 0) div[j] = i;\n                cnt[j]++;\n         \
    \   }\n        }\n    }\n\n    int nth_prime(int n) const { return pr[n]; }\n\n\
    \    int count_prime(int n) const {\n        if (n < 2) return 0;\n        return\
    \ cnt[n];\n    }\n\n    int count_divisors(int n) const {\n        auto f = prime_factors(n);\n\
    \        int res = 1;\n        for (auto p : f) {\n            res *= (1 + p.second);\n\
    \        }\n        return res;\n    }\n\n    int totient(int n) const {\n   \
    \     auto f = prime_factors(n);\n        int res = n;\n        for (auto p :\
    \ f) {\n            res /= p.first;\n        }\n        for (auto p : f) {\n \
    \           res *= p.first - 1;\n        }\n        return res;\n    }\n\n   \
    \ int prev_prime(int n) const {\n        int l = 0, r = pr.size();\n        while\
    \ (r - l > 1) {\n            int m = (l + r) / 2;\n            if (pr[m] < n)\n\
    \                l = m;\n            else\n                r = m;\n        }\n\
    \        return pr[l];\n    }\n\n    int next_prime(int n) const {\n        int\
    \ l = 0, r = pr.size();\n        while (r - l > 1) {\n            int m = (l +\
    \ r) / 2;\n            if (pr[m] <= n)\n                l = m;\n            else\n\
    \                r = m;\n        }\n        return pr[r];\n    }\n\n    bool is_prime(int\
    \ n) const {\n        if (n < 2) return false;\n        return div[n] == n;\n\
    \    }\n\n    vector<pair<int, int>> prime_factors(int n) const {\n        vector<pair<int,\
    \ int>> res;\n        int x = n;\n        while (2 <= x) {\n            if (res.empty()\
    \ || res.back().first != div[x]) {\n                res.push_back({div[x], 1});\n\
    \            } else {\n                res.back().second++;\n            }\n \
    \           x /= div[x];\n        }\n        return res;\n    }\n\n    vector<int>\
    \ get_divisors(int n) const {\n        vector<int> res = {1};\n        auto pf\
    \ = prime_factors(n);\n        for (auto p : pf) {\n            int s = (int)res.size();\n\
    \            for (int i = 0; i < s; i++) {\n                int m = 1;\n     \
    \           for (int j = 0; j < (int)p.second; j++) {\n                    m *=\
    \ p.first;\n                    res.push_back(res[i] * m);\n                }\n\
    \            }\n        }\n        sort(res.begin(), res.end());\n        return\
    \ res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/sieve_of_eratosthenes.hpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/sieve_of_eratosthenes.hpp
layout: document
redirect_from:
- /library/math/sieve_of_eratosthenes.hpp
- /library/math/sieve_of_eratosthenes.hpp.html
title: "Sieve of Eratosthenes (\u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\
  )"
---
