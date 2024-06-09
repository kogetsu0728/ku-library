---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: checker/build_checker.hpp
    title: checker/build_checker.hpp
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
  bundledCode: "#line 2 \"data_structure/cumulative_sum_2d.hpp\"\n\n#line 2 \"checker/build_checker.hpp\"\
    \n\nclass BuildChecker{\n\tprivate:\n\t\tbool built;\n\n\tpublic:\n\t\tBuildChecker():\
    \ built(false){}\n\t\t\n\t\tvoid before() const {\n\t\t\tassert(built==false);\n\
    \t\t}\n\n\t\tvoid after() const {\n\t\t\tassert(built==true);\n\t\t}\n\n\t\tvoid\
    \ build(){\n\t\t\tthis->before();\n\t\t\tbuilt = true;\n\t\t}\n};\n#line 4 \"\
    data_structure/cumulative_sum_2d.hpp\"\n\ntemplate<class T>\nclass CumulativeSum2d{\n\
    \tprivate:\n\t\tBuildChecker build_checker;\n\t\tint h, w;\n\t\tvector<vector<T>>\
    \ v;\n\n\tpublic:\n\t\tCumulativeSum2d(): CumulativeSum2d(0,0){}\n\t\tCumulativeSum2d(int\
    \ _h, int _w, T _e=0):\n\t\t\tbuild_checker(), h(_h), w(_w), v(_h+1,vector<T>(_w+1,_e)){}\n\
    \n\t\tvoid add(int y, int x, T d){\n\t\t\tbuild_checker.before();\n\n\t\t\tv[y+1][x+1]\
    \ += d;\n\t\t}\n\n\t\tvoid add(int y1, int x1, int y2, int x2, T d){\n\t\t\tbuild_checker.before();\n\
    \n\t\t\tadd(y1, x1, d);\n\t\t\tadd(y1, x2, -d);\n\t\t\tadd(y2, x1, -d);\n\t\t\t\
    add(y2, x2, d);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tbuild_checker.build();\n\n\t\
    \t\tfor(int y=1; y<=h; y++){\n\t\t\t\tfor(int x=1; x<=w; x++){\n\t\t\t\t\tv[y][x]\
    \ += v[y][x-1]+v[y-1][x]-v[y-1][x-1];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tT get(int\
    \ y, int x) const {\n\t\t\tbuild_checker.after();\n\n\t\t\treturn v[y+1][x+1];\n\
    \t\t}\n\n\t\tT sum(int y1, int x1, int y2, int x2) const {\n\t\t\tbuild_checker.after();\n\
    \n\t\t\treturn v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];\n\t\t}\n};\n"
  code: "#pragma once\n\n#include \"checker/build_checker.hpp\"\n\ntemplate<class\
    \ T>\nclass CumulativeSum2d{\n\tprivate:\n\t\tBuildChecker build_checker;\n\t\t\
    int h, w;\n\t\tvector<vector<T>> v;\n\n\tpublic:\n\t\tCumulativeSum2d(): CumulativeSum2d(0,0){}\n\
    \t\tCumulativeSum2d(int _h, int _w, T _e=0):\n\t\t\tbuild_checker(), h(_h), w(_w),\
    \ v(_h+1,vector<T>(_w+1,_e)){}\n\n\t\tvoid add(int y, int x, T d){\n\t\t\tbuild_checker.before();\n\
    \n\t\t\tv[y+1][x+1] += d;\n\t\t}\n\n\t\tvoid add(int y1, int x1, int y2, int x2,\
    \ T d){\n\t\t\tbuild_checker.before();\n\n\t\t\tadd(y1, x1, d);\n\t\t\tadd(y1,\
    \ x2, -d);\n\t\t\tadd(y2, x1, -d);\n\t\t\tadd(y2, x2, d);\n\t\t}\n\n\t\tvoid build(){\n\
    \t\t\tbuild_checker.build();\n\n\t\t\tfor(int y=1; y<=h; y++){\n\t\t\t\tfor(int\
    \ x=1; x<=w; x++){\n\t\t\t\t\tv[y][x] += v[y][x-1]+v[y-1][x]-v[y-1][x-1];\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\n\t\tT get(int y, int x) const {\n\t\t\tbuild_checker.after();\n\
    \n\t\t\treturn v[y+1][x+1];\n\t\t}\n\n\t\tT sum(int y1, int x1, int y2, int x2)\
    \ const {\n\t\t\tbuild_checker.after();\n\n\t\t\treturn v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];\n\
    \t\t}\n};\n"
  dependsOn:
  - checker/build_checker.hpp
  isVerificationFile: false
  path: data_structure/cumulative_sum_2d.hpp
  requiredBy: []
  timestamp: '2024-04-24 17:23:11+09:00'
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
