---
title: Fenwick Tree
documentation_of: ../../data_structure/fenwick_tree.hpp
---

## 概要

配列の1点更新と区間和を扱う。添字は 0 始まりで、区間は半開区間 `[l, r)`。`T` には `T(0)`、加算、減算が必要。

## コンストラクタ

```cpp
FenwickTree<T> fw(n);
FenwickTree<T> fw(values);
```

長さ `n` の零列、または `values` から構築する。

制約: `n >= 0`。

計算量: 長さを指定する場合は $O(n)$、配列から構築する場合は $O(n\log n)$。

## add

```cpp
void add(int i, const T& x);
```

`i` 番目の値に `x` を加える。

制約: `0 <= i < n`。

計算量: $O(\log n)$。

## set

```cpp
void set(int i, const T& x);
```

`i` 番目の値を `x` にする。

制約: `0 <= i < n`。

計算量: $O(\log n)$。

## get

```cpp
T get(int i) const;
```

`i` 番目の値を返す。

制約: `0 <= i < n`。

計算量: $O(\log n)$。

## sum

```cpp
T sum(int l, int r) const;
```

`[l, r)` の和を返す。空区間なら `T(0)`。

制約: `0 <= l <= r <= n`。

計算量: $O(\log n)$。

## 使用例

```cpp
FenwickTree<long long> fw(4);
fw.add(1, 3);
fw.set(2, 5);
long long total = fw.sum(1, 3);  // 8
```
