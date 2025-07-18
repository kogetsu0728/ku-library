#pragma once

#include "../template/template.hpp"

/**
 * @brief Segment Tree (セグメント木)
 */
template <class S, S (*op)(S, S), S (*e)()>
class SegmentTree {
  private:
    int n;
    vector<S> v;

    void update(int i) {
        v[i] = op(v[i << 1], v[(i << 1) | 1]);
        return;
    }

  public:
    SegmentTree() : SegmentTree(0) {}
    SegmentTree(int _n) : SegmentTree(vector<S>(_n, e())) {}
    SegmentTree(const vector<S>& _v) : n(int(_v.size())), v(_v.size() * 2, e()) {
        rep (i, 0, n) {
            v[n + i] = _v[i];
        }

        rrep (i, n - 1, 1) {
            update(i);
        }
    }

    S get(int i) const { return v[i + n]; }

    S prod(int l, int r) const {
        l += n;
        r += n;

        S v_l = e(), v_r = e();
        while (l < r) {
            if (l & 1) {
                v_l = op(v_l, v[l++]);
            }

            if (r & 1) {
                v_r = op(v[--r], v_r);
            }

            l >>= 1;
            r >>= 1;
        }

        return op(v_l, v_r);
    }

    void set(int i, S x) {
        i += n;
        v[i] = x;
        while (1 < i) {
            i >>= 1;
            update(i);
        }

        return;
    }
};
