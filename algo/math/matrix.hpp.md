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
  bundledCode: "#line 2 \"math/matrix.hpp\"\n\ntemplate<class T> class Matrix{\n\t\
    private:\n\t\tint ro, co;\n\t\tvector<vector<T>> vec;\n\tpublic:\n\t\tMatrix(int\
    \ _ro, int _co, T _e=0):\n\t\t\tro(_ro), co(_co), vec(_ro,vector<T>(_co,_e)){}\n\
    \n\t\tint row() const { return ro; }\n\t\tint col() const { return co; }\n\n\t\
    \tvector<T> operator[](int i) const {\n\t\t\treturn vec[i];\n\t\t}\n\t\tvector<T>\
    \ &operator[](int i){\n\t\t\treturn vec[i];\n\t\t}\n\n\t\tMatrix<T> &operator+=(const\
    \ Matrix<T> &rhs){\n\t\t\tassert(ro==rhs.row() && co==rhs.col());\n\t\t\tfor(int\
    \ i=0; i<ro; i++){\n\t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tvec[i][j] += rhs[i][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn *this;\n\t\t};\n\t\tMatrix<T> operator+(const\
    \ Matrix<T> &rhs) const {\n\t\t\treturn Matrix(*this) += rhs;\n\t\t}\n\t\tMatrix<T>\
    \ operator+() const {\n\t\t\treturn Matrix(*this);\n\t\t}\n\t\tMatrix<T> &operator+=(T\
    \ rhs){\n\t\t\tfor(int i=0; i<ro; i++){\n\t\t\t\tfor(int j=0; j<co; j++){\n\t\t\
    \t\t\tvec[i][j] += rhs;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn *this;\n\t\t}\n\t\t\
    Matrix<T> operator+(T rhs) const {\n\t\t\treturn Matrix(*this) += rhs;\n\t\t}\n\
    \n\t\tMatrix<T> &operator-=(const Matrix<T> &rhs){\n\t\t\tassert(ro==rhs.row()\
    \ && co==rhs.col());\n\t\t\tfor(int i=0; i<ro; i++){\n\t\t\t\tfor(int j=0; j<co;\
    \ j++){\n\t\t\t\t\tvec[i][j] -= rhs[i][j];\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn *this;\n\
    \t\t}\n\t\tMatrix<T> operator-(const Matrix<T> &rhs) const {\n\t\t\treturn Matrix(*this)\
    \ -= rhs;\n\t\t}\n\t\tMatrix<T> operator-() const {\n\t\t\treturn Matrix(ro, co)-Matrix(*this);\n\
    \t\t}\n\n\t\tMatrix<T> &operator-=(T rhs){\n\t\t\treturn *this += -rhs;\n\t\t\
    }\n\t\tMatrix<T> operator-(T rhs) const {\n\t\t\treturn Matrix(*this) -= rhs;\n\
    \t\t}\n\n\t\tMatrix<T> &operator*=(const Matrix<T> &rhs){\n\t\t\tassert(ro==co\
    \ && rhs.row()==rhs.col() && co==rhs.col());\n\t\t\treturn *this = (*this)*rhs;\n\
    \t\t}\n\t\tMatrix<T> operator*(const Matrix<T> &rhs) const {\n\t\t\tassert(co==rhs.row());\n\
    \t\t\tMatrix<T> res(ro, rhs.col());\n\t\t\tfor(int i=0; i<ro; i++){\n\t\t\t\t\
    for(int j=0; j<rhs.col(); j++){\n\t\t\t\t\tfor(int k=0; k<co; k++){\n\t\t\t\t\t\
    \tres[i][j] += vec[i][k]*rhs[k][j];\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn\
    \ res;\n\t\t}\n\n\t\tMatrix<T> &operator*=(T rhs){\n\t\t\tfor(int i=0; i<ro; i++){\n\
    \t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tvec[i][j] *= rhs;\n\t\t\t\t}\n\t\t\
    \t}\n\t\t\treturn *this;\n\t\t}\n\t\tMatrix<T> operator*(T rhs) const {\n\t\t\t\
    return Matrix(*this) *= rhs;\n\t\t}\n\n\t\tMatrix<T> &operator/=(T rhs){\n\t\t\
    \tfor(int i=0; i<ro; i++){\n\t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tvec[i][j]\
    \ /= rhs;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn *this;\n\t\t}\n\t\tMatrix<T> operator/(T\
    \ rhs) const {\n\t\t\treturn Matrix(*this) /= rhs;\n\t\t}\n\n\t\tbool operator==(const\
    \ Matrix<T> &rhs) const {\n\t\t\tif(ro!=rhs.row() || co!=rhs.col()){\n\t\t\t\t\
    return false;\n\t\t\t}\n\t\t\tbool res = true;\n\t\t\tfor(int i=0; i<ro; i++){\n\
    \t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tif(vec[i][j]!=rhs[i][j]) res = false;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\tMatrix<T> pow(long long rhs)\
    \ const {\n\t\t\tassert(ro==co);\n\t\t\tMatrix<T> res(ro, co);\n\t\t\tfor(int\
    \ i=0; i<ro; i++){\n\t\t\t\tres[i][i] = 1;\n\t\t\t}\n\t\t\tMatrix<T> x = *this;\n\
    \t\t\tlong long n = rhs;\n\t\t\twhile(n){\n\t\t\t\tif(n&1) res *= x;\n\t\t\t\t\
    x *= x;\n\t\t\t\tn >>= 1;\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\tMatrix<T>\
    \ rot(const long long rhs) const {\n\t\t\tint n = 0;\n\t\t\tif(0<=rhs) n = rhs%4;\n\
    \t\t\telse n = (4-abs(rhs)%4)%4;\n\t\t\tMatrix<T> res = *this;\n\t\t\tfor(int\
    \ i=0; i<n; i++){\n\t\t\t\tMatrix<T> tmp(res.col(), res.row());\n\t\t\t\tfor(int\
    \ i=0; i<res.row(); i++){\n\t\t\t\t\tfor(int j=0; j<res.col(); j++){\n\t\t\t\t\
    \t\ttmp[j][res.row()-1-i] = res[i][j];\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tswap(res,tmp);\n\
    \t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T> class Matrix{\n\tprivate:\n\t\tint ro,\
    \ co;\n\t\tvector<vector<T>> vec;\n\tpublic:\n\t\tMatrix(int _ro, int _co, T _e=0):\n\
    \t\t\tro(_ro), co(_co), vec(_ro,vector<T>(_co,_e)){}\n\n\t\tint row() const {\
    \ return ro; }\n\t\tint col() const { return co; }\n\n\t\tvector<T> operator[](int\
    \ i) const {\n\t\t\treturn vec[i];\n\t\t}\n\t\tvector<T> &operator[](int i){\n\
    \t\t\treturn vec[i];\n\t\t}\n\n\t\tMatrix<T> &operator+=(const Matrix<T> &rhs){\n\
    \t\t\tassert(ro==rhs.row() && co==rhs.col());\n\t\t\tfor(int i=0; i<ro; i++){\n\
    \t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tvec[i][j] += rhs[i][j];\n\t\t\t\t\
    }\n\t\t\t}\n\t\t\treturn *this;\n\t\t};\n\t\tMatrix<T> operator+(const Matrix<T>\
    \ &rhs) const {\n\t\t\treturn Matrix(*this) += rhs;\n\t\t}\n\t\tMatrix<T> operator+()\
    \ const {\n\t\t\treturn Matrix(*this);\n\t\t}\n\t\tMatrix<T> &operator+=(T rhs){\n\
    \t\t\tfor(int i=0; i<ro; i++){\n\t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tvec[i][j]\
    \ += rhs;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn *this;\n\t\t}\n\t\tMatrix<T> operator+(T\
    \ rhs) const {\n\t\t\treturn Matrix(*this) += rhs;\n\t\t}\n\n\t\tMatrix<T> &operator-=(const\
    \ Matrix<T> &rhs){\n\t\t\tassert(ro==rhs.row() && co==rhs.col());\n\t\t\tfor(int\
    \ i=0; i<ro; i++){\n\t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tvec[i][j] -= rhs[i][j];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn *this;\n\t\t}\n\t\tMatrix<T> operator-(const\
    \ Matrix<T> &rhs) const {\n\t\t\treturn Matrix(*this) -= rhs;\n\t\t}\n\t\tMatrix<T>\
    \ operator-() const {\n\t\t\treturn Matrix(ro, co)-Matrix(*this);\n\t\t}\n\n\t\
    \tMatrix<T> &operator-=(T rhs){\n\t\t\treturn *this += -rhs;\n\t\t}\n\t\tMatrix<T>\
    \ operator-(T rhs) const {\n\t\t\treturn Matrix(*this) -= rhs;\n\t\t}\n\n\t\t\
    Matrix<T> &operator*=(const Matrix<T> &rhs){\n\t\t\tassert(ro==co && rhs.row()==rhs.col()\
    \ && co==rhs.col());\n\t\t\treturn *this = (*this)*rhs;\n\t\t}\n\t\tMatrix<T>\
    \ operator*(const Matrix<T> &rhs) const {\n\t\t\tassert(co==rhs.row());\n\t\t\t\
    Matrix<T> res(ro, rhs.col());\n\t\t\tfor(int i=0; i<ro; i++){\n\t\t\t\tfor(int\
    \ j=0; j<rhs.col(); j++){\n\t\t\t\t\tfor(int k=0; k<co; k++){\n\t\t\t\t\t\tres[i][j]\
    \ += vec[i][k]*rhs[k][j];\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\
    \t\t}\n\n\t\tMatrix<T> &operator*=(T rhs){\n\t\t\tfor(int i=0; i<ro; i++){\n\t\
    \t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tvec[i][j] *= rhs;\n\t\t\t\t}\n\t\t\t\
    }\n\t\t\treturn *this;\n\t\t}\n\t\tMatrix<T> operator*(T rhs) const {\n\t\t\t\
    return Matrix(*this) *= rhs;\n\t\t}\n\n\t\tMatrix<T> &operator/=(T rhs){\n\t\t\
    \tfor(int i=0; i<ro; i++){\n\t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tvec[i][j]\
    \ /= rhs;\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn *this;\n\t\t}\n\t\tMatrix<T> operator/(T\
    \ rhs) const {\n\t\t\treturn Matrix(*this) /= rhs;\n\t\t}\n\n\t\tbool operator==(const\
    \ Matrix<T> &rhs) const {\n\t\t\tif(ro!=rhs.row() || co!=rhs.col()){\n\t\t\t\t\
    return false;\n\t\t\t}\n\t\t\tbool res = true;\n\t\t\tfor(int i=0; i<ro; i++){\n\
    \t\t\t\tfor(int j=0; j<co; j++){\n\t\t\t\t\tif(vec[i][j]!=rhs[i][j]) res = false;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\tMatrix<T> pow(long long rhs)\
    \ const {\n\t\t\tassert(ro==co);\n\t\t\tMatrix<T> res(ro, co);\n\t\t\tfor(int\
    \ i=0; i<ro; i++){\n\t\t\t\tres[i][i] = 1;\n\t\t\t}\n\t\t\tMatrix<T> x = *this;\n\
    \t\t\tlong long n = rhs;\n\t\t\twhile(n){\n\t\t\t\tif(n&1) res *= x;\n\t\t\t\t\
    x *= x;\n\t\t\t\tn >>= 1;\n\t\t\t}\n\t\t\treturn res;\n\t\t}\n\n\t\tMatrix<T>\
    \ rot(const long long rhs) const {\n\t\t\tint n = 0;\n\t\t\tif(0<=rhs) n = rhs%4;\n\
    \t\t\telse n = (4-abs(rhs)%4)%4;\n\t\t\tMatrix<T> res = *this;\n\t\t\tfor(int\
    \ i=0; i<n; i++){\n\t\t\t\tMatrix<T> tmp(res.col(), res.row());\n\t\t\t\tfor(int\
    \ i=0; i<res.row(); i++){\n\t\t\t\t\tfor(int j=0; j<res.col(); j++){\n\t\t\t\t\
    \t\ttmp[j][res.row()-1-i] = res[i][j];\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\tswap(res,tmp);\n\
    \t\t\t}\n\t\t\treturn res;\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
