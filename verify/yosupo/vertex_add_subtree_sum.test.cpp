#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <bits/stdc++.h>
using namespace std;

#include "../../data_structure/segment_tree.hpp"
#include "../../tree/heavy_light_decomposition.hpp"

long long op(long long a, long long b) { return a + b; }

long long e() { return 0LL; }

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  HeavyLightDecomposition hld(N);
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p;
    hld.add_edge(i, p);
  }

  hld.build();

  SegmentTree<long long, op, e> seg(N);
  for (int i = 0; i < N; i++) {
    hld.node_query(i, [&](int j) -> void {
      seg.set(j, A[i]);
      return;
    });
  }

  for (; Q--;) {
    int t;
    cin >> t;
    if (t == 0) {
      int i;
      cin >> i;
      long long x;
      cin >> x;
      hld.node_query(i, [&](int j) -> void {
        seg.set(j, seg.get(j) + x);
        return;
      });
    } else {
      int i;
      cin >> i;
      long long ans{};
      hld.subtree_query(i, [&](int l, int r) -> void {
        ans += seg.prod(l, r);
        return;
      });
      cout << ans << endl;
    }
  }
}
