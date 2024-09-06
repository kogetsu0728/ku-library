#pragma once
class UnionFind {
 private:
  int n, comp;
  vector<int> par;

 public:
  UnionFind(const int _n = 0) : n(_n), comp(_n), par(_n, -1) {}

  int component() const { return comp; }

  int size(int x) { return -par[leader(x)]; }

  int leader(int x) {
    if (par[x] < 0) return x;
    return par[x] = leader(par[x]);
  }

  bool same(int x, int y) { return leader(x) == leader(y); }

  bool merge(int x, int y) {
    x = leader(x), y = leader(y);
    if (x == y) return false;
    comp--;
    if (par[x] > par[y]) swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  vector<vector<int>> groups() {
    vector<vector<int>> member(n), res;
    for (int i = 0; i < n; i++) {
      member[leader(i)].push_back(i);
    }
    for (int i = 0; i < n; i++) {
      if (!member[i].empty()) {
        res.push_back(member[i]);
      }
    }
    return res;
  }
};
