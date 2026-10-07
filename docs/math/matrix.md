---
title: Matrix
documentation_of: ../../math/matrix.hpp
---

## 概要
行列の積と非負整数乗を扱う。`T` には零元 `T{}`、単位元 `T(1)`、加算、乗算が必要。

## コンストラクタと操作
```cpp
Matrix<T> a(rows, cols);
Matrix<T> square(size);
auto identity = Matrix<T>::identity(size);
```
初期値はすべて `T{}`。正方行列用の1引数コンストラクタと、0行0列のデフォルトコンストラクタもある。

| メソッド・演算子 | 内容 |
| --- | --- |
| `row()` / `col()` | 行数 / 列数 |
| `get(i, j)` / `set(i, j, v)` | 要素の取得 / 設定 |
| `a * b`, `a *= b` | 行列積 |
| `a == b`, `a != b` | 行列の比較 |
| `a.pow(y)` | 正方行列の `y` 乗 |

積には `a.col() == b.row()`、累乗には正方行列かつ `y >= 0` が必要。`h×k` と `k×w` の積は $O(hkw)$、`n×n` 行列の累乗は $O(n^3\log y)$。
