---
title: Set IO
documentation_of: ../../utility/set_io.hpp
---

## 概要
標準入出力の設定を行う。

```cpp
set_io();   // 小数点以下16桁
set_io(d);  // 小数点以下d桁
```

`cin.tie(nullptr)`、`ios_base::sync_with_stdio(false)`、`cout << fixed << setprecision(d)` を設定する。C の標準入出力との混用や、`cin` と `cout` の自動フラッシュに依存する対話処理では設定の影響に注意する。
