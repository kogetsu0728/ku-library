#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/ordered_map_and_range_query.hpp"

using ll = long long;
constexpr ll INF32 = (1LL << 31) - 1;
constexpr ll INF64 = 1LL << 60;

using K = ll;
bool compare(K a, K b) { return a < b; }

using S = ll;
S op(S a, S b) { return min(a, b); }
S e() { return INF32; }

using F = ll;
constexpr F ID = INF64;
S mapping(F f, S a) {
    if (f == ID) return a;
    return f;
}
F composition(F f, F g) {
    if (f == ID) return g;
    return f;
}
F id() { return ID; }

int main() {
    int N, Q;
    cin >> N >> Q;

    OrderedMapAndRangeQuery<K, compare, S, op, e, F, mapping, composition, id>
        rbst;
    rbst.insert(-INF64, e());
    rbst.insert(INF64, e());

    for (; Q--;) {
        int t;
        cin >> t;
        if (t == 0) {
            ll l, r, x;
            cin >> l >> r >> x;
            r++;
            if (!rbst.count(l)) {
                rbst.insert(l, rbst.get(rbst.lower_bound(l) - 1).second);
            }
            if (!rbst.count(r)) {
                rbst.insert(r, rbst.get(rbst.lower_bound(r) - 1).second);
            }
            rbst.apply(rbst.lower_bound(l), rbst.lower_bound(r), x);
        } else {
            ll l, r;
            cin >> l >> r;
            r++;
            cout << rbst.prod(rbst.upper_bound(l) - 1, rbst.lower_bound(r))
                 << endl;
        }
    }
}
