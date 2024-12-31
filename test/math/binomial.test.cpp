#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../math/binomial.hpp"
#include "../../template/template.hpp"

#include <atcoder/modint>
using namespace atcoder;

int main() {
    int T, M;
    cin >> T >> M;

    modint::set_mod(M);
    Binomial<modint> bin(min(M - 1, 10000000));

    while (T--) {
        int n, k;
        cin >> n >> k;

        cout << bin.c(n, k).val() << LF;
    }

    return 0;
}
