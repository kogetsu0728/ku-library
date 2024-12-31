#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/rollback_union_find.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> g(Q + 1);
    vector<int> t(Q), k(Q), u(Q), v(Q);
    for (int i = 0; i < Q; i++) {
        cin >> t[i] >> k[i] >> u[i] >> v[i];
        g[k[i] + 1].push_back(i + 1);
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
        for (int nxt : g[now + 1]) {
            self(self, nxt);
        }
        if (now != -1 && t[now] == 0) {
            uf.undo();
        }
    };

    dfs(dfs, 0);

    for (int i = 0; i < Q; i++) {
        if (t[i] == 1) {
            cout << (ans[i] ? 1 : 0) << endl;
        }
    }
}
