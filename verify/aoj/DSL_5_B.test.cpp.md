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
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_5_B\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../data_structure/cumulative_sum_2d.hpp\"\
    \n\nint main() {\n  int N;\n  cin >> N;\n  vector<long long> x1(N), y1(N), x2(N),\
    \ y2(N);\n  for (int i = 0; i < N; i++) {\n    cin >> x1[i] >> y1[i] >> x2[i]\
    \ >> y2[i];\n  }\n\n  CumulativeSum2d<long long> cs(1001, 1001);\n  for (int i\
    \ = 0; i < N; i++) {\n    cs.add(y1[i], x1[i], y2[i], x2[i], 1LL);\n  }\n\n  cs.build();\n\
    \n  long long ans = 0;\n  for (int i = 0; i < 1000; i++) {\n    for (int j = 0;\
    \ j < 1000; j++) {\n      ans = max(ans, cs.get(i, j));\n    }\n  }\n  cout <<\
    \ ans << endl;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/aoj/DSL_5_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aoj/DSL_5_B.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_5_B.test.cpp
- /verify/verify/aoj/DSL_5_B.test.cpp.html
title: verify/aoj/DSL_5_B.test.cpp
---
