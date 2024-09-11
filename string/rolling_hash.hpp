#pragma once

/**
 * @brief Rolling Hash (ローリングハッシュ)
 */
class RollingHash {
    using ll = long long;

  private:
    static const ll mod1 = 888888901, mod2 = 987654323;
    ll base1, base2;
    int n;
    vector<ll> hash1, hash2, pow1, pow2;

  public:
    RollingHash() {}
    RollingHash(const string& s, const ll _base1 = 2525, const ll _base2 = 4649)
        : base1(_base1), base2(_base2) {
        n = s.length();
        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);
        for (int i = 0; i < n; i++) {
            hash1[i + 1] = (hash1[i] * base1 + s[i]) % mod1;
            hash2[i + 1] = (hash2[i] * base2 + s[i]) % mod2;
            pow1[i + 1] = (pow1[i] * base1) % mod1;
            pow2[i + 1] = (pow2[i] * base2) % mod2;
        }
    }

    pair<ll, ll> get(const int l, const int r) const {
        ll fi = hash1[r] - (hash1[l] * pow1[r - l] % mod1);
        if (fi < 0) fi += mod1;
        ll se = hash2[r] - (hash2[l] * pow2[r - l] % mod2);
        if (se < 0) se += mod2;
        return make_pair(fi, se);
    }

    pair<ll, ll> merge(const pair<ll, ll> a,
                       const pair<ll, ll> b,
                       const int b_len) const {
        ll fi = ((a.first * pow1[b_len]) % mod1 + b.first) % mod1;
        ll se = ((a.second * pow2[b_len]) % mod2 + b.second) % mod2;
        return make_pair(fi, se);
    }

    int lcp(const int a, const int b) const {
        int ok = 0, ng = min(n + 1 - a, n + 1 - b);
        while (1 < ng - ok) {
            int mid = (ok + ng) / 2;
            if (get(a, a + mid) == get(b, b + mid))
                ok = mid;
            else
                ng = mid;
        }
        return ok;
    }
};
