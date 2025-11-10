#pragma once

#include "../template/template.hpp"

/**
 * @brief Matrix (行列)
 */
template <typename T>
class Matrix {
  private:
    vector<vector<T>> data;

  public:
    Matrix() : Matrix(0) {}
    explicit Matrix(int _h) : Matrix(_h, _h) {}
    explicit Matrix(int _h, int _w) : data(_h, vector<T>(_w, T{})) {}

    //! 単位行列
    static Matrix identity(int s) {
        Matrix res(s);

        rep (i, 0, s) {
            res.set(i, i, T(1));
        }

        return res;
    }

    int row() const {
        return data.size();
    }

    int col() const {
        return data.empty() ? 0 : data[0].size();
    }

    T get(int i, int j) const {
        assert(0 <= i && i < row());
        assert(0 <= j && j < col());

        return data[i][j];
    }

    void set(int i, int j, const T v) {
        assert(0 <= i && i < row());
        assert(0 <= j && j < col());

        data[i][j] = v;

        return;
    }

    friend bool operator==(const Matrix& lhs, const Matrix& rhs) {
        return lhs.data == rhs.data;
    }

    friend bool operator!=(const Matrix& lhs, const Matrix& rhs) {
        return lhs.data != rhs.data;
    }

    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
        assert(lhs.col() == rhs.row());

        Matrix res(lhs.row(), rhs.col());
        rep (i, 0, lhs.row()) {
            rep (j, 0, rhs.col()) {
                rep (k, 0, lhs.col()) {
                    res.set(i, j, res.get(i, j) + lhs.get(i, k) * rhs.get(k, j));
                }
            }
        }

        return res;
    }

    Matrix& operator*=(const Matrix& rhs) {
        return *this = *this * rhs;
    }

    Matrix pow(ll y) const {
        assert(0 <= y);

        Matrix res = identity(h);
        Matrix x = *this;

        while (y > 0) {
            if (y & 1) {
                res *= x;
            }

            x *= x;
            y >>= 1;
        }

        return res;
    }
};
