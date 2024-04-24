---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: checker/build_checker.hpp
    title: checker/build_checker.hpp
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
  bundledCode: "#line 2 \"graph/topological_sort.hpp\"\n\n#line 2 \"checker/build_checker.hpp\"\
    \n\nclass BuildChecker{\n\tprivate:\n\t\tbool built;\n\n\tpublic:\n\t\tBuildChecker():\
    \ built(false){}\n\t\t\n\t\tvoid before() const {\n\t\t\tassert(built==false);\n\
    \t\t}\n\n\t\tvoid after() const {\n\t\t\tassert(built==true);\n\t\t}\n\n\t\tvoid\
    \ build(){\n\t\t\tthis->before();\n\t\t\tbuilt = true;\n\t\t}\n};\n#line 4 \"\
    graph/topological_sort.hpp\"\n\nclass TopologicalSort{\n\tprivate:\n\t\tBuildChecker\
    \ build_checker;\n\t\tint n;\n\t\tvector<vector<int>> g;\n\t\tvector<int> p;\n\
    \n\tpublic:\n\t\tTopologicalSort(): TopologicalSort(0) {}\n\t\tTopologicalSort(int\
    \ _n): build_checker(), init(false), n(_n), g(_n){}\n\n\t\tvoid add_edge(int u,\
    \ int v){\n\t\t\tbuild_checker.before();\n\n\t\t\tg[u].push_back(v);\n\t\t}\n\n\
    \t\tbool build(){\n\t\t\tbuild_checker.build();\n\n\t\t\tvector<int> cnt(n);\n\
    \t\t\tfor(int v=0; v<n; v++){\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\tcnt[nv]++;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tqueue<int> que;\n\t\t\tfor(int v=0; v<n; v++){\n\t\t\
    \t\tif(cnt[v]==0){\n\t\t\t\t\tque.push(v);\n\t\t\t\t}\n\t\t\t}\n\t\t\twhile(!que.empty()){\n\
    \t\t\t\tint v = que.front();\n\t\t\t\tque.pop();\n\t\t\t\tp.push_back(v);\n\t\t\
    \t\tfor(int nv:g[v]){\n\t\t\t\t\tcnt[nv]--;\n\t\t\t\t\tif(cnt[nv]==0){\n\t\t\t\
    \t\t\tque.push(nv);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\tif(n!=int(p.size())){\n\
    \t\t\t\tp.clear();\n\t\t\t\treturn false;\n\t\t\t}\n\t\t\treturn true;\n\t\t}\n\
    \n\t\tint operator[](const int i) const {\n\t\t\tbuild_checker.after();\n\n\t\t\
    \treturn p[i];\n\t\t}\n};\n"
  code: "#pragma once\n\n#include \"checker/build_checker.hpp\"\n\nclass TopologicalSort{\n\
    \tprivate:\n\t\tBuildChecker build_checker;\n\t\tint n;\n\t\tvector<vector<int>>\
    \ g;\n\t\tvector<int> p;\n\n\tpublic:\n\t\tTopologicalSort(): TopologicalSort(0)\
    \ {}\n\t\tTopologicalSort(int _n): build_checker(), init(false), n(_n), g(_n){}\n\
    \n\t\tvoid add_edge(int u, int v){\n\t\t\tbuild_checker.before();\n\n\t\t\tg[u].push_back(v);\n\
    \t\t}\n\n\t\tbool build(){\n\t\t\tbuild_checker.build();\n\n\t\t\tvector<int>\
    \ cnt(n);\n\t\t\tfor(int v=0; v<n; v++){\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\t\
    cnt[nv]++;\n\t\t\t\t}\n\t\t\t}\n\t\t\tqueue<int> que;\n\t\t\tfor(int v=0; v<n;\
    \ v++){\n\t\t\t\tif(cnt[v]==0){\n\t\t\t\t\tque.push(v);\n\t\t\t\t}\n\t\t\t}\n\t\
    \t\twhile(!que.empty()){\n\t\t\t\tint v = que.front();\n\t\t\t\tque.pop();\n\t\
    \t\t\tp.push_back(v);\n\t\t\t\tfor(int nv:g[v]){\n\t\t\t\t\tcnt[nv]--;\n\t\t\t\
    \t\tif(cnt[nv]==0){\n\t\t\t\t\t\tque.push(nv);\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\tif(n!=int(p.size())){\n\t\t\t\tp.clear();\n\t\t\t\treturn false;\n\t\t\
    \t}\n\t\t\treturn true;\n\t\t}\n\n\t\tint operator[](const int i) const {\n\t\t\
    \tbuild_checker.after();\n\n\t\t\treturn p[i];\n\t\t}\n};\n"
  dependsOn:
  - checker/build_checker.hpp
  isVerificationFile: false
  path: graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2024-04-24 17:08:54+09:00'
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
