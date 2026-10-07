---
title: Extended Euclidean Algorithm
documentation_of: ../../math/extended_gcd.hpp
---

## 概要

拡張ユークリッドの互除法。`a*x + b*y == g` を満たす `x`, `y` を参照引数に書き込み、`g` を返す。

```cpp
T g = ext_gcd(a, b, x, y);
```

`T` は整数型を想定し、剰余・除算・乗算・減算を使う。計算量は $O(\log \max(|a|, |b|))$。負数を渡した場合、返り値の符号は非負に正規化されない。
