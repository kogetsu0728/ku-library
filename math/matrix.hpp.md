---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Matrix (\u884C\u5217)"
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\n/**\n * @brief Matrix (\u884C\u5217\
    )\n */\ntemplate <class T>\nclass Matrix {\n private:\n  int ro, co;\n  vector<vector<T>>\
    \ vec;\n\n public:\n  Matrix() : Matrix(0, 0) {}\n  Matrix(const int _ro, const\
    \ int _co, const T _e = 0)\n      : ro(_ro), co(_co), vec(_ro, vector<T>(_co,\
    \ _e)) {}\n\n  int row() const { return ro; }\n  int col() const { return co;\
    \ }\n\n  vector<T> operator[](int i) const { return vec[i]; }\n  vector<T> &operator[](int\
    \ i) { return vec[i]; }\n\n  Matrix<T> &operator*=(const Matrix<T> &rhs) {\n \
    \   assert(ro == co && rhs.row() == rhs.col() && co == rhs.col());\n    return\
    \ *this = (*this) * rhs;\n  }\n  Matrix<T> operator*(const Matrix<T> &rhs) const\
    \ {\n    assert(co == rhs.row());\n    Matrix<T> res(ro, rhs.col());\n    for\
    \ (int i = 0; i < ro; i++) {\n      for (int j = 0; j < rhs.col(); j++) {\n  \
    \      for (int k = 0; k < co; k++) {\n          res[i][j] += vec[i][k] * rhs[k][j];\n\
    \        }\n      }\n    }\n    return res;\n  }\n\n  Matrix<T> pow(long long\
    \ n) const {\n    assert(ro == co);\n    Matrix<T> res(ro, co);\n    for (int\
    \ i = 0; i < ro; i++) {\n      res[i][i] = 1;\n    }\n    Matrix<T> x = *this;\n\
    \    while (n) {\n      if (n & 1) res *= x;\n      x *= x;\n      n >>= 1;\n\
    \    }\n    return res;\n  }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Matrix (\u884C\u5217)\n */\ntemplate <class\
    \ T>\nclass Matrix {\n private:\n  int ro, co;\n  vector<vector<T>> vec;\n\n public:\n\
    \  Matrix() : Matrix(0, 0) {}\n  Matrix(const int _ro, const int _co, const T\
    \ _e = 0)\n      : ro(_ro), co(_co), vec(_ro, vector<T>(_co, _e)) {}\n\n  int\
    \ row() const { return ro; }\n  int col() const { return co; }\n\n  vector<T>\
    \ operator[](int i) const { return vec[i]; }\n  vector<T> &operator[](int i) {\
    \ return vec[i]; }\n\n  Matrix<T> &operator*=(const Matrix<T> &rhs) {\n    assert(ro\
    \ == co && rhs.row() == rhs.col() && co == rhs.col());\n    return *this = (*this)\
    \ * rhs;\n  }\n  Matrix<T> operator*(const Matrix<T> &rhs) const {\n    assert(co\
    \ == rhs.row());\n    Matrix<T> res(ro, rhs.col());\n    for (int i = 0; i < ro;\
    \ i++) {\n      for (int j = 0; j < rhs.col(); j++) {\n        for (int k = 0;\
    \ k < co; k++) {\n          res[i][j] += vec[i][k] * rhs[k][j];\n        }\n \
    \     }\n    }\n    return res;\n  }\n\n  Matrix<T> pow(long long n) const {\n\
    \    assert(ro == co);\n    Matrix<T> res(ro, co);\n    for (int i = 0; i < ro;\
    \ i++) {\n      res[i][i] = 1;\n    }\n    Matrix<T> x = *this;\n    while (n)\
    \ {\n      if (n & 1) res *= x;\n      x *= x;\n      n >>= 1;\n    }\n    return\
    \ res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:44:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: "Matrix (\u884C\u5217)"
---
