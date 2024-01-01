---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algo/graph/topological_sort.hpp
    title: algo/graph/topological_sort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A
  bundledCode: "#line 1 \"algo/verify/aoj/GRL_4_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <queue>\nusing namespace\
    \ std;\n\n#line 2 \"algo/graph/topological_sort.hpp\"\n\nclass TopologicalSort{\n\
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
    \n\t\tint operator[](const int i) const {\n\t\t\treturn p[i];\n\t\t}\n};\n#line\
    \ 9 \"algo/verify/aoj/GRL_4_A.test.cpp\"\n\nint main(){\n\tint N, M;\n\tcin >>\
    \ N >> M;\n\tTopologicalSort ts(N);\n\tfor(int i=0; i<M; i++){\n\t\tint u, v;\n\
    \t\tcin >> u >> v;\n\t\tts.add_edge(u, v);\n\t}\n\n\tcout << (ts.build()?0:1)\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <iostream>\n#include <vector>\n#include <queue>\nusing namespace\
    \ std;\n\n#include \"../../graph/topological_sort.hpp\"\n\nint main(){\n\tint\
    \ N, M;\n\tcin >> N >> M;\n\tTopologicalSort ts(N);\n\tfor(int i=0; i<M; i++){\n\
    \t\tint u, v;\n\t\tcin >> u >> v;\n\t\tts.add_edge(u, v);\n\t}\n\n\tcout << (ts.build()?0:1)\
    \ << endl;\n}\n"
  dependsOn:
  - algo/graph/topological_sort.hpp
  isVerificationFile: true
  path: algo/verify/aoj/GRL_4_A.test.cpp
  requiredBy: []
  timestamp: '2024-01-01 10:28:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: algo/verify/aoj/GRL_4_A.test.cpp
layout: document
redirect_from:
- /verify/algo/verify/aoj/GRL_4_A.test.cpp
- /verify/algo/verify/aoj/GRL_4_A.test.cpp.html
title: algo/verify/aoj/GRL_4_A.test.cpp
---
