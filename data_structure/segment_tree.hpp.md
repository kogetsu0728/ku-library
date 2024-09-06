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
  bundledCode: "#line 2 \"data_structure/segment_tree.hpp\"\n\ntemplate <class S,\
    \ S (*op)(S, S), S (*e)()>\nclass SegmentTree {\n private:\n  int n;\n  vector<S>\
    \ v;\n\n  void update(int i) { v[i] = op(v[i << 1], v[(i << 1) | 1]); }\n\n public:\n\
    \  SegmentTree() : SegmentTree(0) {}\n  SegmentTree(int _n) : SegmentTree(vector<S>(_n,\
    \ e())) {}\n  SegmentTree(const vector<S> &_v) {\n    n = (int)_v.size();\n  \
    \  v.assign(2 * n, e());\n    for (int i = 0; i < n; i++) v[n + i] = _v[i];\n\
    \    for (int i = n - 1; i >= 1; i--) update(i);\n  }\n\n  S get(int i) const\
    \ {\n    i += n;\n    return v[i];\n  }\n\n  S prod(int l, int r) const {\n  \
    \  l += n, r += n;\n    S v_l = e(), v_r = e();\n    while (l < r) {\n      if\
    \ (l & 1) v_l = op(v_l, v[l++]);\n      if (r & 1) v_r = op(v[--r], v_r);\n  \
    \    l >>= 1, r >>= 1;\n    }\n    return op(v_l, v_r);\n  }\n\n  void set(int\
    \ i, S x) {\n    i += n;\n    v[i] = x;\n    while (1 < i) {\n      i >>= 1;\n\
    \      update(i);\n    }\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\nclass SegmentTree\
    \ {\n private:\n  int n;\n  vector<S> v;\n\n  void update(int i) { v[i] = op(v[i\
    \ << 1], v[(i << 1) | 1]); }\n\n public:\n  SegmentTree() : SegmentTree(0) {}\n\
    \  SegmentTree(int _n) : SegmentTree(vector<S>(_n, e())) {}\n  SegmentTree(const\
    \ vector<S> &_v) {\n    n = (int)_v.size();\n    v.assign(2 * n, e());\n    for\
    \ (int i = 0; i < n; i++) v[n + i] = _v[i];\n    for (int i = n - 1; i >= 1; i--)\
    \ update(i);\n  }\n\n  S get(int i) const {\n    i += n;\n    return v[i];\n \
    \ }\n\n  S prod(int l, int r) const {\n    l += n, r += n;\n    S v_l = e(), v_r\
    \ = e();\n    while (l < r) {\n      if (l & 1) v_l = op(v_l, v[l++]);\n     \
    \ if (r & 1) v_r = op(v[--r], v_r);\n      l >>= 1, r >>= 1;\n    }\n    return\
    \ op(v_l, v_r);\n  }\n\n  void set(int i, S x) {\n    i += n;\n    v[i] = x;\n\
    \    while (1 < i) {\n      i >>= 1;\n      update(i);\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/vertex_add_path_sum.test.cpp
  - verify/yosupo/vertex_add_subtree_sum.test.cpp
  - verify/yosupo/static_range_min.test.cpp
  - verify/yosupo/static_range_sum.test.cpp
documentation_of: data_structure/segment_tree.hpp
layout: document
redirect_from:
- /library/data_structure/segment_tree.hpp
- /library/data_structure/segment_tree.hpp.html
title: data_structure/segment_tree.hpp
---
