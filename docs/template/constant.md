---
title: Constants
documentation_of: ../../template/constant.hpp
---

## 概要

提出用テンプレートで使う定数を定義する。

### `INF<T>`

`numeric_limits<T>::max() / 2`

### `DY4`, `DX4`

右・上・左・下の順の4方向移動量

### `DY8`, `DX8`

右から反時計回りの8方向移動量

### `LF`

改行文字 `\n`

移動先は `(y + DY4[i], x + DX4[i])`、または8方向版で求める。`INF<T>` は実際の無限大ではなく、加算時の余裕を残した番兵値である。
