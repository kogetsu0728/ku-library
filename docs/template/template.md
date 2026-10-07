---
title: 提出用テンプレート
documentation_of: ../../template/template.hpp
---

## 概要
競技プログラミングの提出用に、共通ヘッダーとユーティリティをまとめて読み込む。

```cpp
#include "template/template.hpp"
```

読み込むものは `constant.hpp`、`include.hpp`、`macro.hpp`、`type_alias.hpp`、`utility/choose_min_max.hpp`、`utility/set_io.hpp`。各機能の詳細はそれぞれのヘッダーのドキュメントを参照。

`include.hpp` が `<bits/stdc++.h>` を使用するため、GNU C++ を前提とする。
