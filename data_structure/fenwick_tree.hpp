#pragma once

#include "../template/template.hpp"

/**
 * @brief Fenwick Tree
 */
template <class T> class FenwickTree {
  private:
    int n;
    vector<T> v;

    T sum(int r) const {
        assert(0 <= r && r <= n);

        T res = T(0);
        while (0 < r) {
            res += v[r - 1];
            r -= 1 << __builtin_ctz(r);
        }

        return res;
    }

  public:
    FenwickTree() : FenwickTree(0) {}
    FenwickTree(int _n) : n(_n), v(_n, T(0)) { assert(0 <= n); }
    FenwickTree(const vector<T>& _v) : FenwickTree(_v.size()) {
        rep(i, 0, _v.size()) { set(i, _v[i]); }
    }

    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);

        return sum(r) - sum(l);
    }

    T get(int i) const {
        assert(0 <= i && i < n);

        return sum(i, i + 1);
    }

    void add(int i, const T& x) {
        assert(0 <= i && i < n);

        i++;
        while (i <= n) {
            v[i - 1] += x;
            i += 1 << __builtin_ctz(i);
        }

        return;
    }

    void set(int i, const T& x) {
        assert(0 <= i && i < n);

        add(i, x - get(i));

        return;
    }
};
