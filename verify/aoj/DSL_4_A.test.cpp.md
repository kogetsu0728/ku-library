---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data_structure/cumulative_sum_2d.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/cumulative_sum_2d.hpp\"\
    \n#include \"../../misc/compress.hpp\"\n\nint main() {\n  int N;\n  cin >> N;\n\
    \  vector<long long> x1(N), y1(N), x2(N), y2(N);\n  for (int i = 0; i < N; i++)\
    \ {\n    cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n  }\n\n  Compress<long long>\
    \ cmp_x, cmp_y;\n  for (int i = 0; i < N; i++) {\n    cmp_x.push(x1[i]), cmp_x.push(x2[i]);\n\
    \    cmp_y.push(y1[i]), cmp_y.push(y2[i]);\n  }\n\n  cmp_x.build(), cmp_y.build();\n\
    \n  CumulativeSum2d<int> cnt(int(cmp_y.size()), int(cmp_x.size()));\n  for (int\
    \ i = 0; i < N; i++) {\n    cnt.add(cmp_y.get(y1[i]), cmp_x.get(x1[i]), cmp_y.get(y2[i]),\n\
    \            cmp_x.get(x2[i]), 1);\n  }\n\n  cnt.build();\n\n  long long ans{};\n\
    \  for (int i = 0; i < int(cmp_y.size()) - 1; i++) {\n    for (int j = 0; j <\
    \ int(cmp_x.size()) - 1; j++) {\n      if (cnt.get(i, j)) {\n        ans += (cmp_y.nth(i\
    \ + 1) - cmp_y.nth(i)) *\n               (cmp_x.nth(j + 1) - cmp_x.nth(j));\n\
    \      }\n    }\n  }\n\n  cout << ans << endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/aoj/DSL_4_A.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/DSL_4_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_4_A.test.cpp
- /verify/verify/aoj/DSL_4_A.test.cpp.html
title: verify/aoj/DSL_4_A.test.cpp
---
