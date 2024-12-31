#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"

// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/ordered_map_and_range_query.hpp"

using ll = long long;
constexpr ll INF64 = 1LL << 60;

using K = ll;
bool compare(K a, K b) { return a < b; }

using S = ll;
S op(S a, S b) { return min(a, b); }
S e() { return INF64; }

using F = ll;
S mapping(F f, S a) { return a + f; }
F composition(F f, F g) { return f + g; }
F id() { return 0LL; }

int main() {
    int N, Q;
    cin >> N >> Q;

    OrderedMapAndRangeQuery<K, compare, S, op, e, F, mapping, composition, id>
        rbst;
    rbst.insert(-INF64, 0LL);
    rbst.insert(INF64, 0LL);

    for (; Q--;) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r;
            cin >> l >> r;
            r++;
            ll x;
            cin >> x;
            if (!rbst.count(l)) {
                rbst.insert(l, rbst.get(rbst.lower_bound(l) - 1).second);
            }
            if (!rbst.count(r)) {
                rbst.insert(r, rbst.get(rbst.lower_bound(r) - 1).second);
            }
            rbst.apply(rbst.lower_bound(l), rbst.lower_bound(r), x);
        } else {
            int l, r;
            cin >> l >> r;
            r++;
            S ans = rbst.prod(rbst.upper_bound(l) - 1, rbst.lower_bound(r));
            if (ans == e())
                cout << 0LL << endl;
            else
                cout << ans << endl;
        }
    }
}
