#pragma once

#include "../template/template.hpp"

/**
 * @brief Rolling Hash (ローリングハッシュ)
 */
template <class T>
class RollingHash {
  private:
    vector<T> hash, pow;

  public:
    RollingHash() : RollingHash("") {}
    RollingHash(const string& _s, const T& _base = T(2525))
        : hash(_s.length() + 1), pow(_s.length() + 1) {
        hash[0] = T(0);
        pow[0] = T(1);

        rep (i, 0, _s.length()) {
            hash[i + 1] = hash[i] * _base + T(_s[i]);
            pow[i + 1] = pow[i] * _base;
        }
    }

    int size() const { return hash.size() - 1; }

    T shift(const T& h, int d) const { return h * pow[d]; }

    T get() const { return hash.back(); }

    T get(int l, int r) const { return hash[r] - shift(hash[l], r - l); }
};
