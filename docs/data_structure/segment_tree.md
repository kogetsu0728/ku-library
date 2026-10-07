---
title: Segment Tree
documentation_of: ../../data_structure/segment_tree.hpp
---

## 概要
点更新と区間集約を行う。添字は 0 始まり、区間は `[l, r)`。`S` と関数 `op`、`e` は結合則と単位元を満たすモノイドを定義する。順序を保って集約するため、`op` は可換でなくてもよい。

## コンストラクタ
```cpp
SegmentTree<S, op, e> seg(n);
SegmentTree<S, op, e> seg(values);
```
単位元で埋めた長さ `n` の列、または `values` から構築する。計算量は $O(n)$。

## 操作
| メソッド | 内容 | 計算量 |
| --- | --- | --- |
| `get(i)` | `i` 番目の値 | $O(1)$ |
| `set(i, x)` | `i` 番目を `x` にする | $O(\log n)$ |
| `prod(l, r)` | `[l, r)` の集約値。空区間なら `e()` | $O(\log n)$ |

`0 <= i < n`、`0 <= l <= r <= n` を前提とする。
