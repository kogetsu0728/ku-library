---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.hpp
    title: graph/topological_sort.hpp
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
  bundledCode: "#line 1 \"verify/aoj/GRL_4_A.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"graph/topological_sort.hpp\"\
    \n\nclass TopologicalSort {\n private:\n  bool init;\n  int n;\n  vector<vector<int>>\
    \ g;\n  vector<int> p;\n\n public:\n  TopologicalSort() : TopologicalSort(0) {}\n\
    \  TopologicalSort(int _n) : init(false), n(_n), g(_n) {}\n\n  void add_edge(int\
    \ u, int v) {\n    assert(!init);\n\n    g[u].push_back(v);\n  }\n\n  bool build()\
    \ {\n    assert(!init);\n    init = true;\n\n    vector<int> cnt(n);\n    for\
    \ (int v = 0; v < n; v++) {\n      for (int nv : g[v]) {\n        cnt[nv]++;\n\
    \      }\n    }\n    queue<int> que;\n    for (int v = 0; v < n; v++) {\n    \
    \  if (cnt[v] == 0) {\n        que.push(v);\n      }\n    }\n    while (!que.empty())\
    \ {\n      int v = que.front();\n      que.pop();\n      p.push_back(v);\n   \
    \   for (int nv : g[v]) {\n        cnt[nv]--;\n        if (cnt[nv] == 0) {\n \
    \         que.push(nv);\n        }\n      }\n    }\n    if (n != int(p.size()))\
    \ {\n      p.clear();\n      return false;\n    }\n    return true;\n  }\n\n \
    \ int operator[](const int i) const {\n    assert(init);\n\n    return p[i];\n\
    \  }\n};\n#line 8 \"verify/aoj/GRL_4_A.test.cpp\"\n\nint main() {\n  int N, M;\n\
    \  cin >> N >> M;\n  TopologicalSort ts(N);\n  for (int i = 0; i < M; i++) {\n\
    \    int u, v;\n    cin >> u >> v;\n    ts.add_edge(u, v);\n  }\n\n  cout << (ts.build()\
    \ ? 0 : 1) << endl;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/topological_sort.hpp\"\
    \n\nint main() {\n  int N, M;\n  cin >> N >> M;\n  TopologicalSort ts(N);\n  for\
    \ (int i = 0; i < M; i++) {\n    int u, v;\n    cin >> u >> v;\n    ts.add_edge(u,\
    \ v);\n  }\n\n  cout << (ts.build() ? 0 : 1) << endl;\n}\n"
  dependsOn:
  - graph/topological_sort.hpp
  isVerificationFile: true
  path: verify/aoj/GRL_4_A.test.cpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/GRL_4_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/GRL_4_A.test.cpp
- /verify/verify/aoj/GRL_4_A.test.cpp.html
title: verify/aoj/GRL_4_A.test.cpp
---
