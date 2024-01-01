---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: algo/graph/low_link.hpp
    title: algo/graph/low_link.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B
  bundledCode: "#line 1 \"algo/verify/aoj/GRL_3_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"algo/graph/low_link.hpp\"\
    \n\nclass LowLink{\n\tprivate:\n\t\tint n, comp;\n\t\tvector<vector<int>> g;\n\
    \t\tvector<bool> seen;\n\t\tvector<int> ord, low, art;\n\t\tset<pair<int,int>>\
    \ bri;\n\n\t\tvoid dfs(int v, int p, int &i){\n\t\t\tseen[v] = true;\n\t\t\tord[v]\
    \ = low[v] = i++;\n\t\t\tfor(const int &nv:g[v]){\n\t\t\t\tif(seen[nv]){\n\t\t\
    \t\t\tif(nv!=p){\n\t\t\t\t\t\tlow[v] = min(low[v], ord[nv]);\n\t\t\t\t\t}\n\t\t\
    \t\t}else{\n\t\t\t\t\tdfs(nv, v, i);\n\t\t\t\t\tlow[v] = min(low[v], low[nv]);\n\
    \t\t\t\t\tif(ord[v]<=low[nv]) art[v]++;\n\t\t\t\t\tif(ord[v]<low[nv]) bri.insert(make_pair(min(v,nv),max(v,nv)));\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tif(p==-1) art[v]--;\n\t\t}\n\n\tpublic:\n\t\tLowLink(const\
    \ int _n=0):\n\t\t\tn(_n), comp(0), g(_n), seen(_n), ord(_n), low(_n), art(_n){}\n\
    \n\t\tvoid add_edge(int u, int v){\n\t\t\tg[u].push_back(v);\n\t\t\tg[v].push_back(u);\n\
    \t\t}\n\n\t\tvoid build(){\n\t\t\tfor(int v=0; v<n; v++) if(!seen[v]){\n\t\t\t\
    \tcomp++;\n\t\t\t\tint i{};\n\t\t\t\tdfs(v, -1, i);\n\t\t\t}\n\t\t}\n\n\t\tint\
    \ component() const {\n\t\t\treturn comp;\n\t\t}\n\n\t\tint get_art(int v) const\
    \ {\n\t\t\treturn art[v];\n\t\t}\n\n\t\tbool is_art(int v) const {\n\t\t\treturn\
    \ 0<get_art(v);\n\t\t}\n\n\t\tbool is_bridge(int u, int v) const {\n\t\t\treturn\
    \ bri.count(make_pair(min(u,v),max(u,v)));\n\t\t}\n};\n#line 7 \"algo/verify/aoj/GRL_3_B.test.cpp\"\
    \n\nint main(){\n\tint N, M;\n\tcin >> N >> M;\n\tLowLink lo(N);\n\tvector<pair<int,int>>\
    \ edge(N);\n\tfor(int i=0; i<M; i++){\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t\
    edge[i] = make_pair(min(u, v), max(u, v));\n\t\tlo.add_edge(u, v);\n\t}\n\n\t\
    lo.build();\n\n\tvector<pair<int,int>> ans;\n\tfor(auto [u,v]:edge){\n\t\tif(lo.is_bridge(u,v)){\n\
    \t\t\tans.push_back(make_pair(u, v));\n\t\t}\n\t}\n\n\tsort(ans.begin(), ans.end());\n\
    \n\tfor(auto [u,v]:ans){\n\t\tcout << u << ' ' << v << endl;\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../graph/low_link.hpp\"\
    \n\nint main(){\n\tint N, M;\n\tcin >> N >> M;\n\tLowLink lo(N);\n\tvector<pair<int,int>>\
    \ edge(N);\n\tfor(int i=0; i<M; i++){\n\t\tint u, v;\n\t\tcin >> u >> v;\n\t\t\
    edge[i] = make_pair(min(u, v), max(u, v));\n\t\tlo.add_edge(u, v);\n\t}\n\n\t\
    lo.build();\n\n\tvector<pair<int,int>> ans;\n\tfor(auto [u,v]:edge){\n\t\tif(lo.is_bridge(u,v)){\n\
    \t\t\tans.push_back(make_pair(u, v));\n\t\t}\n\t}\n\n\tsort(ans.begin(), ans.end());\n\
    \n\tfor(auto [u,v]:ans){\n\t\tcout << u << ' ' << v << endl;\n\t}\n}\n"
  dependsOn:
  - algo/graph/low_link.hpp
  isVerificationFile: true
  path: algo/verify/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2024-01-01 13:55:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: algo/verify/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/algo/verify/aoj/GRL_3_B.test.cpp
- /verify/algo/verify/aoj/GRL_3_B.test.cpp.html
title: algo/verify/aoj/GRL_3_B.test.cpp
---
