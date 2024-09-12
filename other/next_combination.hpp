#pragma once

/**
 * @brief Next Combination
 */
template <class T>
bool next_combination(const T& begin, const T& end, const int k) {
    const T& sub = begin + k;

    if (begin == end || begin == sub || end == sub) {
        return false;
    }

    T src = sub;
    while (begin != src) {
        src--;

        if (*src < *(end - 1)) {
            T dest = sub;
            while (*dest <= *src) dest++;

            iter_swap(src, dest);

            rotate(src + 1, dest + 1, end);
            rotate(sub, sub + (end - dest) - 1, end);

            return true;
        }
    }

    rotate(begin, sub, end);

    return false;
}
