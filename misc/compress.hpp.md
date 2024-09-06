---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/DSL_4_A.test.cpp
    title: verify/aoj/DSL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/compress.hpp\"\n\ntemplate <class T, class C = less<T>>\n\
    class Compress {\n private:\n  bool init;\n  vector<T> vec;\n\n public:\n  Compress()\
    \ : Compress(vector<T>()) {}\n  Compress(const vector<T>& _vec) : init(false),\
    \ vec(_vec) {}\n\n  void push(const T x) {\n    assert(!init);\n\n    vec.push_back(x);\n\
    \  }\n\n  void build() {\n    assert(!init);\n    init = true;\n\n    sort(vec.begin(),\
    \ vec.end(), C());\n    vec.erase(unique(vec.begin(), vec.end()), vec.end());\n\
    \  }\n\n  size_t size() const {\n    assert(init);\n\n    return vec.size();\n\
    \  }\n\n  T nth(const int i) const {\n    assert(init);\n\n    assert(0 <= i &&\
    \ i < int(vec.size()));\n    return vec[i];\n  }\n\n  int get(const T x) const\
    \ {\n    assert(init);\n\n    int ng = -1, ok = int(vec.size()) - 1;\n    while\
    \ (1 < ok - ng) {\n      int mid = (ok + ng) / 2;\n      if (!C()(vec[mid], x))\n\
    \        ok = mid;\n      else\n        ng = mid;\n    }\n    return ok;\n  }\n\
    \n  bool contains(const T x) const {\n    assert(init);\n\n    return nth(get(x))\
    \ == x;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, class C = less<T>>\nclass Compress {\n\
    \ private:\n  bool init;\n  vector<T> vec;\n\n public:\n  Compress() : Compress(vector<T>())\
    \ {}\n  Compress(const vector<T>& _vec) : init(false), vec(_vec) {}\n\n  void\
    \ push(const T x) {\n    assert(!init);\n\n    vec.push_back(x);\n  }\n\n  void\
    \ build() {\n    assert(!init);\n    init = true;\n\n    sort(vec.begin(), vec.end(),\
    \ C());\n    vec.erase(unique(vec.begin(), vec.end()), vec.end());\n  }\n\n  size_t\
    \ size() const {\n    assert(init);\n\n    return vec.size();\n  }\n\n  T nth(const\
    \ int i) const {\n    assert(init);\n\n    assert(0 <= i && i < int(vec.size()));\n\
    \    return vec[i];\n  }\n\n  int get(const T x) const {\n    assert(init);\n\n\
    \    int ng = -1, ok = int(vec.size()) - 1;\n    while (1 < ok - ng) {\n     \
    \ int mid = (ok + ng) / 2;\n      if (!C()(vec[mid], x))\n        ok = mid;\n\
    \      else\n        ng = mid;\n    }\n    return ok;\n  }\n\n  bool contains(const\
    \ T x) const {\n    assert(init);\n\n    return nth(get(x)) == x;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/DSL_4_A.test.cpp
documentation_of: misc/compress.hpp
layout: document
redirect_from:
- /library/misc/compress.hpp
- /library/misc/compress.hpp.html
title: misc/compress.hpp
---
