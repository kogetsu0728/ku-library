#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"

#include "../../math/binomial.hpp"
#include "../../math/dynamic_mod_int.hpp"
#include "../../template/template.hpp"

int main() {
    int T, M;
    cin >> T >> M;

    DynamicModInt::set_mod(M);
    Binomial<DynamicModInt> bin(min(M - 1, 10000000));

    while (T--) {
        int n, k;
        cin >> n >> k;

        cout << bin.c(n, k).val() << LF;
    }

    return 0;
}
