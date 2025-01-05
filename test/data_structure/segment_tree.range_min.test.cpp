#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../data_structure/segment_tree.hpp"
#include "../../template/template.hpp"

ll op(ll a, ll b) { return min(a, b); }
ll e() { return INF<ll>; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    rep(i, 0, N) { cin >> A[i]; }

    SegmentTree<ll, op, e> seg(A);
    while (Q--) {
        int l, r;
        cin >> l >> r;

        cout << seg.prod(l, r) << LF;
    }

    return 0;
}
