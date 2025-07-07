#pragma once

#include "../template/template.hpp"

/**
 * @brief Static Mod Int
 */
template <int M>
class StaticModInt {
    static_assert(2 < M);
    static_assert(M <= INT_MAX / 2);

  private:
    int v;

  public:
    StaticModInt() : v(0) {}
    StaticModInt(ll _v) : v(int(((_v % M) + M) % M)) {}

    static StaticModInt raw(int _v) {
        StaticModInt res;
        res.v = _v;

        return res;
    }

    static int mod() { return M; }
    int val() const { return v; }

    friend bool operator==(const StaticModInt& lhs, const StaticModInt& rhs) {
        return lhs.v == rhs.v;
    }

    friend bool operator!=(const StaticModInt& lhs, const StaticModInt& rhs) {
        return !(lhs == rhs);
    }

    StaticModInt& operator+=(const StaticModInt& rhs) {
        v += rhs.val();
        if (M <= v) {
            v -= M;
        }

        return *this;
    }

    StaticModInt& operator-=(const StaticModInt& rhs) {
        if (v < rhs.val()) {
            v += M;
        }
        v -= rhs.val();

        return *this;
    }

    StaticModInt& operator*=(const StaticModInt& rhs) {
        v = (ull(v) * rhs.val()) % M;

        return *this;
    }

    StaticModInt& operator/=(const StaticModInt& rhs) {
        assert(rhs.val() != 0);

        return *this *= rhs.inv();
    }

    friend StaticModInt operator+(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) += rhs;
    }

    friend StaticModInt operator-(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) -= rhs;
    }

    friend StaticModInt operator*(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) *= rhs;
    }

    friend StaticModInt operator/(const StaticModInt& lhs, const StaticModInt& rhs) {
        return StaticModInt(lhs) /= rhs;
    }

    StaticModInt pow(ll y) const {
        StaticModInt res = raw(1);
        StaticModInt x = *this;

        while (0 < y) {
            if (y & 1) {
                res *= x;
            }

            x *= x;
            y >>= 1;
        }

        return res;
    }

    StaticModInt inv() const { return pow(M - 2); }
};
