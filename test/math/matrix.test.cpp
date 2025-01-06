#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../../math/matrix.hpp"
#include "../../math/static_mod_int.hpp"
#include "../../template/template.hpp"

int main() {
    int N;
    cin >> N;
    ll K;
    cin >> K;

    vector A(N, std::vector<StaticModInt<998244353>>(N));
    Matrix<StaticModInt<998244353>> mat(N);
    rep (i, 0, N) {
        rep (j, 0, N) {
            ll a;
            cin >> a;

            mat.set(i, j, StaticModInt<998244353>(a));
        }
    }

    mat = mat.pow(K);

    rep (i, 0, N) {
        rep (j, 0, N) {
            if (0 < j) {
                cout << ' ';
            }

            cout << mat.get(i, j).val();
        }
        cout << LF;
    }

    return 0;
}
