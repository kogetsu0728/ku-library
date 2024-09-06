#ifdef ATCODER
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#else
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
template <class T>
using graph = vector<vector<T>>;
template <class T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, s, n) for (ll i = (ll)(s); i < (ll)(n); i++)
#define rrep(i, s, n) for (ll i = (ll)(s); i >= (ll)(n); i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
constexpr int INF32 = INT_MAX / 2;
constexpr ll INF64 = 1LL << 60;
constexpr ld PI = 3.14159265358979323846;
constexpr array<int, 4> DX4 = {0, 1, 0, -1}, DY4 = {-1, 0, 1, 0};
constexpr array<int, 8> DX8 = {0, 1, 1, 1, 0, -1, -1, -1},
                        DY8 = {-1, -1, 0, 1, 1, 1, 0, -1};
template <class T>
inline bool chmax(T& a, const T& b) {
  return a < b ? a = b, true : false;
}
template <class T>
inline bool chmin(T& a, const T& b) {
  return b < a ? a = b, true : false;
}
struct SETUP {
  SETUP() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(16);
  }
} SETUP;
