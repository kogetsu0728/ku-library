#pragma once

#include <bits/stdc++.h>
using namespace std;

using uint = unsigned;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;

constexpr int INF32 = INT_MAX / 2;
constexpr ll INF64 = 1LL << 60;
constexpr array<int, 8> DX = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr array<int, 8> DY = {-1, 0, 1, 0, -1, 1, 1, -1};
constexpr char LF = '\n';
const ld PI = acos(-1);

#define rep(i, a, b) for (ll i = (ll)(a); (i) < (ll)(b); (i)++)
#define rrep(i, a, b) for (ll i = (ll)(a); (i) >= (ll)(b); (i)--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template <class T> bool chmin(T& a, const T& b) {
    return (a > b) ? (a = b, true) : false;
}
template <class T> bool chmax(T& a, const T& b) {
    return (a < b) ? (a = b, true) : false;
}
