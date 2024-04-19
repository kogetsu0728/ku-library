---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/GRL_4_A.test.cpp
    title: verify/aoj/GRL_4_A.test.cpp
  - icon: ':x:'
    path: verify/yukicoder/468.test.cpp
    title: verify/yukicoder/468.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n\nclass TopologicalSort{\n\
    \tprivate:\n\t\tbool init;\n\t\tint n;\n\t\tvector<vector<int>> g;\n\t\tvector<int>\
    \ p;\n\n\tpublic:\n\t\tTopologicalSort(): TopologicalSort(0) {}\n\t\tTopologicalSort(int\
    \ _n): init(false), n(_n), g(_n){}\n\n\t\tvoid add_edge(int u, int v){\n\t\t\t\
    assert(!init);\n\t\t\tg[u].push_back(v);\n\t\t}\n\n\t\tbool build(){\n\t\t\tassert(!init);\n\
    \t\t\tinit = true;\n\t\t\tvector<int> cnt(n);\n\t\t\tfor(int v=0; v<n; v++){\n\
    \t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\tcnt[nv]++;\n\t\t\t\t}\n\t\t\t}\n\t\t\tqueue<int>\
    \ que;\n\t\t\tfor(int v=0; v<n; v++){\n\t\t\t\tif(cnt[v]==0){\n\t\t\t\t\tque.push(v);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\twhile(!que.empty()){\n\t\t\t\tint v = que.front();\n\
    \t\t\t\tque.pop();\n\t\t\t\tp.push_back(v);\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\
    \t\tcnt[nv]--;\n\t\t\t\t\tif(cnt[nv]==0){\n\t\t\t\t\t\tque.push(nv);\n\t\t\t\t\
    \t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(n!=int(p.size())){\n\t\t\t\tp.clear();\n\t\t\
    \t\treturn false;\n\t\t\t}\n\t\t\treturn true;\n\t\t}\n\n\t\tint operator[](const\
    \ int i) const {\n\t\t\tassert(init);\n\t\t\treturn p[i];\n\t\t}\n};\n"
  code: "#pragma once\n\nclass TopologicalSort{\n\tprivate:\n\t\tbool init;\n\t\t\
    int n;\n\t\tvector<vector<int>> g;\n\t\tvector<int> p;\n\n\tpublic:\n\t\tTopologicalSort():\
    \ TopologicalSort(0) {}\n\t\tTopologicalSort(int _n): init(false), n(_n), g(_n){}\n\
    \n\t\tvoid add_edge(int u, int v){\n\t\t\tassert(!init);\n\t\t\tg[u].push_back(v);\n\
    \t\t}\n\n\t\tbool build(){\n\t\t\tassert(!init);\n\t\t\tinit = true;\n\t\t\tvector<int>\
    \ cnt(n);\n\t\t\tfor(int v=0; v<n; v++){\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\t\
    cnt[nv]++;\n\t\t\t\t}\n\t\t\t}\n\t\t\tqueue<int> que;\n\t\t\tfor(int v=0; v<n;\
    \ v++){\n\t\t\t\tif(cnt[v]==0){\n\t\t\t\t\tque.push(v);\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\twhile(!que.empty()){\n\t\t\t\tint v = que.front();\n\t\t\t\tque.pop();\n\t\
    \t\t\tp.push_back(v);\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\tcnt[nv]--;\n\t\t\t\
    \t\tif(cnt[nv]==0){\n\t\t\t\t\t\tque.push(nv);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\tif(n!=int(p.size())){\n\t\t\t\tp.clear();\n\t\t\t\treturn false;\n\t\t\
    \t}\n\t\t\treturn true;\n\t\t}\n\n\t\tint operator[](const int i) const {\n\t\t\
    \tassert(init);\n\t\t\treturn p[i];\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-04-19 21:31:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
