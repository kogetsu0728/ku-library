#pragma once

#include "../template/template.hpp"

/**
 * @brief Matrix (行列)
 */
template <class T> class Matrix {
  private:
    int h, w;
    vector<vector<T>> d;

  public:
    Matrix() : Matrix(0) {}
    Matrix(int _h) : Matrix(_h, _h) {}
    Matrix(int _h, int _w) : h(_h), w(_w), d(_h, vector<T>(_w, T(0))) {}

    //! 単位行列
    static Matrix identity(int s) {
        Matrix res(s);

        rep (i, 0, s) {
            res.set(i, i, T(1));
        }

        return res;
    }

    int height() const { return h; }
    int width() const { return w; }

    T get(int i, int j) const { return d[i][j]; }
    T set(int i, int j, const T& v) { return d[i][j] = v; }

    friend bool operator==(const Matrix& lhs, const Matrix& rhs) {
        return lhs.d == rhs.d;
    }

    friend bool operator!=(const Matrix& lhs, const Matrix& rhs) {
        return lhs.d != rhs.d;
    }

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        assert(lhs.w == rhs.h);

        Matrix res(lhs.h, rhs.w);
        rep (i, 0, lhs.h) {
            rep (j, 0, rhs.w) {
                rep (k, 0, lhs.w) {
                    res.set(i, j, res.get(i, j) + lhs.get(i, k) * rhs.get(k, j));
                }
            }
        }

        return res;
    }

    Matrix& operator*=(const Matrix& rhs) noexcept { return *this = *this * rhs; }

    Matrix pow(ll y) const noexcept {
        assert(0 <= y);

        Matrix res = identity(h);
        Matrix x = *this;

        while (0 < y) {
            if (y & 1U) {
                res *= x;
            }

            x *= x;
            y >>= 1U;
        }

        return res;
    }
};
