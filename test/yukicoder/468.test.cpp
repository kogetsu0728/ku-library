#define PROBLEM "https://yukicoder.me/problems/no/468"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/topological_sort.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<pair<int, int>>> g(N);
    TopologicalSort tp(N), tp_inv(N);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        tp.add_edge(u, v);
        tp_inv.add_edge(v, u);
    }

    tp.build();
    tp_inv.build();

    vector<int> dp(N, 0), ep(N, 1 << 30);
    dp[0] = ep[0] = 0;

    for (int i = 0; i < N; i++) {
        int v = tp[i];
        for (auto [nv, co] : g[v]) {
            dp[nv] = max(dp[nv], dp[v] + co);
        }
    }

    ep[N - 1] = dp[N - 1];

    for (int i = 0; i < N; i++) {
        int v = tp_inv[i];
        for (auto [nv, co] : g[v]) {
            ep[v] = min(ep[v], ep[nv] - co);
        }
    }

    int cnt = N;
    for (int i = 0; i < N; i++) {
        if (dp[i] == ep[i]) {
            cnt--;
        }
    }

    cout << dp[N - 1] << ' ' << cnt << '/' << N << endl;
}
