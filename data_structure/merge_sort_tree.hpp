#pragma once

/**
 * @brief merge-sort tree
 */
class MergeSortTree {
  using ll = long long;

 private:
  int n;
  vector<vector<ll>> v, s;

  void update(int i) {
    v[i] = vector<ll>();
    queue<ll> a, b;
    for (ll x : v[i << 1]) {
      a.emplace(x);
    }
    for (ll x : v[(i << 1) | 1]) {
      b.emplace(x);
    }

    while (!a.empty() || !b.empty()) {
      if (b.empty() || (!a.empty() && a.front() < b.front())) {
        v[i].emplace_back(a.front());
        a.pop();
      } else {
        v[i].emplace_back(b.front());
        b.pop();
      }
    }

    s[i] = vector<ll>(v[i].size() + 1);
    for (int j = 0; j < int(v[i].size()); j++) {
      s[i][j + 1] = s[i][j] + v[i][j];
    }
  }

 public:
  MergeSortTree(vector<ll> _v) {
    n = 1;
    while (n < int(_v.size())) {
      n *= 2;
    }
    while (int(_v.size()) < n) {
      _v.emplace_back(LLONG_MAX);
    }

    v = vector(2 * n, vector<ll>({MAX_A}));
    s = vector(2 * n, vector<ll>({0LL, MAX_A}));

    for (int i = 0; i < n; i++) {
      v[n + i] = vector<ll>({_v[i]});
      s[n + i] = vector<ll>({0, _v[i]});
    }

    for (int i = n - 1; i >= 1; i--) {
      update(i);
    }
  }

  /**
   * @brief [l, r)に含まれるa以下の数の総和
   */
  ll sum(int l, int r, ll a) const {
    l += n;
    r += n;
    ll res = 0;
    while (l < r) {
      if (l & 1) {
        int t =
            distance(v[l].begin(), upper_bound(v[l].begin(), v[l].end(), a));
        res += s[l][t];
        l++;
      }
      if (r & 1) {
        r--;
        int t =
            distance(v[r].begin(), upper_bound(v[r].begin(), v[r].end(), a));
        res += s[r][t];
      }
      l >>= 1;
      r >>= 1;
    }

    return res;
  }

  /**
   * @brief [l, r)に含まれるa以下の数の個数
   */
  int count(int l, int r, ll a) const {
    l += n;
    r += n;
    int res = 0;
    while (l < r) {
      if (l & 1) {
        int t =
            distance(v[l].begin(), upper_bound(v[l].begin(), v[l].end(), a));
        res += t;
        l++;
      }
      if (r & 1) {
        r--;
        int t =
            distance(v[r].begin(), upper_bound(v[r].begin(), v[r].end(), a));
        res += t;
      }
      l >>= 1;
      r >>= 1;
    }

    return res;
  }
};
