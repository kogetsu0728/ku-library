#define PROBLEM "https://yukicoder.me/problems/no/106"

#include "../../math/prime_sieve.hpp"
#include "../../template/template.hpp"

int main() {
    int N, K;
    cin >> N >> K;

    PrimeSieve ps(N);

    int ans = 0;
    rep (i, 2, N + 1) {
        auto pf = ps.get_prime_factors(i);

        if (K <= int(pf.size())) {
            ans++;
        }
    }

    cout << ans << LF;

    return 0;
}
