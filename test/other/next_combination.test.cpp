#define PROBLEM "https://yukicoder.me/problems/no/2561"

#include "../../other/next_combination.hpp"
#include "../../template/template.hpp"

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, 0, N) { cin >> A[i]; }

    vector<int> id(N);
    iota(all(id), 0);

    int ans = 0;
    do {
        ll s1 = 0, s2 = 0;
        rep(i, 0, K) {
            s1 = (s1 + A[id[i]]) % 998;
            s2 = (s2 + A[id[i]]) % 998244353;
        }

        if (s2 <= s1) {
            ans = (ans + 1) % 998;
        }
    } while (next_combination(id.begin(), id.end(), K));

    cout << ans << LF;

    return 0;
}
