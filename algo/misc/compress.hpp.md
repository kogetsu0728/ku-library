---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: algo/verify/aoj/DSL_4_A.test.cpp
    title: algo/verify/aoj/DSL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algo/misc/compress.hpp\"\n\ntemplate<class T,class C=less<T>>\n\
    class Compress{\n\tprivate:\n\t\tvector<T> v;\n\n\tpublic:\n\t\tCompress(){}\n\
    \n\t\tvoid push(const T x){\n\t\t\tv.push_back(x);\n\t\t}\n\n\t\tvoid build(){\n\
    \t\t\tsort(v.begin(), v.end(), C());\n\t\t\tv.erase(unique(v.begin(),v.end()),v.end());\n\
    \t\t}\n\n\t\tsize_t size() const {\n\t\t\treturn v.size();\n\t\t}\n\n\t\tT nth(const\
    \ int i) const {\n\t\t\tassert(0<=i && i<int(v.size()));\n\t\t\treturn v[i];\n\
    \t\t}\n\n\t\tint get(const T x) const {\n\t\t\tint ng=-1, ok=int(v.size())-1;\n\
    \t\t\twhile(1<ok-ng){\n\t\t\t\tint mid=(ok+ng)/2;\n\t\t\t\tif(!C()(v[mid],x))\
    \ ok=mid;\n\t\t\t\telse ng=mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n\n\t\tbool\
    \ count(const T x) const {\n\t\t\treturn nth(get(x))==x;\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T,class C=less<T>>\nclass Compress{\n\tprivate:\n\
    \t\tvector<T> v;\n\n\tpublic:\n\t\tCompress(){}\n\n\t\tvoid push(const T x){\n\
    \t\t\tv.push_back(x);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tsort(v.begin(), v.end(),\
    \ C());\n\t\t\tv.erase(unique(v.begin(),v.end()),v.end());\n\t\t}\n\n\t\tsize_t\
    \ size() const {\n\t\t\treturn v.size();\n\t\t}\n\n\t\tT nth(const int i) const\
    \ {\n\t\t\tassert(0<=i && i<int(v.size()));\n\t\t\treturn v[i];\n\t\t}\n\n\t\t\
    int get(const T x) const {\n\t\t\tint ng=-1, ok=int(v.size())-1;\n\t\t\twhile(1<ok-ng){\n\
    \t\t\t\tint mid=(ok+ng)/2;\n\t\t\t\tif(!C()(v[mid],x)) ok=mid;\n\t\t\t\telse ng=mid;\n\
    \t\t\t}\n\t\t\treturn ok;\n\t\t}\n\n\t\tbool count(const T x) const {\n\t\t\t\
    return nth(get(x))==x;\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/misc/compress.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - algo/verify/aoj/DSL_4_A.test.cpp
documentation_of: algo/misc/compress.hpp
layout: document
redirect_from:
- /library/algo/misc/compress.hpp
- /library/algo/misc/compress.hpp.html
title: algo/misc/compress.hpp
---
