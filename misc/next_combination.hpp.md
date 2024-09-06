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
  bundledCode: "#line 2 \"misc/next_combination.hpp\"\n\ntemplate <typename T>\nbool\
    \ next_combination(const T &begin, const T &end, int k) {\n  const T &sub = begin\
    \ + k;\n  if (begin == end || begin == sub || end == sub) return false;\n  T src\
    \ = sub;\n  while (begin != src) {\n    src--;\n    if ((*src) < (*(end - 1)))\
    \ {\n      T des = sub;\n      while ((*des) <= (*src)) des++;\n      iter_swap(src,\
    \ des);\n      rotate(src + 1, des + 1, end);\n      rotate(sub, sub + (end -\
    \ des) - 1, end);\n      return true;\n    }\n  }\n  rotate(begin, sub, end);\n\
    \  return false;\n}\n"
  code: "#pragma once\n\ntemplate <typename T>\nbool next_combination(const T &begin,\
    \ const T &end, int k) {\n  const T &sub = begin + k;\n  if (begin == end || begin\
    \ == sub || end == sub) return false;\n  T src = sub;\n  while (begin != src)\
    \ {\n    src--;\n    if ((*src) < (*(end - 1))) {\n      T des = sub;\n      while\
    \ ((*des) <= (*src)) des++;\n      iter_swap(src, des);\n      rotate(src + 1,\
    \ des + 1, end);\n      rotate(sub, sub + (end - des) - 1, end);\n      return\
    \ true;\n    }\n  }\n  rotate(begin, sub, end);\n  return false;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/next_combination.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/next_combination.hpp
layout: document
redirect_from:
- /library/misc/next_combination.hpp
- /library/misc/next_combination.hpp.html
title: misc/next_combination.hpp
---
