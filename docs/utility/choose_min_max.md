---
title: Choose Minimum / Maximum
documentation_of: ../../utility/choose_min_max.hpp
---

## 概要

値を小さく・大きく更新するヘルパー。変更した場合だけ `true` を返す。

```cpp
bool changed_min = chmin(a, b);  // b < a なら a = b
bool changed_max = chmax(a, b);  // a < b なら a = b
```

`T` には比較と代入が必要。どちらも $O(1)$ 回の比較を行う。
