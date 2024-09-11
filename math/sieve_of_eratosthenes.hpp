#pragma once

/**
 * @brief Sieve of Eratosthenes (エラトステネスの篩)
 */
class SieveOfEratosthenes {
  private:
    vector<int> div, pr, cnt;

  public:
    SieveOfEratosthenes() {}
    SieveOfEratosthenes(int n) : div(n + 1), pr(0), cnt(n + 1) {
        div[1] = 1;

        for (int i = 2; i <= n; i++) {
            if (div[i] != 0) continue;

            pr.emplace_back(i);
            for (int j = i; j <= n; j += i) {
                if (div[j] == 0) div[j] = i;
                cnt[j]++;
            }
        }
    }

    bool is_prime(int n) const { return (n < 2 ? false : div[n] == n); }

    int nth_prime(int n) const { return pr[n]; }

    int prev_prime(int n) const {
        int ok = 0, ng = int(pr.size());

        while (1 < ng - ok) {
            int m = (ok + ng) / 2;
            if (pr[m] < n)
                ok = m;
            else
                ng = m;
        }

        return pr[ok];
    }

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

    int next_prime(int n) const {
        int ok = 0, ng = int(pr.size());

        while (1 < ng - ok) {
            int m = (ok + ng) / 2;
            if (pr[m] <= n)
                ok = m;
            else
                ng = m;
        }

        return pr[ng];
    }

    int count_prime_factors(int n) const { return (n < 2 ? 0 : cnt[n]); }

    int count_divisors(int n) const {
        auto f = prime_factors(n);
        int res = 1;

        for (auto p : f) {
            res *= (1 + p.second);
        }

        return res;
    }

    int totient(int n) const {
        int res = n;
        auto f = prime_factors(n);

        for (const auto& p : f) {
            res /= p.first;
        }

        for (const auto& p : f) {
            res *= p.first - 1;
        }

        return res;
    }
};
