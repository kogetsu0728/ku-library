#pragma once

/**
 * @brief Choose Minimum
 */
template <class T> bool chmin(T& a, const T& b) {
    return (a > b) ? (a = b, true) : false;
}

/**
 * @brief Choose Maximum
 */
template <class T> bool chmax(T& a, const T& b) {
    return (a < b) ? (a = b, true) : false;
}
