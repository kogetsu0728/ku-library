---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Merge-Sort Tree
    links: []
  bundledCode: "#line 2 \"data_structure/merge_sort_tree.hpp\"\n\n/**\n * @brief Merge-Sort\
    \ Tree\n */\nclass MergeSortTree {\n  using ll = long long;\n\n private:\n  int\
    \ n;\n  vector<vector<ll>> v, s;\n\n  void update(int i) {\n    v[i] = vector<ll>();\n\
    \    queue<ll> a, b;\n    for (ll x : v[i << 1]) {\n      a.emplace(x);\n    }\n\
    \    for (ll x : v[(i << 1) | 1]) {\n      b.emplace(x);\n    }\n\n    while (!a.empty()\
    \ || !b.empty()) {\n      if (b.empty() || (!a.empty() && a.front() < b.front()))\
    \ {\n        v[i].emplace_back(a.front());\n        a.pop();\n      } else {\n\
    \        v[i].emplace_back(b.front());\n        b.pop();\n      }\n    }\n\n \
    \   s[i] = vector<ll>(v[i].size() + 1);\n    for (int j = 0; j < int(v[i].size());\
    \ j++) {\n      s[i][j + 1] = s[i][j] + v[i][j];\n    }\n  }\n\n public:\n  MergeSortTree(vector<ll>\
    \ _v) {\n    n = 1;\n    while (n < int(_v.size())) {\n      n *= 2;\n    }\n\
    \    while (int(_v.size()) < n) {\n      _v.emplace_back(LLONG_MAX);\n    }\n\n\
    \    v = vector(2 * n, vector<ll>({MAX_A}));\n    s = vector(2 * n, vector<ll>({0LL,\
    \ MAX_A}));\n\n    for (int i = 0; i < n; i++) {\n      v[n + i] = vector<ll>({_v[i]});\n\
    \      s[n + i] = vector<ll>({0, _v[i]});\n    }\n\n    for (int i = n - 1; i\
    \ >= 1; i--) {\n      update(i);\n    }\n  }\n\n  /**\n   * @brief [l, r)\u306B\
    \u542B\u307E\u308C\u308Ba\u4EE5\u4E0B\u306E\u6570\u306E\u7DCF\u548C\n   */\n \
    \ ll sum(int l, int r, ll a) const {\n    l += n;\n    r += n;\n    ll res = 0;\n\
    \    while (l < r) {\n      if (l & 1) {\n        int t =\n            distance(v[l].begin(),\
    \ upper_bound(v[l].begin(), v[l].end(), a));\n        res += s[l][t];\n      \
    \  l++;\n      }\n      if (r & 1) {\n        r--;\n        int t =\n        \
    \    distance(v[r].begin(), upper_bound(v[r].begin(), v[r].end(), a));\n     \
    \   res += s[r][t];\n      }\n      l >>= 1;\n      r >>= 1;\n    }\n\n    return\
    \ res;\n  }\n\n  /**\n   * @brief [l, r)\u306B\u542B\u307E\u308C\u308Ba\u4EE5\u4E0B\
    \u306E\u6570\u306E\u500B\u6570\n   */\n  int count(int l, int r, ll a) const {\n\
    \    l += n;\n    r += n;\n    int res = 0;\n    while (l < r) {\n      if (l\
    \ & 1) {\n        int t =\n            distance(v[l].begin(), upper_bound(v[l].begin(),\
    \ v[l].end(), a));\n        res += t;\n        l++;\n      }\n      if (r & 1)\
    \ {\n        r--;\n        int t =\n            distance(v[r].begin(), upper_bound(v[r].begin(),\
    \ v[r].end(), a));\n        res += t;\n      }\n      l >>= 1;\n      r >>= 1;\n\
    \    }\n\n    return res;\n  }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Merge-Sort Tree\n */\nclass MergeSortTree\
    \ {\n  using ll = long long;\n\n private:\n  int n;\n  vector<vector<ll>> v, s;\n\
    \n  void update(int i) {\n    v[i] = vector<ll>();\n    queue<ll> a, b;\n    for\
    \ (ll x : v[i << 1]) {\n      a.emplace(x);\n    }\n    for (ll x : v[(i << 1)\
    \ | 1]) {\n      b.emplace(x);\n    }\n\n    while (!a.empty() || !b.empty())\
    \ {\n      if (b.empty() || (!a.empty() && a.front() < b.front())) {\n       \
    \ v[i].emplace_back(a.front());\n        a.pop();\n      } else {\n        v[i].emplace_back(b.front());\n\
    \        b.pop();\n      }\n    }\n\n    s[i] = vector<ll>(v[i].size() + 1);\n\
    \    for (int j = 0; j < int(v[i].size()); j++) {\n      s[i][j + 1] = s[i][j]\
    \ + v[i][j];\n    }\n  }\n\n public:\n  MergeSortTree(vector<ll> _v) {\n    n\
    \ = 1;\n    while (n < int(_v.size())) {\n      n *= 2;\n    }\n    while (int(_v.size())\
    \ < n) {\n      _v.emplace_back(LLONG_MAX);\n    }\n\n    v = vector(2 * n, vector<ll>({MAX_A}));\n\
    \    s = vector(2 * n, vector<ll>({0LL, MAX_A}));\n\n    for (int i = 0; i < n;\
    \ i++) {\n      v[n + i] = vector<ll>({_v[i]});\n      s[n + i] = vector<ll>({0,\
    \ _v[i]});\n    }\n\n    for (int i = n - 1; i >= 1; i--) {\n      update(i);\n\
    \    }\n  }\n\n  /**\n   * @brief [l, r)\u306B\u542B\u307E\u308C\u308Ba\u4EE5\u4E0B\
    \u306E\u6570\u306E\u7DCF\u548C\n   */\n  ll sum(int l, int r, ll a) const {\n\
    \    l += n;\n    r += n;\n    ll res = 0;\n    while (l < r) {\n      if (l &\
    \ 1) {\n        int t =\n            distance(v[l].begin(), upper_bound(v[l].begin(),\
    \ v[l].end(), a));\n        res += s[l][t];\n        l++;\n      }\n      if (r\
    \ & 1) {\n        r--;\n        int t =\n            distance(v[r].begin(), upper_bound(v[r].begin(),\
    \ v[r].end(), a));\n        res += s[r][t];\n      }\n      l >>= 1;\n      r\
    \ >>= 1;\n    }\n\n    return res;\n  }\n\n  /**\n   * @brief [l, r)\u306B\u542B\
    \u307E\u308C\u308Ba\u4EE5\u4E0B\u306E\u6570\u306E\u500B\u6570\n   */\n  int count(int\
    \ l, int r, ll a) const {\n    l += n;\n    r += n;\n    int res = 0;\n    while\
    \ (l < r) {\n      if (l & 1) {\n        int t =\n            distance(v[l].begin(),\
    \ upper_bound(v[l].begin(), v[l].end(), a));\n        res += t;\n        l++;\n\
    \      }\n      if (r & 1) {\n        r--;\n        int t =\n            distance(v[r].begin(),\
    \ upper_bound(v[r].begin(), v[r].end(), a));\n        res += t;\n      }\n   \
    \   l >>= 1;\n      r >>= 1;\n    }\n\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/merge_sort_tree.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:53:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data_structure/merge_sort_tree.hpp
layout: document
redirect_from:
- /library/data_structure/merge_sort_tree.hpp
- /library/data_structure/merge_sort_tree.hpp.html
title: Merge-Sort Tree
---
