---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: algo/verify/yukicoder/468.cpp
    title: algo/verify/yukicoder/468.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algo/verify/aoj/GRL_4_A.test.cpp
    title: algo/verify/aoj/GRL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algo/graph/topological_sort.hpp\"\n\nclass TopologicalSort{\n\
    \tprivate:\n\t\tint n;\n\t\tvector<vector<int>> g;\n\t\tvector<int> p;\n\n\tpublic:\n\
    \t\tTopologicalSort():TopologicalSort(0){}\n\t\tTopologicalSort(int _n):\n\t\t\
    \tn(_n), g(_n){}\n\n\t\tvoid add_edge(int u, int v){\n\t\t\tg[u].push_back(v);\n\
    \t\t}\n\n\t\tbool build(){\n\t\t\tvector<int> cnt(n);\n\t\t\tfor(int v=0; v<n;\
    \ v++){\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\tcnt[nv]++;\n\t\t\t\t}\n\t\t\t}\n\
    \t\t\tqueue<int> que;\n\t\t\tfor(int v=0; v<n; v++){\n\t\t\t\tif(cnt[v]==0){\n\
    \t\t\t\t\tque.push(v);\n\t\t\t\t}\n\t\t\t}\n\t\t\twhile(!que.empty()){\n\t\t\t\
    \tint v = que.front();\n\t\t\t\tque.pop();\n\t\t\t\tp.push_back(v);\n\t\t\t\t\
    for(int nv:g[v]){\n\t\t\t\t\tcnt[nv]--;\n\t\t\t\t\tif(cnt[nv]==0){\n\t\t\t\t\t\
    \tque.push(nv);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(n!=int(p.size())){\n\
    \t\t\t\tp.clear();\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\treturn true;\n\t\t}\n\
    \n\t\tint operator[](const int i) const {\n\t\t\treturn p[i];\n\t\t}\n};\n"
  code: "#pragma once\n\nclass TopologicalSort{\n\tprivate:\n\t\tint n;\n\t\tvector<vector<int>>\
    \ g;\n\t\tvector<int> p;\n\n\tpublic:\n\t\tTopologicalSort():TopologicalSort(0){}\n\
    \t\tTopologicalSort(int _n):\n\t\t\tn(_n), g(_n){}\n\n\t\tvoid add_edge(int u,\
    \ int v){\n\t\t\tg[u].push_back(v);\n\t\t}\n\n\t\tbool build(){\n\t\t\tvector<int>\
    \ cnt(n);\n\t\t\tfor(int v=0; v<n; v++){\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\t\
    cnt[nv]++;\n\t\t\t\t}\n\t\t\t}\n\t\t\tqueue<int> que;\n\t\t\tfor(int v=0; v<n;\
    \ v++){\n\t\t\t\tif(cnt[v]==0){\n\t\t\t\t\tque.push(v);\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\twhile(!que.empty()){\n\t\t\t\tint v = que.front();\n\t\t\t\tque.pop();\n\t\
    \t\t\tp.push_back(v);\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\tcnt[nv]--;\n\t\t\t\
    \t\tif(cnt[nv]==0){\n\t\t\t\t\t\tque.push(nv);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\tif(n!=int(p.size())){\n\t\t\t\tp.clear();\n\t\t\t\treturn false;\n\t\t\
    \t}\n\t\t\treturn true;\n\t\t}\n\n\t\tint operator[](const int i) const {\n\t\t\
    \treturn p[i];\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/graph/topological_sort.hpp
  requiredBy:
  - algo/verify/yukicoder/468.cpp
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algo/verify/aoj/GRL_4_A.test.cpp
documentation_of: algo/graph/topological_sort.hpp
layout: document
redirect_from:
- /library/algo/graph/topological_sort.hpp
- /library/algo/graph/topological_sort.hpp.html
title: algo/graph/topological_sort.hpp
---
