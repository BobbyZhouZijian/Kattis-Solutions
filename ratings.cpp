#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ncr[505][505];
ll arr[35];

void precompute() {
    for (int i = 0; i < 505;++i) {
        ncr[i][0] = 1;
        ncr[i][i] = 1;
    }

    for (int i = 2; i < 505; ++i) {
        for (int j = 1; j < i; ++j) {
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    precompute();
    int n;
    while (cin >> n) {
        if ( n == 0 ) break;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }
        ll res = 0;
        for (int i = 0; i < sum; ++i) {
            res += ncr[i+n-1][n-1];
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < arr[i]; ++j) {
                ll cur_sum = sum - j;
                res += ncr[cur_sum+n-2-i][n-2-i];
            }
            sum -= arr[i];
        }
        cout << res+1 << '\n';
    }
}
