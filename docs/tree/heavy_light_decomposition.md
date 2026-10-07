---
title: Heavy Light Decomposition
documentation_of: ../../tree/heavy_light_decomposition.hpp
---

## 概要
根を頂点 `0` とする木を、頂点の位置を表す連続した添字に分解する。部分木・パス上の頂点に対応する区間を得て、セグメント木などと組み合わせる。辺は無向で追加する。

## 操作
```cpp
HeavyLightDecomposition hld(n);
hld.add_edge(u, v);
hld.build();
```

| メソッド | 内容 |
| --- | --- |
| `depth(v)` | 根からの深さ |
| `lca(u, v)` | 最小共通祖先 |
| `node_query(v, func)` | `v` の位置 `i` を `func(i)` に渡す |
| `subtree_query(v, func)` | 部分木の頂点区間 `[l, r)` を渡す |
| `path_query(u, v, func)` | 両端を含むパスを分割した各頂点区間 `[l, r)` を渡す |

`n >= 1` の連結な木を前提とし、`add_edge` は `build()` の前、その他の操作は後に使う。構築は $O(n)$、`lca` と `path_query` は $O(\log n)$ 個の鎖をたどる。`node_query`・`subtree_query` は $O(1)$ 回コールバックを呼ぶ。

`path_query` の区間はパス順に渡されるとは限らない。非可換な集約では向きを別途管理する必要がある。深さ優先探索は再帰を使う。
