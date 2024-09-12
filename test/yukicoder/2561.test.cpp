#define PROBLEM "https://yukicoder.me/problems/no/2561"

#include <bits/stdc++.h>
using namespace std;

#include "../../other/next_combination.hpp"

int main() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> id(N);
    iota(id.begin(), id.end(), 0);

    int ans = 0;
    do {
        long long s1 = 0, s2 = 0;
        for (int i = 0; i < K; i++) {
            s1 = (s1 + A[id[i]]) % 998;
            s2 = (s2 + A[id[i]]) % 998244353;
        }

        if (s2 <= s1) {
            ans = (ans + 1) % 998;
        }
    } while (next_combination(id.begin(), id.end(), K));

    cout << ans << endl;

    return 0;
}
