#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../data_structure/rollback_union_find.hpp"
#include "../../template/template.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<vector<int>> g(Q + 1);
    vector<int> t(Q), k(Q), u(Q), v(Q);
    rep (i, 0, Q) {
        cin >> t[i] >> k[i] >> u[i] >> v[i];
        g[k[i] + 1].emplace_back(i + 1);
    }

    RollbackUnionFind uf(N);
    vector<bool> ans(Q);

    auto dfs = [&](auto& self, int now) -> void {
        now--;

        if (now != -1) {
            if (t[now] == 0) {
                uf.merge(u[now], v[now]);
            } else {
                ans[now] = uf.same(u[now], v[now]);
            }
        }

        for (int nex : g[now + 1]) {
            self(self, nex);
        }

        if (now != -1 && t[now] == 0) {
            uf.undo();
        }

        return;
    };

    dfs(dfs, 0);

    rep (i, 0, Q) {
        if (t[i] == 1) {
            cout << (ans[i] ? 1 : 0) << LF;
        }
    }

    return 0;
}
