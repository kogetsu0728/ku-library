#pragma once

#include "include.hpp"

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

using ld = long double;

template <class T, bool REVERSE = false>
using heap = priority_queue<T, vector<T>, conditional_t<REVERSE, greater<T>, less<T>>>;
