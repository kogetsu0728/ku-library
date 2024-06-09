---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data_structure/cumulative_sum_2d.hpp
    title: data_structure/cumulative_sum_2d.hpp
  - icon: ':heavy_check_mark:'
    path: graph/low_link.hpp
    title: graph/low_link.hpp
  - icon: ':heavy_check_mark:'
    path: graph/topological_sort.hpp
    title: graph/topological_sort.hpp
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  - icon: ':heavy_check_mark:'
    path: tree/heavy_light_decomposition.hpp
    title: tree/heavy_light_decomposition.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/DSL_4_A.test.cpp
    title: verify/aoj/DSL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/DSL_5_B.test.cpp
    title: verify/aoj/DSL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/GRL_3_A.test.cpp
    title: verify/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/GRL_3_B.test.cpp
    title: verify/aoj/GRL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aoj/GRL_4_A.test.cpp
    title: verify/aoj/GRL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/lca.test.cpp
    title: verify/yosupo/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/vertex_add_path_sum.test.cpp
    title: verify/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/vertex_add_subtree_sum.test.cpp
    title: verify/yosupo/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/468.test.cpp
    title: verify/yukicoder/468.test.cpp
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
  - data_structure/cumulative_sum_2d.hpp
  - graph/low_link.hpp
  - graph/topological_sort.hpp
  - tree/heavy_light_decomposition.hpp
  timestamp: '2024-04-24 17:00:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/GRL_4_A.test.cpp
  - verify/aoj/GRL_3_A.test.cpp
  - verify/aoj/DSL_5_B.test.cpp
  - verify/aoj/DSL_4_A.test.cpp
  - verify/aoj/GRL_3_B.test.cpp
  - verify/yukicoder/468.test.cpp
  - verify/yosupo/vertex_add_subtree_sum.test.cpp
  - verify/yosupo/vertex_add_path_sum.test.cpp
  - verify/yosupo/lca.test.cpp
documentation_of: checker/build_checker.hpp
layout: document
redirect_from:
- /library/checker/build_checker.hpp
- /library/checker/build_checker.hpp.html
title: checker/build_checker.hpp
---
