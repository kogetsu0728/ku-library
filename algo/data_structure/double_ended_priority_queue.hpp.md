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
  bundledCode: "#line 2 \"data_structure/double_ended_priority_queue.hpp\"\n\ntemplate<class\
    \ T,class C=less<T>>\nclass DoubleEndedPriorityQueue: public multiset<T,C>{\n\t\
    public:\n\t\tDoubleEndedPriorityQueue():\n\t\t\tmultiset<T>(){}\n\n\t\tvoid push(T\
    \ val){\n\t\t\tthis->insert(val);\n\t\t}\n\n\t\tT min() const {\n\t\t\treturn\
    \ *(this->begin());\n\t\t}\n\n\t\tT max() const {\n\t\t\treturn *(--(this->end()));\n\
    \t\t}\n\n\t\tvoid pop_min(){\n\t\t\tthis->erase(this->begin());\n\t\t}\n\n\t\t\
    void pop_max(){\n\t\t\tthis->erase(--(this->end()));\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T,class C=less<T>>\nclass DoubleEndedPriorityQueue:\
    \ public multiset<T,C>{\n\tpublic:\n\t\tDoubleEndedPriorityQueue():\n\t\t\tmultiset<T>(){}\n\
    \n\t\tvoid push(T val){\n\t\t\tthis->insert(val);\n\t\t}\n\n\t\tT min() const\
    \ {\n\t\t\treturn *(this->begin());\n\t\t}\n\n\t\tT max() const {\n\t\t\treturn\
    \ *(--(this->end()));\n\t\t}\n\n\t\tvoid pop_min(){\n\t\t\tthis->erase(this->begin());\n\
    \t\t}\n\n\t\tvoid pop_max(){\n\t\t\tthis->erase(--(this->end()));\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data_structure/double_ended_priority_queue.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
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
