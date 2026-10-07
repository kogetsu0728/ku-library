---
title: Merge Sort Tree
documentation_of: ../../data_structure/merge_sort_tree.hpp
---

## 概要
静的な列について、区間内の `a` 以下の要素数と総和を求める。添字は 0 始まり、区間は `[l, r)`。`T` には大小比較、加算、`T(0)` が必要。

## コンストラクタ
```cpp
MergeSortTree<T> mst(values, inf);
```
`values` から構築する。`inf` は内部で 2 のべき乗長に補う要素の値。構築の時間・空間計算量は $O(n\log n)$。

## 操作
| メソッド | 内容 | 計算量 |
| --- | --- | --- |
| `count(l, r, a)` | `[l, r)` 内の `a` 以下の個数 | $O(\log^2 n)$ |
| `sum(l, r, a)` | `[l, r)` 内の `a` 以下の値の総和 | $O(\log^2 n)$ |

`0 <= l <= r <= values.size()` が必要。更新はできない。
