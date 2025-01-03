#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../data_structure/fenwick_tree.hpp"
#include "../../template/template.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<ll> A(N);
    rep(i, 0, N) { cin >> A[i]; }

    FenwickTree<ll> fw1(N);
    FenwickTree<ll> fw2(N);
    FenwickTree<ll> fw3(A);
    rep(i, 0, N) {
        fw1.add(i, A[i]);
        fw2.set(i, A[i]);
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;

        assert(fw1.sum(l, r) == fw2.sum(l, r));
        assert(fw2.sum(l, r) == fw3.sum(l, r));

        cout << fw1.sum(l, r) << LF;
    }

    return 0;
}
