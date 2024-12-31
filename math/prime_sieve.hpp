#pragma once

#include "../template/template.hpp"

/**
 * @brief Prime Sieve (エラトステネスの篩)
 */
class PrimeSieve {
  private:
    vector<int> div, pri;

  public:
    PrimeSieve() : PrimeSieve(0) {}
    PrimeSieve(int _n) : div(_n + 1), pri(0) {
        rep(i, 2, _n + 1) {
            if (div[i] != 0) {
                continue;
            }

            div[i] = i;
            pri.emplace_back(i);

            for (ll j = i * i; j <= ll(_n); j += i) {
                if (div[j] != 0) {
                    continue;
                }

                div[j] = i;
            }
        }
    }

    bool is_prime(const int n) const { return (n < 2) ? false : (div[n] == n); }

    const vector<int>& get_primes() const { return pri; }

    vector<pair<int, int>> get_prime_factors(int n) const {
        vector<pair<int, int>> res;

        while (2 <= n) {
            if (res.empty() || res.back().first != div[n]) {
                res.emplace_back(div[n], 1);
            } else {
                res.back().second++;
            }

            n /= div[n];
        }

        return res;
    }

    vector<int> get_divisors(int n) const {
        vector<int> res;
        res.emplace_back(1);

        auto pf = get_prime_factors(n);

        for (auto [p, q] : pf) {
            int s = res.size();

            rep(i, 0, s) {
                int m = 1;

                rep(j, 0, q) {
                    m *= p;
                    res.emplace_back(res[i] * m);
                }
            }
        }

        sort(all(res));

        return res;
    }
};
