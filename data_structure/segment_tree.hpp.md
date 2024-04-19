---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/static_range_min.test.cpp
    title: verify/yosupo/static_range_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/static_range_sum.test.cpp
    title: verify/yosupo/static_range_sum.test.cpp
  - icon: ':x:'
    path: verify/yosupo/vertex_add_path_sum.test.cpp
    title: verify/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: verify/yosupo/vertex_add_subtree_sum.test.cpp
    title: verify/yosupo/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/segment_tree.hpp\"\n\ntemplate<class S, S\
    \ (*op)(S,S), S (*e)()>\nclass SegmentTree{\n\tprivate:\n\t\tint n;\n\t\tvector<S>\
    \ v;\n\n\t\tvoid update(int i){\n\t\t\tv[i] = op(v[i<<1], v[(i<<1)|1]);\n\t\t\
    }\n\n\tpublic:\n\t\tSegmentTree():SegmentTree(0){}\n\t\tSegmentTree(int _n):SegmentTree(vector<S>(_n,\
    \ e())){}\n\t\tSegmentTree(const vector<S> &_v){\n\t\t\tn = (int)_v.size();\n\t\
    \t\tv.assign(2*n, e());\n\t\t\tfor(int i=0; i<n; i++) v[n+i] = _v[i];\n\t\t\t\
    for(int i=n-1; i>=1; i--) update(i);\n\t\t}\n\n\t\tS get(int i) const {\n\t\t\t\
    i += n;\n\t\t\treturn v[i];\n\t\t}\n\n\t\tS prod(int l, int r) const {\n\t\t\t\
    l += n, r += n;\n\t\t\tS v_l = e(), v_r = e();\n\t\t\twhile(l<r){\n\t\t\t\tif(l&1)\
    \ v_l = op(v_l, v[l++]);\n\t\t\t\tif(r&1) v_r = op(v[--r], v_r);\n\t\t\t\tl >>=\
    \ 1, r >>= 1;\n\t\t\t}\n\t\t\treturn op(v_l, v_r);\n\t\t}\n\n\t\tvoid set(int\
    \ i, S x){\n\t\t\ti += n;\n\t\t\tv[i] = x;\n\t\t\twhile(1<i){\n\t\t\t\ti >>= 1;\n\
    \t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class S, S (*op)(S,S), S (*e)()>\nclass SegmentTree{\n\
    \tprivate:\n\t\tint n;\n\t\tvector<S> v;\n\n\t\tvoid update(int i){\n\t\t\tv[i]\
    \ = op(v[i<<1], v[(i<<1)|1]);\n\t\t}\n\n\tpublic:\n\t\tSegmentTree():SegmentTree(0){}\n\
    \t\tSegmentTree(int _n):SegmentTree(vector<S>(_n, e())){}\n\t\tSegmentTree(const\
    \ vector<S> &_v){\n\t\t\tn = (int)_v.size();\n\t\t\tv.assign(2*n, e());\n\t\t\t\
    for(int i=0; i<n; i++) v[n+i] = _v[i];\n\t\t\tfor(int i=n-1; i>=1; i--) update(i);\n\
    \t\t}\n\n\t\tS get(int i) const {\n\t\t\ti += n;\n\t\t\treturn v[i];\n\t\t}\n\n\
    \t\tS prod(int l, int r) const {\n\t\t\tl += n, r += n;\n\t\t\tS v_l = e(), v_r\
    \ = e();\n\t\t\twhile(l<r){\n\t\t\t\tif(l&1) v_l = op(v_l, v[l++]);\n\t\t\t\t\
    if(r&1) v_r = op(v[--r], v_r);\n\t\t\t\tl >>= 1, r >>= 1;\n\t\t\t}\n\t\t\treturn\
    \ op(v_l, v_r);\n\t\t}\n\n\t\tvoid set(int i, S x){\n\t\t\ti += n;\n\t\t\tv[i]\
    \ = x;\n\t\t\twhile(1<i){\n\t\t\t\ti >>= 1;\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-01-07 12:12:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/static_range_sum.test.cpp
  - verify/yosupo/static_range_min.test.cpp
  - verify/yosupo/vertex_add_subtree_sum.test.cpp
  - verify/yosupo/vertex_add_path_sum.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.hpp
- /library/data_structure/segment_tree.hpp.html
title: data_structure/segment_tree.hpp
---
