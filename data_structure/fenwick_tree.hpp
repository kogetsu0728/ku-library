#pragma once

#include <cassert>
#include <cstddef>
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

    static int checked_size(int size) noexcept {
        assert(0 <= size);
        return size;
    }

    static int checked_size(std::size_t size) noexcept {
        assert(size <= std::numeric_limits<int>::max());
        return static_cast<int>(size);
    }

    T sum(int r) const {
        assert(0 <= r && r <= n);

        T res = T(0);
        while (0 < r) {
            res += tree[r - 1];
            r -= r & -r;
        }

        return res;
    }

  public:
    FenwickTree() : FenwickTree(0) {}
    FenwickTree(int _n) : n(checked_size(_n)), tree(n, T(0)) {}
    FenwickTree(const std::vector<T>& values) : n(checked_size(values.size())), tree(values) {
        for (int i = 0; i < n; ++i) {
            int parent = i | (i + 1);
            if (parent < n) {
                tree[parent] += tree[i];
            }
        }
    }

    T sum(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);

        return sum(r) - sum(l);
    }

    T get(int i) const {
        assert(0 <= i && i < n);

        return sum(i, i + 1);
    }

    void add(int i, const T& delta) {
        assert(0 <= i && i < n);

        i++;
        while (i <= n) {
            tree[i - 1] += delta;
            i += i & -i;
        }

        return;
    }

    void set(int i, const T& value) {
        assert(0 <= i && i < n);

        add(i, value - get(i));

        return;
    }
};
