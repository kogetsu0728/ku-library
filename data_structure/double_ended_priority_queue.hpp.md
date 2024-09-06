---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/double_ended_priority_queue.test.cpp
    title: verify/yosupo/double_ended_priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data_structure/double_ended_priority_queue.hpp\"\n\ntemplate\
    \ <class T, class C = less<T>>\nclass DoubleEndedPriorityQueue : public multiset<T,\
    \ C> {\n public:\n  DoubleEndedPriorityQueue() : multiset<T>() {}\n\n  void push(T\
    \ val) { this->insert(val); }\n\n  T min() const { return *(this->begin()); }\n\
    \n  T max() const { return *(--(this->end())); }\n\n  void pop_min() { this->erase(this->begin());\
    \ }\n\n  void pop_max() { this->erase(--(this->end())); }\n};\n"
  code: "#pragma once\n\ntemplate <class T, class C = less<T>>\nclass DoubleEndedPriorityQueue\
    \ : public multiset<T, C> {\n public:\n  DoubleEndedPriorityQueue() : multiset<T>()\
    \ {}\n\n  void push(T val) { this->insert(val); }\n\n  T min() const { return\
    \ *(this->begin()); }\n\n  T max() const { return *(--(this->end())); }\n\n  void\
    \ pop_min() { this->erase(this->begin()); }\n\n  void pop_max() { this->erase(--(this->end()));\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/double_ended_priority_queue.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/double_ended_priority_queue.test.cpp
documentation_of: data_structure/double_ended_priority_queue.hpp
layout: document
redirect_from:
- /library/data_structure/double_ended_priority_queue.hpp
- /library/data_structure/double_ended_priority_queue.hpp.html
title: data_structure/double_ended_priority_queue.hpp
---
