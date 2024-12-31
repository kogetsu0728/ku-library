#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include "../../string/rolling_hash.hpp"
#include "../../math/static_mod_int.hpp"
#include "../../template/template.hpp"

int main() {
    string S;
    cin >> S;

    int N = S.length();

    RollingHash<StaticModInt<999999937>> rh1(S);
    RollingHash<StaticModInt<998244353>> rh2(S, 4649);

    assert(rh1.size() == N);
    assert(rh2.size() == N);

    vector<int> ans(N);

    rep(i, 0, N) {
        auto check = [&](int m) -> bool {
            if (rh1.get(0, m) != rh1.get(i, i + m)) {
                return false;
            }

            if (rh2.get(0, m) != rh2.get(i, i + m)) {
                return false;
            }

            return true;
        };

        int ok = 0, ng = N - i + 1;
        while (1 < abs(ok - ng)) {
            int mid = (ok + ng) / 2;

            if (check(mid)) {
                ok = mid;
            } else {
                ng = mid;
            }
        }

        ans[i] = ok;
    }

    rep(i, 0, N) {
        if (0 < i) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << LF;

    return 0;
}
