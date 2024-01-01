---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algo/verify/aoj/DSL_1_B.test.cpp
    title: algo/verify/aoj/DSL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algo/data_structure/weighted_union_find.hpp\"\n\ntemplate<class\
    \ T> class WeightedUnionFind{\n\tprivate:\n\t\tint n, comp;\n\t\tvector<int> par,\
    \ rank;\n\t\tvector<T> wei;\n\n\tpublic:\n\t\tWeightedUnionFind(const int _n=0,\
    \ const T _e=0):\n\t\t\tn(_n), comp(_n), par(_n, -1), rank(_n), wei(n,_e){}\n\n\
    \t\tint component() const {\n\t\t\treturn comp;\n\t\t}\n\n\t\tint size(int x){\n\
    \t\t\treturn -par[leader(x)];\n\t\t}\n\n\t\tint leader(int x){\n\t\t\tif(par[x]<0)\
    \ return x;\n\t\t\tint rx = leader(par[x]);\n\t\t\twei[x] += wei[par[x]];\n\t\t\
    \treturn par[x] = rx;\n\t\t}\n\n\t\tT weight(int x){\n\t\t\tleader(x);\n\t\t\t\
    return wei[x];\n\t\t}\n\n\t\tbool same(int x, int y){\n\t\t\treturn leader(x)==leader(y);\n\
    \t\t}\n\n\t\tbool merge(int x, int y, T w){\n\t\t\tw += weight(x) - weight(y);\n\
    \t\t\tx = leader(x), y = leader(y);\n\t\t\tif(x==y) return false;\n\t\t\tcomp--;\n\
    \t\t\tif(rank[x]<rank[y]){\n\t\t\t\tswap(x, y);\n\t\t\t\tw = -w;\n\t\t\t}\n\t\t\
    \tif(rank[x]==rank[y]) rank[x]++;\n\t\t\tpar[x] += par[y];\n\t\t\tpar[y] = x;\n\
    \t\t\twei[y] = w;\n\t\t\treturn true;\n\t\t}\n\n\t\tT diff(int x, int y){\n\t\t\
    \tassert(same(x, y));\n\t\t\treturn weight(y) - weight(x);\n\t\t}\n\n\t\tvector<vector<int>>\
    \ groups(){\n\t\t\tvector<vector<int>> member(n), res;\n\t\t\tfor(int i=0; i<n;\
    \ i++){\n\t\t\t\tmember[leader(i)].push_back(i);\n\t\t\t}\n\t\t\tfor(int i=0;\
    \ i<n; i++){\n\t\t\t\tif(!member[i].empty()){\n\t\t\t\t\tres.push_back(member[i]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T> class WeightedUnionFind{\n\tprivate:\n\t\
    \tint n, comp;\n\t\tvector<int> par, rank;\n\t\tvector<T> wei;\n\n\tpublic:\n\t\
    \tWeightedUnionFind(const int _n=0, const T _e=0):\n\t\t\tn(_n), comp(_n), par(_n,\
    \ -1), rank(_n), wei(n,_e){}\n\n\t\tint component() const {\n\t\t\treturn comp;\n\
    \t\t}\n\n\t\tint size(int x){\n\t\t\treturn -par[leader(x)];\n\t\t}\n\n\t\tint\
    \ leader(int x){\n\t\t\tif(par[x]<0) return x;\n\t\t\tint rx = leader(par[x]);\n\
    \t\t\twei[x] += wei[par[x]];\n\t\t\treturn par[x] = rx;\n\t\t}\n\n\t\tT weight(int\
    \ x){\n\t\t\tleader(x);\n\t\t\treturn wei[x];\n\t\t}\n\n\t\tbool same(int x, int\
    \ y){\n\t\t\treturn leader(x)==leader(y);\n\t\t}\n\n\t\tbool merge(int x, int\
    \ y, T w){\n\t\t\tw += weight(x) - weight(y);\n\t\t\tx = leader(x), y = leader(y);\n\
    \t\t\tif(x==y) return false;\n\t\t\tcomp--;\n\t\t\tif(rank[x]<rank[y]){\n\t\t\t\
    \tswap(x, y);\n\t\t\t\tw = -w;\n\t\t\t}\n\t\t\tif(rank[x]==rank[y]) rank[x]++;\n\
    \t\t\tpar[x] += par[y];\n\t\t\tpar[y] = x;\n\t\t\twei[y] = w;\n\t\t\treturn true;\n\
    \t\t}\n\n\t\tT diff(int x, int y){\n\t\t\tassert(same(x, y));\n\t\t\treturn weight(y)\
    \ - weight(x);\n\t\t}\n\n\t\tvector<vector<int>> groups(){\n\t\t\tvector<vector<int>>\
    \ member(n), res;\n\t\t\tfor(int i=0; i<n; i++){\n\t\t\t\tmember[leader(i)].push_back(i);\n\
    \t\t\t}\n\t\t\tfor(int i=0; i<n; i++){\n\t\t\t\tif(!member[i].empty()){\n\t\t\t\
    \t\tres.push_back(member[i]);\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/data_structure/weighted_union_find.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algo/verify/aoj/DSL_1_B.test.cpp
documentation_of: algo/data_structure/weighted_union_find.hpp
layout: document
redirect_from:
- /library/algo/data_structure/weighted_union_find.hpp
- /library/algo/data_structure/weighted_union_find.hpp.html
title: algo/data_structure/weighted_union_find.hpp
---
