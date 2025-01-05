#pragma once

/**
 * @brief Choose Minimum
 */
template <class T> bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }

    return false;
}

/**
 * @brief Choose Maximum
 */
template <class T> bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }

    return false;
}
