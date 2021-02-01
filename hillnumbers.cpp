#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

bool ishill() {
    bool is_falling = false;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] > s[i-1] && is_falling) return false;
        if (s[i] < s[i-1]) {
            is_falling = true;
        }
    }
    return true;
}

ll dp[20][15][2][2];

ll dfs(int pos, int pre, int state, bool fp) {
    if (pos == s.length()) return 1;
    ll &ans = dp[pos][pre][state][fp];
    if (ans != -1) return ans;
    ans = 0;
    int fpmax = fp ? s[pos] - '0' : 9;
    if (state) {
        for (int i = 0; i <= min(fpmax, pre-1); ++i) {
            ans += dfs(pos+1, i, 0, fp && i==fpmax);
        }
        for (int i = pre; i <= fpmax; ++i) {
            ans += dfs(pos+1, i, 1, fp && i==fpmax);
        }
    } else {
        for (int i = 0; i <= min(fpmax, pre); ++i) {
            ans += dfs(pos+1, i, 0, fp && i == fpmax);
        }
    }
    
    return ans;
}

void solve() {
    memset(dp, -1, sizeof dp);
    cout << dfs(0, 0, 1, 1) - 1 << '\n';
}

int main() {
    cin >> s;

    if (!ishill()) {
        cout << "-1\n";
    } else {
        solve();
    }
}
