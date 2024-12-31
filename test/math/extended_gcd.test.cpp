#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"

#include "../../math/extended_gcd.hpp"
#include "../../template/template.hpp"

int main() {
    ll a, b;
    cin >> a >> b;

    ll x, y;
    ext_gcd(a, b, x, y);

    cout << x << ' ' << y << LF;

    return 0;
}
