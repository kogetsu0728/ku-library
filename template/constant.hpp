#pragma once

#include "include.hpp"
#include "type_alias.hpp"

  template <class T> constexpr T INF = numeric_limits<T>::max() / 2;
constexpr array<int, 4> DY4 = {0, -1, 0, 1};
constexpr array<int, 4> DX4 = {1, 0, -1, 0};
constexpr array<int, 8> DY8 = {0, -1, -1, -1, 0, 1, 1, 1};
constexpr array<int, 8> DX8 = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr char LF = '\n';
constexpr ld PI = acos(-1);
