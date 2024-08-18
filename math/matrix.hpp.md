---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\ntemplate<class T>\nclass Matrix{\n\t\
    private:\n\t\tint ro, co;\n\t\tvector<vector<T>> vec;\n\n\tpublic:\n\t\tMatrix():\
    \ Matrix(0, 0) {}\n\t\tMatrix(const int _ro, const int _co, const T _e=0):\n\t\
    \t\tro(_ro), co(_co), vec(_ro, vector<T>(_co, _e)) {}\n\n\t\tint row() const {\
    \ return ro; }\n\t\tint col() const { return co; }\n\n\t\tvector<T> operator[](int\
    \ i) const {\n\t\t\treturn vec[i];\n\t\t}\n\t\tvector<T> &operator[](int i){\n\
    \t\t\treturn vec[i];\n\t\t}\n\n\t\tMatrix<T> &operator*=(const Matrix<T> &rhs){\n\
    \t\t\tassert(ro==co && rhs.row()==rhs.col() && co==rhs.col());\n\t\t\treturn *this\
    \ = (*this)*rhs;\n\t\t}\n\t\tMatrix<T> operator*(const Matrix<T> &rhs) const {\n\
    \t\t\tassert(co==rhs.row());\n\t\t\tMatrix<T> res(ro, rhs.col());\n\t\t\tfor(int\
    \ i=0; i<ro; i++){\n\t\t\t\tfor(int j=0; j<rhs.col(); j++){\n\t\t\t\t\tfor(int\
    \ k=0; k<co; k++){\n\t\t\t\t\t\tres[i][j] += vec[i][k]*rhs[k][j];\n\t\t\t\t\t\
    }\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\tMatrix<T> pow(long long\
    \ n) const {\n\t\t\tassert(ro==co);\n\t\t\tMatrix<T> res(ro, co);\n\t\t\tfor(int\
    \ i=0; i<ro; i++){\n\t\t\t\tres[i][i] = 1;\n\t\t\t}\n\t\t\tMatrix<T> x = *this;\n\
    \t\t\twhile(n){\n\t\t\t\tif(n&1) res *= x;\n\t\t\t\tx *= x;\n\t\t\t\tn >>= 1;\n\
    \t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T>\nclass Matrix{\n\tprivate:\n\t\tint ro,\
    \ co;\n\t\tvector<vector<T>> vec;\n\n\tpublic:\n\t\tMatrix(): Matrix(0, 0) {}\n\
    \t\tMatrix(const int _ro, const int _co, const T _e=0):\n\t\t\tro(_ro), co(_co),\
    \ vec(_ro, vector<T>(_co, _e)) {}\n\n\t\tint row() const { return ro; }\n\t\t\
    int col() const { return co; }\n\n\t\tvector<T> operator[](int i) const {\n\t\t\
    \treturn vec[i];\n\t\t}\n\t\tvector<T> &operator[](int i){\n\t\t\treturn vec[i];\n\
    \t\t}\n\n\t\tMatrix<T> &operator*=(const Matrix<T> &rhs){\n\t\t\tassert(ro==co\
    \ && rhs.row()==rhs.col() && co==rhs.col());\n\t\t\treturn *this = (*this)*rhs;\n\
    \t\t}\n\t\tMatrix<T> operator*(const Matrix<T> &rhs) const {\n\t\t\tassert(co==rhs.row());\n\
    \t\t\tMatrix<T> res(ro, rhs.col());\n\t\t\tfor(int i=0; i<ro; i++){\n\t\t\t\t\
    for(int j=0; j<rhs.col(); j++){\n\t\t\t\t\tfor(int k=0; k<co; k++){\n\t\t\t\t\t\
    \tres[i][j] += vec[i][k]*rhs[k][j];\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ res;\n\t\t}\n\n\t\tMatrix<T> pow(long long n) const {\n\t\t\tassert(ro==co);\n\
    \t\t\tMatrix<T> res(ro, co);\n\t\t\tfor(int i=0; i<ro; i++){\n\t\t\t\tres[i][i]\
    \ = 1;\n\t\t\t}\n\t\t\tMatrix<T> x = *this;\n\t\t\twhile(n){\n\t\t\t\tif(n&1)\
    \ res *= x;\n\t\t\t\tx *= x;\n\t\t\t\tn >>= 1;\n\t\t\t}\n\t\t\treturn res;\n\t\
    \t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2024-08-18 22:54:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
