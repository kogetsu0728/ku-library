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
  bundledCode: "#line 2 \"misc/compress.hpp\"\n\ntemplate<class T,class C=less<T>>\n\
    class Compress{\n\tprivate:\n\t\tbool init;\n\t\tvector<T> vec;\n\n\tpublic:\n\
    \t\tCompress(): Compress(vector<T>()) {}\n\t\tCompress(const vector<T>& _vec):\n\
    \t\t\tinit(false), vec(_vec) {}\n\n\t\tvoid push(const T x){\n\t\t\tassert(!init);\n\
    \n\t\t\tvec.push_back(x);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tassert(!init);\n\t\
    \t\tinit = true;\n\n\t\t\tsort(vec.begin(), vec.end(), C());\n\t\t\tvec.erase(unique(vec.begin(),vec.end()),vec.end());\n\
    \t\t}\n\n\t\tsize_t size() const {\n\t\t\tassert(init);\n\n\t\t\treturn vec.size();\n\
    \t\t}\n\n\t\tT nth(const int i) const {\n\t\t\tassert(init);\n\n\t\t\tassert(0<=i\
    \ && i<int(vec.size()));\n\t\t\treturn vec[i];\n\t\t}\n\n\t\tint get(const T x)\
    \ const {\n\t\t\tassert(init);\n\n\t\t\tint ng=-1, ok=int(vec.size())-1;\n\t\t\
    \twhile(1<ok-ng){\n\t\t\t\tint mid=(ok+ng)/2;\n\t\t\t\tif(!C()(vec[mid],x)) ok=mid;\n\
    \t\t\t\telse ng=mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n\n\t\tbool contains(const\
    \ T x) const {\n\t\t\tassert(init);\n\n\t\t\treturn nth(get(x))==x;\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T,class C=less<T>>\nclass Compress{\n\tprivate:\n\
    \t\tbool init;\n\t\tvector<T> vec;\n\n\tpublic:\n\t\tCompress(): Compress(vector<T>())\
    \ {}\n\t\tCompress(const vector<T>& _vec):\n\t\t\tinit(false), vec(_vec) {}\n\n\
    \t\tvoid push(const T x){\n\t\t\tassert(!init);\n\n\t\t\tvec.push_back(x);\n\t\
    \t}\n\n\t\tvoid build(){\n\t\t\tassert(!init);\n\t\t\tinit = true;\n\n\t\t\tsort(vec.begin(),\
    \ vec.end(), C());\n\t\t\tvec.erase(unique(vec.begin(),vec.end()),vec.end());\n\
    \t\t}\n\n\t\tsize_t size() const {\n\t\t\tassert(init);\n\n\t\t\treturn vec.size();\n\
    \t\t}\n\n\t\tT nth(const int i) const {\n\t\t\tassert(init);\n\n\t\t\tassert(0<=i\
    \ && i<int(vec.size()));\n\t\t\treturn vec[i];\n\t\t}\n\n\t\tint get(const T x)\
    \ const {\n\t\t\tassert(init);\n\n\t\t\tint ng=-1, ok=int(vec.size())-1;\n\t\t\
    \twhile(1<ok-ng){\n\t\t\t\tint mid=(ok+ng)/2;\n\t\t\t\tif(!C()(vec[mid],x)) ok=mid;\n\
    \t\t\t\telse ng=mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n\n\t\tbool contains(const\
    \ T x) const {\n\t\t\tassert(init);\n\n\t\t\treturn nth(get(x))==x;\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy: []
  timestamp: '2024-08-18 22:40:10+09:00'
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
