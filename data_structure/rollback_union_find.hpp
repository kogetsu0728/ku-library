#pragma once

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
    RollbackUnionFind(const int _n) : n(_n), comp(_n), par(_n, -1), his() {}

    int size(int x) const { return -par[leader(x)]; }

    int component() const { return comp; }

    int leader(int x) const {
        if (par[x] < 0) return x;
        return leader(par[x]);
    }

    bool same(int x, int y) const { return leader(x) == leader(y); }

    bool merge(int x, int y) {
        x = leader(x), y = leader(y);
        his.push(make_pair(x, par[x]));
        his.push(make_pair(y, par[y]));
        if (x == y) return false;
        comp--;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    bool undo() {
        if (his.empty()) return false;
        vector<int> x(2);
        for (int i = 0; i < 2; i++) {
            auto [v, p] = his.top();
            his.pop();
            x[i] = v;
            par[v] = p;
        }
        if (x[0] != x[1]) comp++;
        return true;
    }

    void snapshot() {
        while (!his.empty()) his.pop();
    }

    void rollback() {
        while (!his.empty()) undo();
    }

    vector<vector<int>> groups() const {
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
