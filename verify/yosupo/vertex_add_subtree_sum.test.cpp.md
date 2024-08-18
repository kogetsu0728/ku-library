---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: data_structure/segment_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/yosupo/vertex_add_subtree_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data_structure/segment_tree.hpp\"\
    \n\ntemplate<class S, S (*op)(S,S), S (*e)()>\nclass SegmentTree{\n\tprivate:\n\
    \t\tint n;\n\t\tvector<S> v;\n\n\t\tvoid update(int i){\n\t\t\tv[i] = op(v[i<<1],\
    \ v[(i<<1)|1]);\n\t\t}\n\n\tpublic:\n\t\tSegmentTree():SegmentTree(0){}\n\t\t\
    SegmentTree(int _n):SegmentTree(vector<S>(_n, e())){}\n\t\tSegmentTree(const vector<S>\
    \ &_v){\n\t\t\tn = (int)_v.size();\n\t\t\tv.assign(2*n, e());\n\t\t\tfor(int i=0;\
    \ i<n; i++) v[n+i] = _v[i];\n\t\t\tfor(int i=n-1; i>=1; i--) update(i);\n\t\t\
    }\n\n\t\tS get(int i) const {\n\t\t\ti += n;\n\t\t\treturn v[i];\n\t\t}\n\n\t\t\
    S prod(int l, int r) const {\n\t\t\tl += n, r += n;\n\t\t\tS v_l = e(), v_r =\
    \ e();\n\t\t\twhile(l<r){\n\t\t\t\tif(l&1) v_l = op(v_l, v[l++]);\n\t\t\t\tif(r&1)\
    \ v_r = op(v[--r], v_r);\n\t\t\t\tl >>= 1, r >>= 1;\n\t\t\t}\n\t\t\treturn op(v_l,\
    \ v_r);\n\t\t}\n\n\t\tvoid set(int i, S x){\n\t\t\ti += n;\n\t\t\tv[i] = x;\n\t\
    \t\twhile(1<i){\n\t\t\t\ti >>= 1;\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n};\n#line\
    \ 2 \"tree/heavy_light_decomposition.hpp\"\n\nclass HeavyLightDecomposition{\n\
    \tprivate:\n\t\tbool init;\n\t\tint n;\n\t\tvector<vector<int>> g;\n\t\tvector<int>\
    \ siz, par, dep, top, in, out;\n\n\t\tvoid dfs_siz(int v, int p){\n\t\t\tpar[v]\
    \ = p;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p){\n\t\t\t\t\tif(nv==g[v].back())\
    \ break;\n\t\t\t\t\tswap(nv, g[v].back());\n\t\t\t\t}\n\t\t\t\tdfs_siz(nv, v);\n\
    \t\t\t\tsiz[v] += siz[nv];\n\t\t\t\tif(siz[nv]>siz[g[v][0]]){\n\t\t\t\t\tswap(nv,\
    \ g[v][0]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tvoid dfs_hld(int v, int p, int &i){\n\
    \t\t\tin[v] = i++;\n\t\t\tfor(int &nv:g[v]){\n\t\t\t\tif(nv==p) continue;\n\t\t\
    \t\tdep[nv] = dep[v]+1;\n\t\t\t\tif(nv==g[v][0]) top[nv] = top[v];\n\t\t\t\telse\
    \ top[nv] = nv;\n\t\t\t\tdfs_hld(nv, v, i);\n\t\t\t}\n\t\t\tout[v] = i;\n\t\t\
    }\n\n\tpublic:\n\t\tHeavyLightDecomposition(): HeavyLightDecomposition(0) {}\n\
    \t\tHeavyLightDecomposition(const int _n):\n\t\t\tinit(false), n(_n), g(_n), siz(_n,\
    \ 1), par(_n, -1),\n\t\t\tdep(_n), top(_n), in(_n), out(_n){}\n\n\t\tvoid add_edge(int\
    \ u, int v){\n\t\t\tassert(!init);\n\n\t\t\tg[u].push_back(v);\n\t\t\tg[v].push_back(u);\n\
    \t\t}\n\n\t\tvoid build(){\n\t\t\tassert(!init);\n\t\t\tinit = true;\n\n\t\t\t\
    dfs_siz(0, -1);\n\t\t\tint i{};\n\t\t\tdfs_hld(0, -1, i);\n\t\t}\n\n\t\tint depth(int\
    \ v) const {\n\t\t\tassert(init);\n\n\t\t\treturn dep[v];\n\t\t}\n\n\t\tint lca(int\
    \ u, int v) const {\n\t\t\tassert(init);\n\n\t\t\twhile(true){\n\t\t\t\tif(in[u]>in[v])\
    \ swap(u, v);\n\t\t\t\tif(top[u]==top[v]) return u;\n\t\t\t\tv = par[top[v]];\n\
    \t\t\t}\n\t\t}\n\n\t\tvoid node_query(int v, const function<void(int)> &func)\
    \ const {\n\t\t\tassert(init);\n\n\t\t\tfunc(in[v]);\n\t\t}\n\n\t\tvoid subtree_query(int\
    \ v, const function<void(int,int)> &func) const {\n\t\t\tassert(init);\n\n\t\t\
    \tfunc(in[v], out[v]);\n\t\t}\n\n\t\tvoid path_query(int u, int v, const function<void(int,int)>\
    \ &func) const {\n\t\t\tassert(init);\n\n\t\t\twhile(true){\n\t\t\t\tif(in[u]>in[v])\
    \ swap(u, v);\n\t\t\t\tfunc(max(in[u], in[top[v]]), in[v]+1);\n\t\t\t\tif(top[u]==top[v])\
    \ break;\n\t\t\t\tv = par[top[v]];\n\t\t\t}\n\t\t}\n};\n#line 8 \"verify/yosupo/vertex_add_subtree_sum.test.cpp\"\
    \n\nlong long op(long long a, long long b){\n\treturn a+b;\n}\n\nlong long e(){\n\
    \treturn 0LL;\n}\n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<long\
    \ long> A(N);\n\tfor(int i=0; i<N; i++){\n\t\tcin >> A[i];\n\t}\n\t\n\tHeavyLightDecomposition\
    \ hld(N);\n\tfor(int i=1; i<N; i++){\n\t\tint p;\n\t\tcin >> p;\n\t\thld.add_edge(i,\
    \ p);\n\t}\n\n\thld.build();\n\n\tSegmentTree<long long, op, e> seg(N);\n\tfor(int\
    \ i=0; i<N; i++){\n\t\thld.node_query(i, [&](int j) -> void{\n\t\t\t\tseg.set(j,\
    \ A[i]);\n\t\t\t\treturn;\n\t\t\t\t});\n\t}\n\n\tfor(;Q--;){\n\t\tint t;\n\t\t\
    cin >> t;\n\t\tif(t==0){\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\t\tlong long x;\n\t\
    \t\tcin >> x;\n\t\t\thld.node_query(i, [&](int j) -> void{\n\t\t\t\t\tseg.set(j,\
    \ seg.get(j)+x);\n\t\t\t\t\treturn;\n\t\t\t\t\t});\n\t\t}else{\n\t\t\tint i;\n\
    \t\t\tcin >> i;\n\t\t\tlong long ans{};\n\t\t\thld.subtree_query(i, [&](int l,\
    \ int r) -> void{\n\t\t\t\t\tans += seg.prod(l, r);\n\t\t\t\t\treturn;\n\t\t\t\
    \t\t});\n\t\t\tcout << ans << endl;\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/segment_tree.hpp\"\
    \n#include \"../../tree/heavy_light_decomposition.hpp\"\n\nlong long op(long long\
    \ a, long long b){\n\treturn a+b;\n}\n\nlong long e(){\n\treturn 0LL;\n}\n\nint\
    \ main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<long long> A(N);\n\tfor(int\
    \ i=0; i<N; i++){\n\t\tcin >> A[i];\n\t}\n\t\n\tHeavyLightDecomposition hld(N);\n\
    \tfor(int i=1; i<N; i++){\n\t\tint p;\n\t\tcin >> p;\n\t\thld.add_edge(i, p);\n\
    \t}\n\n\thld.build();\n\n\tSegmentTree<long long, op, e> seg(N);\n\tfor(int i=0;\
    \ i<N; i++){\n\t\thld.node_query(i, [&](int j) -> void{\n\t\t\t\tseg.set(j, A[i]);\n\
    \t\t\t\treturn;\n\t\t\t\t});\n\t}\n\n\tfor(;Q--;){\n\t\tint t;\n\t\tcin >> t;\n\
    \t\tif(t==0){\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\t\tlong long x;\n\t\t\tcin >>\
    \ x;\n\t\t\thld.node_query(i, [&](int j) -> void{\n\t\t\t\t\tseg.set(j, seg.get(j)+x);\n\
    \t\t\t\t\treturn;\n\t\t\t\t\t});\n\t\t}else{\n\t\t\tint i;\n\t\t\tcin >> i;\n\t\
    \t\tlong long ans{};\n\t\t\thld.subtree_query(i, [&](int l, int r) -> void{\n\t\
    \t\t\t\tans += seg.prod(l, r);\n\t\t\t\t\treturn;\n\t\t\t\t\t});\n\t\t\tcout <<\
    \ ans << endl;\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data_structure/segment_tree.hpp
  - tree/heavy_light_decomposition.hpp
  isVerificationFile: true
  path: verify/yosupo/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-08-18 22:40:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/vertex_add_subtree_sum.test.cpp
- /verify/verify/yosupo/vertex_add_subtree_sum.test.cpp.html
title: verify/yosupo/vertex_add_subtree_sum.test.cpp
---