---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"verify/yosupo/zalgorithm.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include <iostream>\n#include\
    \ <string>\n#include <vector>\nusing namespace std;\n\n#line 2 \"string/rolling_hash.hpp\"\
    \n\nclass RollingHash{\n\tprivate:\n\t\tstatic const long long mod1=888888901,\
    \ mod2=987654323;\n\t\tlong long base1, base2;\n\t\tint n;\n\t\tvector<long long>\
    \ hash1, hash2, pow1, pow2;\n\n\tpublic:\n\t\tRollingHash(const string &s, const\
    \ long long _base1=2525, const long long _base2=4649):\n\t\t\tbase1(_base1), base2(_base2)\
    \ {\n\t\t\t\tn = s.length();\n\t\t\t\thash1.assign(n+1, 0);\n\t\t\t\thash2.assign(n+1,\
    \ 0);\n\t\t\t\tpow1.assign(n+1, 1);\n\t\t\t\tpow2.assign(n+1, 1);\n\t\t\t\tfor\
    \ (int i=0; i<n; i++){\n\t\t\t\t\thash1[i+1] = (hash1[i]*base1+s[i]) % mod1;\n\
    \t\t\t\t\thash2[i+1] = (hash2[i]*base2+s[i]) % mod2;\n\t\t\t\t\tpow1[i+1] = (pow1[i]*base1)\
    \ % mod1;\n\t\t\t\t\tpow2[i+1] = (pow2[i]*base2) % mod2;\n\t\t\t\t}\n\t\t\t}\n\
    \n\t\tpair<long long, long long> get(const int l, const int r) const {\n\t\t\t\
    long long fi = hash1[r]-(hash1[l]*pow1[r-l]%mod1);\n\t\t\tif(fi<0) fi += mod1;\n\
    \t\t\tlong long se = hash2[r]-(hash2[l]*pow2[r-l]%mod2);\n\t\t\tif(se<0) se +=\
    \ mod2;\n\t\t\treturn make_pair(fi,se);\n\t\t}\n\n\t\tpair<long long, long long>\
    \ merge( \\\n\t\t\t\tconst pair<long long, long long> a, const pair<long long,\
    \ long long> b, const int b_len) const {\n\t\t\tlong long fi = ((a.first*pow1[b_len])%mod1\
    \ + b.first) % mod1;\n\t\t\tlong long se = ((a.second*pow2[b_len])%mod2 + b.second)\
    \ % mod2;\n\t\t\treturn make_pair(fi, se);\n\t\t}\n\n\t\tint lcp(const int a,\
    \ const int b) const {\n\t\t\tint ok = 0, ng = min(n+1-a,n+1-b);\n\t\t\twhile(1<ng-ok){\n\
    \t\t\t\tint mid = (ok+ng)/2;\n\t\t\t\tif(get(a,a+mid)==get(b,b+mid)) ok = mid;\n\
    \t\t\t\telse ng = mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n};\n#line 9 \"verify/yosupo/zalgorithm.test.cpp\"\
    \n\nint main(){\n\tstring S;\n\tcin >> S;\n\n\tRollingHash rh(S);\n\n\tfor(int\
    \ i=0; i<int(S.length()); i++){\n\t\tif(i) cout << ' ';\n\t\tcout << rh.lcp(0,i);\n\
    \t}\n\tcout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\nusing namespace std;\n\n#include\
    \ \"../../string/rolling_hash.hpp\"\n\nint main(){\n\tstring S;\n\tcin >> S;\n\
    \n\tRollingHash rh(S);\n\n\tfor(int i=0; i<int(S.length()); i++){\n\t\tif(i) cout\
    \ << ' ';\n\t\tcout << rh.lcp(0,i);\n\t}\n\tcout << endl;\n}\n"
  dependsOn:
  - string/rolling_hash.hpp
  isVerificationFile: true
  path: verify/yosupo/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2024-03-24 12:59:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/zalgorithm.test.cpp
- /verify/verify/yosupo/zalgorithm.test.cpp.html
title: verify/yosupo/zalgorithm.test.cpp
---
