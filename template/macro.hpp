#pragma once

/**
 * @title マクロ
 * @see https://trap.jp/post/1224/
 */

#include "include.hpp"
#include "type_alias.hpp"

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)

#define overload4(a, b, c, d, e, ...) e

#define rep1(i, a) for (ll i = 0; (i) < (ll)(a); ++(i))
#define rep2(i, a, b) for (ll i = (ll)(a); (i) < (ll)(b); ++(i))
#define rep3(i, a, b, c) for (ll i = (ll)(a); (i) < (ll)(b); (i) += (ll)(c))
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep1(i, a) for (ll i = (ll)(a); (i) >= 0; --(i))
#define rrep2(i, a, b) for (ll i = (ll)(a); (i) >= (ll)(b); --(i))
#define rrep3(i, a, b, c) for (ll i = (ll)(a); (i) >= (ll)(b); (i) -= (ll)(c))
#define rrep(...) overload4(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)
