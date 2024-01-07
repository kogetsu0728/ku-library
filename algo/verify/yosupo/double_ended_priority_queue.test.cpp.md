---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data_structure/double_ended_priority_queue.hpp
    title: data_structure/double_ended_priority_queue.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"verify/yosupo/double_ended_priority_queue.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\n\n\
    #include <iostream>\n#include <set>\nusing namespace std;\n\n#line 2 \"data_structure/double_ended_priority_queue.hpp\"\
    \n\ntemplate<class T,class C=less<T>>\nclass DoubleEndedPriorityQueue: public\
    \ multiset<T,C>{\n\tpublic:\n\t\tDoubleEndedPriorityQueue():\n\t\t\tmultiset<T>(){}\n\
    \n\t\tvoid push(T val){\n\t\t\tthis->insert(val);\n\t\t}\n\n\t\tT min() const\
    \ {\n\t\t\treturn *(this->begin());\n\t\t}\n\n\t\tT max() const {\n\t\t\treturn\
    \ *(--(this->end()));\n\t\t}\n\n\t\tvoid pop_min(){\n\t\t\tthis->erase(this->begin());\n\
    \t\t}\n\n\t\tvoid pop_max(){\n\t\t\tthis->erase(--(this->end()));\n\t\t}\n};\n\
    #line 8 \"verify/yosupo/double_ended_priority_queue.test.cpp\"\n\nint main(){\n\
    \tint N, Q;\n\tcin >> N >> Q;\n\tDoubleEndedPriorityQueue<long long> que;\n\t\
    for(int i=0; i<N; i++){\n\t\tlong long s;\n\t\tcin >> s;\n\t\tque.push(s);\n\t\
    }\n\n\tfor(;Q--;){\n\t\tint t;\n\t\tcin >> t;\n\t\tif(t==0){\n\t\t\tlong long\
    \ x;\n\t\t\tcin >> x;\n\t\t\tque.push(x);\n\t\t}else if(t==1){\n\t\t\tcout <<\
    \ que.min() << endl;\n\t\t\tque.pop_min();\n\t\t}else{\n\t\t\tcout << que.max()\
    \ << endl;\n\t\t\tque.pop_max();\n\t\t}\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <iostream>\n#include <set>\nusing namespace std;\n\n#include \"../../data_structure/double_ended_priority_queue.hpp\"\
    \n\nint main(){\n\tint N, Q;\n\tcin >> N >> Q;\n\tDoubleEndedPriorityQueue<long\
    \ long> que;\n\tfor(int i=0; i<N; i++){\n\t\tlong long s;\n\t\tcin >> s;\n\t\t\
    que.push(s);\n\t}\n\n\tfor(;Q--;){\n\t\tint t;\n\t\tcin >> t;\n\t\tif(t==0){\n\
    \t\t\tlong long x;\n\t\t\tcin >> x;\n\t\t\tque.push(x);\n\t\t}else if(t==1){\n\
    \t\t\tcout << que.min() << endl;\n\t\t\tque.pop_min();\n\t\t}else{\n\t\t\tcout\
    \ << que.max() << endl;\n\t\t\tque.pop_max();\n\t\t}\n\t}\n}\n"
  dependsOn:
  - data_structure/double_ended_priority_queue.hpp
  isVerificationFile: true
  path: verify/yosupo/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-01-01 10:28:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/double_ended_priority_queue.test.cpp
- /verify/verify/yosupo/double_ended_priority_queue.test.cpp.html
title: verify/yosupo/double_ended_priority_queue.test.cpp
---
