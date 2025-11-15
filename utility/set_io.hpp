#pragma once

#include "../template/include.hpp"

void set_io(int d = 16) {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(d);

    return;
}
