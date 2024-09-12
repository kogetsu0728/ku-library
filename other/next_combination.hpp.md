---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2561.test.cpp
    title: test/yukicoder/2561.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Next Combination
    links: []
  bundledCode: "#line 2 \"other/next_combination.hpp\"\n\n/**\n * @brief Next Combination\n\
    \ */\ntemplate <class T>\nbool next_combination(const T& begin, const T& end,\
    \ const int k) {\n    const T& sub = begin + k;\n\n    if (begin == end || begin\
    \ == sub || end == sub) {\n        return false;\n    }\n\n    T src = sub;\n\
    \    while (begin != src) {\n        src--;\n\n        if (*src < *(end - 1))\
    \ {\n            T dest = sub;\n            while (*dest <= *src) dest++;\n\n\
    \            iter_swap(src, dest);\n\n            rotate(src + 1, dest + 1, end);\n\
    \            rotate(sub, sub + (end - dest) - 1, end);\n\n            return true;\n\
    \        }\n    }\n\n    rotate(begin, sub, end);\n\n    return false;\n}\n"
  code: "#pragma once\n\n/**\n * @brief Next Combination\n */\ntemplate <class T>\n\
    bool next_combination(const T& begin, const T& end, const int k) {\n    const\
    \ T& sub = begin + k;\n\n    if (begin == end || begin == sub || end == sub) {\n\
    \        return false;\n    }\n\n    T src = sub;\n    while (begin != src) {\n\
    \        src--;\n\n        if (*src < *(end - 1)) {\n            T dest = sub;\n\
    \            while (*dest <= *src) dest++;\n\n            iter_swap(src, dest);\n\
    \n            rotate(src + 1, dest + 1, end);\n            rotate(sub, sub + (end\
    \ - dest) - 1, end);\n\n            return true;\n        }\n    }\n\n    rotate(begin,\
    \ sub, end);\n\n    return false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/next_combination.hpp
  requiredBy: []
  timestamp: '2024-09-12 11:06:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2561.test.cpp
documentation_of: other/next_combination.hpp
layout: document
redirect_from:
- /library/other/next_combination.hpp
- /library/other/next_combination.hpp.html
title: Next Combination
---
