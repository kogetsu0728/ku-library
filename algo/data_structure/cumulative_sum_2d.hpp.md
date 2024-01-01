---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algo/verify/aoj/DSL_4_A.test.cpp
    title: algo/verify/aoj/DSL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: algo/verify/aoj/DSL_5_B.test.cpp
    title: algo/verify/aoj/DSL_5_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algo/data_structure/cumulative_sum_2d.hpp\"\n\ntemplate<class\
    \ T>\nclass CumulativeSum2d{\n\tprivate:\n\t\tint h, w;\n\t\tvector<vector<T>>\
    \ v;\n\n\tpublic:\n\t\tCumulativeSum2d():CumulativeSum2d(0,0){}\n\t\tCumulativeSum2d(int\
    \ _h, int _w, T _e=0):\n\t\t\th(_h), w(_w), v(_h+1,vector<T>(_w+1,_e)){}\n\n\t\
    \tvoid add(int y, int x, T d){\n\t\t\tv[y+1][x+1] += d;\n\t\t}\n\n\t\tvoid add(int\
    \ y1, int x1, int y2, int x2, T d){\n\t\t\tadd(y1, x1, d);\n\t\t\tadd(y1, x2,\
    \ -d);\n\t\t\tadd(y2, x1, -d);\n\t\t\tadd(y2, x2, d);\n\t\t}\n\n\t\tvoid build(){\n\
    \t\t\tfor(int y=1; y<=h; y++){\n\t\t\t\tfor(int x=1; x<=w; x++){\n\t\t\t\t\tv[y][x]\
    \ += v[y][x-1]+v[y-1][x]-v[y-1][x-1];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tT get(int\
    \ y, int x) const {\n\t\t\treturn v[y+1][x+1];\n\t\t}\n\n\t\tT sum(int y1, int\
    \ x1, int y2, int x2) const {\n\t\t\treturn v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];\n\
    \t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T>\nclass CumulativeSum2d{\n\tprivate:\n\t\
    \tint h, w;\n\t\tvector<vector<T>> v;\n\n\tpublic:\n\t\tCumulativeSum2d():CumulativeSum2d(0,0){}\n\
    \t\tCumulativeSum2d(int _h, int _w, T _e=0):\n\t\t\th(_h), w(_w), v(_h+1,vector<T>(_w+1,_e)){}\n\
    \n\t\tvoid add(int y, int x, T d){\n\t\t\tv[y+1][x+1] += d;\n\t\t}\n\n\t\tvoid\
    \ add(int y1, int x1, int y2, int x2, T d){\n\t\t\tadd(y1, x1, d);\n\t\t\tadd(y1,\
    \ x2, -d);\n\t\t\tadd(y2, x1, -d);\n\t\t\tadd(y2, x2, d);\n\t\t}\n\n\t\tvoid build(){\n\
    \t\t\tfor(int y=1; y<=h; y++){\n\t\t\t\tfor(int x=1; x<=w; x++){\n\t\t\t\t\tv[y][x]\
    \ += v[y][x-1]+v[y-1][x]-v[y-1][x-1];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tT get(int\
    \ y, int x) const {\n\t\t\treturn v[y+1][x+1];\n\t\t}\n\n\t\tT sum(int y1, int\
    \ x1, int y2, int x2) const {\n\t\t\treturn v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];\n\
    \t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/data_structure/cumulative_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algo/verify/aoj/DSL_5_B.test.cpp
  - algo/verify/aoj/DSL_4_A.test.cpp
documentation_of: algo/data_structure/cumulative_sum_2d.hpp
layout: document
redirect_from:
- /library/algo/data_structure/cumulative_sum_2d.hpp
- /library/algo/data_structure/cumulative_sum_2d.hpp.html
title: algo/data_structure/cumulative_sum_2d.hpp
---
