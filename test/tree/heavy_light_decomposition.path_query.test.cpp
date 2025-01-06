#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../tree/heavy_light_decomposition.hpp"
#include "../../data_structure/segment_tree.hpp"
#include "../../template/template.hpp"

ll op(ll a, ll b) { return a + b; }

ll e() { return 0LL; }

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    rep(i, 0, N) { cin >> A[i]; }

    HeavyLightDecomposition hld(N);
    rep(i, 0, N - 1) {
        int u, v;
        cin >> u >> v;

        hld.add_edge(u, v);
    }

    hld.build();

    SegmentTree<ll, op, e> seg(N);

    rep(i, 0, N) {
        hld.node_query(i, [&](int j) -> void {
            seg.set(j, A[i]);
            return;
        });
    }

    while (Q--) {
        int t;
        cin >> t;

        if (t == 0) {
            int i;
            cin >> i;

            ll x;
            cin >> x;

            hld.node_query(i, [&](int j) -> void {
                seg.set(j, seg.get(j) + x);
                return;
            });
        } else {
            int u, v;
            cin >> u >> v;

            ll ans = 0;

            hld.path_query(u, v, [&](int l, int r) -> void {
                ans += seg.prod(l, r);
                return;
            });

            cout << ans << LF;
        }
    }

    return 0;
}
