---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/zalgorithm.test.cpp
    title: verify/yosupo/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n\nclass RollingHash{\n\tusing\
    \ ll = long long;\n\n\tprivate:\n\t\tstatic const ll mod1=888888901, mod2=987654323;\n\
    \t\tll base1, base2;\n\t\tint n;\n\t\tvector<ll> hash1, hash2, pow1, pow2;\n\n\
    \tpublic:\n\t\tRollingHash(const string &s, const ll _base1=2525, const ll _base2=4649):\n\
    \t\t\tbase1(_base1), base2(_base2) {\n\t\t\t\tn = s.length();\n\t\t\t\thash1.assign(n+1,\
    \ 0);\n\t\t\t\thash2.assign(n+1, 0);\n\t\t\t\tpow1.assign(n+1, 1);\n\t\t\t\tpow2.assign(n+1,\
    \ 1);\n\t\t\t\tfor (int i=0; i<n; i++){\n\t\t\t\t\thash1[i+1] = (hash1[i]*base1+s[i])\
    \ % mod1;\n\t\t\t\t\thash2[i+1] = (hash2[i]*base2+s[i]) % mod2;\n\t\t\t\t\tpow1[i+1]\
    \ = (pow1[i]*base1) % mod1;\n\t\t\t\t\tpow2[i+1] = (pow2[i]*base2) % mod2;\n\t\
    \t\t\t}\n\t\t\t}\n\n\t\tpair<ll,ll> get(const int l, const int r) const{\n\t\t\
    \tll fi = hash1[r]-(hash1[l]*pow1[r-l]%mod1);\n\t\t\tif(fi<0) fi += mod1;\n\t\t\
    \tll se = hash2[r]-(hash2[l]*pow2[r-l]%mod2);\n\t\t\tif(se<0) se += mod2;\n\t\t\
    \treturn make_pair(fi,se);\n\t\t}\n\n\t\tpair<ll,ll> merge(const pair<ll,ll> a,\
    \ const pair<ll,ll> b, const int b_len) const{\n\t\t\tll fi = ((a.first*pow1[b_len])%mod1\
    \ + b.first) % mod1;\n\t\t\tll se = ((a.second*pow2[b_len])%mod2 + b.second) %\
    \ mod2;\n\t\t\treturn make_pair(fi, se);\n\t\t}\n\n\t\tint lcp(const int a, const\
    \ int b) const{\n\t\t\tint ok = 0, ng = min(n+1-a,n+1-b);\n\t\t\twhile(1<ng-ok){\n\
    \t\t\t\tint mid = (ok+ng)/2;\n\t\t\t\tif(get(a,a+mid)==get(b,b+mid)) ok = mid;\n\
    \t\t\t\telse ng = mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n};\n"
  code: "#pragma once\n\nclass RollingHash{\n\tusing ll = long long;\n\n\tprivate:\n\
    \t\tstatic const ll mod1=888888901, mod2=987654323;\n\t\tll base1, base2;\n\t\t\
    int n;\n\t\tvector<ll> hash1, hash2, pow1, pow2;\n\n\tpublic:\n\t\tRollingHash(const\
    \ string &s, const ll _base1=2525, const ll _base2=4649):\n\t\t\tbase1(_base1),\
    \ base2(_base2) {\n\t\t\t\tn = s.length();\n\t\t\t\thash1.assign(n+1, 0);\n\t\t\
    \t\thash2.assign(n+1, 0);\n\t\t\t\tpow1.assign(n+1, 1);\n\t\t\t\tpow2.assign(n+1,\
    \ 1);\n\t\t\t\tfor (int i=0; i<n; i++){\n\t\t\t\t\thash1[i+1] = (hash1[i]*base1+s[i])\
    \ % mod1;\n\t\t\t\t\thash2[i+1] = (hash2[i]*base2+s[i]) % mod2;\n\t\t\t\t\tpow1[i+1]\
    \ = (pow1[i]*base1) % mod1;\n\t\t\t\t\tpow2[i+1] = (pow2[i]*base2) % mod2;\n\t\
    \t\t\t}\n\t\t\t}\n\n\t\tpair<ll,ll> get(const int l, const int r) const{\n\t\t\
    \tll fi = hash1[r]-(hash1[l]*pow1[r-l]%mod1);\n\t\t\tif(fi<0) fi += mod1;\n\t\t\
    \tll se = hash2[r]-(hash2[l]*pow2[r-l]%mod2);\n\t\t\tif(se<0) se += mod2;\n\t\t\
    \treturn make_pair(fi,se);\n\t\t}\n\n\t\tpair<ll,ll> merge(const pair<ll,ll> a,\
    \ const pair<ll,ll> b, const int b_len) const{\n\t\t\tll fi = ((a.first*pow1[b_len])%mod1\
    \ + b.first) % mod1;\n\t\t\tll se = ((a.second*pow2[b_len])%mod2 + b.second) %\
    \ mod2;\n\t\t\treturn make_pair(fi, se);\n\t\t}\n\n\t\tint lcp(const int a, const\
    \ int b) const{\n\t\t\tint ok = 0, ng = min(n+1-a,n+1-b);\n\t\t\twhile(1<ng-ok){\n\
    \t\t\t\tint mid = (ok+ng)/2;\n\t\t\t\tif(get(a,a+mid)==get(b,b+mid)) ok = mid;\n\
    \t\t\t\telse ng = mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-08-18 22:54:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/zalgorithm.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
redirect_from:
- /library/string/rolling_hash.hpp
- /library/string/rolling_hash.hpp.html
title: string/rolling_hash.hpp
---
