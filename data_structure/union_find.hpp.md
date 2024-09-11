---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"data_structure/union_find.hpp\"\n\n/**\n * @brief Union\
    \ Find\n */\nclass UnionFind {\n  private:\n    int n, comp;\n    vector<int>\
    \ par;\n\n  public:\n    UnionFind(const int _n = 0) : n(_n), comp(_n), par(_n,\
    \ -1) {}\n\n    int component() const { return comp; }\n\n    int size(int x)\
    \ { return -par[leader(x)]; }\n\n    int leader(int x) {\n        if (par[x] <\
    \ 0) return x;\n        return par[x] = leader(par[x]);\n    }\n\n    bool same(int\
    \ x, int y) { return leader(x) == leader(y); }\n\n    bool merge(int x, int y)\
    \ {\n        x = leader(x), y = leader(y);\n        if (x == y) return false;\n\
    \        comp--;\n        if (par[x] > par[y]) swap(x, y);\n        par[x] +=\
    \ par[y];\n        par[y] = x;\n        return true;\n    }\n\n    vector<vector<int>>\
    \ groups() {\n        vector<vector<int>> member(n), res;\n        for (int i\
    \ = 0; i < n; i++) {\n            member[leader(i)].push_back(i);\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            if (!member[i].empty()) {\n\
    \                res.push_back(member[i]);\n            }\n        }\n       \
    \ return res;\n    }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Union Find\n */\nclass UnionFind {\n  private:\n\
    \    int n, comp;\n    vector<int> par;\n\n  public:\n    UnionFind(const int\
    \ _n = 0) : n(_n), comp(_n), par(_n, -1) {}\n\n    int component() const { return\
    \ comp; }\n\n    int size(int x) { return -par[leader(x)]; }\n\n    int leader(int\
    \ x) {\n        if (par[x] < 0) return x;\n        return par[x] = leader(par[x]);\n\
    \    }\n\n    bool same(int x, int y) { return leader(x) == leader(y); }\n\n \
    \   bool merge(int x, int y) {\n        x = leader(x), y = leader(y);\n      \
    \  if (x == y) return false;\n        comp--;\n        if (par[x] > par[y]) swap(x,\
    \ y);\n        par[x] += par[y];\n        par[y] = x;\n        return true;\n\
    \    }\n\n    vector<vector<int>> groups() {\n        vector<vector<int>> member(n),\
    \ res;\n        for (int i = 0; i < n; i++) {\n            member[leader(i)].push_back(i);\n\
    \        }\n        for (int i = 0; i < n; i++) {\n            if (!member[i].empty())\
    \ {\n                res.push_back(member[i]);\n            }\n        }\n   \
    \     return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2024-09-11 11:30:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind.test.cpp
documentation_of: data_structure/union_find.hpp
layout: document
redirect_from:
- /library/data_structure/union_find.hpp
- /library/data_structure/union_find.hpp.html
title: Union Find
---
