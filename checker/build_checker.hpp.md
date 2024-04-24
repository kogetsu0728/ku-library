---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/DSL_4_A.test.cpp
    title: verify/aoj/DSL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"checker/build_checker.hpp\"\n\nclass BuildChecker{\n\tprivate:\n\
    \t\tbool built;\n\n\tpublic:\n\t\tBuildChecker(): built(false){}\n\t\t\n\t\tvoid\
    \ before() const {\n\t\t\tassert(built==false);\n\t\t}\n\n\t\tvoid after() const\
    \ {\n\t\t\tassert(built==true);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tthis->before();\n\
    \t\t\tbuilt = true;\n\t\t}\n};\n"
  code: "#pragma once\n\nclass BuildChecker{\n\tprivate:\n\t\tbool built;\n\n\tpublic:\n\
    \t\tBuildChecker(): built(false){}\n\t\t\n\t\tvoid before() const {\n\t\t\tassert(built==false);\n\
    \t\t}\n\n\t\tvoid after() const {\n\t\t\tassert(built==true);\n\t\t}\n\n\t\tvoid\
    \ build(){\n\t\t\tthis->before();\n\t\t\tbuilt = true;\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: checker/build_checker.hpp
  requiredBy:
  - misc/compress.hpp
  timestamp: '2024-04-24 17:00:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/DSL_4_A.test.cpp
documentation_of: checker/build_checker.hpp
layout: document
redirect_from:
- /library/checker/build_checker.hpp
- /library/checker/build_checker.hpp.html
title: checker/build_checker.hpp
---
