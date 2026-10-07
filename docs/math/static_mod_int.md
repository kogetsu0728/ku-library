---
title: Static Mod Int
documentation_of: ../../math/static_mod_int.hpp
---

## 概要

コンパイル時に決めた法 `M` で整数演算を行う。

```cpp
using Mint = StaticModInt<998244353>;
Mint x(value);
```

### `mod()` / `val()`

法 / 正規化された値

### `raw(v)`

正規化せず値を作る。`0 <= v < M` が必要

### `+`, `-`, `*`, `/` と各複合代入

四則演算

### `==`, `!=`

値の比較

### `pow(y)`

`y` 乗

### `inv()`

逆元

`2 < M <= INT_MAX / 2` が必要。`pow` の指数は非負。`pow` は $O(\log y)$、`inv` と除算は $O(\log M)$、他は $O(1)$。`inv()` は `x^(M-2)` を使うため、**法が素数で、値が 0 でない**場合に逆元になる。除算も同じ条件が必要。
