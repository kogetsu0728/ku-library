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
  bundledCode: "#line 2 \"math/fraction.hpp\"\n\ntemplate<class T> class Fraction{\n\
    \tprivate:\n\t\tT num, den;\n\t\tFraction<T> &reduce(){\n\t\t\tassert(den!=0);\n\
    \t\t\tif(num==0){\n\t\t\t\tden = 1;\n\t\t\t}else{\n\t\t\t\tif(den<0){ num *= -1,\
    \ den *= -1; }\n\t\t\t\tT div = gcd(abs(num), den);\n\t\t\t\tnum /= div, den /=\
    \ div;\n\t\t\t}\n\t\t\treturn *this;\n\t\t}\n\n\tpublic:\n\t\tFraction(const T\
    \ _num=0, const T _den=1):\n\t\t\tnum(_num), den(_den){\n\t\t\t\treduce();\n\t\
    \t\t}\n\n\t\tT numer() const { return num; }\n\t\tT denom() const { return den;\
    \ }\n\t\tlong double val() const { return (long double)num/den; }\n\n\t\tbool\
    \ operator<(const Fraction<T> &rhs) const {\n\t\t\treturn num*rhs.denom() < rhs.numer()*den;\n\
    \t\t}\n\t\tbool operator>(const Fraction<T> &rhs) const {\n\t\t\treturn num*rhs.denom()\
    \ > rhs.numer()*den;\n\t\t}\n\t\tbool operator==(const Fraction<T> &rhs) const\
    \ {\n\t\t\treturn num*rhs.denom() == rhs.numer()*den;\n\t\t}\n\n\t\tFraction<T>\
    \ &operator+=(const Fraction<T> &rhs){\n\t\t\tnum = num*rhs.denom() + rhs.numer()*den;\n\
    \t\t\tden = den*rhs.denom();\n\t\t\treturn reduce();\n\t\t}\n\t\tFraction<T> operator+(const\
    \ Fraction<T> &rhs) const {\n\t\t\treturn Fraction(*this) += rhs;\n\t\t}\n\t\t\
    Fraction<T> operator+() const {\n\t\t\treturn Fraction(*this);\n\t\t}\n\n\t\t\
    Fraction<T> &operator-=(const Fraction<T> &rhs){\n\t\t\tnum = num*rhs.denom()\
    \ - rhs.numer()*den;\n\t\t\tden = den*rhs.denom();\n\t\t\treturn reduce();\n\t\
    \t}\n\t\tFraction<T> operator-(const Fraction<T> &rhs) const {\n\t\t\treturn Fraction(*this)\
    \ -= rhs;\n\t\t}\n\t\tFraction<T> operator-() const {\n\t\t\treturn Fraction()-Fraction(*this);\n\
    \t\t}\n\n\t\tFraction<T> &operator*=(const Fraction<T> &rhs){\n\t\t\tnum = num*rhs.numer();\n\
    \t\t\tden = den*rhs.denom();\n\t\t\treturn reduce();\n\t\t}\n\t\tFraction<T> operator*(const\
    \ Fraction<T> &rhs) const {\n\t\t\treturn Fraction(*this) *= rhs;\n\t\t}\n\n\t\
    \tFraction<T> &operator/=(const Fraction<T> &rhs){\n\t\t\tnum = num*rhs.denom();\n\
    \t\t\tden = den*rhs.numer();\n\t\t\treturn reduce();\n\t\t}\n\t\tFraction<T> operator/(const\
    \ Fraction<T> &rhs) const {\n\t\t\treturn Fraction(*this) /= rhs;\n\t\t}\n\n\t\
    \tfriend ostream& operator<<(ostream& os, const Fraction &rhs){\n\t\t\tos << rhs.val();\n\
    \t\t\treturn os;\n\t\t}\n};\n"
  code: "#pragma once\n\ntemplate<class T> class Fraction{\n\tprivate:\n\t\tT num,\
    \ den;\n\t\tFraction<T> &reduce(){\n\t\t\tassert(den!=0);\n\t\t\tif(num==0){\n\
    \t\t\t\tden = 1;\n\t\t\t}else{\n\t\t\t\tif(den<0){ num *= -1, den *= -1; }\n\t\
    \t\t\tT div = gcd(abs(num), den);\n\t\t\t\tnum /= div, den /= div;\n\t\t\t}\n\t\
    \t\treturn *this;\n\t\t}\n\n\tpublic:\n\t\tFraction(const T _num=0, const T _den=1):\n\
    \t\t\tnum(_num), den(_den){\n\t\t\t\treduce();\n\t\t\t}\n\n\t\tT numer() const\
    \ { return num; }\n\t\tT denom() const { return den; }\n\t\tlong double val()\
    \ const { return (long double)num/den; }\n\n\t\tbool operator<(const Fraction<T>\
    \ &rhs) const {\n\t\t\treturn num*rhs.denom() < rhs.numer()*den;\n\t\t}\n\t\t\
    bool operator>(const Fraction<T> &rhs) const {\n\t\t\treturn num*rhs.denom() >\
    \ rhs.numer()*den;\n\t\t}\n\t\tbool operator==(const Fraction<T> &rhs) const {\n\
    \t\t\treturn num*rhs.denom() == rhs.numer()*den;\n\t\t}\n\n\t\tFraction<T> &operator+=(const\
    \ Fraction<T> &rhs){\n\t\t\tnum = num*rhs.denom() + rhs.numer()*den;\n\t\t\tden\
    \ = den*rhs.denom();\n\t\t\treturn reduce();\n\t\t}\n\t\tFraction<T> operator+(const\
    \ Fraction<T> &rhs) const {\n\t\t\treturn Fraction(*this) += rhs;\n\t\t}\n\t\t\
    Fraction<T> operator+() const {\n\t\t\treturn Fraction(*this);\n\t\t}\n\n\t\t\
    Fraction<T> &operator-=(const Fraction<T> &rhs){\n\t\t\tnum = num*rhs.denom()\
    \ - rhs.numer()*den;\n\t\t\tden = den*rhs.denom();\n\t\t\treturn reduce();\n\t\
    \t}\n\t\tFraction<T> operator-(const Fraction<T> &rhs) const {\n\t\t\treturn Fraction(*this)\
    \ -= rhs;\n\t\t}\n\t\tFraction<T> operator-() const {\n\t\t\treturn Fraction()-Fraction(*this);\n\
    \t\t}\n\n\t\tFraction<T> &operator*=(const Fraction<T> &rhs){\n\t\t\tnum = num*rhs.numer();\n\
    \t\t\tden = den*rhs.denom();\n\t\t\treturn reduce();\n\t\t}\n\t\tFraction<T> operator*(const\
    \ Fraction<T> &rhs) const {\n\t\t\treturn Fraction(*this) *= rhs;\n\t\t}\n\n\t\
    \tFraction<T> &operator/=(const Fraction<T> &rhs){\n\t\t\tnum = num*rhs.denom();\n\
    \t\t\tden = den*rhs.numer();\n\t\t\treturn reduce();\n\t\t}\n\t\tFraction<T> operator/(const\
    \ Fraction<T> &rhs) const {\n\t\t\treturn Fraction(*this) /= rhs;\n\t\t}\n\n\t\
    \tfriend ostream& operator<<(ostream& os, const Fraction &rhs){\n\t\t\tos << rhs.val();\n\
    \t\t\treturn os;\n\t\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fraction.hpp
  requiredBy: []
  timestamp: '2024-01-01 10:12:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fraction.hpp
layout: document
redirect_from:
- /library/math/fraction.hpp
- /library/math/fraction.hpp.html
title: math/fraction.hpp
---
