---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: tree/heavy_light_decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/yosupo/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"tree/heavy_light_decomposition.hpp\"\
    \n\nclass HeavyLightDecomposition{\n\tprivate:\n\t\tbool init;\n\t\tint n;\n\t\
    \tvector<vector<int>> g;\n\t\tvector<int> siz, par, dep, top, in, out;\n\n\t\t\
    void dfs_siz(int v, int p){\n\t\t\tpar[v] = p;\n\t\t\tfor(int &nv:g[v]){\n\t\t\
    \t\tif(nv==p){\n\t\t\t\t\tif(nv==g[v].back()) break;\n\t\t\t\t\tswap(nv, g[v].back());\n\
    \t\t\t\t}\n\t\t\t\tdfs_siz(nv, v);\n\t\t\t\tsiz[v] += siz[nv];\n\t\t\t\tif(siz[nv]>siz[g[v][0]]){\n\
    \t\t\t\t\tswap(nv, g[v][0]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tvoid dfs_hld(int\
    \ v, int p, int &i){\n\t\t\tin[v] = i++;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p)\
    \ continue;\n\t\t\t\tdep[nv] = dep[v]+1;\n\t\t\t\tif(nv==g[v][0]) top[nv] = top[v];\n\
    \t\t\t\telse top[nv] = nv;\n\t\t\t\tdfs_hld(nv, v, i);\n\t\t\t}\n\t\t\tout[v]\
    \ = i;\n\t\t}\n\n\tpublic:\n\t\tHeavyLightDecomposition(): HeavyLightDecomposition(0)\
    \ {}\n\t\tHeavyLightDecomposition(const int _n):\n\t\t\tinit(false), n(_n), g(_n),\
    \ siz(_n, 1), par(_n, -1),\n\t\t\tdep(_n), top(_n), in(_n), out(_n){}\n\n\t\t\
    void add_edge(int u, int v){\n\t\t\tassert(!init);\n\t\t\tg[u].push_back(v);\n\
    \t\t\tg[v].push_back(u);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tassert(!init);\n\t\
    \t\tinit = true;\n\t\t\tdfs_siz(0, -1);\n\t\t\tint i{};\n\t\t\tdfs_hld(0, -1,\
    \ i);\n\t\t}\n\n\t\tint depth(int v) const {\n\t\t\tassert(init);\n\t\t\treturn\
    \ dep[v];\n\t\t}\n\n\t\tint lca(int u, int v) const {\n\t\t\tassert(init);\n\t\
    \t\twhile(true){\n\t\t\t\tif(in[u]>in[v]) swap(u, v);\n\t\t\t\tif(top[u]==top[v])\
    \ return u;\n\t\t\t\tv = par[top[v]];\n\t\t\t}\n\t\t}\n\n\t\tvoid node_query(int\
    \ v, const function<void(int)> &func) const {\n\t\t\tassert(init);\n\t\t\tfunc(in[v]);\n\
    \t\t}\n\n\t\tvoid subtree_query(int v, const function<void(int,int)> &func) const\
    \ {\n\t\t\tassert(init);\n\t\t\tfunc(in[v], out[v]);\n\t\t}\n\n\t\tvoid path_query(int\
    \ u, int v, const function<void(int,int)> &func) const {\n\t\t\tassert(init);\n\
    \t\t\twhile(true){\n\t\t\t\tif(in[u]>in[v]) swap(u, v);\n\t\t\t\tfunc(max(in[u],\
    \ in[top[v]]), in[v]+1);\n\t\t\t\tif(top[u]==top[v]) break;\n\t\t\t\tv = par[top[v]];\n\
    \t\t\t}\n\t\t}\n};\n#line 7 \"verify/yosupo/lca.test.cpp\"\n\nint main(){\n\t\
    int N, Q;\n\tcin >> N >> Q;\n\tHeavyLightDecomposition hld(N);\n\tfor(int i=1;\
    \ i<N; i++){\n\t\tint p;\n\t\tcin >> p;\n\t\thld.add_edge(i, p);\n\t}\n\n\thld.build();\n\
    \n\tfor(;Q--;){\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tcout << hld.lca(u, v)\
    \ << endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#include \"../../tree/heavy_light_decomposition.hpp\"\n\
    \nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tHeavyLightDecomposition hld(N);\n\
    \tfor(int i=1; i<N; i++){\n\t\tint p;\n\t\tcin >> p;\n\t\thld.add_edge(i, p);\n\
    \t}\n\n\thld.build();\n\n\tfor(;Q--;){\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t\
    cout << hld.lca(u, v) << endl;\n\t}\n}\n"
  dependsOn:
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: verify/yosupo/lca.test.cpp
  requiredBy: []
  timestamp: '2024-04-19 21:38:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/lca.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/lca.test.cpp
- /verify/verify/yosupo/lca.test.cpp.html
title: verify/yosupo/lca.test.cpp
---
