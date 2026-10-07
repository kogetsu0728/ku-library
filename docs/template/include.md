---
title: Common Includes
documentation_of: ../../template/include.hpp
---

## 概要

`<bits/stdc++.h>` を読み込み、`using namespace std;` を宣言する。GNU C++ の環境を前提とする。

`LOCAL` が定義されている場合は、読み込み前に `_GLIBCXX_DEBUG` を定義する。ローカル検証時には GNU libstdc++ のデバッグモードを利用できる。
