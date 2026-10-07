---
title: Topological Sort
documentation_of: ../../graph/topological_sort.hpp
---

## 概要
有向グラフのトポロジカル順序を求め、閉路の有無を判定する。頂点は `0` から `n-1`。

## 操作
```cpp
TopologicalSort graph(n);
graph.add_edge(u, v);  // u -> v
graph.build();
```

| メソッド | 内容 |
| --- | --- |
| `is_dag()` | 有向非巡回グラフなら `true` |
| `get(i)` | トポロジカル順序の `i` 番目の頂点 |

`add_edge` は `build()` の前、問い合わせはその後に行う。`get(i)` は `is_dag()` が `true` かつ `0 <= i < n` の場合に使える。順序は一意とは限らない。構築は $O(n+m)$、各問い合わせは $O(1)$。
