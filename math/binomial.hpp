#pragma once

#include "../template/template.hpp"

/**
 * @brief Binomial (二項係数)
 * @note 参考: https://blog.hamayanhamayan.com/entry/2018/06/06/210256
 */
template <class T>
class Binomial {
  private:
    int n;
    vector<T> fact, ifact;

  public:
    Binomial() : Binomial(0) {}
    Binomial(int _n) : n(_n), fact(_n + 1), ifact(_n + 1) {
        assert(0 <= _n);

        fact[0] = T(1);
        rep (i, 0, n) {
            fact[i + 1] = fact[i] * T(i + 1);
        }

        ifact[n] = T(1) / fact[n];
        rrep (i, n, 1) {
            ifact[i - 1] = ifact[i] * T(i);
        }
    }

    //! 順列
    T p(int a, int b) const {
        if (b < 0 || a < b) {
            return T(0);
        }

        assert(0 <= a && a <= n);
        assert(0 <= a - b && a - b <= n);

        return fact[a] * ifact[a - b];
    }

    //! 組合せ
    T c(int a, int b) const {
        if (b < 0 || a < b) {
            return T(0);
        }

        assert(0 <= b && b <= n);

        return p(a, b) * ifact[b];
    }

    //! 重複組合せ
    T h(int a, int b) const {
        if (a == 0 && b == 0) {
            return T(1);
        }

        if (a <= 0 || b < 0) {
            return T(0);
        }

        return c(a + b - 1, b);
    }
};
