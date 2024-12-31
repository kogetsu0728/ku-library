#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_B"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/low_link.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    LowLink lo(N);
    vector<pair<int, int>> edge(M);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edge[i] = make_pair(min(u, v), max(u, v));
        lo.add_edge(u, v);
    }

    lo.build();

    vector<pair<int, int>> ans;
    for (auto [u, v] : edge) {
        if (lo.is_bridge(u, v)) {
            ans.push_back(make_pair(u, v));
        }
    }

    sort(ans.begin(), ans.end());

    for (auto [u, v] : ans) {
        cout << u << ' ' << v << endl;
    }
}
