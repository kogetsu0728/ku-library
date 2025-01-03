#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/weighted_union_find.hpp"

int main() {
    int N, Q;
    cin >> N >> Q;
    WeightedUnionFind<int> uf(N);
    for (; Q--;) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0) {
            int z;
            cin >> z;
            uf.merge(x, y, z);
        } else {
            if (uf.same(x, y)) {
                cout << uf.diff(x, y) << endl;
            } else {
                cout << '?' << endl;
            }
        }
    }
}
