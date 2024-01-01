---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algo/data_structure/rollback_union_find.hpp
    title: algo/data_structure/rollback_union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"algo/verify/yosupo/persistent_unionfind.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"algo/data_structure/rollback_union_find.hpp\"\
    \n\nclass RollbackUnionFind{\n\tprivate:\n\t\tint n, comp;\n\t\tvector<int> par;\n\
    \t\tstack<pair<int,int>> his;\n\n\tpublic:\n\t\tRollbackUnionFind():RollbackUnionFind(0){}\n\
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
    }\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n#line 7 \"algo/verify/yosupo/persistent_unionfind.test.cpp\"\
    \n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<vector<int>> g(Q+1);\n\
    \tvector<int> t(Q), k(Q), u(Q), v(Q);\n\tfor(int i=0; i<Q; i++){\n\t\tcin >> t[i]\
    \ >> k[i] >> u[i] >> v[i];\n\t\tg[k[i]+1].push_back(i+1);\n\t}\n\n\tRollbackUnionFind\
    \ uf(N);\n\tvector<bool> ans(Q);\n\tauto dfs = [&](auto &self, int now) -> void{\n\
    \t\tnow--;\n\t\tif(now!=-1){\n\t\t\tif(t[now]==0){\n\t\t\t\tuf.merge(u[now], v[now]);\n\
    \t\t\t}else{\n\t\t\t\tans[now] = uf.same(u[now], v[now]);\n\t\t\t}\n\t\t}\n\t\t\
    for(int nxt:g[now+1]){\n\t\t\tself(self, nxt);\n\t\t}\n\t\tif(now!=-1 && t[now]==0){\n\
    \t\t\tuf.undo();\n\t\t}\n\t};\n\n\tdfs(dfs, 0);\n\n\tfor(int i=0; i<Q; i++){\n\
    \t\tif(t[i]==1){\n\t\t\tcout << (ans[i]?1:0) << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/rollback_union_find.hpp\"\
    \n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<vector<int>> g(Q+1);\n\
    \tvector<int> t(Q), k(Q), u(Q), v(Q);\n\tfor(int i=0; i<Q; i++){\n\t\tcin >> t[i]\
    \ >> k[i] >> u[i] >> v[i];\n\t\tg[k[i]+1].push_back(i+1);\n\t}\n\n\tRollbackUnionFind\
    \ uf(N);\n\tvector<bool> ans(Q);\n\tauto dfs = [&](auto &self, int now) -> void{\n\
    \t\tnow--;\n\t\tif(now!=-1){\n\t\t\tif(t[now]==0){\n\t\t\t\tuf.merge(u[now], v[now]);\n\
    \t\t\t}else{\n\t\t\t\tans[now] = uf.same(u[now], v[now]);\n\t\t\t}\n\t\t}\n\t\t\
    for(int nxt:g[now+1]){\n\t\t\tself(self, nxt);\n\t\t}\n\t\tif(now!=-1 && t[now]==0){\n\
    \t\t\tuf.undo();\n\t\t}\n\t};\n\n\tdfs(dfs, 0);\n\n\tfor(int i=0; i<Q; i++){\n\
    \t\tif(t[i]==1){\n\t\t\tcout << (ans[i]?1:0) << endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - algo/data_structure/rollback_union_find.hpp
  isVerificationFile: true
  path: algo/verify/yosupo/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-01-01 13:30:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: algo/verify/yosupo/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/algo/verify/yosupo/persistent_unionfind.test.cpp
- /verify/algo/verify/yosupo/persistent_unionfind.test.cpp.html
title: algo/verify/yosupo/persistent_unionfind.test.cpp
---
