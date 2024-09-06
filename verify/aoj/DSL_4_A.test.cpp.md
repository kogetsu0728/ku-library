---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/cumulative_sum_2d.hpp
    title: data_structure/cumulative_sum_2d.hpp
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
  bundledCode: "#line 1 \"verify/aoj/DSL_4_A.test.cpp\"\n#define PROBLEM \\\n  \"\
    https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\n\n#include\
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
    \ - v[y1][x2] - v[y2][x1] + v[y1][x1];\n  }\n};\n#line 2 \"misc/compress.hpp\"\
    \n\ntemplate <class T, class C = less<T>>\nclass Compress {\n private:\n  bool\
    \ init;\n  vector<T> vec;\n\n public:\n  Compress() : Compress(vector<T>()) {}\n\
    \  Compress(const vector<T>& _vec) : init(false), vec(_vec) {}\n\n  void push(const\
    \ T x) {\n    assert(!init);\n\n    vec.push_back(x);\n  }\n\n  void build() {\n\
    \    assert(!init);\n    init = true;\n\n    sort(vec.begin(), vec.end(), C());\n\
    \    vec.erase(unique(vec.begin(), vec.end()), vec.end());\n  }\n\n  size_t size()\
    \ const {\n    assert(init);\n\n    return vec.size();\n  }\n\n  T nth(const int\
    \ i) const {\n    assert(init);\n\n    assert(0 <= i && i < int(vec.size()));\n\
    \    return vec[i];\n  }\n\n  int get(const T x) const {\n    assert(init);\n\n\
    \    int ng = -1, ok = int(vec.size()) - 1;\n    while (1 < ok - ng) {\n     \
    \ int mid = (ok + ng) / 2;\n      if (!C()(vec[mid], x))\n        ok = mid;\n\
    \      else\n        ng = mid;\n    }\n    return ok;\n  }\n\n  bool contains(const\
    \ T x) const {\n    assert(init);\n\n    return nth(get(x)) == x;\n  }\n};\n#line\
    \ 9 \"verify/aoj/DSL_4_A.test.cpp\"\n\nint main() {\n  int N;\n  cin >> N;\n \
    \ vector<long long> x1(N), y1(N), x2(N), y2(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n  }\n\n  Compress<long long>\
    \ cmp_x, cmp_y;\n  for (int i = 0; i < N; i++) {\n    cmp_x.push(x1[i]), cmp_x.push(x2[i]);\n\
    \    cmp_y.push(y1[i]), cmp_y.push(y2[i]);\n  }\n\n  cmp_x.build(), cmp_y.build();\n\
    \n  CumulativeSum2d<int> cnt(int(cmp_y.size()), int(cmp_x.size()));\n  for (int\
    \ i = 0; i < N; i++) {\n    cnt.add(cmp_y.get(y1[i]), cmp_x.get(x1[i]), cmp_y.get(y2[i]),\n\
    \            cmp_x.get(x2[i]), 1);\n  }\n\n  cnt.build();\n\n  long long ans{};\n\
    \  for (int i = 0; i < int(cmp_y.size()) - 1; i++) {\n    for (int j = 0; j <\
    \ int(cmp_x.size()) - 1; j++) {\n      if (cnt.get(i, j)) {\n        ans += (cmp_y.nth(i\
    \ + 1) - cmp_y.nth(i)) *\n               (cmp_x.nth(j + 1) - cmp_x.nth(j));\n\
    \      }\n    }\n  }\n\n  cout << ans << endl;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/cumulative_sum_2d.hpp\"\
    \n#include \"../../misc/compress.hpp\"\n\nint main() {\n  int N;\n  cin >> N;\n\
    \  vector<long long> x1(N), y1(N), x2(N), y2(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n  }\n\n  Compress<long long>\
    \ cmp_x, cmp_y;\n  for (int i = 0; i < N; i++) {\n    cmp_x.push(x1[i]), cmp_x.push(x2[i]);\n\
    \    cmp_y.push(y1[i]), cmp_y.push(y2[i]);\n  }\n\n  cmp_x.build(), cmp_y.build();\n\
    \n  CumulativeSum2d<int> cnt(int(cmp_y.size()), int(cmp_x.size()));\n  for (int\
    \ i = 0; i < N; i++) {\n    cnt.add(cmp_y.get(y1[i]), cmp_x.get(x1[i]), cmp_y.get(y2[i]),\n\
    \            cmp_x.get(x2[i]), 1);\n  }\n\n  cnt.build();\n\n  long long ans{};\n\
    \  for (int i = 0; i < int(cmp_y.size()) - 1; i++) {\n    for (int j = 0; j <\
    \ int(cmp_x.size()) - 1; j++) {\n      if (cnt.get(i, j)) {\n        ans += (cmp_y.nth(i\
    \ + 1) - cmp_y.nth(i)) *\n               (cmp_x.nth(j + 1) - cmp_x.nth(j));\n\
    \      }\n    }\n  }\n\n  cout << ans << endl;\n}\n"
  dependsOn:
  - data_structure/cumulative_sum_2d.hpp
  - misc/compress.hpp
  isVerificationFile: true
  path: verify/aoj/DSL_4_A.test.cpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/DSL_4_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_4_A.test.cpp
- /verify/verify/aoj/DSL_4_A.test.cpp.html
title: verify/aoj/DSL_4_A.test.cpp
---
