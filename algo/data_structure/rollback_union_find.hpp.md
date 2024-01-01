---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algo/data_structure/rollback_union_find.hpp\"\n\nclass RollbackUnionFind{\n\
    \tprivate:\n\t\tint n, comp;\n\t\tvector<int> par;\n\t\tstack<pair<int,int>> his;\n\
    \n\tpublic:\n\t\tRollbackUnionFind():RollbackUnionFind(0){}\n\t\tRollbackUnionFind(const\
    \ int _n):\n\t\t\tn(_n), comp(_n), par(_n,-1), his(){}\n\n\t\tint size(int x)\
    \ const {\n\t\t\treturn -par[leader(x)];\n\t\t}\n\n\t\tint component() const {\n\
    \t\t\treturn comp;\n\t\t}\n\n\t\tint leader(int x) const {\n\t\t\tif(par[x]<0)\
    \ return x;\n\t\t\treturn leader(par[x]);\n\t\t}\n\n\t\tbool same(int x, int y)\
    \ const {\n\t\t\treturn leader(x)==leader(y);\n\t\t}\n\n\t\tbool merge(int x,\
    \ int y){\n\t\t\tx = leader(x), y = leader(y);\n\t\t\this.push(make_pair(x, par[x]));\n\
    \t\t\this.push(make_pair(y, par[y]));\n\t\t\tif(x==y) return false;\n\t\t\tcomp--;\n\
    \t\t\tif(par[x]>par[y]) swap(x, y);\n\t\t\tpar[x] += par[y];\n\t\t\tpar[y] = x;\n\
    \t\t\treturn true;\n\t\t}\n\n\t\tbool undo(){\n\t\t\tif(his.empty()) return false;\n\
    \t\t\tvector<int> x(2);\n\t\t\tfor(int i=0; i<2; i++){\n\t\t\t\tauto [v,p] = his.top();\n\
    \t\t\t\this.pop();\n\t\t\t\tx[i] = v;\n\t\t\t\tpar[v] = p;\n\t\t\t}\n\t\t\tif(x[0]!=x[1])\
    \ comp++;\n\t\t\treturn true;\n\t\t}\n\n\t\tvoid snapshot(){\n\t\t\twhile(!his.empty())\
    \ his.pop();\n\t\t}\n\n\t\tvoid rollback(){\n\t\t\twhile(!his.empty()) undo();\n\
    \t\t}\n\n\t\tvector<vector<int>> groups() const {\n\t\t\tvector<vector<int>> member(n),\
    \ res;\n\t\t\tfor(int i=0; i<n; i++){\n\t\t\t\tmember[leader(i)].push_back(i);\n\
    \t\t\t}\n\t\t\tfor(int i=0; i<n; i++){\n\t\t\t\tif(!member[i].empty()){\n\t\t\t\
    \t\tres.push_back(member[i]);\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\
    };\n"
  code: "#pragma once\n\nclass RollbackUnionFind{\n\tprivate:\n\t\tint n, comp;\n\t\
    \tvector<int> par;\n\t\tstack<pair<int,int>> his;\n\n\tpublic:\n\t\tRollbackUnionFind():RollbackUnionFind(0){}\n\
    \t\tRollbackUnionFind(const int _n):\n\t\t\tn(_n), comp(_n), par(_n,-1), his(){}\n\
    \n\t\tint size(int x) const {\n\t\t\treturn -par[leader(x)];\n\t\t}\n\n\t\tint\
    \ component() const {\n\t\t\treturn comp;\n\t\t}\n\n\t\tint leader(int x) const\
    \ {\n\t\t\tif(par[x]<0) return x;\n\t\t\treturn leader(par[x]);\n\t\t}\n\n\t\t\
    bool same(int x, int y) const {\n\t\t\treturn leader(x)==leader(y);\n\t\t}\n\n\
    \t\tbool merge(int x, int y){\n\t\t\tx = leader(x), y = leader(y);\n\t\t\this.push(make_pair(x,\
    \ par[x]));\n\t\t\this.push(make_pair(y, par[y]));\n\t\t\tif(x==y) return false;\n\
    \t\t\tcomp--;\n\t\t\tif(par[x]>par[y]) swap(x, y);\n\t\t\tpar[x] += par[y];\n\t\
    \t\tpar[y] = x;\n\t\t\treturn true;\n\t\t}\n\n\t\tbool undo(){\n\t\t\tif(his.empty())\
    \ return false;\n\t\t\tvector<int> x(2);\n\t\t\tfor(int i=0; i<2; i++){\n\t\t\t\
    \tauto [v,p] = his.top();\n\t\t\t\this.pop();\n\t\t\t\tx[i] = v;\n\t\t\t\tpar[v]\
    \ = p;\n\t\t\t}\n\t\t\tif(x[0]!=x[1]) comp++;\n\t\t\treturn true;\n\t\t}\n\n\t\
    \tvoid snapshot(){\n\t\t\twhile(!his.empty()) his.pop();\n\t\t}\n\n\t\tvoid rollback(){\n\
    \t\t\twhile(!his.empty()) undo();\n\t\t}\n\n\t\tvector<vector<int>> groups() const\
    \ {\n\t\t\tvector<vector<int>> member(n), res;\n\t\t\tfor(int i=0; i<n; i++){\n\
    \t\t\t\tmember[leader(i)].push_back(i);\n\t\t\t}\n\t\t\tfor(int i=0; i<n; i++){\n\
    \t\t\t\tif(!member[i].empty()){\n\t\t\t\t\tres.push_back(member[i]);\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/data_structure/rollback_union_find.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algo/data_structure/rollback_union_find.hpp
layout: document
redirect_from:
- /library/algo/data_structure/rollback_union_find.hpp
- /library/algo/data_structure/rollback_union_find.hpp.html
title: algo/data_structure/rollback_union_find.hpp
---
