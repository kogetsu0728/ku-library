#pragma once

/**
 * @title Choose Minimum / Maximum
 */

template <class T>
bool chmin(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }

    return false;
}

template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }

    return false;
}
