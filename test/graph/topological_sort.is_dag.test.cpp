#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_A"

#include "../../graph/topological_sort.hpp"
#include "../../template/template.hpp"

int main() {
    int N, M;
    cin >> N >> M;

    TopologicalSort ts(N);
    rep(i, 0, M) {
        int u, v;
        cin >> u >> v;

        ts.add_edge(u, v);
    }

    ts.build();

    cout << (ts.is_dag() ? 0 : 1) << LF;

    return 0;
}
