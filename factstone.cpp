#include <bits/stdc++.h>
using namespace std;

int n;
int pows[30];

void solve() {
    int pow = pows[(n - 1960) / 10 + 2];
    double thres = 0;
    int i = 0;
    while (thres <= pow) {
        ++i;
        thres += log2(i);
    }
    cout << i-1 << '\n';
}

int main() {
    pows[0] = 1;
    for (int i = 1; i < 30; ++i) {
        pows[i] = pows[i-1] << 1;
    }
    while(cin >> n) {
        if (n == 0) break;
        solve();
    }
}
