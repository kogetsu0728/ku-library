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
  bundledCode: "#line 2 \"algo/math/sieve_of_eratosthenes.hpp\"\n\nclass SieveOfEratosthenes{\n\
    \tprivate:\n\t\tint siz;\n\t\tvector<int> div, pr, cnt;\n\tpublic:\n\t\tSieveOfEratosthenes(int\
    \ n):\n\t\t\tsiz(n),div(n+1),pr(0),cnt(n+1){\n\t\t\t\tdiv[1] = 1;\n\t\t\t\tfor(int\
    \ i=2; i<=n; i++){\n\t\t\t\t\tif(div[i]!=0) continue;\n\t\t\t\t\tpr.push_back(i);\n\
    \t\t\t\t\tfor(int j=i; j<=n; j+=i){\n\t\t\t\t\t\tif(div[j]==0) div[j] = i;\n\t\
    \t\t\t\t\tcnt[j]++;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\tint nth_prime(int\
    \ n) const {\n\t\t\treturn pr[n];\n\t\t}\n\n\t\tint count_prime(int n) const {\n\
    \t\t\tif(n<2) return 0;\n\t\t\treturn cnt[n];\n\t\t}\n\n\t\tint count_divisors(int\
    \ n) const {\n\t\t\tauto f = prime_factors(n);\n\t\t\tint res = 1;\n\t\t\tfor(auto\
    \ p:f){\n\t\t\t\tres *= (1+p.second);\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\
    \tint totient(int n) const {\n\t\t\tauto f = prime_factors(n);\n\t\t\tint res\
    \ = n;\n\t\t\tfor(auto p:f){\n\t\t\t\tres /= p.first;\n\t\t\t}\n\t\t\tfor(auto\
    \ p:f){\n\t\t\t\tres *= p.first-1;\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\t\
    int prev_prime(int n) const {\n\t\t\tint l=0, r=pr.size();\n\t\t\twhile(r-l>1){\n\
    \t\t\t\tint m=(l+r)/2;\n\t\t\t\tif(pr[m]<n) l=m;\n\t\t\t\telse r=m;\n\t\t\t}\n\
    \t\t\treturn pr[l];\n\t\t}\n\n\t\tint next_prime(int n) const {\n\t\t\tint l=0,\
    \ r=pr.size();\n\t\t\twhile(r-l>1){\n\t\t\t\tint m=(l+r)/2;\n\t\t\t\tif(pr[m]<=n)\
    \ l=m;\n\t\t\t\telse r=m;\n\t\t\t}\n\t\t\treturn pr[r];\n\t\t}\n\n\t\tbool is_prime(int\
    \ n) const {\n\t\t\tif(n<2) return false;\n\t\t\treturn div[n]==n;\n\t\t}\n\n\t\
    \tvector<pair<int,int>> prime_factors(int n) const {\n\t\t\tvector<pair<int,int>>\
    \ res;\n\t\t\tint x = n;\n\t\t\twhile(2<=x){\n\t\t\t\tif(res.empty() || res.back().first!=div[x]){\n\
    \t\t\t\t\tres.push_back({div[x], 1});\n\t\t\t\t}else{\n\t\t\t\t\tres.back().second++;\n\
    \t\t\t\t}\n\t\t\t\tx /= div[x];\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\tvector<int>\
    \ get_divisors(int n) const {\n\t\t\tvector<int> res = {1};\n\t\t\tauto pf = prime_factors(n);\n\
    \t\t\tfor(auto p:pf){\n\t\t\t\tint s=(int)res.size();\n\t\t\t\tfor(int i=0; i<s;\
    \ i++){\n\t\t\t\t\tint m = 1;\n\t\t\t\t\tfor(int j=0; j<(int)p.second; j++){\n\
    \t\t\t\t\t\tm *= p.first;\n\t\t\t\t\t\tres.push_back(res[i]*m);\n\t\t\t\t\t}\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tsort(res.begin(), res.end());\n\t\t\treturn res;\n\t\
    \t}\n};\n"
  code: "#pragma once\n\nclass SieveOfEratosthenes{\n\tprivate:\n\t\tint siz;\n\t\t\
    vector<int> div, pr, cnt;\n\tpublic:\n\t\tSieveOfEratosthenes(int n):\n\t\t\t\
    siz(n),div(n+1),pr(0),cnt(n+1){\n\t\t\t\tdiv[1] = 1;\n\t\t\t\tfor(int i=2; i<=n;\
    \ i++){\n\t\t\t\t\tif(div[i]!=0) continue;\n\t\t\t\t\tpr.push_back(i);\n\t\t\t\
    \t\tfor(int j=i; j<=n; j+=i){\n\t\t\t\t\t\tif(div[j]==0) div[j] = i;\n\t\t\t\t\
    \t\tcnt[j]++;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\n\t\tint nth_prime(int n) const\
    \ {\n\t\t\treturn pr[n];\n\t\t}\n\n\t\tint count_prime(int n) const {\n\t\t\t\
    if(n<2) return 0;\n\t\t\treturn cnt[n];\n\t\t}\n\n\t\tint count_divisors(int n)\
    \ const {\n\t\t\tauto f = prime_factors(n);\n\t\t\tint res = 1;\n\t\t\tfor(auto\
    \ p:f){\n\t\t\t\tres *= (1+p.second);\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\
    \tint totient(int n) const {\n\t\t\tauto f = prime_factors(n);\n\t\t\tint res\
    \ = n;\n\t\t\tfor(auto p:f){\n\t\t\t\tres /= p.first;\n\t\t\t}\n\t\t\tfor(auto\
    \ p:f){\n\t\t\t\tres *= p.first-1;\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\t\
    int prev_prime(int n) const {\n\t\t\tint l=0, r=pr.size();\n\t\t\twhile(r-l>1){\n\
    \t\t\t\tint m=(l+r)/2;\n\t\t\t\tif(pr[m]<n) l=m;\n\t\t\t\telse r=m;\n\t\t\t}\n\
    \t\t\treturn pr[l];\n\t\t}\n\n\t\tint next_prime(int n) const {\n\t\t\tint l=0,\
    \ r=pr.size();\n\t\t\twhile(r-l>1){\n\t\t\t\tint m=(l+r)/2;\n\t\t\t\tif(pr[m]<=n)\
    \ l=m;\n\t\t\t\telse r=m;\n\t\t\t}\n\t\t\treturn pr[r];\n\t\t}\n\n\t\tbool is_prime(int\
    \ n) const {\n\t\t\tif(n<2) return false;\n\t\t\treturn div[n]==n;\n\t\t}\n\n\t\
    \tvector<pair<int,int>> prime_factors(int n) const {\n\t\t\tvector<pair<int,int>>\
    \ res;\n\t\t\tint x = n;\n\t\t\twhile(2<=x){\n\t\t\t\tif(res.empty() || res.back().first!=div[x]){\n\
    \t\t\t\t\tres.push_back({div[x], 1});\n\t\t\t\t}else{\n\t\t\t\t\tres.back().second++;\n\
    \t\t\t\t}\n\t\t\t\tx /= div[x];\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\tvector<int>\
    \ get_divisors(int n) const {\n\t\t\tvector<int> res = {1};\n\t\t\tauto pf = prime_factors(n);\n\
    \t\t\tfor(auto p:pf){\n\t\t\t\tint s=(int)res.size();\n\t\t\t\tfor(int i=0; i<s;\
    \ i++){\n\t\t\t\t\tint m = 1;\n\t\t\t\t\tfor(int j=0; j<(int)p.second; j++){\n\
    \t\t\t\t\t\tm *= p.first;\n\t\t\t\t\t\tres.push_back(res[i]*m);\n\t\t\t\t\t}\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\tsort(res.begin(), res.end());\n\t\t\treturn res;\n\t\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algo/math/sieve_of_eratosthenes.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algo/math/sieve_of_eratosthenes.hpp
layout: document
redirect_from:
- /library/algo/math/sieve_of_eratosthenes.hpp
- /library/algo/math/sieve_of_eratosthenes.hpp.html
title: algo/math/sieve_of_eratosthenes.hpp
---
