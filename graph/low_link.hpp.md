---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/GRL_3_A.test.cpp
    title: verify/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/GRL_3_B.test.cpp
    title: verify/aoj/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/low_link.hpp\"\n\nclass LowLink{\n\tprivate:\n\t\t\
    bool init;\n\t\tint n, comp;\n\t\tvector<vector<int>> g;\n\t\tvector<bool> seen;\n\
    \t\tvector<int> ord, low, art;\n\t\tset<pair<int,int>> bri;\n\n\t\tvoid dfs(int\
    \ v, int p, int &i){\n\t\t\tseen[v] = true;\n\t\t\tord[v] = low[v] = i++;\n\t\t\
    \tfor(const int &nv:g[v]){\n\t\t\t\tif(seen[nv]){\n\t\t\t\t\tif(nv!=p){\n\t\t\t\
    \t\t\tlow[v] = min(low[v], ord[nv]);\n\t\t\t\t\t}\n\t\t\t\t}else{\n\t\t\t\t\t\
    dfs(nv, v, i);\n\t\t\t\t\tlow[v] = min(low[v], low[nv]);\n\t\t\t\t\tif(ord[v]<=low[nv])\
    \ art[v]++;\n\t\t\t\t\tif(ord[v]<low[nv]) bri.insert(make_pair(min(v,nv),max(v,nv)));\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif(p==-1) art[v]--;\n\t\t}\n\n\tpublic:\n\t\tLowLink():\
    \ LowLink(0) {}\n\t\tLowLink(const int _n):\n\t\t\tinit(false), n(_n), comp(0),\
    \ g(_n), seen(_n), ord(_n), low(_n), art(_n){}\n\n\t\tvoid add_edge(int u, int\
    \ v){\n\t\t\tassert(!init);\n\t\t\tg[u].push_back(v);\n\t\t\tg[v].push_back(u);\n\
    \t\t}\n\n\t\tvoid build(){\n\t\t\tassert(!init);\n\t\t\tinit = true;\n\t\t\tfor(int\
    \ v=0; v<n; v++) if(!seen[v]){\n\t\t\t\tcomp++;\n\t\t\t\tint i{};\n\t\t\t\tdfs(v,\
    \ -1, i);\n\t\t\t}\n\t\t}\n\n\t\tint component() const {\n\t\t\tassert(init);\n\
    \t\t\treturn comp;\n\t\t}\n\n\t\tint get_art(int v) const {\n\t\t\tassert(init);\n\
    \t\t\treturn art[v];\n\t\t}\n\n\t\tbool is_art(int v) const {\n\t\t\tassert(init);\n\
    \t\t\treturn 0<get_art(v);\n\t\t}\n\n\t\tbool is_bridge(int u, int v) const {\n\
    \t\t\tassert(init);\n\t\t\treturn bri.count(make_pair(min(u,v),max(u,v)));\n\t\
    \t}\n};\n"
  code: "#pragma once\n\nclass LowLink{\n\tprivate:\n\t\tbool init;\n\t\tint n, comp;\n\
    \t\tvector<vector<int>> g;\n\t\tvector<bool> seen;\n\t\tvector<int> ord, low,\
    \ art;\n\t\tset<pair<int,int>> bri;\n\n\t\tvoid dfs(int v, int p, int &i){\n\t\
    \t\tseen[v] = true;\n\t\t\tord[v] = low[v] = i++;\n\t\t\tfor(const int &nv:g[v]){\n\
    \t\t\t\tif(seen[nv]){\n\t\t\t\t\tif(nv!=p){\n\t\t\t\t\t\tlow[v] = min(low[v],\
    \ ord[nv]);\n\t\t\t\t\t}\n\t\t\t\t}else{\n\t\t\t\t\tdfs(nv, v, i);\n\t\t\t\t\t\
    low[v] = min(low[v], low[nv]);\n\t\t\t\t\tif(ord[v]<=low[nv]) art[v]++;\n\t\t\t\
    \t\tif(ord[v]<low[nv]) bri.insert(make_pair(min(v,nv),max(v,nv)));\n\t\t\t\t}\n\
    \t\t\t}\n\t\t\tif(p==-1) art[v]--;\n\t\t}\n\n\tpublic:\n\t\tLowLink(): LowLink(0)\
    \ {}\n\t\tLowLink(const int _n):\n\t\t\tinit(false), n(_n), comp(0), g(_n), seen(_n),\
    \ ord(_n), low(_n), art(_n){}\n\n\t\tvoid add_edge(int u, int v){\n\t\t\tassert(!init);\n\
    \t\t\tg[u].push_back(v);\n\t\t\tg[v].push_back(u);\n\t\t}\n\n\t\tvoid build(){\n\
    \t\t\tassert(!init);\n\t\t\tinit = true;\n\t\t\tfor(int v=0; v<n; v++) if(!seen[v]){\n\
    \t\t\t\tcomp++;\n\t\t\t\tint i{};\n\t\t\t\tdfs(v, -1, i);\n\t\t\t}\n\t\t}\n\n\t\
    \tint component() const {\n\t\t\tassert(init);\n\t\t\treturn comp;\n\t\t}\n\n\t\
    \tint get_art(int v) const {\n\t\t\tassert(init);\n\t\t\treturn art[v];\n\t\t\
    }\n\n\t\tbool is_art(int v) const {\n\t\t\tassert(init);\n\t\t\treturn 0<get_art(v);\n\
    \t\t}\n\n\t\tbool is_bridge(int u, int v) const {\n\t\t\tassert(init);\n\t\t\t\
    return bri.count(make_pair(min(u,v),max(u,v)));\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/low_link.hpp
  requiredBy: []
  timestamp: '2024-04-19 21:31:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/GRL_3_A.test.cpp
  - verify/aoj/GRL_3_B.test.cpp
documentation_of: graph/low_link.hpp
layout: document
redirect_from:
- /library/graph/low_link.hpp
- /library/graph/low_link.hpp.html
title: graph/low_link.hpp
---
