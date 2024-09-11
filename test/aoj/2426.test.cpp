#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/merge_sort_tree.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<long long, long long>> pos(N);
    for (int i = 0; i < N; i++) {
        long long x, y;
        cin >> x >> y;
        pos[i] = make_pair(x, y);
    }

    sort(pos.begin(), pos.end());

    vector<long long> xv(N), yv(N);
    for (int i = 0; i < N; i++) {
        auto [x, y] = pos[i];

        xv[i] = x;
        yv[i] = y;
    }

    MergeSortTree<long long> mst(yv, LLONG_MAX);
    for (; M--;) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int l = lower_bound(xv.begin(), xv.end(), x1) - xv.begin();
        int r = upper_bound(xv.begin(), xv.end(), x2) - xv.begin();

        int ans = mst.count(l, r, y2) - mst.count(l, r, y1 - 1);
        cout << ans << '\n';
    }

    return 0;
}
