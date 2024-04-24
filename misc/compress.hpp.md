---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aoj/DSL_4_A.test.cpp
    title: verify/aoj/DSL_4_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/compress.hpp\"\n\ntemplate<class T,class C=less<T>>\n\
    class Compress{\n\tprivate:\n\t\tBuildChecker build_checker;\n\t\tvector<T> vec;\n\
    \n\tpublic:\n\t\tCompress(): build_checker(), vec() {}\n\n\t\tvoid push(const\
    \ T x){\n\t\t\tbuild_checker.before();\n\n\t\t\tvec.push_back(x);\n\t\t}\n\n\t\
    \tvoid build(){\n\t\t\tbuild_checker.build();\n\n\t\t\tsort(vec.begin(), vec.end(),\
    \ C());\n\t\t\tvec.erase(unique(vec.begin(),vec.end()),vec.end());\n\t\t}\n\n\t\
    \tsize_t size() const {\n\t\t\tbuild_checker.after();\n\n\t\t\treturn vec.size();\n\
    \t\t}\n\n\t\tT nth(const int i) const {\n\t\t\tbuild_checker.after();\n\n\t\t\t\
    assert(0<=i && i<int(vec.size()));\n\t\t\treturn vec[i];\n\t\t}\n\n\t\tint get(const\
    \ T x) const {\n\t\t\tbuild_checker.after();\n\n\t\t\tint ng=-1, ok=int(vec.size())-1;\n\
    \t\t\twhile(1<ok-ng){\n\t\t\t\tint mid=(ok+ng)/2;\n\t\t\t\tif(!C()(vec[mid],x))\
    \ ok=mid;\n\t\t\t\telse ng=mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n\n\t\tbool\
    \ contains(const T x) const {\n\t\t\tbuild_checker.after();\n\n\t\t\treturn nth(get(x))==x;\n\
    \t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T,class C=less<T>>\nclass Compress{\n\tprivate:\n\
    \t\tBuildChecker build_checker;\n\t\tvector<T> vec;\n\n\tpublic:\n\t\tCompress():\
    \ build_checker(), vec() {}\n\n\t\tvoid push(const T x){\n\t\t\tbuild_checker.before();\n\
    \n\t\t\tvec.push_back(x);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tbuild_checker.build();\n\
    \n\t\t\tsort(vec.begin(), vec.end(), C());\n\t\t\tvec.erase(unique(vec.begin(),vec.end()),vec.end());\n\
    \t\t}\n\n\t\tsize_t size() const {\n\t\t\tbuild_checker.after();\n\n\t\t\treturn\
    \ vec.size();\n\t\t}\n\n\t\tT nth(const int i) const {\n\t\t\tbuild_checker.after();\n\
    \n\t\t\tassert(0<=i && i<int(vec.size()));\n\t\t\treturn vec[i];\n\t\t}\n\n\t\t\
    int get(const T x) const {\n\t\t\tbuild_checker.after();\n\n\t\t\tint ng=-1, ok=int(vec.size())-1;\n\
    \t\t\twhile(1<ok-ng){\n\t\t\t\tint mid=(ok+ng)/2;\n\t\t\t\tif(!C()(vec[mid],x))\
    \ ok=mid;\n\t\t\t\telse ng=mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n\n\t\tbool\
    \ contains(const T x) const {\n\t\t\tbuild_checker.after();\n\n\t\t\treturn nth(get(x))==x;\n\
    \t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy: []
  timestamp: '2024-04-24 16:42:35+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aoj/DSL_4_A.test.cpp
documentation_of: misc/compress.hpp
layout: document
redirect_from:
- /library/misc/compress.hpp
- /library/misc/compress.hpp.html
title: misc/compress.hpp
---
