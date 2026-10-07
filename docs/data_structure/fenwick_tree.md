---
title: Fenwick Tree
documentation_of: ../../data_structure/fenwick_tree.hpp
---

## 概要
点更新と区間和を扱う。添字は 0 始まり、区間は半開区間 `[l, r)`。`T` には `T(0)`、加算、減算が必要。

## コンストラクタ
```cpp
FenwickTree<T> fw(n);
FenwickTree<T> fw(values);
```
長さ `n` の零列、または `values` から構築する。計算量はそれぞれ $O(n)$、$O(n\log n)$。

## 操作
| メソッド | 内容 | 計算量 |
| --- | --- | --- |
| `sum(l, r)` | `[l, r)` の和 | $O(\log n)$ |
| `get(i)` | `i` 番目の値 | $O(\log n)$ |
| `add(i, x)` | `i` 番目に `x` を加える | $O(\log n)$ |
| `set(i, x)` | `i` 番目を `x` にする | $O(\log n)$ |

`0 <= l <= r <= n`、`0 <= i < n` が必要。
