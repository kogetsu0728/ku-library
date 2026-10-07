---
title: Union Find
documentation_of: ../../data_structure/union_find.hpp
---

## 概要

集合ごとに集約値を持てる Union Find。頂点は `0` から `n-1`。デフォルトの `S` は `bool`、`op` は XOR、`e` は `false`。独自の値を使う場合、`op` は結合的かつ可換、`e` は単位元とする。併合時は集合サイズによって根を入れ替えるため、`op` に渡す値の順序は `merge(x, y)` の引数順と一致するとは限らない。

## コンストラクタと操作

```cpp
UnionFind<> uf(n);
UnionFind<S, op, e> uf_with_values(n);
```

### `size()`

連結成分数

### `size(x)`

`x` を含む成分の頂点数

### `leader(x)` / `same(x, y)`

代表元 / 同じ成分か

### `merge(x, y)`

成分を併合。新たに併合した場合 `true`。値は `op` でまとめる

### `set(x, v)` / `get(x)`

`x` の成分の集約値を直接設定 / 取得

### `groups()`

成分ごとの頂点一覧

`set` は成分値全体を上書きし、頂点単位の値を保持しない。`groups()` は $O(n\alpha(n))$、その他の集合操作は償却 $O(\alpha(n))$、`size()` は $O(1)$。
