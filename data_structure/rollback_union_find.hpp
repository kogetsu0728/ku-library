#pragma once

#include "../template/template.hpp"

/**
 * @brief Rollback Union Find (Rollback付きUnion Find)
 */
class RollbackUnionFind {
  private:
    int n, comp;
    vector<int> par;
    stack<pair<int, int>> his;

  public:
    RollbackUnionFind() : RollbackUnionFind(0) {}
    RollbackUnionFind(int _n) : n(_n), comp(_n), par(_n, -1), his() {}

    int size() const { return comp; }
    int size(int x) const { return -par[leader(x)]; }

    int leader(int x) const {
        if (par[x] < 0) {
            return x;
        }

        return leader(par[x]);
    }

    bool same(int x, int y) const { return leader(x) == leader(y); }

    bool merge(int x, int y) {
        x = leader(x);
        y = leader(y);

        his.emplace(x, par[x]);
        his.emplace(y, par[y]);

        if (x == y) {
            return false;
        }

        if (size(x) < size(y)) {
            swap(x, y);
        }

        comp--;
        par[x] += par[y];
        par[y] = x;

        return true;
    }

    bool undo() {
        if (his.empty()) {
            return false;
        }

        vector<int> x(2);
        rep (i, 0, 2) {
            auto [v, p] = his.top();
            his.pop();

            x[i] = v;
            par[v] = p;
        }

        if (x[0] != x[1]) {
            comp++;
        }

        return true;
    }

    void snapshot() {
        while (!his.empty()) {
            his.pop();
        }

        return;
    }

    void rollback() {
        while (undo())
            ;

        return;
    }

    vector<vector<int>> groups() const {
        vector<vector<int>> mem(n);
        vector<vector<int>> res;

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
};
