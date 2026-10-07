---
title: Rollback Union Find
documentation_of: ../../data_structure/rollback_union_find.hpp
---

## 概要

直前の `merge` を取り消せる Union Find。頂点は `0` から `n-1`。経路圧縮を行わず、集合サイズによって併合する。

## コンストラクタと操作

```cpp
RollbackUnionFind uf(n);
```

### `size()`

連結成分数

計算量: $O(1)$

### `size(x)`

`x` を含む成分の頂点数

計算量: $O(\log n)$

### `leader(x)` / `same(x, y)`

代表元 / 同じ成分か

計算量: $O(\log n)$

### `merge(x, y)`

併合。新たに併合した場合 `true`

計算量: $O(\log n)$

### `undo()`

直前の `merge` 1回を取り消す。履歴がなければ `false`

計算量: $O(1)$

### `snapshot()`

現在までの取り消し履歴を破棄

計算量: 履歴数に比例

### `rollback()`

最後の `snapshot` 以降の `merge` をすべて取り消す

計算量: 履歴数に比例

### `groups()`

成分ごとの頂点一覧

計算量: $O(n\log n)$

同じ成分に対する `merge` も履歴に残り、`undo` の対象になる。`snapshot()` は状態を変更せず、取り消せる範囲だけを更新する。
