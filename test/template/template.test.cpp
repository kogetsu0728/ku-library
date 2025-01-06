#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include "../../template/template.hpp"

int main() {
    ll s = 0;

    s = 0;
    rep (i, 0, 10) {
        s += i;
    }
    assert(s == 45);
    assert(chmin(s, 0LL));
    assert(chmax(s, 100LL));

    heap<int> max_queue_1;
    heap<int, false> max_queue_2;
    heap<int, true> min_queue;
    rep (i, 0, 10) {
        max_queue_1.emplace(i);
        max_queue_2.emplace(i);
        min_queue.emplace(i);
    }
    assert(max_queue_1.top() == 9);
    assert(max_queue_2.top() == 9);
    assert(min_queue.top() == 0);

    s = 0;
    rep (i, 0, 10, 1) {
        s += i;
    }
    assert(s == 45);

    s = 0;
    rep (i, 0, 10, 1) {
        s += i;
    }
    assert(s == 45);

    s = 0;
    rep (i, 0, 10, 9) {
        s += i;
    }
    assert(s == 9);

    s = 0;
    rrep (i, 9, 0) {
        s += i;
    }
    assert(s == 45);

    s = 0;
    rrep (i, 9, 0, 1) {
        s += i;
    }
    assert(s == 45);

    s = 0;
    rrep (i, 9, 0, 9) {
        s += i;
    }
    assert(s == 9);

    string ans = "Hello World";

    cout << ans << LF;

    return 0;
}
