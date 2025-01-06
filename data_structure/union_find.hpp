#pragma once

#include "../template/template.hpp"

namespace _UnionFind {
using S = bool;
S op(S a, S b) { return a ^ b; }
S e() { return false; }
};  // namespace _UnionFind

/**
 * @brief Union Find
 */
template <class S = _UnionFind::S,
          S (*op)(S, S) = _UnionFind::op,
          S (*e)() = _UnionFind::e>
class UnionFind {
  private:
    int n, comp;
    vector<int> par;
    vector<S> val;

  public:
    UnionFind() : UnionFind(0) {}
    UnionFind(int _n) : n(_n), comp(_n), par(_n, -1), val(_n, e()) {}

    int size() const { return comp; }

    int size(int x) { return -par[leader(x)]; }

    int leader(int x) {
        if (par[x] < 0) return x;
        return par[x] = leader(par[x]);
    }

    bool same(int x, int y) { return leader(x) == leader(y); }

    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);
        if (x == y) return false;

        if (par[x] > par[y]) swap(x, y);

        comp--;
        par[x] += par[y];
        par[y] = x;
        val[x] = op(val[x], val[y]);

        return true;
    }

    vector<vector<int>> groups() {
        vector<vector<int>> mem(n), res;

        rep (i, 0, n) {
            mem[leader(i)].emplace_back(i);
        }

        rep (i, 0, n) {
            if (!mem[i].empty()) {
                res.emplace_back(mem[i]);
            }
        }

        return res;
    }

    void set(int x, S v) {
        val[leader(x)] = v;

        return;
    }

    S get(int x) { return val[leader(x)]; }
};
