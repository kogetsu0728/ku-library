#pragma once

#include <cassert>
#include <limits>
#include <vector>

/**
 * @brief Fenwick Tree
 */
template <class T>
class FenwickTree {
  private:
    int n;
    std::vector<T> tree;

    T sum(const int r) const {
        assert(0 <= r && r <= n);

        T res = T(0);
        for (int i = r; 0 < i; i -= i & -i) {
            res += tree[i - 1];
        }

        return res;
    }

  public:
    FenwickTree() : FenwickTree(0) {}
    FenwickTree(const int _n) : n(_n) {
        assert(0 <= n);
        tree = std::vector<T>(n, T(0));
    }
    FenwickTree(const std::vector<T>& values) {
        assert(values.size() <= std::numeric_limits<int>::max());
        n = static_cast<int>(values.size());
        tree = std::vector<T>(values);
        for (int i = 0; i < n; ++i) {
            int parent = i | (i + 1);
            if (parent < n) {
                tree[parent] += tree[i];
            }
        }
    }

    T sum(const int l, const int r) const {
        assert(0 <= l && l <= r && r <= n);

        return sum(r) - sum(l);
    }

    T get(const int i) const {
        assert(0 <= i && i < n);

        return sum(i, i + 1);
    }

    void add(const int index, const T& delta) {
        assert(0 <= index && index < n);

        for (int i = index; i < n; i = i | (i + 1)) {
            tree[i] += delta;
        }
    }

    void set(const int i, const T& value) {
        assert(0 <= i && i < n);

        add(i, value - get(i));

        return;
    }
};
