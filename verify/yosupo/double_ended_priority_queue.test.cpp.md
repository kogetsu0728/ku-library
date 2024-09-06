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
    \n\ntemplate <class T, class C = less<T>>\nclass DoubleEndedPriorityQueue : public\
    \ multiset<T, C> {\n public:\n  DoubleEndedPriorityQueue() : multiset<T>() {}\n\
    \n  void push(T val) { this->insert(val); }\n\n  T min() const { return *(this->begin());\
    \ }\n\n  T max() const { return *(--(this->end())); }\n\n  void pop_min() { this->erase(this->begin());\
    \ }\n\n  void pop_max() { this->erase(--(this->end())); }\n};\n#line 8 \"verify/yosupo/double_ended_priority_queue.test.cpp\"\
    \n\nint main() {\n  int N, Q;\n  cin >> N >> Q;\n  DoubleEndedPriorityQueue<long\
    \ long> que;\n  for (int i = 0; i < N; i++) {\n    long long s;\n    cin >> s;\n\
    \    que.push(s);\n  }\n\n  for (; Q--;) {\n    int t;\n    cin >> t;\n    if\
    \ (t == 0) {\n      long long x;\n      cin >> x;\n      que.push(x);\n    } else\
    \ if (t == 1) {\n      cout << que.min() << endl;\n      que.pop_min();\n    }\
    \ else {\n      cout << que.max() << endl;\n      que.pop_max();\n    }\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include <iostream>\n#include <set>\nusing namespace std;\n\n#include \"../../data_structure/double_ended_priority_queue.hpp\"\
    \n\nint main() {\n  int N, Q;\n  cin >> N >> Q;\n  DoubleEndedPriorityQueue<long\
    \ long> que;\n  for (int i = 0; i < N; i++) {\n    long long s;\n    cin >> s;\n\
    \    que.push(s);\n  }\n\n  for (; Q--;) {\n    int t;\n    cin >> t;\n    if\
    \ (t == 0) {\n      long long x;\n      cin >> x;\n      que.push(x);\n    } else\
    \ if (t == 1) {\n      cout << que.min() << endl;\n      que.pop_min();\n    }\
    \ else {\n      cout << que.max() << endl;\n      que.pop_max();\n    }\n  }\n\
    }\n"
  dependsOn:
  - data_structure/double_ended_priority_queue.hpp
  isVerificationFile: true
  path: verify/yosupo/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/double_ended_priority_queue.test.cpp
- /verify/verify/yosupo/double_ended_priority_queue.test.cpp.html
title: verify/yosupo/double_ended_priority_queue.test.cpp
---
