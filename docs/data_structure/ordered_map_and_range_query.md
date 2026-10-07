---
title: Ordered Map and Range Query
documentation_of: ../../data_structure/ordered_map_and_range_query.hpp
---

## 概要
キー順に並ぶ連想配列に対し、順位による区間集約と遅延更新を行う。内部では乱択平衡木を使う。`compare(a, b)` はキーの厳密弱順序を表す。各キーは1件だけ保持し、同じキーを `insert` すると値を置き換える。

`S` と `op`・`e` は集約用モノイド、`F` と `mapping`・`composition`・`id` は遅延更新を定義する。`composition(f, g)` は既存の `g` の後に `f` を適用する結果とし、`mapping` は区間全体の集約値にも正しく作用する必要がある。`F` には `!=` による `id()` との比較も必要。

## 型と操作
```cpp
OrderedMapAndRangeQuery<K, compare, S, op, e, F, mapping, composition, id> mp;
```

| メソッド | 内容 |
| --- | --- |
| `size()` | 要素数 |
| `lower_bound(k)` / `upper_bound(k)` | `k` 以上 / `k` より大きい最初の要素の順位 |
| `count(k)` | キー `k` の有無 |
| `get(i)` | 順位 `i` の `(key, value)` |
| `insert(k, v)` / `erase(k)` | 挿入または置換 / 削除 |
| `prod(a, b)` | 順位 `[a, b)` の集約値 |
| `apply(a, b, f)` | 順位 `[a, b)` に `f` を適用 |

各操作は期待 $O(\log n)$。`get` は `0 <= i < size()`、区間操作は `0 <= a <= b <= size()` を前提とする。`get` が返す順位はキーそのものではない。
