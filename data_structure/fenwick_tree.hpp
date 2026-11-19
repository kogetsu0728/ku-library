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
    std::vector<T> tree;

    [[nodiscard]]
    T prefix_sum(const int r) const {
        assert(0 <= r && r <= this->size());

        T res = T(0);
        for (int i = r; 0 < i; i -= i & -i) {
            res += tree[i - 1];
        }

        return res;
    }

  public:
    FenwickTree() : FenwickTree(0) {}
    FenwickTree(const int n) {
        assert(0 <= n);
        tree = std::vector<T>(n, T(0));
    }
    FenwickTree(const std::vector<T>& values) {
        assert(values.size() <= std::numeric_limits<int>::max());
        tree = std::vector<T>(values);
        const int n = this->size();
        for (int i = 0; i < n; ++i) {
            int parent = i | (i + 1);
            if (parent < n) {
                tree[parent] += tree[i];
            }
        }
    }

    [[nodiscard]]
    int size() const noexcept {
        return static_cast<int>(tree.size());
    }

    [[nodiscard]]
    T sum(const int l, const int r) const {
        assert(0 <= l && l <= r && r <= this->size());

        return this->prefix_sum(r) - this->prefix_sum(l);
    }

    [[nodiscard]]
    T get(const int i) const {
        assert(0 <= i && i < this->size());

        return this->sum(i, i + 1);
    }

    void add(const int index, const T& delta) {
        const int n = this->size();
        assert(0 <= index && index < n);

        for (int i = index; i < n; i = i | (i + 1)) {
            tree[i] += delta;
        }
    }

    void set(const int i, const T& value) {
        assert(0 <= i && i < this->size());

        this->add(i, value - this->get(i));

        return;
    }
};
