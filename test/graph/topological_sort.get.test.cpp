#define PROBLEM "https://yukicoder.me/problems/no/468"

#include "../../graph/topological_sort.hpp"
#include "../../template/template.hpp"

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> g(N);
    TopologicalSort ts(N);
    TopologicalSort ts_inv(N);

    rep(i, 0, M) {
        int u, v, w;
        cin >> u >> v >> w;

        g[u].emplace_back(v, w);
        ts.add_edge(u, v);
        ts_inv.add_edge(v, u);
    }

    ts.build();
    ts_inv.build();

    assert(ts.is_dag());
    assert(ts_inv.is_dag());

    vector<int> dp(N, 0);
    vector<int> ep(N, INF<int>);
    ep[0] = 0;

    rep(i, 0, N) {
        int v = ts.get(i);
        for (auto [nv, co] : g[v]) {
            dp[nv] = max(dp[nv], dp[v] + co);
        }
    }

    ep[N - 1] = dp[N - 1];

    rep(i, 0, N) {
        int v = ts_inv.get(i);
        for (auto [nv, co] : g[v]) {
            ep[v] = min(ep[v], ep[nv] - co);
        }
    }

    int cnt = N;
    rep(i, 0, N) {
        if (dp[i] == ep[i]) {
            cnt--;
        }
    }

    cout << dp[N - 1] << ' ' << cnt << '/' << N << LF;

    return 0;
}
