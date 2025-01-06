#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../tree/heavy_light_decomposition.hpp"
#include "../../data_structure/segment_tree.hpp"
#include "../../template/template.hpp"

ll op(ll a, ll b) { return a + b; }

ll e() { return 0LL; }

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    rep(i, 0, N) { cin >> A[i]; }

    HeavyLightDecomposition hld(N);
    rep(i, 1, N) {
        int p;
        cin >> p;
        hld.add_edge(i, p);
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
            int i;
            cin >> i;

            ll ans = 0;
            hld.subtree_query(i, [&](int l, int r) -> void {
                ans += seg.prod(l, r);
                return;
            });

            cout << ans << LF;
        }
    }

    return 0;
}
