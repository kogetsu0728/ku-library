#pragma once

/**
 * @brief Matrix (行列)
 */
template <class T> class Matrix {
  private:
    vector<vector<T>> val;

  public:
    Matrix() {}
    Matrix(const size_t _size) : Matrix(_size, _size) {}
    Matrix(const size_t _height, const size_t _width)
        : val(_height, vector<T>(_width)) {}
    Matrix(const vector<vector<T>> _val) : val(_val) {}

    size_t height() const { return val.size(); }
    size_t width() const { return (height() ? val[0].size() : 0); }

    T get(const int i, const int j) const { return val[i][j]; }
    T set(const int i, const int j, const T& v) { return val[i][j] = v; }

    static Matrix identity(const size_t s) {
        Matrix res(s, s);
        for (int i = 0; i < int(s); i++) {
            res.set(i, i, T(1));
        }

        return res;
    }

    friend bool operator==(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        return lhs.val == rhs.val;
    }

    friend Matrix<T> operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) {
        assert(lhs.width() == rhs.height());

        Matrix<T> res(lhs.height(), rhs.width());
        for (int i = 0; i < int(lhs.height()); i++) {
            for (int j = 0; j < int(rhs.width()); j++) {
                for (int k = 0; k < int(lhs.width()); k++) {
                    res.set(i, j,
                            res.get(i, j) + lhs.get(i, k) * rhs.get(k, j));
                }
            }
        }

        return res;
    }

    Matrix<T>& operator*=(const Matrix<T>& rhs) {
        assert(height() == width() && rhs.height() == rhs.width() &&
               height() == rhs.height());

        return *this = (*this) * rhs;
    }

    Matrix<T> pow(const long long n) const {
        assert(height() == width());

        long long m = n;
        Matrix<T> res = identity(height());
        Matrix<T> x(*this);
        while (m) {
            if (m & 1) res *= x;
            x *= x;
            m >>= 1;
        }

        return res;
    }
};
