#pragma once

#include "../template/template.hpp"

/**
 * @brief Next Combination
 * @note 速度が重要なら再帰を書く (e.g., func(index, count, sum))
 */
template <class I> bool next_combination(const I& begin, const I& end, const size_t k) {
    const I sub = next(begin, k);

    if (begin == end || begin == sub || end == sub) {
        return false;
    }

    I src = sub;
    while (begin != src) {
        advance(src, -1);

        if (*src < *prev(end, 1)) {
            I dst = sub;
            while (*dst <= *src) {
                advance(dst, 1);
            }

            iter_swap(src, dst);
            rotate(next(src, 1), next(dst, 1), end);
            rotate(sub, next(sub, distance(dst, end) - 1), end);

            return true;
        }
    }

    rotate(begin, sub, end);

    return false;
}
