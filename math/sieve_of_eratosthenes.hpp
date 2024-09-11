#pragma once

/**
 * @brief Sieve of Eratosthenes (エラトステネスの篩)
 */
class SieveOfEratosthenes {
  private:
    vector<int> div, pr;

  public:
    SieveOfEratosthenes() {}
    SieveOfEratosthenes(int n) : div(n + 1), pr() {
        div[1] = 1;

        for (long long i = 2; i <= n; i++) {
            if (div[i] != 0) continue;

            div[i] = i;
            pr.emplace_back(i);

            for (long long j = i * i; j <= n; j += i) {
                if (div[j] != 0) continue;

                div[j] = i;
            }
        }
    }

    bool is_prime(int n) const { return (n < 2 ? false : div[n] == n); }

    vector<int> get_primes() const { return pr; }

    vector<pair<int, int>> prime_factors(int n) const {
        vector<pair<int, int>> res;
        int x = n;

        while (2 <= x) {
            if (res.empty() || res.back().first != div[x]) {
                res.push_back({div[x], 1});
            } else {
                res.back().second++;
            }

            x /= div[x];
        }

        return res;
    }

    vector<int> divisors(int n) const {
        vector<int> res({1});
        auto pf = prime_factors(n);

        for (const auto& p : pf) {
            int s = int(res.size());

            for (int i = 0; i < s; i++) {
                int m = 1;

                for (int j = 0; j < int(p.second); j++) {
                    m *= p.first;
                    res.push_back(res[i] * m);
                }
            }
        }

        sort(res.begin(), res.end());

        return res;
    }
};
