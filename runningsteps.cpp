#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int p;
int k, s;

ll bin[105][105];

void initialize() {
    for (int i = 0; i < 105; ++i)
        bin[i][0] = 1, bin[i][i] = 1;

    for (int i = 1; i < 105; ++i)
        for (int j = 1; j < i; ++j)
            bin[i][j] = bin[i-1][j] + bin[i-1][j-1];
}

void solve() {
    cin >> k >> s;
    s /= 2;
    int lo = s/3 + (s%3>0);
    int hi = s/2;
    ll res = 0;
    
    for (int i = lo; i <= hi; ++i) {
        int step1 = s - 2*i;
        ll b = bin[step1+i][i];
        res += b*b;
    }
    cout << k << ' ' << res << '\n';
}

int main() {
    initialize();
    cin >> p;
    while (p--)
        solve();
}
