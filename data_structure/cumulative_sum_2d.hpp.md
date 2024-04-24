---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/DSL_4_A.test.cpp
    title: verify/aoj/DSL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/DSL_5_B.test.cpp
    title: verify/aoj/DSL_5_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/cumulative_sum_2d.hpp\"\n\ntemplate<class\
    \ T>\nclass CumulativeSum2d{\n\tprivate:\n\t\tbool init;\n\t\tint h, w;\n\t\t\
    vector<vector<T>> v;\n\n\tpublic:\n\t\tCumulativeSum2d():CumulativeSum2d(0,0){}\n\
    \t\tCumulativeSum2d(int _h, int _w, T _e=0):\n\t\t\tinit(false), h(_h), w(_w),\
    \ v(_h+1,vector<T>(_w+1,_e)){}\n\n\t\tvoid add(int y, int x, T d){\n\t\t\tassert(!init);\n\
    \t\t\tv[y+1][x+1] += d;\n\t\t}\n\n\t\tvoid add(int y1, int x1, int y2, int x2,\
    \ T d){\n\t\t\tassert(!init);\n\t\t\tadd(y1, x1, d);\n\t\t\tadd(y1, x2, -d);\n\
    \t\t\tadd(y2, x1, -d);\n\t\t\tadd(y2, x2, d);\n\t\t}\n\n\t\tvoid build(){\n\t\t\
    \tassert(!init);\n\t\t\tinit = true;\n\t\t\tfor(int y=1; y<=h; y++){\n\t\t\t\t\
    for(int x=1; x<=w; x++){\n\t\t\t\t\tv[y][x] += v[y][x-1]+v[y-1][x]-v[y-1][x-1];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tT get(int y, int x) const {\n\t\t\tassert(init);\n\
    \t\t\treturn v[y+1][x+1];\n\t\t}\n\n\t\tT sum(int y1, int x1, int y2, int x2)\
    \ const {\n\t\t\tassert(init);\n\t\t\treturn v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];\n\
    \t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T>\nclass CumulativeSum2d{\n\tprivate:\n\t\
    \tbool init;\n\t\tint h, w;\n\t\tvector<vector<T>> v;\n\n\tpublic:\n\t\tCumulativeSum2d():CumulativeSum2d(0,0){}\n\
    \t\tCumulativeSum2d(int _h, int _w, T _e=0):\n\t\t\tinit(false), h(_h), w(_w),\
    \ v(_h+1,vector<T>(_w+1,_e)){}\n\n\t\tvoid add(int y, int x, T d){\n\t\t\tassert(!init);\n\
    \t\t\tv[y+1][x+1] += d;\n\t\t}\n\n\t\tvoid add(int y1, int x1, int y2, int x2,\
    \ T d){\n\t\t\tassert(!init);\n\t\t\tadd(y1, x1, d);\n\t\t\tadd(y1, x2, -d);\n\
    \t\t\tadd(y2, x1, -d);\n\t\t\tadd(y2, x2, d);\n\t\t}\n\n\t\tvoid build(){\n\t\t\
    \tassert(!init);\n\t\t\tinit = true;\n\t\t\tfor(int y=1; y<=h; y++){\n\t\t\t\t\
    for(int x=1; x<=w; x++){\n\t\t\t\t\tv[y][x] += v[y][x-1]+v[y-1][x]-v[y-1][x-1];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tT get(int y, int x) const {\n\t\t\tassert(init);\n\
    \t\t\treturn v[y+1][x+1];\n\t\t}\n\n\t\tT sum(int y1, int x1, int y2, int x2)\
    \ const {\n\t\t\tassert(init);\n\t\t\treturn v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];\n\
    \t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/cumulative_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-04-19 21:31:05+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aoj/DSL_4_A.test.cpp
  - verify/aoj/DSL_5_B.test.cpp
documentation_of: data_structure/cumulative_sum_2d.hpp
layout: document
redirect_from:
- /library/data_structure/cumulative_sum_2d.hpp
- /library/data_structure/cumulative_sum_2d.hpp.html
title: data_structure/cumulative_sum_2d.hpp
---
