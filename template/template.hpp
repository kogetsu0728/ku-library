#pragma once

#include <bits/stdc++.h>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T, bool R = false>
using heap = priority_queue<T, vector<T>, conditional_t<R, greater<T>, less<T>>>;

template <class T> constexpr T INF = numeric_limits<T>::max() / 2;
constexpr array<int, 4> DY4 = {0, -1, 0, 1};
constexpr array<int, 4> DX4 = {1, 0, -1, 0};
constexpr array<int, 8> DY8 = {0, -1, -1, -1, 0, 1, 1, 1};
constexpr array<int, 8> DX8 = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr char LF = '\n';
constexpr ld PI = acos(-1);

#ifdef ONLINE_JUDGE
constexpr bool IS_LOCAL = false;
#else
constexpr bool IS_LOCAL = true;
#endif

#define IF_LOCAL if constexpr (IS_LOCAL)

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define overload4(a, b, c, d, e, ...) e

#define rep1(i, a, b) for (ll i = (ll)(a); (i) < (ll)(b); ++(i))
#define rep2(i, a, b, c) for (ll i = (ll)(a); (i) < (ll)(b); (i) += (ll)(c))
#define rep(...) overload4(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)

#define rrep1(i, a, b) for (ll i = (ll)(a); (i) >= (ll)(b); --(i))
#define rrep2(i, a, b, c) for (ll i = (ll)(a); (i) >= (ll)(b); (i) -= (ll)(c))
#define rrep(...) overload4(__VA_ARGS__, rrep2, rrep1)(__VA_ARGS__)

#include "other/choose_min_max.hpp"
