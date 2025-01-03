#pragma once

#include "../template/template.hpp"

/**
 * @brief Fenwick Tree
 */
template <class T> class FenwickTree {
  private:
    int n;
    vector<T> v;

  public:
    FenwickTree() : FenwickTree(0) {}
    FenwickTree(int _n) : n(_n), v(_n, T(0)) {}
    FenwickTree(const vector<T>& _v) : FenwickTree(_v.size()) {
        rep(i, 0, _v.size()) { set(i, _v[i]); }
    }

    T sum(int r) const {
        T res = T(0);
        while (0 < r) {
            res += v[r - 1];
            r -= 1 << __builtin_ctz(r);
        }

        return res;
    }

    T sum(int l, int r) const {
        assert(l <= r);
        return sum(r) - sum(l);
    }

    T get(int i) const { return sum(i, i + 1); }

    void add(int i, const T& x) {
        i++;
        while (i <= n) {
            v[i - 1] += x;
            i += 1 << __builtin_ctz(i);
        }

        return;
    }

    void set(int i, const T& x) {
        add(i, x - get(i));

        return;
    }
};
