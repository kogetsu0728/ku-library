---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algo/verify/yosupo/unionfind.test.cpp
    title: algo/verify/yosupo/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algo/data_structure/union_find.hpp\"\nclass UnionFind{\n\
    \tprivate:\n\t\tint n, comp;\n\t\tvector<int> par;\n\n\tpublic:\n\t\tUnionFind(const\
    \ int _n=0):\n\t\t\tn(_n), comp(_n), par(_n,-1){}\n\n\t\tint component() const\
    \ {\n\t\t\treturn comp;\n\t\t}\n\n\t\tint size(int x){\n\t\t\treturn -par[leader(x)];\n\
    \t\t}\n\n\t\tint leader(int x){\n\t\t\tif(par[x]<0) return x;\n\t\t\treturn par[x]=leader(par[x]);\n\
    \t\t}\n\n\t\tbool same(int x, int y){\n\t\t\treturn leader(x)==leader(y);\n\t\t\
    }\n\n\t\tbool merge(int x, int y){\n\t\t\tx=leader(x), y=leader(y);\n\t\t\tif(x==y)\
    \ return false;\n\t\t\tcomp--;\n\t\t\tif(par[x]>par[y]) swap(x, y);\n\t\t\tpar[x]\
    \ += par[y];\n\t\t\tpar[y] = x;\n\t\t\treturn true;\n\t\t}\n\n\t\tvector<vector<int>>\
    \ groups(){\n\t\t\tvector<vector<int>> member(n), res;\n\t\t\tfor(int i=0; i<n;\
    \ i++){\n\t\t\t\tmember[leader(i)].push_back(i);\n\t\t\t}\n\t\t\tfor(int i=0;\
    \ i<n; i++){\n\t\t\t\tif(!member[i].empty()){\n\t\t\t\t\tres.push_back(member[i]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n"
  code: "#pragma once\nclass UnionFind{\n\tprivate:\n\t\tint n, comp;\n\t\tvector<int>\
    \ par;\n\n\tpublic:\n\t\tUnionFind(const int _n=0):\n\t\t\tn(_n), comp(_n), par(_n,-1){}\n\
    \n\t\tint component() const {\n\t\t\treturn comp;\n\t\t}\n\n\t\tint size(int x){\n\
    \t\t\treturn -par[leader(x)];\n\t\t}\n\n\t\tint leader(int x){\n\t\t\tif(par[x]<0)\
    \ return x;\n\t\t\treturn par[x]=leader(par[x]);\n\t\t}\n\n\t\tbool same(int x,\
    \ int y){\n\t\t\treturn leader(x)==leader(y);\n\t\t}\n\n\t\tbool merge(int x,\
    \ int y){\n\t\t\tx=leader(x), y=leader(y);\n\t\t\tif(x==y) return false;\n\t\t\
    \tcomp--;\n\t\t\tif(par[x]>par[y]) swap(x, y);\n\t\t\tpar[x] += par[y];\n\t\t\t\
    par[y] = x;\n\t\t\treturn true;\n\t\t}\n\n\t\tvector<vector<int>> groups(){\n\t\
    \t\tvector<vector<int>> member(n), res;\n\t\t\tfor(int i=0; i<n; i++){\n\t\t\t\
    \tmember[leader(i)].push_back(i);\n\t\t\t}\n\t\t\tfor(int i=0; i<n; i++){\n\t\t\
    \t\tif(!member[i].empty()){\n\t\t\t\t\tres.push_back(member[i]);\n\t\t\t\t}\n\t\
    \t\t}\n\t\t\treturn res;\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/data_structure/union_find.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algo/verify/yosupo/unionfind.test.cpp
documentation_of: algo/data_structure/union_find.hpp
layout: document
redirect_from:
- /library/algo/data_structure/union_find.hpp
- /library/algo/data_structure/union_find.hpp.html
title: algo/data_structure/union_find.hpp
---
