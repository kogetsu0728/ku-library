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
  bundledCode: "#line 1 \"verify/aoj/DSL_5_B.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"data_structure/cumulative_sum_2d.hpp\"\
    \n\ntemplate <class T>\nclass CumulativeSum2d {\n private:\n  bool init;\n  int\
    \ h, w;\n  vector<vector<T>> v;\n\n public:\n  CumulativeSum2d() : CumulativeSum2d(0,\
    \ 0) {}\n  CumulativeSum2d(int _h, int _w, T _e = 0)\n      : init(false), h(_h),\
    \ w(_w), v(_h + 1, vector<T>(_w + 1, _e)) {}\n\n  void add(int y, int x, T d)\
    \ {\n    assert(!init);\n\n    v[y + 1][x + 1] += d;\n  }\n\n  void add(int y1,\
    \ int x1, int y2, int x2, T d) {\n    assert(!init);\n\n    add(y1, x1, d);\n\
    \    add(y1, x2, -d);\n    add(y2, x1, -d);\n    add(y2, x2, d);\n  }\n\n  void\
    \ build() {\n    assert(!init);\n    init = true;\n\n    for (int y = 1; y <=\
    \ h; y++) {\n      for (int x = 1; x <= w; x++) {\n        v[y][x] += v[y][x -\
    \ 1] + v[y - 1][x] - v[y - 1][x - 1];\n      }\n    }\n  }\n\n  T get(int y, int\
    \ x) const {\n    assert(init);\n\n    return v[y + 1][x + 1];\n  }\n\n  T sum(int\
    \ y1, int x1, int y2, int x2) const {\n    assert(init);\n\n    return v[y2][x2]\
    \ - v[y1][x2] - v[y2][x1] + v[y1][x1];\n  }\n};\n#line 8 \"verify/aoj/DSL_5_B.test.cpp\"\
    \n\nint main() {\n  int N;\n  cin >> N;\n  vector<long long> x1(N), y1(N), x2(N),\
    \ y2(N);\n  for (int i = 0; i < N; i++) {\n    cin >> x1[i] >> y1[i] >> x2[i]\
    \ >> y2[i];\n  }\n\n  CumulativeSum2d<long long> cs(1001, 1001);\n  for (int i\
    \ = 0; i < N; i++) {\n    cs.add(y1[i], x1[i], y2[i], x2[i], 1LL);\n  }\n\n  cs.build();\n\
    \n  long long ans = 0;\n  for (int i = 0; i < 1000; i++) {\n    for (int j = 0;\
    \ j < 1000; j++) {\n      ans = max(ans, cs.get(i, j));\n    }\n  }\n  cout <<\
    \ ans << endl;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/cumulative_sum_2d.hpp\"\
    \n\nint main() {\n  int N;\n  cin >> N;\n  vector<long long> x1(N), y1(N), x2(N),\
    \ y2(N);\n  for (int i = 0; i < N; i++) {\n    cin >> x1[i] >> y1[i] >> x2[i]\
    \ >> y2[i];\n  }\n\n  CumulativeSum2d<long long> cs(1001, 1001);\n  for (int i\
    \ = 0; i < N; i++) {\n    cs.add(y1[i], x1[i], y2[i], x2[i], 1LL);\n  }\n\n  cs.build();\n\
    \n  long long ans = 0;\n  for (int i = 0; i < 1000; i++) {\n    for (int j = 0;\
    \ j < 1000; j++) {\n      ans = max(ans, cs.get(i, j));\n    }\n  }\n  cout <<\
    \ ans << endl;\n}\n"
  dependsOn:
  - data_structure/cumulative_sum_2d.hpp
  isVerificationFile: true
  path: verify/aoj/DSL_5_B.test.cpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/DSL_5_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_5_B.test.cpp
- /verify/verify/aoj/DSL_5_B.test.cpp.html
title: verify/aoj/DSL_5_B.test.cpp
---
