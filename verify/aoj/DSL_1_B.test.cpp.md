---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/weighted_union_find.hpp
    title: data_structure/weighted_union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"verify/aoj/DSL_1_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data_structure/weighted_union_find.hpp\"\
    \n\ntemplate<class T> class WeightedUnionFind{\n\tprivate:\n\t\tint n, comp;\n\
    \t\tvector<int> par, rank;\n\t\tvector<T> wei;\n\n\tpublic:\n\t\tWeightedUnionFind(const\
    \ int _n=0, const T _e=0):\n\t\t\tn(_n), comp(_n), par(_n, -1), rank(_n), wei(n,_e){}\n\
    \n\t\tint component() const {\n\t\t\treturn comp;\n\t\t}\n\n\t\tint size(int x){\n\
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
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n#line 7 \"verify/aoj/DSL_1_B.test.cpp\"\
    \n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tWeightedUnionFind<int> uf(N);\n\
    \tfor(;Q--;){\n\t\tint t, x, y;\n\t\tcin >> t >> x >> y;\n\t\tif(t==0){\n\t\t\t\
    int z;\n\t\t\tcin >> z;\n\t\t\tuf.merge(x, y, z);\n\t\t}else{\n\t\t\tif(uf.same(x,y)){\n\
    \t\t\t\tcout << uf.diff(x, y) << endl;\n\t\t\t}else{\n\t\t\t\tcout << '?' << endl;\n\
    \t\t\t}\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/weighted_union_find.hpp\"\
    \n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tWeightedUnionFind<int> uf(N);\n\
    \tfor(;Q--;){\n\t\tint t, x, y;\n\t\tcin >> t >> x >> y;\n\t\tif(t==0){\n\t\t\t\
    int z;\n\t\t\tcin >> z;\n\t\t\tuf.merge(x, y, z);\n\t\t}else{\n\t\t\tif(uf.same(x,y)){\n\
    \t\t\t\tcout << uf.diff(x, y) << endl;\n\t\t\t}else{\n\t\t\t\tcout << '?' << endl;\n\
    \t\t\t}\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data_structure/weighted_union_find.hpp
  isVerificationFile: true
  path: verify/aoj/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2024-04-19 21:20:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_1_B.test.cpp
- /verify/verify/aoj/DSL_1_B.test.cpp.html
title: verify/aoj/DSL_1_B.test.cpp
---
