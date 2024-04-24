---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/low_link.hpp
    title: graph/low_link.hpp
  - icon: ':x:'
    path: graph/topological_sort.hpp
    title: graph/topological_sort.hpp
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/DSL_4_A.test.cpp
    title: verify/aoj/DSL_4_A.test.cpp
  - icon: ':x:'
    path: verify/aoj/GRL_3_A.test.cpp
    title: verify/aoj/GRL_3_A.test.cpp
  - icon: ':x:'
    path: verify/aoj/GRL_3_B.test.cpp
    title: verify/aoj/GRL_3_B.test.cpp
  - icon: ':x:'
    path: verify/aoj/GRL_4_A.test.cpp
    title: verify/aoj/GRL_4_A.test.cpp
  - icon: ':x:'
    path: verify/yukicoder/468.test.cpp
    title: verify/yukicoder/468.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - graph/low_link.hpp
  - graph/topological_sort.hpp
  - misc/compress.hpp
  timestamp: '2024-04-24 17:00:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yukicoder/468.test.cpp
  - verify/aoj/DSL_4_A.test.cpp
  - verify/aoj/GRL_4_A.test.cpp
  - verify/aoj/GRL_3_A.test.cpp
  - verify/aoj/GRL_3_B.test.cpp
documentation_of: checker/build_checker.hpp
layout: document
redirect_from:
- /library/checker/build_checker.hpp
- /library/checker/build_checker.hpp.html
title: checker/build_checker.hpp
---
