---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/GRL_4_A.test.cpp
    title: verify/aoj/GRL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/468.test.cpp
    title: verify/yukicoder/468.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n\nclass TopologicalSort {\n\
    \ private:\n  bool init;\n  int n;\n  vector<vector<int>> g;\n  vector<int> p;\n\
    \n public:\n  TopologicalSort() : TopologicalSort(0) {}\n  TopologicalSort(int\
    \ _n) : init(false), n(_n), g(_n) {}\n\n  void add_edge(int u, int v) {\n    assert(!init);\n\
    \n    g[u].push_back(v);\n  }\n\n  bool build() {\n    assert(!init);\n    init\
    \ = true;\n\n    vector<int> cnt(n);\n    for (int v = 0; v < n; v++) {\n    \
    \  for (int nv : g[v]) {\n        cnt[nv]++;\n      }\n    }\n    queue<int> que;\n\
    \    for (int v = 0; v < n; v++) {\n      if (cnt[v] == 0) {\n        que.push(v);\n\
    \      }\n    }\n    while (!que.empty()) {\n      int v = que.front();\n    \
    \  que.pop();\n      p.push_back(v);\n      for (int nv : g[v]) {\n        cnt[nv]--;\n\
    \        if (cnt[nv] == 0) {\n          que.push(nv);\n        }\n      }\n  \
    \  }\n    if (n != int(p.size())) {\n      p.clear();\n      return false;\n \
    \   }\n    return true;\n  }\n\n  int operator[](const int i) const {\n    assert(init);\n\
    \n    return p[i];\n  }\n};\n"
  code: "#pragma once\n\nclass TopologicalSort {\n private:\n  bool init;\n  int n;\n\
    \  vector<vector<int>> g;\n  vector<int> p;\n\n public:\n  TopologicalSort() :\
    \ TopologicalSort(0) {}\n  TopologicalSort(int _n) : init(false), n(_n), g(_n)\
    \ {}\n\n  void add_edge(int u, int v) {\n    assert(!init);\n\n    g[u].push_back(v);\n\
    \  }\n\n  bool build() {\n    assert(!init);\n    init = true;\n\n    vector<int>\
    \ cnt(n);\n    for (int v = 0; v < n; v++) {\n      for (int nv : g[v]) {\n  \
    \      cnt[nv]++;\n      }\n    }\n    queue<int> que;\n    for (int v = 0; v\
    \ < n; v++) {\n      if (cnt[v] == 0) {\n        que.push(v);\n      }\n    }\n\
    \    while (!que.empty()) {\n      int v = que.front();\n      que.pop();\n  \
    \    p.push_back(v);\n      for (int nv : g[v]) {\n        cnt[nv]--;\n      \
    \  if (cnt[nv] == 0) {\n          que.push(nv);\n        }\n      }\n    }\n \
    \   if (n != int(p.size())) {\n      p.clear();\n      return false;\n    }\n\
    \    return true;\n  }\n\n  int operator[](const int i) const {\n    assert(init);\n\
    \n    return p[i];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yukicoder/468.test.cpp
  - verify/aoj/GRL_4_A.test.cpp
documentation_of: graph/topological_sort.hpp
layout: document
redirect_from:
- /library/graph/topological_sort.hpp
- /library/graph/topological_sort.hpp.html
title: graph/topological_sort.hpp
---
