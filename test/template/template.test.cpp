#define PROBLEM \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template/template.hpp"

int main() {
    ll s = 0;

    s = 0;
    rep(i, 0, 10) { s += i; }
    assert(s == 45);
    assert(chmin(s, 0LL));
    assert(chmax(s, 100LL));

    s = 0;
    rep(i, 0, 10, 1) { s += i; }
    assert(s == 45);

    s = 0;
    rep(i, 0, 10, 1) { s += i; }
    assert(s == 45);

    s = 0;
    rep(i, 0, 10, 9) { s += i; }
    assert(s == 9);

    s = 0;
    rrep(i, 9, 0) { s += i; }
    assert(s == 45);

    s = 0;
    rrep(i, 9, 0, 1) { s += i; }
    assert(s == 45);

    s = 0;
    rrep(i, 9, 0, 9) { s += i; }
    assert(s == 9);

    string ans = "Hello World";

    cout << ans << LF;

    return 0;
}
