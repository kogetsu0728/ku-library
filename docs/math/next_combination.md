---
title: Next Combination
documentation_of: ../../math/next_combination.hpp
---

## 概要
範囲 `[begin, end)` の先頭 `k` 要素で表す組合せを、辞書順で次の組合せに進める。範囲全体の要素を並べ替える。

```cpp
bool advanced = next_combination(begin, end, k);
```

次がある場合は `true`。最後まで進んだ場合は `false` を返し、範囲を先頭の組合せに戻す。`k == 0` または `k == n` なら `false`。`0 <= k <= n`、双方向に移動できる反復子、比較可能な要素を前提とする。1回の計算量は $O(n)$。使用前に範囲を昇順に並べると先頭の組合せから列挙できる。
