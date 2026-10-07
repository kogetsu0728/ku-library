---
title: Weighted Union Find
documentation_of: ../../data_structure/weighted_union_find.hpp
---

## 概要
頂点間の差分制約を管理する Union Find。`T` には零元、加算、減算、単項マイナスが必要。頂点は `0` から `n-1`。

## コンストラクタと操作
```cpp
WeightedUnionFind<T> uf(n);
WeightedUnionFind<T> uf(n, zero);
```
第2引数は根の重みの初期値で、通常は `T(0)` を使う。

| メソッド | 内容 |
| --- | --- |
| `size()` / `size(x)` | 連結成分数 / `x` の成分の頂点数 |
| `leader(x)` / `same(x, y)` | 代表元 / 同じ成分か |
| `weight(x)` | 根から `x` までの重み |
| `merge(x, y, w)` | `weight(y) - weight(x) == w` となるよう併合。別成分なら `true` |
| `diff(x, y)` | `weight(y) - weight(x)` |
| `groups()` | 成分ごとの頂点一覧 |

`diff` は同じ成分の頂点にのみ使える。既に同じ成分なら `merge` は `false` を返し、指定した差分との整合性は検査しない。`groups()` は $O(n\alpha(n))$、その他の集合操作は償却 $O(\alpha(n))$。
