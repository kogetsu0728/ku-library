#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../tree/heavy_light_decomposition.hpp"
#include "../../template/template.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    HeavyLightDecomposition hld(N);
    rep(i, 1, N) {
        int p;
        cin >> p;

        hld.add_edge(i, p);
    }

    hld.build();

    while (Q--) {
        int u, v;
        cin >> u >> v;

        cout << hld.lca(u, v) << LF;
    }

    return 0;
}
