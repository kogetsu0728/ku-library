---
title: Prime Sieve
documentation_of: ../../math/prime_sieve.hpp
---

## 概要
`n` 以下の素数と最小素因数を前計算し、素数判定・素因数分解・約数列挙を行う。

```cpp
PrimeSieve sieve(n);
```

| メソッド | 内容 |
| --- | --- |
| `is_prime(x)` | `x` が素数か |
| `get_primes()` | `n` 以下の素数を昇順で保持する参照 |
| `get_prime_factors(x)` | `(素因数, 指数)` の列 |
| `get_divisors(x)` | 正の約数を昇順で返す |

`n >= 0` とし、`is_prime` には `0 <= x <= n`、素因数分解・約数列挙には `1 <= x <= n` を渡す。構築は $O(n\log\log n)$ 程度、素数判定は $O(1)$、素因数分解は $O(\log x)$、約数列挙は生成する約数の個数を `d` として $O(d\log d + \log x)$。
