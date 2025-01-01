#pragma once

#include "../template/template.hpp"

/**
 * @brief Dynamic Mod Int
 * @note 仮実装
 */
class DynamicModInt {
  private:
    int v;
    static int m;

  public:
    DynamicModInt() : v(0) {}
    DynamicModInt(ll _v) : v(int(((_v % m) + m) % m)) {}

    static void set_mod(int _m) {
        m = _m;
        assert(m <= INT_MAX / 2);

        return;
    }

    static DynamicModInt raw(int _v) {
        DynamicModInt res;
        res.v = _v;

        return res;
    }

    static int mod() { return m; }
    int val() const { return v; }

    friend bool operator==(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return lhs.v == rhs.v;
    }

    friend bool operator!=(const DynamicModInt& lhs, const DynamicModInt& rhs) {
        return !(lhs == rhs);
    }

    DynamicModInt& operator+=(const DynamicModInt& rhs) {
        v += rhs.v;
        if (m <= v) {
            v -= m;
        }

        return *this;
    }

    DynamicModInt& operator-=(const DynamicModInt& rhs) {
        if (v < rhs.v) {
            v += m;
        }
        v -= rhs.v;

        return *this;
    }

    DynamicModInt& operator*=(const DynamicModInt& rhs) {
        v = (ull(v) * rhs.val()) % m;

        return *this;
    }

    DynamicModInt& operator/=(const DynamicModInt& rhs) {
        assert(rhs.v != 0);

        return *this *= rhs.inv();
    }

    friend DynamicModInt operator+(const DynamicModInt& lhs,
                                   const DynamicModInt& rhs) {
        return DynamicModInt(lhs) += rhs;
    }

    friend DynamicModInt operator-(const DynamicModInt& lhs,
                                   const DynamicModInt& rhs) {
        return DynamicModInt(lhs) -= rhs;
    }

    friend DynamicModInt operator*(const DynamicModInt& lhs,
                                   const DynamicModInt& rhs) {
        return DynamicModInt(lhs) *= rhs;
    }

    friend DynamicModInt operator/(const DynamicModInt& lhs,
                                   const DynamicModInt& rhs) {
        return DynamicModInt(lhs) /= rhs;
    }

    DynamicModInt pow(ll y) const {
        DynamicModInt res = raw(1);
        DynamicModInt x = *this;

        while (0 < y) {
            if (y & 1) {
                res *= x;
            }

            x *= x;
            y >>= 1;
        }

        return res;
    }

    DynamicModInt inv() const { return pow(m - 2); }
};

int DynamicModInt::m = 998244353;
