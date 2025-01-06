#pragma once

#include "../template/template.hpp"

/**
 * @brief Topological Sort (トポロジカルソート)
 * @note 参考: https://algo-logic.info/topological-sort/
 */
class TopologicalSort {
  private:
    bool init, dag;
    int n;
    vector<vector<int>> g;
    vector<int> p;

  public:
    TopologicalSort() : TopologicalSort(0) {}
    TopologicalSort(int _n) : init(false), dag(false), n(_n), g(_n), p(0) {}

    void add_edge(int u, int v) noexcept {
        assert(!init);

        g[u].emplace_back(v);
    }

    void build() noexcept {
        assert(!init);
        init = true;

        vector<int> cnt(n);
        rep (v, 0, n) {
            for (int nv : g[v]) {
                cnt[nv]++;
            }
        }

        queue<int> que;
        rep (v, 0, n) {
            if (cnt[v] == 0) {
                que.emplace(v);
            }
        }

        p.reserve(n);
        while (!que.empty()) {
            int v = que.front();
            que.pop();

            p.emplace_back(v);

            for (int nv : g[v]) {
                cnt[nv]--;

                if (cnt[nv] == 0) {
                    que.emplace(nv);
                }
            }
        }

        if (int(p.size()) == n) {
            dag = true;
        } else {
            p.clear();
        }

        return;
    }

    bool is_dag() const {
        assert(init);

        return dag;
    }

    int get(int i) const {
        assert(init);
        assert(dag);

        return p[i];
    }
};
