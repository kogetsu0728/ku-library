---
title: Type Aliases
documentation_of: ../../template/type_alias.hpp
---

## 概要
整数・浮動小数点型と優先度付きキューの別名を定義する。

| 名前 | 型 |
| --- | --- |
| `uint` | `unsigned int` |
| `ll` | `long long` |
| `ull` | `unsigned long long` |
| `ld` | `long double` |
| `heap<T>` | 最大値を先頭に取り出す `priority_queue` |
| `heap<T, true>` | 最小値を先頭に取り出す `priority_queue` |

`heap<T, true>` は `greater<T>`、通常の `heap<T>` は `less<T>` を比較に使う。
