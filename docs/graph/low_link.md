---
title: Low Link
documentation_of: ../../graph/low_link.hpp
---

## 概要

無向グラフの関節点と橋を求める。頂点は `0` から `n-1`。連結成分ごとに深さ優先探索を行う。

## 操作

```cpp
LowLink graph(n);
graph.add_edge(u, v);
graph.build();
```

### `component()`

元のグラフの連結成分数

### `get_art(v)`

関節点判定に使う値。根では DFS 子の数から1を引いた値、根以外では分離される DFS 子の数

### `is_art(v)`

`v` が関節点なら `true`

### `is_bridge(u, v)`

辺 `(u, v)` が橋なら `true`

辺の追加は `build()` より前、問い合わせは `build()` より後に行う。構築は $O(n+m\log m)$、関節点の問い合わせは $O(1)$、橋の問い合わせは $O(\log m)$。

親頂点を番号だけで判定しているため、**同じ2頂点間に複数の辺があるグラフでは橋判定が正しくない場合がある**。自己ループも通常の単純無向グラフの前提から外れる。
