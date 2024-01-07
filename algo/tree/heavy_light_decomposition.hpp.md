---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 2 \"tree/heavy_light_decomposition.hpp\"\n\nclass HeavyLightDecomposition{\n\
    \tprivate:\n\t\tint n;\n\t\tvector<vector<int>> g;\n\t\tvector<int> siz, par,\
    \ dep, top, in, out;\n\n\t\tvoid dfs_siz(int v, int p){\n\t\t\tpar[v] = p;\n\t\
    \t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p){\n\t\t\t\t\tif(nv==g[v].back()) break;\n\
    \t\t\t\t\tswap(nv, g[v].back());\n\t\t\t\t}\n\t\t\t\tdfs_siz(nv, v);\n\t\t\t\t\
    siz[v] += siz[nv];\n\t\t\t\tif(siz[nv]>siz[g[v][0]]){\n\t\t\t\t\tswap(nv, g[v][0]);\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tvoid dfs_hld(int v, int p, int &i){\n\t\t\tin[v]\
    \ = i++;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p) continue;\n\t\t\t\tdep[nv]\
    \ = dep[v]+1;\n\t\t\t\tif(nv==g[v][0]) top[nv] = top[v];\n\t\t\t\telse top[nv]\
    \ = nv;\n\t\t\t\tdfs_hld(nv, v, i);\n\t\t\t}\n\t\t\tout[v] = i;\n\t\t}\n\n\tpublic:\n\
    \t\tHeavyLightDecomposition(const int _n=0):\n\t\t\tn(_n), g(_n), siz(_n, 1),\
    \ par(_n, -1),\n\t\t\tdep(_n), top(_n), in(_n), out(_n){}\n\n\t\tvoid add_edge(int\
    \ u, int v){\n\t\t\tg[u].push_back(v);\n\t\t\tg[v].push_back(u);\n\t\t}\n\n\t\t\
    void build(){\n\t\t\tdfs_siz(0, -1);\n\t\t\tint i{};\n\t\t\tdfs_hld(0, -1, i);\n\
    \t\t}\n\n\t\tint depth(int v) const {\n\t\t\treturn dep[v];\n\t\t}\n\n\t\tint\
    \ lca(int u, int v) const {\n\t\t\twhile(true){\n\t\t\t\tif(in[u]>in[v]) swap(u,\
    \ v);\n\t\t\t\tif(top[u]==top[v]) return u;\n\t\t\t\tv = par[top[v]];\n\t\t\t\
    }\n\t\t}\n\n\t\tvoid node_query(int v, const function<void(int)> &func) const\
    \ {\n\t\t\tfunc(in[v]);\n\t\t}\n\n\t\tvoid subtree_query(int v, const function<void(int,int)>\
    \ &func) const {\n\t\t\tfunc(in[v], out[v]);\n\t\t}\n\n\t\tvoid path_query(int\
    \ u, int v, const function<void(int,int)> &func) const {\n\t\t\twhile(true){\n\
    \t\t\t\tif(in[u]>in[v]) swap(u, v);\n\t\t\t\tfunc(max(in[u], in[top[v]]), in[v]+1);\n\
    \t\t\t\tif(top[u]==top[v]) break;\n\t\t\t\tv = par[top[v]];\n\t\t\t}\n\t\t}\n\
    };\n"
  code: "#pragma once\n\nclass HeavyLightDecomposition{\n\tprivate:\n\t\tint n;\n\t\
    \tvector<vector<int>> g;\n\t\tvector<int> siz, par, dep, top, in, out;\n\n\t\t\
    void dfs_siz(int v, int p){\n\t\t\tpar[v] = p;\n\t\t\tfor(int &nv:g[v]){\n\t\t\
    \t\tif(nv==p){\n\t\t\t\t\tif(nv==g[v].back()) break;\n\t\t\t\t\tswap(nv, g[v].back());\n\
    \t\t\t\t}\n\t\t\t\tdfs_siz(nv, v);\n\t\t\t\tsiz[v] += siz[nv];\n\t\t\t\tif(siz[nv]>siz[g[v][0]]){\n\
    \t\t\t\t\tswap(nv, g[v][0]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tvoid dfs_hld(int\
    \ v, int p, int &i){\n\t\t\tin[v] = i++;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p)\
    \ continue;\n\t\t\t\tdep[nv] = dep[v]+1;\n\t\t\t\tif(nv==g[v][0]) top[nv] = top[v];\n\
    \t\t\t\telse top[nv] = nv;\n\t\t\t\tdfs_hld(nv, v, i);\n\t\t\t}\n\t\t\tout[v]\
    \ = i;\n\t\t}\n\n\tpublic:\n\t\tHeavyLightDecomposition(const int _n=0):\n\t\t\
    \tn(_n), g(_n), siz(_n, 1), par(_n, -1),\n\t\t\tdep(_n), top(_n), in(_n), out(_n){}\n\
    \n\t\tvoid add_edge(int u, int v){\n\t\t\tg[u].push_back(v);\n\t\t\tg[v].push_back(u);\n\
    \t\t}\n\n\t\tvoid build(){\n\t\t\tdfs_siz(0, -1);\n\t\t\tint i{};\n\t\t\tdfs_hld(0,\
    \ -1, i);\n\t\t}\n\n\t\tint depth(int v) const {\n\t\t\treturn dep[v];\n\t\t}\n\
    \n\t\tint lca(int u, int v) const {\n\t\t\twhile(true){\n\t\t\t\tif(in[u]>in[v])\
    \ swap(u, v);\n\t\t\t\tif(top[u]==top[v]) return u;\n\t\t\t\tv = par[top[v]];\n\
    \t\t\t}\n\t\t}\n\n\t\tvoid node_query(int v, const function<void(int)> &func)\
    \ const {\n\t\t\tfunc(in[v]);\n\t\t}\n\n\t\tvoid subtree_query(int v, const function<void(int,int)>\
    \ &func) const {\n\t\t\tfunc(in[v], out[v]);\n\t\t}\n\n\t\tvoid path_query(int\
    \ u, int v, const function<void(int,int)> &func) const {\n\t\t\twhile(true){\n\
    \t\t\t\tif(in[u]>in[v]) swap(u, v);\n\t\t\t\tfunc(max(in[u], in[top[v]]), in[v]+1);\n\
    \t\t\t\tif(top[u]==top[v]) break;\n\t\t\t\tv = par[top[v]];\n\t\t\t}\n\t\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/vertex_add_subtree_sum.test.cpp
  - verify/yosupo/vertex_add_path_sum.test.cpp
  - verify/yosupo/lca.test.cpp
documentation_of: tree/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/tree/heavy_light_decomposition.hpp
- /library/tree/heavy_light_decomposition.hpp.html
title: tree/heavy_light_decomposition.hpp
---
