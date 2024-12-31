#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_A"

#include <bits/stdc++.h>
using namespace std;

#include "../../graph/low_link.hpp"

int main() {
    int N, M;
    cin >> N >> M;
    LowLink lo(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        lo.add_edge(u, v);
    }

    lo.build();

    for (int i = 0; i < N; i++) {
        if (lo.is_art(i)) {
            cout << i << endl;
        }
    }
}
