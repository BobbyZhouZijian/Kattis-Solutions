#include <bits/stdc++.h>
using namespace std;

string solve(int k) {
    if (k == 1) return "4";
    if (k == 2) return "7";
    long cum = 0;
    long pow = 1;
    while (cum < k) {
        pow <<= 1;
        cum += pow;
    }
    cum -= pow;
    pow >>= 1;
    if (k <= cum + pow) {
        return "4" + solve(k - pow);
    } else {
        return "7" + solve(k - pow * 2);
    }
}

int main() {
    int k; cin >> k;
    cout << solve(k) << endl;
}