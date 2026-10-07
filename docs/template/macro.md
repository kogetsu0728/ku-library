---
title: Macros
documentation_of: ../../template/macro.hpp
---

## 概要

提出用の範囲・ループマクロとローカル判定を定義する。ループ変数の型は `ll`。

### `rep(i, a)`

`i = 0, ..., a-1`

### `rep(i, a, b)`

`i = a, ..., b-1`

### `rep(i, a, b, c)`

`a` から `b` 未満まで `c` ずつ増加

### `rrep(i, a)`

`i = a, ..., 0`

### `rrep(i, a, b)`

`i = a, ..., b`

### `rrep(i, a, b, c)`

`a` から `b` 以上まで `c` ずつ減少

`rep` の刻み幅には正数、`rrep` の刻み幅にも正数を渡す。境界と刻み幅は各反復で評価される。

`all(a)` は `begin(a), end(a)`、`rall(a)` は `rbegin(a), rend(a)` に展開される。`LOCAL` が定義されていると `IS_LOCAL` は `true` となり、`IF_LOCAL` は `if constexpr (IS_LOCAL)` に展開される。
