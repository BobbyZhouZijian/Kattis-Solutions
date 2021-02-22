#include <bits/stdc++.h>
using namespace std;

int N;
int p[20];
int dp[2][(1<<15)];
int all;

int search(int pos, int mask) {
    if (mask == all && pos==1) return 0;
    int &ans = dp[pos][mask];
    if (ans > -1) return ans;

    ans = INT_MAX;

    if (pos == 1) {
        for (int i = 0; i < N; ++i) {
            if (!(mask & (1<<i))) continue;
            ans = min(ans, p[i] + search(0, (all ^ mask) | (1<<i)));
        }

        return ans;
    }

    if (pos == 0 && __builtin_popcount(mask) == 1) {
        int pos = mask & (-mask);
        int i = __builtin_ctz(pos);
        return ans = min(ans, p[i]);
    }

    for (int i = 0; i < N; ++i) {
        if (!(mask & (1<<i))) continue;
        for (int j = 0; j < N; ++j) {
            if (j == i || !(mask & (1 << j))) continue;
            ans = min(ans, max(p[i], p[j]) + search(1, (all ^ mask) | (1<<i) | (1<<j)));
        }
    }

    return ans;
}

void fast() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

int main() {
    fast();
    memset(dp, -1, sizeof dp);
    cin >> N;
    all = (1 << N)-1;
    for (int i = 0; i < N; ++i)
        cin >> p[i];

    cout << search(0, all) << endl;
}
