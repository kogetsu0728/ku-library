#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "../../string/rolling_hash.hpp"

int main() {
    string S;
    cin >> S;

    RollingHash rh(S);

    for (int i = 0; i < int(S.length()); i++) {
        if (i) cout << ' ';
        cout << rh.lcp(0, i);
    }
    cout << endl;
}
