#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005, mod = 1000000;
string s;
int n, dp[MAXN][MAXN];

int search(int pos, int left) {
    if (pos == n) return 1;
    int &ans = dp[pos][left];
    int right = pos-left;
    if (ans !=-1) return ans;
    ans = 0;
    if (s[pos] == '(') {
        if (left+1 > n/2) return 0;
        return ans = search(pos+1, left+1);
    } else if (s[pos] == ')') {
        if (right+1 > n/2 || right+1 > left) return 0;
        return ans = search(pos+1, left); 
    }
    if (left+1 <= n/2)
        ans += search(pos+1, left+1);
    if (right+1 <= n/2 && right < left)
        ans += search(pos+1, left);
    return ans = (ans % mod);
}

void solve() {
    memset(dp, -1, sizeof dp);
    n = s.length();
    cout << search(0, 0) % mod << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while (cin >> s) {
        solve();
    }
}
