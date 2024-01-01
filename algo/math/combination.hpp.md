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
  bundledCode: "#line 2 \"algo/math/combination.hpp\"\n\ntemplate<class T>\nclass\
    \ Combination{\n\tprivate:\n\t\tvector<T> fac, ifac;\n\n\tpublic:\n\t\tCombination():Combination(0){}\n\
    \t\tCombination(int _n):\n\t\t\tfac(_n+1,1),ifac(_n+1,1){\n\t\t\t\tfor(int i=0;\
    \ i<=_n; i++) fac[i+1] = fac[i]*(i+1);\n\t\t\t\tifac[_n] = 1/fac[_n];\n\t\t\t\t\
    for(int i=_n+1; i>0; i--) ifac[i-1] = ifac[i]*i;\n\t\t\t}\n\n\t\tT p(int a, int\
    \ b){ \n\t\t\tif(b<0 || a<b) return 0;\n\t\t\treturn fac[a]*ifac[a-b];\n\t\t}\n\
    \n\t\tT c(int a, int b){\n\t\t\tif(b<0 || a<b) return 0;\n\t\t\treturn p(a,b)*ifac[b];\n\
    \t\t}\n\n\t\tT h(int a, int b){\n\t\t\tif(a==0 && b==0) return 1;\n\t\t\tif(a<=0\
    \ || b<0) return 0;\n\t\t\treturn c(a+b-1, b);\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T>\nclass Combination{\n\tprivate:\n\t\tvector<T>\
    \ fac, ifac;\n\n\tpublic:\n\t\tCombination():Combination(0){}\n\t\tCombination(int\
    \ _n):\n\t\t\tfac(_n+1,1),ifac(_n+1,1){\n\t\t\t\tfor(int i=0; i<=_n; i++) fac[i+1]\
    \ = fac[i]*(i+1);\n\t\t\t\tifac[_n] = 1/fac[_n];\n\t\t\t\tfor(int i=_n+1; i>0;\
    \ i--) ifac[i-1] = ifac[i]*i;\n\t\t\t}\n\n\t\tT p(int a, int b){ \n\t\t\tif(b<0\
    \ || a<b) return 0;\n\t\t\treturn fac[a]*ifac[a-b];\n\t\t}\n\n\t\tT c(int a, int\
    \ b){\n\t\t\tif(b<0 || a<b) return 0;\n\t\t\treturn p(a,b)*ifac[b];\n\t\t}\n\n\
    \t\tT h(int a, int b){\n\t\t\tif(a==0 && b==0) return 1;\n\t\t\tif(a<=0 || b<0)\
    \ return 0;\n\t\t\treturn c(a+b-1, b);\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/math/combination.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algo/math/combination.hpp
layout: document
redirect_from:
- /library/algo/math/combination.hpp
- /library/algo/math/combination.hpp.html
title: algo/math/combination.hpp
---
