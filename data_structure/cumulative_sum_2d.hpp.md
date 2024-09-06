---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/DSL_4_A.test.cpp
    title: verify/aoj/DSL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/DSL_5_B.test.cpp
    title: verify/aoj/DSL_5_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/cumulative_sum_2d.hpp\"\n\ntemplate <class\
    \ T>\nclass CumulativeSum2d {\n private:\n  bool init;\n  int h, w;\n  vector<vector<T>>\
    \ v;\n\n public:\n  CumulativeSum2d() : CumulativeSum2d(0, 0) {}\n  CumulativeSum2d(int\
    \ _h, int _w, T _e = 0)\n      : init(false), h(_h), w(_w), v(_h + 1, vector<T>(_w\
    \ + 1, _e)) {}\n\n  void add(int y, int x, T d) {\n    assert(!init);\n\n    v[y\
    \ + 1][x + 1] += d;\n  }\n\n  void add(int y1, int x1, int y2, int x2, T d) {\n\
    \    assert(!init);\n\n    add(y1, x1, d);\n    add(y1, x2, -d);\n    add(y2,\
    \ x1, -d);\n    add(y2, x2, d);\n  }\n\n  void build() {\n    assert(!init);\n\
    \    init = true;\n\n    for (int y = 1; y <= h; y++) {\n      for (int x = 1;\
    \ x <= w; x++) {\n        v[y][x] += v[y][x - 1] + v[y - 1][x] - v[y - 1][x -\
    \ 1];\n      }\n    }\n  }\n\n  T get(int y, int x) const {\n    assert(init);\n\
    \n    return v[y + 1][x + 1];\n  }\n\n  T sum(int y1, int x1, int y2, int x2)\
    \ const {\n    assert(init);\n\n    return v[y2][x2] - v[y1][x2] - v[y2][x1] +\
    \ v[y1][x1];\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nclass CumulativeSum2d {\n private:\n\
    \  bool init;\n  int h, w;\n  vector<vector<T>> v;\n\n public:\n  CumulativeSum2d()\
    \ : CumulativeSum2d(0, 0) {}\n  CumulativeSum2d(int _h, int _w, T _e = 0)\n  \
    \    : init(false), h(_h), w(_w), v(_h + 1, vector<T>(_w + 1, _e)) {}\n\n  void\
    \ add(int y, int x, T d) {\n    assert(!init);\n\n    v[y + 1][x + 1] += d;\n\
    \  }\n\n  void add(int y1, int x1, int y2, int x2, T d) {\n    assert(!init);\n\
    \n    add(y1, x1, d);\n    add(y1, x2, -d);\n    add(y2, x1, -d);\n    add(y2,\
    \ x2, d);\n  }\n\n  void build() {\n    assert(!init);\n    init = true;\n\n \
    \   for (int y = 1; y <= h; y++) {\n      for (int x = 1; x <= w; x++) {\n   \
    \     v[y][x] += v[y][x - 1] + v[y - 1][x] - v[y - 1][x - 1];\n      }\n    }\n\
    \  }\n\n  T get(int y, int x) const {\n    assert(init);\n\n    return v[y + 1][x\
    \ + 1];\n  }\n\n  T sum(int y1, int x1, int y2, int x2) const {\n    assert(init);\n\
    \n    return v[y2][x2] - v[y1][x2] - v[y2][x1] + v[y1][x1];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cumulative_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/DSL_5_B.test.cpp
  - verify/aoj/DSL_4_A.test.cpp
documentation_of: data_structure/cumulative_sum_2d.hpp
layout: document
redirect_from:
- /library/data_structure/cumulative_sum_2d.hpp
- /library/data_structure/cumulative_sum_2d.hpp.html
title: data_structure/cumulative_sum_2d.hpp
---
