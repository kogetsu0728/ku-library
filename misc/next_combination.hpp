#pragma once

/**
 * @brief Next Combination
 */
template <typename T>
bool next_combination(const T& begin, const T& end, int k) {
    const T& sub = begin + k;

    if (begin == end || begin == sub || end == sub) return false;

    T src = sub;
    while (begin != src) {
        src--;
        if ((*src) < (*(end - 1))) {
            T des = sub;
            while ((*des) <= (*src)) des++;
            iter_swap(src, des);
            rotate(src + 1, des + 1, end);
            rotate(sub, sub + (end - des) - 1, end);
            return true;
        }
    }
    rotate(begin, sub, end);

    return false;
}
