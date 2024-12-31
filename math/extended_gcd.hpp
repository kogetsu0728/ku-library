#pragma once

/**
 * @brief Extended Euclidean Algorithm (拡張ユークリッドの互除法)
 * @note 参考: https://qiita.com/drken/items/b97ff231e43bce50199a
 */
template <class T> T ext_gcd(T a, T b, T& x, T& y) {
    if (b == T(0)) {
        x = T(1);
        y = T(0);

        return a;
    }

    T res = ext_gcd(b, a % b, y, x);
    y -= (a / b) * x;

    return res;
}
