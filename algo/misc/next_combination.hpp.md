---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algo/misc/next_combination.hpp\"\n\ntemplate <typename T>\
    \ bool next_combination(const T &begin, const T &end, int k){\n\tconst T &sub\
    \ = begin+k;\n\tif(begin==end || begin==sub || end==sub) return false;\n\tT src\
    \ = sub;\n\twhile(begin!=src){\n\t\tsrc--;\n\t\tif((*src)<(*(end-1))){\n\t\t\t\
    T des=sub;\n\t\t\twhile((*des)<=(*src)) des++;\n\t\t\titer_swap(src, des);\n\t\
    \t\trotate(src+1, des+1, end);\n\t\t\trotate(sub, sub+(end-des)-1, end);\n\t\t\
    \treturn true;\n\t\t}\n\t}\n\trotate(begin, sub, end);\n\treturn false;\n}\n"
  code: "#pragma once\n\ntemplate <typename T> bool next_combination(const T &begin,\
    \ const T &end, int k){\n\tconst T &sub = begin+k;\n\tif(begin==end || begin==sub\
    \ || end==sub) return false;\n\tT src = sub;\n\twhile(begin!=src){\n\t\tsrc--;\n\
    \t\tif((*src)<(*(end-1))){\n\t\t\tT des=sub;\n\t\t\twhile((*des)<=(*src)) des++;\n\
    \t\t\titer_swap(src, des);\n\t\t\trotate(src+1, des+1, end);\n\t\t\trotate(sub,\
    \ sub+(end-des)-1, end);\n\t\t\treturn true;\n\t\t}\n\t}\n\trotate(begin, sub,\
    \ end);\n\treturn false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/misc/next_combination.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algo/misc/next_combination.hpp
layout: document
redirect_from:
- /library/algo/misc/next_combination.hpp
- /library/algo/misc/next_combination.hpp.html
title: algo/misc/next_combination.hpp
---
