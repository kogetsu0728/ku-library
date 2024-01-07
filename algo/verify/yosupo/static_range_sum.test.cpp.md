---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/segment_tree.hpp
    title: data_structure/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verify/yosupo/static_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include <iostream>\n\
    #include <vector>\nusing namespace std;\n\n#line 2 \"data_structure/segment_tree.hpp\"\
    \n\ntemplate<class S, S (*op)(S,S), S (*e)()>\nclass SegmentTree{\n\tprivate:\n\
    \t\tint n;\n\t\tvector<S> v;\n\n\t\tvoid update(int i){\n\t\t\tv[i] = op(v[i<<1],\
    \ v[(i<<1)|1]);\n\t\t}\n\n\tpublic:\n\t\tSegmentTree():SegmentTree(0){}\n\t\t\
    SegmentTree(int _n):SegmentTree(vector<S>(_n, e())){}\n\t\tSegmentTree(const vector<S>\
    \ &_v){\n\t\t\tn = (int)_v.size();\n\t\t\tv.assign(2*n, e());\n\t\t\tfor(int i=0;\
    \ i<n; i++) v[n+i] = _v[i];\n\t\t\tfor(int i=n-1; i>=1; i--) update(i);\n\t\t\
    }\n\n\t\tS get(int i) const {\n\t\t\ti += n;\n\t\t\treturn v[i];\n\t\t}\n\n\t\t\
    S prod(int l, int r) const {\n\t\t\tl += n, r += n;\n\t\t\tS v_l = e(), v_r =\
    \ e();\n\t\t\twhile(l<r){\n\t\t\t\tif(l&1) v_l = op(v_l, v[l++]);\n\t\t\t\tif(r&1)\
    \ v_r = op(v[--r], v_r);\n\t\t\t\tl >>= 1, r >>= 1;\n\t\t\t}\n\t\t\treturn op(v_l,\
    \ v_r);\n\t\t}\n\n\t\tvoid set(int i, S x){\n\t\t\ti += n;\n\t\t\tv[i] = x;\n\t\
    \t\twhile(1<i){\n\t\t\t\ti >>= 1;\n\t\t\t\tupdate(i);\n\t\t\t}\n\t\t}\n};\n#line\
    \ 8 \"verify/yosupo/static_range_sum.test.cpp\"\n\nlong long op(long long a, long\
    \ long b){\n\treturn a+b;\n}\n\nlong long e(){\n\treturn 0LL;\n}\n\nint main(){\n\
    \tint N, Q;\n\tcin >> N >> Q;\n\tvector<long long> A(N);\n\tfor(int i=0; i<N;\
    \ i++){\n\t\tcin >> A[i];\n\t}\n\n\tSegmentTree<long long, op, e> seg(A);\n\t\
    for(;Q--;){\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\tcout << seg.prod(l,r) << endl;\n\
    \t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <iostream>\n#include <vector>\nusing namespace std;\n\n#include \"../../data_structure/segment_tree.hpp\"\
    \n\nlong long op(long long a, long long b){\n\treturn a+b;\n}\n\nlong long e(){\n\
    \treturn 0LL;\n}\n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tvector<long\
    \ long> A(N);\n\tfor(int i=0; i<N; i++){\n\t\tcin >> A[i];\n\t}\n\n\tSegmentTree<long\
    \ long, op, e> seg(A);\n\tfor(;Q--;){\n\t\tint l, r;\n\t\tcin >> l >> r;\n\t\t\
    cout << seg.prod(l,r) << endl;\n\t}\n}\n"
  dependsOn:
  - data_structure/segment_tree.hpp
  isVerificationFile: true
  path: verify/yosupo/static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-01 10:28:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/static_range_sum.test.cpp
- /verify/verify/yosupo/static_range_sum.test.cpp.html
title: verify/yosupo/static_range_sum.test.cpp
---
