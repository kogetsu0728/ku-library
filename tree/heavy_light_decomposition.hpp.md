---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: checker/build_checker.hpp
    title: checker/build_checker.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/lca.test.cpp
    title: verify/yosupo/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/vertex_add_path_sum.test.cpp
    title: verify/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/vertex_add_subtree_sum.test.cpp
    title: verify/yosupo/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/heavy_light_decomposition.hpp\"\n\n#line 2 \"checker/build_checker.hpp\"\
    \n\nclass BuildChecker{\n\tprivate:\n\t\tbool built;\n\n\tpublic:\n\t\tBuildChecker():\
    \ built(false){}\n\t\t\n\t\tvoid before() const {\n\t\t\tassert(built==false);\n\
    \t\t}\n\n\t\tvoid after() const {\n\t\t\tassert(built==true);\n\t\t}\n\n\t\tvoid\
    \ build(){\n\t\t\tthis->before();\n\t\t\tbuilt = true;\n\t\t}\n};\n#line 4 \"\
    tree/heavy_light_decomposition.hpp\"\n\nclass HeavyLightDecomposition{\n\tprivate:\n\
    \t\tBuildChecker build_checker;\n\t\tint n;\n\t\tvector<vector<int>> g;\n\t\t\
    vector<int> siz, par, dep, top, in, out;\n\n\t\tvoid dfs_siz(int v, int p){\n\t\
    \t\tpar[v] = p;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p){\n\t\t\t\t\tif(nv==g[v].back())\
    \ break;\n\t\t\t\t\tswap(nv, g[v].back());\n\t\t\t\t}\n\t\t\t\tdfs_siz(nv, v);\n\
    \t\t\t\tsiz[v] += siz[nv];\n\t\t\t\tif(siz[nv]>siz[g[v][0]]){\n\t\t\t\t\tswap(nv,\
    \ g[v][0]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tvoid dfs_hld(int v, int p, int &i){\n\
    \t\t\tin[v] = i++;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p) continue;\n\t\t\
    \t\tdep[nv] = dep[v]+1;\n\t\t\t\tif(nv==g[v][0]) top[nv] = top[v];\n\t\t\t\telse\
    \ top[nv] = nv;\n\t\t\t\tdfs_hld(nv, v, i);\n\t\t\t}\n\t\t\tout[v] = i;\n\t\t\
    }\n\n\tpublic:\n\t\tHeavyLightDecomposition(): HeavyLightDecomposition(0) {}\n\
    \t\tHeavyLightDecomposition(const int _n):\n\t\t\tbuild_checker(), n(_n), g(_n),\
    \ siz(_n, 1), par(_n, -1),\n\t\t\tdep(_n), top(_n), in(_n), out(_n){}\n\n\t\t\
    void add_edge(int u, int v){\n\t\t\tbuild_checker.before();\n\n\t\t\tg[u].push_back(v);\n\
    \t\t\tg[v].push_back(u);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tbuild_checker.build();\n\
    \n\t\t\tdfs_siz(0, -1);\n\t\t\tint i{};\n\t\t\tdfs_hld(0, -1, i);\n\t\t}\n\n\t\
    \tint depth(int v) const {\n\t\t\tbuild_checker.after();\n\n\t\t\treturn dep[v];\n\
    \t\t}\n\n\t\tint lca(int u, int v) const {\n\t\t\tbuild_checker.after();\n\n\t\
    \t\twhile(true){\n\t\t\t\tif(in[u]>in[v]) swap(u, v);\n\t\t\t\tif(top[u]==top[v])\
    \ return u;\n\t\t\t\tv = par[top[v]];\n\t\t\t}\n\t\t}\n\n\t\tvoid node_query(int\
    \ v, const function<void(int)> &func) const {\n\t\t\tbuild_checker.after();\n\n\
    \t\t\tfunc(in[v]);\n\t\t}\n\n\t\tvoid subtree_query(int v, const function<void(int,int)>\
    \ &func) const {\n\t\t\tbuild_checker.after();\n\n\t\t\tfunc(in[v], out[v]);\n\
    \t\t}\n\n\t\tvoid path_query(int u, int v, const function<void(int,int)> &func)\
    \ const {\n\t\t\tbuild_checker.after();\n\n\t\t\twhile(true){\n\t\t\t\tif(in[u]>in[v])\
    \ swap(u, v);\n\t\t\t\tfunc(max(in[u], in[top[v]]), in[v]+1);\n\t\t\t\tif(top[u]==top[v])\
    \ break;\n\t\t\t\tv = par[top[v]];\n\t\t\t}\n\t\t}\n};\n"
  code: "#pragma once\n\n#include \"checker/build_checker.hpp\"\n\nclass HeavyLightDecomposition{\n\
    \tprivate:\n\t\tBuildChecker build_checker;\n\t\tint n;\n\t\tvector<vector<int>>\
    \ g;\n\t\tvector<int> siz, par, dep, top, in, out;\n\n\t\tvoid dfs_siz(int v,\
    \ int p){\n\t\t\tpar[v] = p;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p){\n\t\
    \t\t\t\tif(nv==g[v].back()) break;\n\t\t\t\t\tswap(nv, g[v].back());\n\t\t\t\t\
    }\n\t\t\t\tdfs_siz(nv, v);\n\t\t\t\tsiz[v] += siz[nv];\n\t\t\t\tif(siz[nv]>siz[g[v][0]]){\n\
    \t\t\t\t\tswap(nv, g[v][0]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tvoid dfs_hld(int\
    \ v, int p, int &i){\n\t\t\tin[v] = i++;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p)\
    \ continue;\n\t\t\t\tdep[nv] = dep[v]+1;\n\t\t\t\tif(nv==g[v][0]) top[nv] = top[v];\n\
    \t\t\t\telse top[nv] = nv;\n\t\t\t\tdfs_hld(nv, v, i);\n\t\t\t}\n\t\t\tout[v]\
    \ = i;\n\t\t}\n\n\tpublic:\n\t\tHeavyLightDecomposition(): HeavyLightDecomposition(0)\
    \ {}\n\t\tHeavyLightDecomposition(const int _n):\n\t\t\tbuild_checker(), n(_n),\
    \ g(_n), siz(_n, 1), par(_n, -1),\n\t\t\tdep(_n), top(_n), in(_n), out(_n){}\n\
    \n\t\tvoid add_edge(int u, int v){\n\t\t\tbuild_checker.before();\n\n\t\t\tg[u].push_back(v);\n\
    \t\t\tg[v].push_back(u);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tbuild_checker.build();\n\
    \n\t\t\tdfs_siz(0, -1);\n\t\t\tint i{};\n\t\t\tdfs_hld(0, -1, i);\n\t\t}\n\n\t\
    \tint depth(int v) const {\n\t\t\tbuild_checker.after();\n\n\t\t\treturn dep[v];\n\
    \t\t}\n\n\t\tint lca(int u, int v) const {\n\t\t\tbuild_checker.after();\n\n\t\
    \t\twhile(true){\n\t\t\t\tif(in[u]>in[v]) swap(u, v);\n\t\t\t\tif(top[u]==top[v])\
    \ return u;\n\t\t\t\tv = par[top[v]];\n\t\t\t}\n\t\t}\n\n\t\tvoid node_query(int\
    \ v, const function<void(int)> &func) const {\n\t\t\tbuild_checker.after();\n\n\
    \t\t\tfunc(in[v]);\n\t\t}\n\n\t\tvoid subtree_query(int v, const function<void(int,int)>\
    \ &func) const {\n\t\t\tbuild_checker.after();\n\n\t\t\tfunc(in[v], out[v]);\n\
    \t\t}\n\n\t\tvoid path_query(int u, int v, const function<void(int,int)> &func)\
    \ const {\n\t\t\tbuild_checker.after();\n\n\t\t\twhile(true){\n\t\t\t\tif(in[u]>in[v])\
    \ swap(u, v);\n\t\t\t\tfunc(max(in[u], in[top[v]]), in[v]+1);\n\t\t\t\tif(top[u]==top[v])\
    \ break;\n\t\t\t\tv = par[top[v]];\n\t\t\t}\n\t\t}\n};\n"
  dependsOn:
  - checker/build_checker.hpp
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2024-04-24 17:23:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/vertex_add_path_sum.test.cpp
  - verify/yosupo/vertex_add_subtree_sum.test.cpp
  - verify/yosupo/lca.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/tree/heavy_light_decomposition.hpp
- /library/tree/heavy_light_decomposition.hpp.html
title: tree/heavy_light_decomposition.hpp
---
