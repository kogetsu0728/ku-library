#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include <bits/stdc++.h>
using namespace std;

#include "../../tree/heavy_light_decomposition.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    HeavyLightDecomposition hld(N);
    for (int i = 1; i < N; i++) {
        int p;
        cin >> p;
        hld.add_edge(i, p);
    }

    hld.build();

    for (; Q--;) {
        int u, v;
        cin >> u >> v;
        cout << hld.lca(u, v) << endl;
    }
}
