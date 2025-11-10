#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include "../../math/matrix.hpp"
#include "../../math/static_mod_int.hpp"
#include "../../template/template.hpp"

using mint = StaticModInt<998244353>;

int main() {
    int N;
    cin >> N;

    ll K;
    cin >> K;

    Matrix<mint> mat(N);
    rep (i, 0, N) {
        rep (j, 0, N) {
            ll a;
            cin >> a;

            mat.set(i, j, mint(a));
        }
    }

    mat = mat.pow(K);

    rep (i, 0, N) {
        rep (j, 0, N) {
            if (j > 0) {
                cout << ' ';
            }

            cout << mat.get(i, j).val();
        }

        cout << LF;
    }

    return 0;
}
