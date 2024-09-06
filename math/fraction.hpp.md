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
  bundledCode: "#line 2 \"math/fraction.hpp\"\n\ntemplate <class T>\nclass Fraction\
    \ {\n private:\n  T num, den;\n  Fraction<T> &reduce() {\n    assert(den != 0);\n\
    \    if (num == 0) {\n      den = 1;\n    } else {\n      if (den < 0) {\n   \
    \     num *= -1, den *= -1;\n      }\n      T div = gcd(abs(num), den);\n    \
    \  num /= div, den /= div;\n    }\n    return *this;\n  }\n\n public:\n  Fraction(const\
    \ T _num = 0, const T _den = 1) : num(_num), den(_den) {\n    reduce();\n  }\n\
    \n  T numer() const { return num; }\n  T denom() const { return den; }\n  long\
    \ double val() const { return (long double)num / den; }\n\n  bool operator<(const\
    \ Fraction<T> &rhs) const {\n    return num * rhs.denom() < rhs.numer() * den;\n\
    \  }\n  bool operator>(const Fraction<T> &rhs) const {\n    return num * rhs.denom()\
    \ > rhs.numer() * den;\n  }\n  bool operator==(const Fraction<T> &rhs) const {\n\
    \    return num * rhs.denom() == rhs.numer() * den;\n  }\n  bool operator<=(const\
    \ Fraction<T> &rhs) const {\n    return num * rhs.denom() <= rhs.numer() * den;\n\
    \  }\n  bool operator>=(const Fraction<T> &rhs) const {\n    return num * rhs.denom()\
    \ >= rhs.numer() * den;\n  }\n\n  Fraction<T> &operator+=(const Fraction<T> &rhs)\
    \ {\n    num = num * rhs.denom() + rhs.numer() * den;\n    den = den * rhs.denom();\n\
    \    return reduce();\n  }\n  Fraction<T> operator+(const Fraction<T> &rhs) const\
    \ {\n    return Fraction(*this) += rhs;\n  }\n  Fraction<T> operator+() const\
    \ { return Fraction(*this); }\n\n  Fraction<T> &operator-=(const Fraction<T> &rhs)\
    \ {\n    num = num * rhs.denom() - rhs.numer() * den;\n    den = den * rhs.denom();\n\
    \    return reduce();\n  }\n  Fraction<T> operator-(const Fraction<T> &rhs) const\
    \ {\n    return Fraction(*this) -= rhs;\n  }\n  Fraction<T> operator-() const\
    \ { return Fraction() - Fraction(*this); }\n\n  Fraction<T> &operator*=(const\
    \ Fraction<T> &rhs) {\n    num = num * rhs.numer();\n    den = den * rhs.denom();\n\
    \    return reduce();\n  }\n  Fraction<T> operator*(const Fraction<T> &rhs) const\
    \ {\n    return Fraction(*this) *= rhs;\n  }\n\n  Fraction<T> &operator/=(const\
    \ Fraction<T> &rhs) {\n    num = num * rhs.denom();\n    den = den * rhs.numer();\n\
    \    return reduce();\n  }\n  Fraction<T> operator/(const Fraction<T> &rhs) const\
    \ {\n    return Fraction(*this) /= rhs;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const Fraction &rhs) {\n    os << rhs.val();\n    return os;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nclass Fraction {\n private:\n  T num,\
    \ den;\n  Fraction<T> &reduce() {\n    assert(den != 0);\n    if (num == 0) {\n\
    \      den = 1;\n    } else {\n      if (den < 0) {\n        num *= -1, den *=\
    \ -1;\n      }\n      T div = gcd(abs(num), den);\n      num /= div, den /= div;\n\
    \    }\n    return *this;\n  }\n\n public:\n  Fraction(const T _num = 0, const\
    \ T _den = 1) : num(_num), den(_den) {\n    reduce();\n  }\n\n  T numer() const\
    \ { return num; }\n  T denom() const { return den; }\n  long double val() const\
    \ { return (long double)num / den; }\n\n  bool operator<(const Fraction<T> &rhs)\
    \ const {\n    return num * rhs.denom() < rhs.numer() * den;\n  }\n  bool operator>(const\
    \ Fraction<T> &rhs) const {\n    return num * rhs.denom() > rhs.numer() * den;\n\
    \  }\n  bool operator==(const Fraction<T> &rhs) const {\n    return num * rhs.denom()\
    \ == rhs.numer() * den;\n  }\n  bool operator<=(const Fraction<T> &rhs) const\
    \ {\n    return num * rhs.denom() <= rhs.numer() * den;\n  }\n  bool operator>=(const\
    \ Fraction<T> &rhs) const {\n    return num * rhs.denom() >= rhs.numer() * den;\n\
    \  }\n\n  Fraction<T> &operator+=(const Fraction<T> &rhs) {\n    num = num * rhs.denom()\
    \ + rhs.numer() * den;\n    den = den * rhs.denom();\n    return reduce();\n \
    \ }\n  Fraction<T> operator+(const Fraction<T> &rhs) const {\n    return Fraction(*this)\
    \ += rhs;\n  }\n  Fraction<T> operator+() const { return Fraction(*this); }\n\n\
    \  Fraction<T> &operator-=(const Fraction<T> &rhs) {\n    num = num * rhs.denom()\
    \ - rhs.numer() * den;\n    den = den * rhs.denom();\n    return reduce();\n \
    \ }\n  Fraction<T> operator-(const Fraction<T> &rhs) const {\n    return Fraction(*this)\
    \ -= rhs;\n  }\n  Fraction<T> operator-() const { return Fraction() - Fraction(*this);\
    \ }\n\n  Fraction<T> &operator*=(const Fraction<T> &rhs) {\n    num = num * rhs.numer();\n\
    \    den = den * rhs.denom();\n    return reduce();\n  }\n  Fraction<T> operator*(const\
    \ Fraction<T> &rhs) const {\n    return Fraction(*this) *= rhs;\n  }\n\n  Fraction<T>\
    \ &operator/=(const Fraction<T> &rhs) {\n    num = num * rhs.denom();\n    den\
    \ = den * rhs.numer();\n    return reduce();\n  }\n  Fraction<T> operator/(const\
    \ Fraction<T> &rhs) const {\n    return Fraction(*this) /= rhs;\n  }\n\n  friend\
    \ ostream &operator<<(ostream &os, const Fraction &rhs) {\n    os << rhs.val();\n\
    \    return os;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/fraction.hpp
  requiredBy: []
  timestamp: '2024-09-06 18:14:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fraction.hpp
layout: document
redirect_from:
- /library/math/fraction.hpp
- /library/math/fraction.hpp.html
title: math/fraction.hpp
---
