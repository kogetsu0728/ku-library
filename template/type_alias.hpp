#pragma once

#include "template/include.hpp"

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T, bool R = false>
using heap = priority_queue<T, vector<T>, conditional_t<R, greater<T>, less<T>>>;
