---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/cumulative_sum_2d.hpp
    title: data_structure/cumulative_sum_2d.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B
  bundledCode: "#line 1 \"verify/aoj/DSL_5_B.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data_structure/cumulative_sum_2d.hpp\"\
    \n\ntemplate<class T>\nclass CumulativeSum2d{\n\tprivate:\n\t\tbool init;\n\t\t\
    int h, w;\n\t\tvector<vector<T>> v;\n\n\tpublic:\n\t\tCumulativeSum2d(): CumulativeSum2d(0,0){}\n\
    \t\tCumulativeSum2d(int _h, int _w, T _e=0):\n\t\t\tinit(false), h(_h), w(_w),\
    \ v(_h+1,vector<T>(_w+1,_e)){}\n\n\t\tvoid add(int y, int x, T d){\n\t\t\tassert(!init);\n\
    \n\t\t\tv[y+1][x+1] += d;\n\t\t}\n\n\t\tvoid add(int y1, int x1, int y2, int x2,\
    \ T d){\n\t\t\tassert(!init);\n\n\t\t\tadd(y1, x1, d);\n\t\t\tadd(y1, x2, -d);\n\
    \t\t\tadd(y2, x1, -d);\n\t\t\tadd(y2, x2, d);\n\t\t}\n\n\t\tvoid build(){\n\t\t\
    \tassert(!init);\n\t\t\tinit = true;\n\n\t\t\tfor(int y=1; y<=h; y++){\n\t\t\t\
    \tfor(int x=1; x<=w; x++){\n\t\t\t\t\tv[y][x] += v[y][x-1]+v[y-1][x]-v[y-1][x-1];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tT get(int y, int x) const {\n\t\t\tassert(init);\n\
    \n\t\t\treturn v[y+1][x+1];\n\t\t}\n\n\t\tT sum(int y1, int x1, int y2, int x2)\
    \ const {\n\t\t\tassert(init);\n\n\t\t\treturn v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];\n\
    \t\t}\n};\n#line 7 \"verify/aoj/DSL_5_B.test.cpp\"\n\nint main(){\n\tint N;\n\t\
    cin >> N;\n\tvector<long long> x1(N), y1(N), x2(N), y2(N);\n\tfor(int i=0; i<N;\
    \ i++){\n\t\tcin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n\t}\n\n\tCumulativeSum2d<long\
    \ long> cs(1001, 1001);\n\tfor(int i=0; i<N; i++){\n\t\tcs.add(y1[i], x1[i], y2[i],\
    \ x2[i], 1LL);\n\t}\n\n\tcs.build();\n\n\tlong long ans = 0;\n\tfor(int i=0; i<1000;\
    \ i++){\n\t\tfor(int j=0; j<1000; j++){\n\t\t\tans = max(ans, cs.get(i, j));\n\
    \t\t}\n\t}\n\tcout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/cumulative_sum_2d.hpp\"\
    \n\nint main(){\n\tint N;\n\tcin >> N;\n\tvector<long long> x1(N), y1(N), x2(N),\
    \ y2(N);\n\tfor(int i=0; i<N; i++){\n\t\tcin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n\
    \t}\n\n\tCumulativeSum2d<long long> cs(1001, 1001);\n\tfor(int i=0; i<N; i++){\n\
    \t\tcs.add(y1[i], x1[i], y2[i], x2[i], 1LL);\n\t}\n\n\tcs.build();\n\n\tlong long\
    \ ans = 0;\n\tfor(int i=0; i<1000; i++){\n\t\tfor(int j=0; j<1000; j++){\n\t\t\
    \tans = max(ans, cs.get(i, j));\n\t\t}\n\t}\n\tcout << ans << endl;\n}\n"
  dependsOn:
  - data_structure/cumulative_sum_2d.hpp
  isVerificationFile: true
  path: verify/aoj/DSL_5_B.test.cpp
  requiredBy: []
  timestamp: '2024-08-18 22:40:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/DSL_5_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_5_B.test.cpp
- /verify/verify/aoj/DSL_5_B.test.cpp.html
title: verify/aoj/DSL_5_B.test.cpp
---
