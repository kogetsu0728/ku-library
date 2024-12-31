#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include <vector>
using namespace std;

#include "../../data_structure/segment_tree.hpp"

long long op(long long a, long long b) { return min(a, b); }

long long e() { return 1LL << 60; }

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    SegmentTree<long long, op, e> seg(A);
    for (; Q--;) {
        int l, r;
        cin >> l >> r;
        cout << seg.prod(l, r) << endl;
    }
}
