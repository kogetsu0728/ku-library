---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2441.test.cpp
    title: test/yukicoder/2441.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "Matrix (\u884C\u5217)"
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\n/**\n * @brief Matrix (\u884C\u5217\
    )\n */\ntemplate <class T>\nclass Matrix {\n private:\n  vector<vector<T>> val;\n\
    \n public:\n  Matrix() {}\n  Matrix(const size_t _size) : Matrix(_size, _size)\
    \ {}\n  Matrix(const size_t _height, const size_t _width)\n      : val(_height,\
    \ vector<T>(_width)) {}\n  Matrix(const vector<vector<T>> _val) : val(_val) {}\n\
    \n  size_t height() const { return val.size(); }\n  size_t width() const { return\
    \ (height() ? val[0].size() : 0); }\n\n  T get(const int i, const int j) const\
    \ { return val[i][j]; }\n  T set(const int i, const int j, const T& v) { return\
    \ val[i][j] = v; }\n\n  static Matrix identity(const size_t s) {\n    Matrix res(s,\
    \ s);\n    for (int i = 0; i < int(s); i++) {\n      res.set(i, i, T(1));\n  \
    \  }\n\n    return res;\n  }\n\n  friend bool operator==(const Matrix<T>& lhs,\
    \ const Matrix<T>& rhs) {\n    return lhs.val == rhs.val;\n  }\n\n  friend Matrix<T>\
    \ operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {\n    assert(lhs.width()\
    \ == rhs.height());\n\n    Matrix<T> res(lhs.height(), rhs.width());\n    for\
    \ (int i = 0; i < int(lhs.height()); i++) {\n      for (int j = 0; j < int(rhs.width());\
    \ j++) {\n        for (int k = 0; k < int(lhs.width()); k++) {\n          res.set(i,\
    \ j, res.get(i, j) + lhs.get(i, k) * rhs.get(k, j));\n        }\n      }\n   \
    \ }\n\n    return res;\n  }\n\n  Matrix<T>& operator*=(const Matrix<T>& rhs) {\n\
    \    assert(height() == width() && rhs.height() == rhs.width() &&\n          \
    \ height() == rhs.height());\n\n    return *this = (*this) * rhs;\n  }\n\n  Matrix<T>\
    \ pow(const long long n) const {\n    assert(height() == width());\n\n    long\
    \ long m = n;\n    Matrix<T> res = identity(height());\n    Matrix<T> x(*this);\n\
    \    while (m) {\n      if (m & 1) res *= x;\n      x *= x;\n      m >>= 1;\n\
    \    }\n\n    return res;\n  }\n};\n"
  code: "#pragma once\n\n/**\n * @brief Matrix (\u884C\u5217)\n */\ntemplate <class\
    \ T>\nclass Matrix {\n private:\n  vector<vector<T>> val;\n\n public:\n  Matrix()\
    \ {}\n  Matrix(const size_t _size) : Matrix(_size, _size) {}\n  Matrix(const size_t\
    \ _height, const size_t _width)\n      : val(_height, vector<T>(_width)) {}\n\
    \  Matrix(const vector<vector<T>> _val) : val(_val) {}\n\n  size_t height() const\
    \ { return val.size(); }\n  size_t width() const { return (height() ? val[0].size()\
    \ : 0); }\n\n  T get(const int i, const int j) const { return val[i][j]; }\n \
    \ T set(const int i, const int j, const T& v) { return val[i][j] = v; }\n\n  static\
    \ Matrix identity(const size_t s) {\n    Matrix res(s, s);\n    for (int i = 0;\
    \ i < int(s); i++) {\n      res.set(i, i, T(1));\n    }\n\n    return res;\n \
    \ }\n\n  friend bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs) {\n\
    \    return lhs.val == rhs.val;\n  }\n\n  friend Matrix<T> operator*(const Matrix<T>&\
    \ lhs, const Matrix<T>& rhs) {\n    assert(lhs.width() == rhs.height());\n\n \
    \   Matrix<T> res(lhs.height(), rhs.width());\n    for (int i = 0; i < int(lhs.height());\
    \ i++) {\n      for (int j = 0; j < int(rhs.width()); j++) {\n        for (int\
    \ k = 0; k < int(lhs.width()); k++) {\n          res.set(i, j, res.get(i, j) +\
    \ lhs.get(i, k) * rhs.get(k, j));\n        }\n      }\n    }\n\n    return res;\n\
    \  }\n\n  Matrix<T>& operator*=(const Matrix<T>& rhs) {\n    assert(height() ==\
    \ width() && rhs.height() == rhs.width() &&\n           height() == rhs.height());\n\
    \n    return *this = (*this) * rhs;\n  }\n\n  Matrix<T> pow(const long long n)\
    \ const {\n    assert(height() == width());\n\n    long long m = n;\n    Matrix<T>\
    \ res = identity(height());\n    Matrix<T> x(*this);\n    while (m) {\n      if\
    \ (m & 1) res *= x;\n      x *= x;\n      m >>= 1;\n    }\n\n    return res;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2024-09-08 19:00:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2441.test.cpp
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: "Matrix (\u884C\u5217)"
---
