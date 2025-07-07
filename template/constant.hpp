#pragma once

/**
 * @title 定数
 */

#include "include.hpp"
#include "type_alias.hpp"

template <class T> inline constexpr T INF = numeric_limits<T>::max() / 2;
inline constexpr ld PI = acos(-1);

inline constexpr array<int, 4> DY4 = {0, -1, 0, 1};
inline constexpr array<int, 4> DX4 = {1, 0, -1, 0};
inline constexpr array<int, 8> DY8 = {0, -1, -1, -1, 0, 1, 1, 1};
inline constexpr array<int, 8> DX8 = {1, 1, 0, -1, -1, -1, 0, 1};

inline constexpr char LF = '\n';
