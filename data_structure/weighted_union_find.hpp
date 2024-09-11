#pragma once

/**
 * @brief Weighted Union Find (重み付きUnion Find)
 */
template <class T> class WeightedUnionFind {
  private:
    int n, comp;
    vector<int> par, rank;
    vector<T> wei;

  public:
    WeightedUnionFind(const int _n = 0, const T _e = 0)
        : n(_n), comp(_n), par(_n, -1), rank(_n), wei(n, _e) {}

    int component() const { return comp; }

    int size(int x) { return -par[leader(x)]; }

    int leader(int x) {
        if (par[x] < 0) return x;
        int rx = leader(par[x]);
        wei[x] += wei[par[x]];
        return par[x] = rx;
    }

    T weight(int x) {
        leader(x);
        return wei[x];
    }

    bool same(int x, int y) { return leader(x) == leader(y); }

    bool merge(int x, int y, T w) {
        w += weight(x) - weight(y);
        x = leader(x), y = leader(y);
        if (x == y) return false;
        comp--;
        if (rank[x] < rank[y]) {
            swap(x, y);
            w = -w;
        }
        if (rank[x] == rank[y]) rank[x]++;
        par[x] += par[y];
        par[y] = x;
        wei[y] = w;
        return true;
    }

    T diff(int x, int y) {
        assert(same(x, y));
        return weight(y) - weight(x);
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
