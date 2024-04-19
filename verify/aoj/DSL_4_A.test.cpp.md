---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/cumulative_sum_2d.hpp
    title: data_structure/cumulative_sum_2d.hpp
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A
  bundledCode: "#line 1 \"verify/aoj/DSL_4_A.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"misc/compress.hpp\"\
    \n\ntemplate<class T,class C=less<T>>\nclass Compress{\n\tprivate:\n\t\tvector<T>\
    \ v;\n\n\tpublic:\n\t\tCompress(){}\n\n\t\tvoid push(const T x){\n\t\t\tv.push_back(x);\n\
    \t\t}\n\n\t\tvoid build(){\n\t\t\tsort(v.begin(), v.end(), C());\n\t\t\tv.erase(unique(v.begin(),v.end()),v.end());\n\
    \t\t}\n\n\t\tsize_t size() const {\n\t\t\treturn v.size();\n\t\t}\n\n\t\tT nth(const\
    \ int i) const {\n\t\t\tassert(0<=i && i<int(v.size()));\n\t\t\treturn v[i];\n\
    \t\t}\n\n\t\tint get(const T x) const {\n\t\t\tint ng=-1, ok=int(v.size())-1;\n\
    \t\t\twhile(1<ok-ng){\n\t\t\t\tint mid=(ok+ng)/2;\n\t\t\t\tif(!C()(v[mid],x))\
    \ ok=mid;\n\t\t\t\telse ng=mid;\n\t\t\t}\n\t\t\treturn ok;\n\t\t}\n\n\t\tbool\
    \ count(const T x) const {\n\t\t\treturn nth(get(x))==x;\n\t\t}\n};\n#line 2 \"\
    data_structure/cumulative_sum_2d.hpp\"\n\ntemplate<class T>\nclass CumulativeSum2d{\n\
    \tprivate:\n\t\tbool init;\n\t\tint h, w;\n\t\tvector<vector<T>> v;\n\n\tpublic:\n\
    \t\tCumulativeSum2d():CumulativeSum2d(0,0){}\n\t\tCumulativeSum2d(int _h, int\
    \ _w, T _e=0):\n\t\t\tinit(false), h(_h), w(_w), v(_h+1,vector<T>(_w+1,_e)){}\n\
    \n\t\tvoid add(int y, int x, T d){\n\t\t\tassert(init==false);\n\t\t\tv[y+1][x+1]\
    \ += d;\n\t\t}\n\n\t\tvoid add(int y1, int x1, int y2, int x2, T d){\n\t\t\tassert(init==false);\n\
    \t\t\tadd(y1, x1, d);\n\t\t\tadd(y1, x2, -d);\n\t\t\tadd(y2, x1, -d);\n\t\t\t\
    add(y2, x2, d);\n\t\t}\n\n\t\tvoid build(){\n\t\t\tassert(init==false);\n\t\t\t\
    init = true;\n\t\t\tfor(int y=1; y<=h; y++){\n\t\t\t\tfor(int x=1; x<=w; x++){\n\
    \t\t\t\t\tv[y][x] += v[y][x-1]+v[y-1][x]-v[y-1][x-1];\n\t\t\t\t}\n\t\t\t}\n\t\t\
    }\n\n\t\tT get(int y, int x) const {\n\t\t\tassert(init==true);\n\t\t\treturn\
    \ v[y+1][x+1];\n\t\t}\n\n\t\tT sum(int y1, int x1, int y2, int x2) const {\n\t\
    \t\tassert(init==true);\n\t\t\treturn v[y2][x2]-v[y1][x2]-v[y2][x1]+v[y1][x1];\n\
    \t\t}\n};\n#line 8 \"verify/aoj/DSL_4_A.test.cpp\"\n\nint main(){\n\tint N;\n\t\
    cin >> N;\n\tvector<long long> x1(N), y1(N), x2(N), y2(N);\n\tfor(int i=0; i<N;\
    \ i++){\n\t\tcin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n\t}\n\n\tCompress<long\
    \ long> cmp_x, cmp_y;\n\tfor(int i=0; i<N; i++){\n\t\tcmp_x.push(x1[i]), cmp_x.push(x2[i]);\n\
    \t\tcmp_y.push(y1[i]), cmp_y.push(y2[i]);\n\t}\n\n\tcmp_x.build(), cmp_y.build();\n\
    \n\tCumulativeSum2d<int> cnt(int(cmp_y.size()), int(cmp_x.size()));\n\tfor(int\
    \ i=0; i<N; i++){\n\t\tcnt.add(cmp_y.get(y1[i]), cmp_x.get(x1[i]),\n\t\tcmp_y.get(y2[i]),\
    \ cmp_x.get(x2[i]), 1);\n\t}\n\n\tcnt.build();\n\n\tlong long ans{};\n\tfor(int\
    \ i=0; i<int(cmp_y.size())-1; i++){\n\t\tfor(int j=0; j<int(cmp_x.size())-1; j++){\n\
    \t\t\tif(cnt.get(i,j)){\n\t\t\t\tans += (cmp_y.nth(i+1)-cmp_y.nth(i))*(cmp_x.nth(j+1)-cmp_x.nth(j));\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tcout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../misc/compress.hpp\"\
    \n#include \"../../data_structure/cumulative_sum_2d.hpp\"\n\nint main(){\n\tint\
    \ N;\n\tcin >> N;\n\tvector<long long> x1(N), y1(N), x2(N), y2(N);\n\tfor(int\
    \ i=0; i<N; i++){\n\t\tcin >> x1[i] >> y1[i] >> x2[i] >> y2[i];\n\t}\n\n\tCompress<long\
    \ long> cmp_x, cmp_y;\n\tfor(int i=0; i<N; i++){\n\t\tcmp_x.push(x1[i]), cmp_x.push(x2[i]);\n\
    \t\tcmp_y.push(y1[i]), cmp_y.push(y2[i]);\n\t}\n\n\tcmp_x.build(), cmp_y.build();\n\
    \n\tCumulativeSum2d<int> cnt(int(cmp_y.size()), int(cmp_x.size()));\n\tfor(int\
    \ i=0; i<N; i++){\n\t\tcnt.add(cmp_y.get(y1[i]), cmp_x.get(x1[i]),\n\t\tcmp_y.get(y2[i]),\
    \ cmp_x.get(x2[i]), 1);\n\t}\n\n\tcnt.build();\n\n\tlong long ans{};\n\tfor(int\
    \ i=0; i<int(cmp_y.size())-1; i++){\n\t\tfor(int j=0; j<int(cmp_x.size())-1; j++){\n\
    \t\t\tif(cnt.get(i,j)){\n\t\t\t\tans += (cmp_y.nth(i+1)-cmp_y.nth(i))*(cmp_x.nth(j+1)-cmp_x.nth(j));\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tcout << ans << endl;\n}\n"
  dependsOn:
  - misc/compress.hpp
  - data_structure/cumulative_sum_2d.hpp
  isVerificationFile: true
  path: verify/aoj/DSL_4_A.test.cpp
  requiredBy: []
  timestamp: '2024-04-19 21:17:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aoj/DSL_4_A.test.cpp
layout: document
redirect_from:
- /verify/verify/aoj/DSL_4_A.test.cpp
- /verify/verify/aoj/DSL_4_A.test.cpp.html
title: verify/aoj/DSL_4_A.test.cpp
---
