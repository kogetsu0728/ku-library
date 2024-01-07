---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/union_find.hpp
    title: data_structure/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#include <iostream>\n#include <vector>\nusing namespace std;\n\n#line 2 \"\
    data_structure/union_find.hpp\"\nclass UnionFind{\n\tprivate:\n\t\tint n, comp;\n\
    \t\tvector<int> par;\n\n\tpublic:\n\t\tUnionFind(const int _n=0):\n\t\t\tn(_n),\
    \ comp(_n), par(_n,-1){}\n\n\t\tint component() const {\n\t\t\treturn comp;\n\t\
    \t}\n\n\t\tint size(int x){\n\t\t\treturn -par[leader(x)];\n\t\t}\n\n\t\tint leader(int\
    \ x){\n\t\t\tif(par[x]<0) return x;\n\t\t\treturn par[x]=leader(par[x]);\n\t\t\
    }\n\n\t\tbool same(int x, int y){\n\t\t\treturn leader(x)==leader(y);\n\t\t}\n\
    \n\t\tbool merge(int x, int y){\n\t\t\tx=leader(x), y=leader(y);\n\t\t\tif(x==y)\
    \ return false;\n\t\t\tcomp--;\n\t\t\tif(par[x]>par[y]) swap(x, y);\n\t\t\tpar[x]\
    \ += par[y];\n\t\t\tpar[y] = x;\n\t\t\treturn true;\n\t\t}\n\n\t\tvector<vector<int>>\
    \ groups(){\n\t\t\tvector<vector<int>> member(n), res;\n\t\t\tfor(int i=0; i<n;\
    \ i++){\n\t\t\t\tmember[leader(i)].push_back(i);\n\t\t\t}\n\t\t\tfor(int i=0;\
    \ i<n; i++){\n\t\t\t\tif(!member[i].empty()){\n\t\t\t\t\tres.push_back(member[i]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n#line 8 \"verify/yosupo/unionfind.test.cpp\"\
    \n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\t\n\tUnionFind uf(N);\n\tfor(;Q--;){\n\
    \t\tint t, u, v;\n\t\tcin >> t >> u >> v;\n\t\tif(t==0){\n\t\t\tuf.merge(u, v);\n\
    \t\t}else{\n\t\t\tcout << (uf.same(u,v)?1:0) << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include <vector>\nusing namespace std;\n\n#include \"../../data_structure/union_find.hpp\"\
    \n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\t\n\tUnionFind uf(N);\n\tfor(;Q--;){\n\
    \t\tint t, u, v;\n\t\tcin >> t >> u >> v;\n\t\tif(t==0){\n\t\t\tuf.merge(u, v);\n\
    \t\t}else{\n\t\t\tcout << (uf.same(u,v)?1:0) << endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data_structure/union_find.hpp
  isVerificationFile: true
  path: verify/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-01-01 10:28:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/unionfind.test.cpp
- /verify/verify/yosupo/unionfind.test.cpp.html
title: verify/yosupo/unionfind.test.cpp
---
