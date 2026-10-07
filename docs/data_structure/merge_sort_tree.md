---
title: Merge Sort Tree
documentation_of: ../../data_structure/merge_sort_tree.hpp
---

## 概要

変更しない配列に対して、区間内の `a` 以下の値の個数と総和を求める。添字は 0 始まりで、区間は半開区間 `[l, r)`。`T` には大小比較、加算、`T(0)` が必要。

## コンストラクタ

```cpp
MergeSortTree<T> mst(values, inf);
```

`values` から構築する。`inf` は内部で長さを 2 のべき乗に補うための値。正しい範囲の問い合わせには補った位置は含まれない。

計算量: 時間・空間ともに $O(n\log n)$。ここで $n$ は `values.size()`。

## count

```cpp
int count(int l, int r, const T& a);
```

`[l, r)` にある `a` 以下の値の個数を返す。

制約: `0 <= l <= r <= n`。

計算量: $O(\log^2 n)$。

## sum

```cpp
T sum(int l, int r, const T& a);
```

`[l, r)` にある `a` 以下の値の総和を返す。

制約: `0 <= l <= r <= n`。

計算量: $O(\log^2 n)$。

## 使用例

```cpp
MergeSortTree<int> mst({4, 1, 3, 2}, 0);
int count = mst.count(1, 4, 2);  // 2
int total = mst.sum(1, 4, 2);   // 3
```
