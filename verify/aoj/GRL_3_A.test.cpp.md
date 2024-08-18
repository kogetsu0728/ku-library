---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: graph/low_link.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A
  bundledCode: "#line 1 \"verify/aoj/GRL_3_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"graph/low_link.hpp\"\
    \n\nclass LowLink{\n\tprivate:\n\t\tbool init;\n\t\tint n, comp;\n\t\tvector<vector<int>>\
    \ g;\n\t\tvector<bool> seen;\n\t\tvector<int> ord, low, art;\n\t\tset<pair<int,int>>\
    \ bri;\n\n\t\tvoid dfs(int v, int p, int &i){\n\t\t\tseen[v] = true;\n\t\t\tord[v]\
    \ = low[v] = i++;\n\t\t\tfor(const int &nv:g[v]){\n\t\t\t\tif(seen[nv]){\n\t\t\
    \t\t\tif(nv!=p){\n\t\t\t\t\t\tlow[v] = min(low[v], ord[nv]);\n\t\t\t\t\t}\n\t\t\
    \t\t}else{\n\t\t\t\t\tdfs(nv, v, i);\n\t\t\t\t\tlow[v] = min(low[v], low[nv]);\n\
    \t\t\t\t\tif(ord[v]<=low[nv]) art[v]++;\n\t\t\t\t\tif(ord[v]<low[nv]) bri.insert(make_pair(min(v,nv),max(v,nv)));\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif(p==-1) art[v]--;\n\t\t}\n\n\tpublic:\n\t\tLowLink():\
    \ LowLink(0) {}\n\t\tLowLink(const int _n):\n\t\t\tinit(false), n(_n), comp(0),\
    \ g(_n), seen(_n), ord(_n), low(_n), art(_n){}\n\n\t\tvoid add_edge(int u, int\
    \ v){\n\t\t\tassert(!init);\n\n\t\t\tg[u].push_back(v);\n\t\t\tg[v].push_back(u);\n\
    \t\t}\n\n\t\tvoid build(){\n\t\t\tassert(!init);\n\t\t\tinit = true;\n\n\t\t\t\
    for(int v=0; v<n; v++) if(!seen[v]){\n\t\t\t\tcomp++;\n\t\t\t\tint i{};\n\t\t\t\
    \tdfs(v, -1, i);\n\t\t\t}\n\t\t}\n\n\t\tint component() const {\n\t\t\tassert(init);\n\
    \n\t\t\treturn comp;\n\t\t}\n\n\t\tint get_art(int v) const {\n\t\t\tassert(init);\n\
    \n\t\t\treturn art[v];\n\t\t}\n\n\t\tbool is_art(int v) const {\n\t\t\tassert(init);\n\
    \n\t\t\treturn 0<get_art(v);\n\t\t}\n\n\t\tbool is_bridge(int u, int v) const\
    \ {\n\t\t\tassert(init);\n\n\t\t\treturn bri.count(make_pair(min(u,v),max(u,v)));\n\
    \t\t}\n};\n#line 7 \"verify/aoj/GRL_3_A.test.cpp\"\n\nint main(){\n\tint N, M;\n\
    \tcin >> N >> M;\n\tLowLink lo(N);\n\tfor(int i=0; i<M; i++){\n\t\tint u, v;\n\
    \t\tcin >> u >> v;\n\t\tlo.add_edge(u, v);\n\t}\n\n\tlo.build();\n\n\tfor(int\
    \ i=0; i<N; i++){\n\t\tif(lo.is_art(i)){\n\t\t\tcout << i << endl;\n\t\t}\n\t\
    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/low_link.hpp\"\
    \n\nint main(){\n\tint N, M;\n\tcin >> N >> M;\n\tLowLink lo(N);\n\tfor(int i=0;\
    \ i<M; i++){\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\tlo.add_edge(u, v);\n\t}\n\
    \n\tlo.build();\n\n\tfor(int i=0; i<N; i++){\n\t\tif(lo.is_art(i)){\n\t\t\tcout\
    \ << i << endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - graph/low_link.hpp
  isVerificationFile: true
  path: verify/aoj/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2024-08-18 22:40:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/GRL_3_A.test.cpp
- /verify/verify/aoj/GRL_3_A.test.cpp.html
title: verify/aoj/GRL_3_A.test.cpp
---
