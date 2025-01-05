#pragma once

/**
 * @brief choose minimum
 */
template <class T> bool chmin(T& a, const T& b) {
    return (a > b) ? (a = b, true) : false;
}

/**
 * @brief choose maximum
 */
template <class T> bool chmax(T& a, const T& b) {
    return (a < b) ? (a = b, true) : false;
}
